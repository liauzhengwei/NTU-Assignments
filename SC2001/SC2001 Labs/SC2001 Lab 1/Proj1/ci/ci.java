import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

import com.opencsv.CSVWriter;


public class ci {
    public static final int NUMBER_OF_ITERATIONS=100;
    public static final int NUMBER_OF_THREADS=7;
    public static final int S=5;

    public static void main(String[] args) {
        try {
            //Write header of csv file           
            File file = new File("ci.csv");
            FileWriter outputfile = new FileWriter(file);
            CSVWriter writer = new CSVWriter(outputfile);
            
            String[] header = { "Array Size", "Average Key Comparisons"};
            writer.writeNext(header); 


            //Calculate avg result, and write data to csv.     
            for (int arraySize = 1000; arraySize <=10000000; arraySize+=99990) 
            {                            
                //We need columns for the ArraySize value, and average of results.
                double[] resultOfIterations=new double[NUMBER_OF_ITERATIONS+2];
                resultOfIterations[0]=arraySize;

                //Create threads to test the test sort NUMBER_OF_ITERATIONS number of times, and append it to result array. We can obtain the average later.
                ExecutorService es = Executors.newCachedThreadPool();
                int indexesPerThread=NUMBER_OF_ITERATIONS/NUMBER_OF_THREADS;

                for(int threadId=0;threadId<NUMBER_OF_THREADS;threadId++){
                    es.execute(new MyThread(resultOfIterations,threadId,indexesPerThread,arraySize));   
                    System.out.printf("Array Size:%d Started Thread %d\n",arraySize,threadId);            
                }
                System.out.printf("Waiting for threads to complete...\n\n");     
                es.shutdown();
                
                boolean finished = es.awaitTermination(10, TimeUnit.DAYS);

                //All iterations have been completed. Calculate average and put into index 1 of resultOfIterations
                double avg = 0;
                int numElementAveraged=1;

                for(int i=2;i<=NUMBER_OF_ITERATIONS+1;++i)
                {
                    avg+=(resultOfIterations[i]-avg)/numElementAveraged;
                    numElementAveraged++;
                }
                resultOfIterations[1]=avg;

                //Write data to csv
                String[] result={Integer.toString(arraySize),Double.toString(resultOfIterations[1])};
                writer.writeNext(result);
                System.out.printf("Threads complete for Array size %d, average of %f written to csv.\n\n",arraySize,resultOfIterations[1]); 
            }      
            writer.close();
     
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }
       
    public static int hybridSort(int arr[],int beg, int end,int S){
        int mid = (beg+end)/2;
        if((end-beg) <= S){
            return insertionSort(arr,beg,end);
        }
        else{
            return hybridSort(arr,beg,mid,S) + hybridSort(arr,mid+1, end,S)+ 
            merge(arr, beg, end, mid);
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
    private double[] resultOfIterations;
    private int arraySize;

    public MyThread(double[] resultOfIterations,int threadId,int indexesPerThread, int arraySize)
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
        if(threadId==ci.NUMBER_OF_THREADS-1) endIndex=ci.NUMBER_OF_ITERATIONS+1;

        for(int indexToInsert=startIndex;indexToInsert<=endIndex;indexToInsert++)
        {
            int []arrayToSort = ci.generateInput(arraySize);
            int HBScompCount = ci.hybridSort(arrayToSort,0,arrayToSort.length-1,ci.S);
            resultOfIterations[indexToInsert]=HBScompCount;
        }
    }
}
