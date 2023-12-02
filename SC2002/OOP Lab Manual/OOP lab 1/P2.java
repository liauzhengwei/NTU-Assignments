import java.util.Scanner;

public class P2 {
    public static void main(String [] args){
        int merit,salary;
        char grade;

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter salary:");
        salary = sc.nextInt();
        System.out.println("Enter merit");
        merit = sc.nextInt();

        if(salary>=800){
            grade = 'A';
        }

        else if(salary>=700 && salary<=799){
            if(merit<20){
                grade = 'B';
            }
            else{
                grade = 'A';
            }
        }

        else if(salary>=650 && salary<=699){
            grade = 'B';
        }

        else if(salary>=600 && salary<=649){
            if(merit<10){
                grade = 'C';
            }
            else{
                grade = 'B';
            }
        }
        else if(salary>=500 && salary<=599){
            grade = 'C';
        }
        else{
            grade = '?';
        }
        
        System.out.println("Grade "+ grade);

    }
}
