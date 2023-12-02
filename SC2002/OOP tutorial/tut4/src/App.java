import java.util.*;


public class App {
    public static void main(String[] args) {
//Qn3
        try {
            sampleMethod(99);
        } catch (Exception e) {
            System.out.println("Caught in main.");
        }
    }
    public static void sampleMethod(int n) throws Exception{
        try{
            if(n>0){
                throw new Exception();
            }else if(n<0){
                throw new NegativeNumberException();
            }else{
                System.out.println("No Exception.");
            }
            System.out.println("Still in sampleMethod.");
        }
        catch(NegativeNumberException e){
            System.out.println("Caught in sampleMethod");
        }
        finally {
            System.out.println("In finally block");
        }
        System.out.println("After finally block");



//Qn2
/*
        App exceptiontest = new App();
        Scanner sc = new Scanner(System.in);
        int power =0;
        try{
            System.out.println("Give power level");
            power = sc.nextInt();
            if(power<0) throw new PowerFailureException();
        }
        catch(PowerFailureException p){
            System.out.println(p.getMessage());
        }
        System.out.println("end");
*/
//*******************************************************
//Qn1.
/*        int waittime = 12;

        try {
            System.out.println("Try block entered");
                if (waittime > 30) {
                    throw new Exception("Time Limited Exceeded");
                }
                System.out.println("Leaving try block");
            }
        catch(Exception e){
                System.out.println("Exception: " + e.getMessage());
        }
        System.out.println("After catch block");
*/
    }
}