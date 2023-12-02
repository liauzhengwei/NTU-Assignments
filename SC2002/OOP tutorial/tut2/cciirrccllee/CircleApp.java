package cciirrccllee;
import java.util.Scanner;

public class CircleApp {
    public static void main(String[] args){
        System.out.println("==== Circle Computation =====");
        System.out.println("|1. Create a new circle     |");
        System.out.println("|2. Print Area              |");
        System.out.println("|3. Print Circumference     |");
        System.out.println("|4. Quit                    |");
        System.out.println("=============================");
        
        int choice;
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Choose option (1-3):");
        choice = sc.nextInt();
        double r = 0;   
        Circle circle1 = new Circle(0);

        while(choice!=4){
            switch(choice){
                case 1:
                    System.out.println("Enter the radius to compute the area and circumference");
                    r = sc.nextDouble();
                    circle1 = new Circle(r);

                    System.out.println("A new circle is created");
                    System.out.println("Choose option (1-3):");

                    choice = sc.nextInt();
                    break;
                case 2:
                    circle1.printArea();
                    System.out.println("Choose option (1-3):");

                    choice = sc.nextInt();
                    break;
                case 3:
                    circle1.printCircumference();
                    System.out.println("Choose option (1-3):");

                    choice = sc.nextInt();
                    break;
                case 4:
                    break;
                default:
                    System.out.println("Enter a valid option, 4 to quit");
                    choice = sc.nextInt();
                    break;
            }
        }
        System.out.println("Thank you!!");
    }
}
