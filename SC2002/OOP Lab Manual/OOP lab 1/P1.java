import java.util.Scanner;

public class P1 {
    public static void main(String [] args){
        char choice;
        
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a character: ");
        choice = sc.next().charAt(0);

        switch(choice){
            case 'A':
            case 'a':
                System.out.println("Action movie fan");
                break;
            case 'C':
            case 'c':
                System.out.println("Comedy movie fan");
                break;
            case 'D':
            case 'd':
                System.out.println("Drama movie fan");
                break;
            default:
                System.out.println("Invalid choice");
                break;
        }
    }
}
