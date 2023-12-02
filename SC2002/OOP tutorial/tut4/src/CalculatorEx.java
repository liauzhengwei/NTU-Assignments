package trial;

import java.util.Scanner;

public class CalculatorEx {
    private double result ;
    Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("Calculator is on");
        CalculatorEx cal = new CalculatorEx();
        System.out.println("result = " + cal.resultValue());
        try{
            while(true){
                cal.doCalculation();
                System.out.println("updated result = " + cal.resultValue());
            }
        }
        catch(Exception e){
            System.out.println("Final result = " + cal.resultValue());
            System.out.println("End of Program");
        }
    }

    public CalculatorEx(){
        this.result = 0.0f;
    }

    public double resultValue(){
        return result;
    }

    public void doCalculation() throws Exception{
        char op = sc.next().charAt(0);
        double val;

        if(Character.toLowerCase(op)=='q'){
            throw new Exception();
        }
        else{
            val = sc.nextDouble();
        }
        try{
            result = evaluate(op,result,val);
            System.out.println("result " + Character.toString(op) + " " + val + " = " + result);
        }
        catch(UnknownOperatorException e){
            System.out.println(e.getMessage());
            result = handleUnknowOpException();
        }
    }

    public double evaluate(char op,double n1, double n2) throws UnknownOperatorException{
            switch (op) {
                case '+':
                    return (n1 + n2);
                case '-':
                    return (n1 - n2);
                case '*':
                    return (n1 * n2);
                case '/':
                    return (n1 / n2);
                default:
                    throw new UnknownOperatorException(op);
            }
    }

    public double handleUnknowOpException() throws Exception{
        char op;
        double val,tempResult;

        System.out.println("Please reenter: ");
        System.out.println("updated result = " + result);
        op = sc.next().charAt(0);

        if(Character.toLowerCase(op)=='q'){
            throw new Exception();
        }
        else if(op != '+' && op != '-' && op != '*' && op != '/'){
            System.out.println("Error:System is terminating");
            System.exit(0);
        }
        val = sc.nextDouble();

        tempResult = evaluate(op,result,val);
        System.out.println("result " + Character.toString(op) + " " + val + " = " + tempResult);

        return tempResult;
    }


}
