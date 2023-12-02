package vvmm;
import java.io.*;
import java.util.*;

public class VendingMachine{
    private double drinkCost;
    private boolean run;
    Scanner sc = new Scanner(System.in);

    public VendingMachine(){
        //Drink = new Drink[3];
        //drink[0] = ...
    }
    public double selectDrink(){
        int choice;
        System.out.println("Please enter selection: ");
        choice = sc.nextInt();
        double cost=0;
        
        switch(choice){
            case 1:
                cost = 3.0;
                break;
            case 2:
                cost = 1.0;
                break;
            case 3:
                cost = 5.0;
                break;
        }
        return cost;
    }

    public double insertCoins(double drinkCost){
        System.out.println("Please insert coins: ");
        System.out.println("==========Coins Input=========");
        System.out.println("Enter 'Q' for ten cents input");
        System.out.println("Enter 'T' for twenty cents input");
        System.out.println("Enter 'F' for fifty cents input");
        System.out.println("Enter 'N' for a dollar input");
        System.out.println("=============================");
        
        double amt = 0;
        char choice1;
        do{
            choice1 = sc.next().toUpperCase().charAt(0);
            switch(choice1){
                case 'Q':
                    amt += 0.1;
                    break;
                case 'T':
                    amt += 0.2;
                    break;
                case 'F':
                    amt += 0.5;
                    break;
                case 'N':
                    amt += 1.0;
                    break;

            }
            System.out.printf("Coins inserted: %.2f\n", amt);
        }
        while(amt<drinkCost);
        
        return amt;
    }

    public void checkChange(double amount,double drinkCost){
        double change = amount - drinkCost;
        System.out.printf("Change: $%.2f\n", change);
    }

    public void printReceipt(){
        System.out.println("Please collect your drink\n Thank You!!");
    }

    public void start(){
        System.out.println("======Vending Machine======");
        System.out.println("1.Buy Beer($3.00)");
        System.out.println("2.Buy Coke($1.00)");
        System.out.println("3.Buy Green Tea($5.00)");
        System.out.println("|==========================|");
        
        double drink = selectDrink();

        checkChange(insertCoins(drink), drink);

        printReceipt();
    }
}