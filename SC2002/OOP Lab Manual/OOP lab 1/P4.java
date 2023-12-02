import java.util.Scanner;
import java.lang.String;

public class P4 {
    public static void main(String [] args){
        int height;
        String aString = "AA";
        String bString = "BB";
        String cString = "";
        int flipper = 1;

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the height: ");

        height = sc.nextInt();
        if(height <=0){
            System.out.println("Error input");
        }
        else{
            for(;height>0;height--){
                if(flipper == 1){
                    cString = aString.concat(cString);
                    System.out.println("" + cString);            

                    flipper *= -1;
                }
                else if(flipper == -1){
                    cString = bString.concat(cString);
                    System.out.println(""+ cString);

                    flipper *= -1;                    
                }
            }
        }
    }
}
