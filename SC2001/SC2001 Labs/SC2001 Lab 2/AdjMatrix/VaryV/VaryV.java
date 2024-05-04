//SHOULD BE CORRECT//
package VaryV;
import java.io.*;
import java.lang.*;
import java.util.*;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

import com.opencsv.CSVWriter;

class ShortestPath{
    
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

        return data;    //return data with min_index as first value and comparisons as second value
    }

    int dijkstra(int[][]graph,int src, int V){
        int[]data = new int[2];     //for number of comparisons
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
                if(!sptSet[v] && graph[u][v] !=0    //not in shortest path tree,path exist 
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

    //Varying V from 10 to 1000,produce graph with fixed edges
    public static int[][] generateSparseMatrix(int V) {
        Random rand = new Random();
        int [][]arr = new int[V][V];    //default initialized to 0
        
        int sparseEdges =(int) (((float)3/(float)8)*(V*V-V)); //fixed E

        //create 3/8(V**2-V) Edges with Random Source and Dest Vertices and Random Weights
        for (int i = 0; i < sparseEdges; i++) {
            int src = rand.nextInt(V);          
            int dest = rand.nextInt(V);
            if(src!=dest && arr[src][dest]==0){
                int weight = rand.nextInt(100);     //max weight is assumed 100,distance values
                arr[src][dest] = weight;
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
            File file = new File("aVaryVFixedE.csv");
            FileWriter outputfile = new FileWriter(file);
            CSVWriter writer = new CSVWriter(outputfile);
            
            //remove comment symbol based on if time passed or comparisons is being done
            String[] header = { "Number of Vertices", "Average Time Taken(ns)"};
            //String[] header = { "Number of Vertices", "Average Number of Comparisons Done"};
            writer.writeNext(header); 
        
            for (int V = 10; V <= 1000; V++) {    //for vertices size range from 10 to 1000
                //int V=10;

                double[] resultOfIterations=new double[NUMBER_OF_ITERATIONS+2];     
                resultOfIterations[0]=V;            //vertices as first column in excel
                
                for (int i = 2; i < NUMBER_OF_ITERATIONS+2; i++) {      //generate NUMBER_OF_ITERATIONS graphs and find average
                    int [][]randArray = generateSparseMatrix(V);
                    int comparisons = 0;
                    
                    //printArray(randArray);
                    //System.out.println("");
                
                    ShortestPath t = new ShortestPath();
                    
                    long startTime = System.nanoTime();
                    comparisons = t.dijkstra(randArray,0,V);
                    //t.dijkstra(randArray,0,V);
                    long endTime = System.nanoTime();

                    long timepassed = endTime - startTime;

                    //remove comment symbol below for time passed;
                    resultOfIterations[i] = timepassed;   
                    //resultOfIterations[i] = comparisons;
                }

                double avg = 0;
                int numElementAveraged = 1;

                for (int i = 2; i < NUMBER_OF_ITERATIONS+2; i++) {
                    avg+=(resultOfIterations[i]-avg)/numElementAveraged;
                    numElementAveraged++;
                }
                resultOfIterations[1]=avg;

                //Write data to csv
                String[] result={Integer.toString(V),Double.toString(resultOfIterations[1])};
                writer.writeNext(result);
                //System.out.printf("For Number of Vertices of %d, average number of comparisons of %f written to csv.\n\n",V,resultOfIterations[1]); 
                System.out.printf("For Number of Vertices of %d, average time passed of %f written to csv.\n\n",V,resultOfIterations[1]); 

                //remove comment symbol above for time passed
            }      
            writer.close();
        }
        catch (Exception e) {
            e.printStackTrace();
        }

    }

    /*void printSolution(int[]dist,int V){        //FUNCTION NOT USED
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

    /*public static void printArray(int[][]arr){          //FUNCTION NOT USED
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[0].length; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println("");
        }
    }*/
}

