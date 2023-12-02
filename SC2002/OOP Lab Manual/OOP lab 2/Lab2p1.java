import java.util.Scanner;
public class Lab2p1{
    public static void main(String []args){
        int choice;
        Scanner sc = new Scanner(System.in);
        do{
            System.out.println("");
            System.out.println("Perform the following methods:");
            System.out.println("1: multiplication test");
            System.out.println("2: quotient using division by subtraction");
            System.out.println("3: remainder using division by subtraction");
            System.out.println("4: count the number of digits");
            System.out.println("5: position of a digit");
            System.out.println("6: extract all odd digits");
            System.out.println("7: quit");
            System.out.println("");
            System.out.println("Enter your choice:");
            choice = sc.nextInt();

            switch(choice){
                case 1:
                    mulTest();
                    break;
                case 2:
                    System.out.println("Enter number m to be divided:");
                    int m = sc.nextInt();
                    System.out.println("Enter divisor n:");
                    int n = sc.nextInt();
                    int result = divide(m,n);
                    System.out.println(m +"/"+ n +"=" + result);
                    break;
                case 3:
                    System.out.println("Enter number m to be divided:");
                    int a = sc.nextInt();
                    System.out.println("Enter divisor n:");
                    int b = sc.nextInt();
                    int remainder = modulus(a,b);
                    System.out.println(a +"%"+ b +"=" + remainder);
                    break;
                case 4:
                    System.out.println("Enter number n:");
                    int e = sc.nextInt();
                    int count = countDigits(e);
                    if(count==0){
                        System.out.println("Error input!!");
                        break;
                    }
                    else{
                        System.out.println("count ="+ count);
                        break;
                    }
                case 5:
                    System.out.println("Enter number n:");
                    int p = sc.nextInt();
                    System.out.println("Enter digit to find:");
                    int d = sc.nextInt();
                    int pos = position(p,d);
                    System.out.println("position = "+ pos);
                    break;
                case 6:
                    System.out.println("Enter number n:");
                    long u = sc.nextLong();
                    if(u<0){
                        System.out.println("Error input!!");
                        break;
                    }
                    else{
                        long oddDigits = extractOddDigits(u);
                        System.out.println("oddDigits = "+ oddDigits);
                        break;
                    }
                case 7:
                    System.out.println("Program terminating....");
            }
        }while(choice<7);
    }

    public static void mulTest(){
        int test = 0;
        int correct = 0;
        Scanner sc = new Scanner(System.in);
        
        while(test != 5){
            int x = (1+ (int)(Math.random() * 9));
            int y = (1+ (int)(Math.random() * 9));
            System.out.println("How much is "+ x + " times "+ y + "?");
            double ans = sc.nextDouble();
            
            double result = x * y;
            if(result == ans){
                correct++;
            }
            test++;
        }
        System.out.println(correct + " answers out of 5 are correct");

    }

    public static int divide(int m,int n){
        int count = 0;
        while(m>=0){
            m-=n;
            if(m>=0){
                count++;
            }
        }
        return count;
    }

    public static int modulus(int m, int n){
        int remainder = -1;
        while(m>=0){
            m-=n;
        }
        remainder = m + n;

        return remainder;
    }

    public static int countDigits(int n){
        int digits = 0;

        while(n>0){
            n = n/10;
            digits++;
        }
        return digits;
    }

    public static int position(int n, int digit){
        int y = -1;
        int pos = 1;
        while(n>0){
            y = n%10;
            if(y==digit){
                return pos;
            }
            pos++;
            n = n/10;
        }
        return -1;    
    }

    public static long extractOddDigits(long n){
        long y = -1;
        long oddDigits=0;
        long pos = 1;
        while(n>0){
            y = n%10;
            if(y%2==1){
                oddDigits += pos * y;
                pos *= 10;
            }
            n = n/10;
        }
        if(oddDigits==0){
            return -1;
        }
        else{
            return oddDigits;
        }    
    }
}