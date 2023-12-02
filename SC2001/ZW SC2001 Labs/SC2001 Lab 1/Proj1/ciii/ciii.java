import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

import com.opencsv.CSVWriter;

public class ciii {
    public static final int MIN_ARRAY_SIZE=1000;
    public static final int MAX_ARRAY_SIZE=10000000;
    public static final int ARRAY_SIZE_INTERVAL=399960;//(max-min)/(how many values we want) Final number of values will be number of values we want+1.
    public static final int NUMBER_OF_ITERATIONS=21;
    public static final int NUMBER_OF_THREADS=7;
    public static final int MAX_S=250;
    public static void main(String[] args) {
        try
            {
            //Write header of csv file           
  
            
            int numberOfArrays=((MAX_ARRAY_SIZE-MIN_ARRAY_SIZE)/ARRAY_SIZE_INTERVAL)+1;
            
            //For each array size, we run multiple iterations to get the average comparisons for each S value, and deduce the best optimum S.

            for(int arrayNumber=0;arrayNumber<numberOfArrays;arrayNumber++)
            {
                int arraySize=MIN_ARRAY_SIZE+ARRAY_SIZE_INTERVAL*arrayNumber;
                int indexesPerThread=NUMBER_OF_ITERATIONS/NUMBER_OF_THREADS;
               
               String name=Integer.toString((arraySize));
               name+=".csv";
               File file = new File(name);
               FileWriter outputfile = new FileWriter(file);
               CSVWriter writer = new CSVWriter(outputfile);
               
               String[] header = { "S value", "Time taken"};
               writer.writeNext(header);

                //We need 2 additional columns for the average, and the value of S
                double[][] resultOfIterations=new double[MAX_S][NUMBER_OF_ITERATIONS+2];
                        
                //Each thread will run its fair share of iterations. Every iteration will store its results for every S in the result 2dArray. We can calculate the average later.
                ExecutorService es = Executors.newCachedThreadPool();
                System.out.printf("\n\nCreating Threads for Array Size:%d\n",arraySize);   
                for(int threadId=0;threadId<NUMBER_OF_THREADS;threadId++){
                    es.execute(new MyThread(resultOfIterations,threadId,indexesPerThread,arraySize));           
                }
                System.out.printf("Waiting for threads to complete...\n\n");     
                es.shutdown();
                
                boolean finished = es.awaitTermination(10, TimeUnit.DAYS);      
                
                //All iterations have been completed. Calculate average and put into index [S][1] of resultOfIterations
                for(int sVal=0;sVal<MAX_S;sVal++)
                {
                    double avg = 0;
                    int numElementAveraged=1;

                    for(int i=2;i<=NUMBER_OF_ITERATIONS+1;++i)
                    {
                        avg+=(resultOfIterations[sVal][i]-avg)/(double)numElementAveraged;
                        numElementAveraged++;
                    }
                    resultOfIterations[sVal][1]=avg; 
                }   
                //Find the best S value based on average results, save result for corresponding array size in bestSForArraySize. 
                int minIndex=0;
                for(int iterator=0;iterator<MAX_S;iterator++)
                {
                  String[] result={Integer.toString(iterator),Double.toString(resultOfIterations[iterator][1])};
                  writer.writeNext(result);
                }
               System.out.printf("\nArraySize:%d written to %d.csv!\n",arraySize,arraySize);     
               writer.close();                  
            }


        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
    }

    

    public static int hybridSort(int arr[],int beg, int end,int S){
        int mid = (beg+end)/2;
        if((end-beg) <= S){
            return insertionSort(arr,beg,end);
        }
        else{
            return hybridSort(arr,beg,mid,S) + hybridSort(arr,mid+1, end,S)+ merge(arr, beg, end, mid);
        }
    }

    public static int[] generateInput(int n) {
        Random rand = new Random();
        int arr[] = new int[n];
        for(int i=0;i< arr.length;i++){
            arr[i] = rand.nextInt(n);
        }
        return arr;
    }

    public static int mergeSort(int arr[], int beg,int end){
        int mid = (beg+end)/2;
        if((end-beg) <=0){
            return 0;
        }
        else{
            return mergeSort(arr,beg,mid) + mergeSort(arr,mid+1,end) + merge(arr,beg,end,mid);
        }
    }

    public static int merge(int arr[],int beg,int end,int mid){
        int comCount = 0;
        int leftArrSize = mid - beg + 1;  //start to mid
        int rightArrSize = end - mid;     //mid+1 to end

        int leftArr[] = new int[leftArrSize];
        int rightArr[] = new int[rightArrSize];

        for (int i = 0; i < leftArrSize; i++) {
            leftArr[i] = arr[beg+ i];
        }

        for (int j = 0; j < rightArrSize; j++) {
            rightArr[j] = arr[mid + 1+ j];
        }

        int i=0,j=0;
        int k=beg;
        while(i< leftArrSize && j< rightArrSize) {
            comCount++;
            if (leftArr[i] == rightArr[j]){
                arr[k++] = leftArr[i++];
                arr[k++] = rightArr[j++];
            }
            else if(leftArr[i] < rightArr[j]){
                arr[k++] = leftArr[i++];
            }
            else{
                arr[k++] = rightArr[j++];
            }
        }
        while(i < leftArrSize){
            arr[k++] = leftArr[i++];
        }
        while(j < rightArrSize){
            arr[k++] = rightArr[j++];
        }
        return comCount;
    }

    public static int insertionSort(int arr[],int beg, int end){
        int comp = 0, temp = 0;
        for (int i = beg; i <= end; i++) {
            for (int j = i; j > beg; j--) {
                comp++;
                if (arr[j]<arr[j-1]){
                    temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
                }
                else{
                    break;
                }
            }
        }
        return comp;
    }

}


//Class that creates and runs the threads
class MyThread implements Runnable
{
    private int threadId;
    private int indexesPerThread;
    private double[][] resultOfIterations;
    private int arraySize;

    public MyThread(double[][] resultOfIterations,int threadId,int indexesPerThread,int arraySize)
    {
        this.threadId=threadId;
        this.indexesPerThread=indexesPerThread;
        this.resultOfIterations=resultOfIterations;
        this.arraySize=arraySize;
    }

    public void run()
    {
        int startIndex=threadId*indexesPerThread+2;
        int endIndex=(threadId+1)*indexesPerThread+1;

        //If last thread, we make it finish the remainder of indexes.
        if(threadId==ciii.NUMBER_OF_THREADS-1) endIndex=ciii.NUMBER_OF_ITERATIONS+1;

        for(int indexToInsert=startIndex;indexToInsert<=endIndex;indexToInsert++)
        {
            int []arrayToSort = ciii.generateInput(arraySize);

            //Try all values of S until MAX_S for this array, and store results in resultArray.
            for(int sVal=0;sVal<ciii.MAX_S;sVal++)
            {
                //Copy array to sort with diff S vals
                int[] copyArray = Arrays.copyOfRange(arrayToSort, 0, arrayToSort.length);
                long startTime = System.currentTimeMillis();
                int HBScompCount = ciii.hybridSort(copyArray,0,copyArray.length-1,sVal);
                long endTime = System.currentTimeMillis();
                long timePassed = endTime - startTime;
                resultOfIterations[sVal][indexToInsert]=timePassed;
            }
            //Indexes might be beyond our number of iterations chosen because of +2 slots to accomodate average and S values.
            System.out.printf("|Iteration indexes %d complete.| ",indexToInsert);
        }
    }
}

