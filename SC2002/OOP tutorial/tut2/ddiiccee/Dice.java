package ddiiccee;

public class Dice{
    private int valueOfDice;

    public Dice(){
        this.valueOfDice = 0;
    }

    public void setDiceValue(){
        this.valueOfDice = (1 + (int)(Math.random() * 5 ));
    }//(min + (int)(Math.random()*((max-min)+1))

    public int getDiceValue(){
        return valueOfDice;
    }
    public void printDiceValue(){
        System.out.println("Current Value is " + valueOfDice);
    }
}