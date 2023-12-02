package aDensity;
import java.io.*;
import java.lang.*;
import java.util.*;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

import com.opencsv.CSVWriter;

public class aFixedvVaryE {
    
    //ARRAY for PRIORITY QUEUE
    public static final int NUMBER_OF_ITERATIONS=100;

    int[] minDistance(int[]dist, Boolean[]sptSet,int V){      //O(V) time complexity
        int min = Integer.MAX_VALUE,min_index = -1;
        int[] data = new int[2];
        int comparisons = 0;

        for (int v = 0; v < V; v++) {
            if(sptSet[v]==false){
                if(dist[v]<=min){
                    min = dist[v];
                    min_index = v;
                }
            comparisons++;
            }
        }
        data[0] = min_index;
        data[1] = comparisons;

        return data;
    }

    int dijkstra(int[][]graph,int src, int V){
        int[]data = new int[2];
        int comparison = 0;
        
        int[]dist = new int[V];
        Boolean[]sptSet = new Boolean[V];

        for (int i = 0; i < V; i++) {
            dist[i] = Integer.MAX_VALUE;
            sptSet[i] = false;
        }

        dist[src] = 0;

        //find shortest distance for remaining, non source V-1 vetices
        for (int count = 0; count < V-1; count++) {     //O(V-1) time = O(V) time
            data = minDistance(dist,sptSet,V);         //O(V) time from minDistance

            int u = data[0];
            sptSet[u] = true;

            comparison+=data[1];
            for (int v = 0; v < V; v++) {      //go through all connections to u,O(V) time
                if(!sptSet[v] && graph[u][v] !=0    //not shortest path,path exist 
                    && dist[u] != Integer.MAX_VALUE){     //error check
                    if(dist[u] + graph[u][v] < dist[v]){    //new shortest path
                        dist[v] = dist[u] + graph[u][v];
                    }
                    comparison++;
                }
            }
        }//total O(V^2) time

        //printSolution(dist,V); 
        return comparison;
    }
    
    //SQUARE matrices
    //distance values range from 0 to 100 AKA maxWeight=100

    public static int[][] generateDenseMatrix(int V,int E) {
        Random rand = new Random();
        int [][]arr = new int[V][V];
        /*for(int i=0;i< V;i++){        //default initialized to 0
            for(int j=0;j<V;j++){
                arr[i][j] = 0;
            }
        }*/

        for (int i = 0; i < E; i++) {
            int src = rand.nextInt(V);
            int dest = rand.nextInt(V);
            if(src!=dest && arr[src][dest]==0){
                int weight = rand.nextInt(100);     //max weight is assumed 100
                arr[src][dest] = weight;
                //arr[dest][src] = weight;
            }
            else{
                i--;
            }
        }

        return arr;
    }

    public static void main(String[] args) {
        try {
            //Write header of csv file           
            File file = new File("aFixedVVaryE.csv");
            FileWriter outputfile = new FileWriter(file);
            CSVWriter writer = new CSVWriter(outputfile);
            
            String[] header = { "Number of Edges for 100 Vertices", "Average Time Taken(ns)"};
            //String[] header = { "Number of Edges for 100 Vertices", "Average Number of Comaprisons)"};
            writer.writeNext(header); 
        
            int V=100;
            //int maxEdges = 4950; //= 100 * 99 /2 = V * (V-1) / 2; for bidirectional
            int maxEdges = 9900; //= 100 * 99 = V * (V-1); for unidirectional
            
            //generate graphs with 100 vertices and varying edge number
            for(int E = 100; E<=maxEdges; E+=98){       
                double[] resultOfIterations=new double[NUMBER_OF_ITERATIONS+2];
                resultOfIterations[0]=E;
                    
                for (int j = 2; j < NUMBER_OF_ITERATIONS+2; j++) {
                    //pass edge number to generate array      
                    int [][]randArray = generateDenseMatrix(V,E);
                    int comparisons =0;
                        
                    //printArray(randArray);
                    //System.out.println("");
                    
                    aFixedvVaryE t = new aFixedvVaryE();
                        
                    long startTime = System.nanoTime();
                    comparisons = t.dijkstra(randArray,0,V);
                    long endTime = System.nanoTime();
                    long timepassed = endTime - startTime;
                    
                    //remove comment below for time passed
                    //resultOfIterations[j] = comparisons;
                    resultOfIterations[j] = timepassed; 
                }

                double avg = 0;
                int numElementAveraged = 1;

                for (int j = 2; j < NUMBER_OF_ITERATIONS+2; j++) {
                    avg+=(resultOfIterations[j]-avg)/numElementAveraged;
                    numElementAveraged++;
                }
                resultOfIterations[1]=avg;

                //Write data to csv
                String[] result={Integer.toString(E),Double.toString(resultOfIterations[1])};
                writer.writeNext(result);
                //System.out.printf("For Number of Edges of %d, average number of comparisons of %f written to csv.\n\n",E,resultOfIterations[1]);
                System.out.printf("For Number of Edges of %d, average time taken of %f ns written to csv.\n\n",E,resultOfIterations[1]);  
            }        
            writer.close(); 
        }
        catch (Exception e) {
            e.printStackTrace();
        }

    }

    /*void printSolution(int[]dist,int V){
        System.out.println("Vertex \t\t Distance from Source");
        for (int i = 0; i < V; i++) {
            if(dist[i]!=Integer.MAX_VALUE){
                System.out.println(i + " \t\t " + dist[i]);
            }
            else{
                System.out.println(i + " \t\t Null");
            }
        }
    }*/

    /*public static void printArray(int[][]arr){
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[0].length; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println("");
        }
    }*/
}
