import java.io.*;
import java.lang.*;
import java.util.*;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

import com.opencsv.CSVWriter;


public class SC2001P3{
    public static void main(String[] args) {
        try {
            //Write header of csv file           
            File file = new File("Unbounded Knapsack.csv");
            FileWriter outputfile = new FileWriter(file);
            CSVWriter writer = new CSVWriter(outputfile);
            String[] header = { "Profit","Weight\\Capacity", "0","1","2","3","4","5","6","7","8","9","10","11","12","13","14"};
            writer.writeNext(header); 

            int[] profit = new int[3];
            int[] weight = new int[3];

            weight[0] = 4;
            //weight[0] = 5;  
            profit[0] = 7;

            weight[1] = 6;
            profit[1] = 6;
            
            weight[2] = 8;
            profit[2] = 9;

            //create matrix for inital profit and weight
            int[][] ProfitWeight = new int[3][2];
            for (int i = 0; i <= 2; i++) {
                ProfitWeight[i][0] = profit[i];
                ProfitWeight[i][1] = weight[i];
            }

            //execute knapsack algorithm
            int[][] P = new int[3][15];
            P = Profit(14,3,weight,profit);

            // Print out the table
            for (int i = 0; i <= 2; i++) {
                for (int j = 0; j <= 14; j++) {
                    System.out.print(P[i][j] + " ");
                }
                System.out.println();
            }

            // Write the table to csv file
            for (int i = 0; i <= 2; i++) {
                String[] rowString = new String[ProfitWeight[i].length + P[i].length + 2];
                rowString[0] = Integer.toString(ProfitWeight[i][0]); // Profit
                rowString[1] = Integer.toString(ProfitWeight[i][1]); // Weight
                for (int j = 0; j < P[i].length; j++) {
                    rowString[j + 2] = Integer.toString(P[i][j]);
                }
                writer.writeNext(rowString);
            }  
            writer.close();
        }
        catch (Exception e) {
            e.printStackTrace();
        }

    }

    // Unbounded Knapsack function
    public static int[][] Profit(int Capacity, int NoOfObjType, int[] weight, int[] profit){
        int[][] P = new int[NoOfObjType][Capacity + 1];

        for (int i = 0; i < NoOfObjType; i++) { //Initialise all 
        //first col, since when capacity=0, profit=0.
            P[i][0]=0;
        }

        for (int i = 0; i < NoOfObjType; i++) {
            for (int j = 1; j <= Capacity; j++) { //Start from 1 since
                // first column alr initialised
                if (weight[i] > j)
                {
                    //if first row, initialise to 0. 
                    //If other rows, they can read from above.
                    if(i==0)
                    {
                        P[i][j]=0;
                    }
                    else
                    {
                        P[i][j] = P[i-1][j];
                    }
                } 
                else
                {   //If first row, can't compare with index above,
                    // so only get the leftSide case. 
                    if(i==0)
                    {
                        P[i][j]=P[i][j - weight[i]] + profit[i];
                    }
                    else
                    {
                        P[i][j] = Math.max(P[i-1][j], P[i][j - weight[i]] + profit[i]);
                    }
                }
            }
        }
        return P;
    }

}