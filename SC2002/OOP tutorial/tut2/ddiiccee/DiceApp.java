package ddiiccee;
import java.util.*;
import java.io.*;

public class DiceApp{
    public static void main(String[] args){
        int total = 0;

        System.out.println("Press <key> to roll the first dice");
        Scanner sc = new Scanner(System.in);    
        sc.nextLine();  //waits for user to press enter

        Dice dice1 = new Dice();
        dice1.setDiceValue();
        dice1.getDiceValue();
        dice1.printDiceValue();

        System.out.println("Press <key> to roll the first dice");
        sc.nextLine();

        Dice dice2 = new Dice();
        dice2.setDiceValue();
        dice2.getDiceValue();
        dice2.printDiceValue();
        total = dice1.getDiceValue() + dice2.getDiceValue();

        System.out.println("Your total number is: " + total);
    }
}
    
