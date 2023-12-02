package ppllaannee;

import java.io.*;
import java.util.*;

public class PlaneApp{
    public static void main(String[] args) {
        System.out.println("(1)Show number of empty seats");
        System.out.println("(2)Show the list of empty seats");
        System.out.println("(3)Show the list of seat assignments by seat ID");
        System.out.println("(4)Show the list of seat assifnments by customer ID");
        System.out.println("(5)Assign a customer to a seat");
        System.out.println("(6)Remove a seat assignment");
        System.out.println("(7)Exit");
    
        Scanner sc = new Scanner(System.in);
        int choice;
        int seatID;
        int custID;
        Plane coloAirLine = new Plane();

        do{
            System.out.println("\nEnter the number of your choice: ");
            choice = sc.nextInt();

            switch(choice){
                case 1:
                    coloAirLine.showNumEmptySeats();
                    break;
                case 2:
                    System.out.println("The following seats are empty: ");
                    coloAirLine.showEmptySeats();
                    break;
                case 3:
                    System.out.println("The seat assignments are as follow: ");
                    coloAirLine.showAssignedSeats(true);
                    break;
                case 4:
                    System.out.println("The seat assignments are as follow: ");
                    coloAirLine.showAssignedSeats(false);
                    break;
                case 5:
                    System.out.println("Assigning Seat ..");
                    System.out.println("    Please enter SeatID: ");
                    seatID = sc.nextInt();
                    System.out.println("    Please enter Customer ID: ");
                    custID = sc.nextInt();
                    coloAirLine.assignSeat(seatID,custID);
                    break;
                case 6:
                    System.out.println("    Please enter SeatID: ");
                    seatID = sc.nextInt();
                    coloAirLine.unAssignSeat(seatID);
                    break;
                case 7:
                    break;
                default:

            }
        }while (choice!=7);
    }
}
