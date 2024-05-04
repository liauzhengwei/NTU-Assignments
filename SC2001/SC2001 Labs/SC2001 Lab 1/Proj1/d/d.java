import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

import com.opencsv.CSVWriter;


public class d {

    static final int ARRAY_SIZE=10000000;
    static final int NUMBER_OF_ITERATIONS=500;
    static final int OPTIMAL_S=48;//Our range is 30-55, but the optimal S for array size of 10,000,000 is 48, so we use 48 for this.
    static final int NUMBER_OF_THREADS=7;
    public static void main(String[] args) {

    try{
        File file = new File("d.csv");
        FileWriter outputfile = new FileWriter(file);
        CSVWriter writer = new CSVWriter(outputfile);
        
        double[][] resultArray=new double[Results.NUM_RESULT_CATEGORIES][NUMBER_OF_ITERATIONS];

        ExecutorService es = Executors.newCachedThreadPool();
        int indexesPerThread=NUMBER_OF_ITERATIONS/NUMBER_OF_THREADS;

        for(int threadId=0;threadId<NUMBER_OF_THREADS;threadId++){
            es.execute(new MyThread(resultArray,threadId,indexesPerThread,ARRAY_SIZE));   
            System.out.printf("Started Thread %d\n",threadId);            
        }
        System.out.printf("Waiting for threads to complete...\n\n");     
        es.shutdown();
        
        boolean finished = es.awaitTermination(10, TimeUnit.MINUTES);
        
        //Calculate all the averages and output to file.         
        String[] header = { "Avg HBS Time", "Avg HBS Comparisons","Avg MS Time","Avg MS Comparisons"};
        writer.writeNext(header); 
        
        double[] finalArray=new double[4];
        for(int i=0;i<Results.NUM_RESULT_CATEGORIES;i++)
        {
            double avg=0;
            int numElementAveraged=1;
            for(int j=0;j<NUMBER_OF_ITERATIONS;++j)
            {
                avg+=(resultArray[i][j]-avg)/numElementAveraged;
                numElementAveraged++;
            }
            finalArray[i]=avg;
        }
        String[] result={Double.toString(finalArray[Results.HBS_TIME]),Double.toString(finalArray[Results.HBS_COMP]),Double.toString(finalArray[Results.MS_TIME]),Double.toString(finalArray[Results.MS_COMP])};
        writer.writeNext(result);
        System.out.printf("HBS_TIME:%f\nHBS_COMP:%f\nMS_TIME:%f\nMS_COMP:%f\nSaved in csv.",finalArray[Results.HBS_TIME],finalArray[Results.HBS_COMP],finalArray[Results.MS_TIME],finalArray[Results.MS_COMP]); 

        writer.close();
    }
 
    catch(Exception e){
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

    public MyThread(double[][] resultOfIterations,int threadId,int indexesPerThread, int arraySize)
    {
        this.threadId=threadId;
        this.indexesPerThread=indexesPerThread;
        this.resultOfIterations=resultOfIterations;
        this.arraySize=arraySize;
    }

    public void run()
    {
        int HBScompCount;
        int MScompCount;
        long startTime,endTime,timePassed;
        int startIndex=threadId*indexesPerThread+2;
        int endIndex=(threadId+1)*indexesPerThread+1;

        //If last thread, we make it finish the remainder of indexes.
        if(threadId==d.NUMBER_OF_THREADS-1) endIndex=d.NUMBER_OF_ITERATIONS-1;

        for(int indexToInsert=startIndex;indexToInsert<=endIndex;indexToInsert++)
        {
            int[] arr = d.generateInput(arraySize);

            int[] b = Arrays.copyOfRange(arr, 0, arr.length);
            //KEY COMPARISONS & CPU times for HYBRID SORT
            startTime = System.currentTimeMillis();
            HBScompCount = d.hybridSort(arr,0,arr.length-1,d.OPTIMAL_S);
            endTime = System.currentTimeMillis();
            timePassed = endTime - startTime;
            resultOfIterations[Results.HBS_TIME][indexToInsert]=timePassed;
            resultOfIterations[Results.HBS_COMP][indexToInsert]=HBScompCount;

            //KEY COMPARISONS & CPU times for MERGE SORT
            startTime = System.currentTimeMillis();
            MScompCount = d.mergeSort(b,0,arr.length-1);
            endTime = System.currentTimeMillis();
            timePassed = endTime - startTime;
            resultOfIterations[Results.MS_TIME][indexToInsert]=timePassed;
            resultOfIterations[Results.MS_COMP][indexToInsert]=MScompCount;
            System.out.printf("Thread %d Index %d complete!\n",threadId,indexToInsert);
        }
    }
}

class Results 
{
    public final static int HBS_TIME = 0;
    public final static int HBS_COMP = 1;
    public final static int MS_TIME = 2;
    public final static int MS_COMP = 3;
    public final static int NUM_RESULT_CATEGORIES = 4;
}
