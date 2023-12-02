import java.util.Scanner;

public class P3 {
    public static void main(String []args){
        int startingValue;
        int endingValue;
        int increment;

        //1sgd = 1.82usd;

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the starting value: ");
        startingValue = sc.nextInt();

        System.out.println("Enter the ending value: ");
        endingValue = sc.nextInt();
        System.out.println("Enter the increment value: ");
        increment = sc.nextInt();

        if(startingValue>endingValue){
            System.out.println("Error input");
        }
        else{
            System.out.println("US$        S$");
            System.out.println("-------------");
            /*for
            for(;startingValue<=endingValue;startingValue+=increment){
                System.out.println(startingValue + "\t\t" + 1.82*startingValue);
            }*/

            /*while
            while(startingValue<=endingValue){
                System.out.println(startingValue + "\t\t" + 1.82*startingValue);
                startingValue+=increment;
            }*/
                
            //do while
            do{
                System.out.println(startingValue + "\t\t" + 1.82*startingValue);
                startingValue+=increment;
            }while(startingValue<=endingValue);
        }
    }
}
