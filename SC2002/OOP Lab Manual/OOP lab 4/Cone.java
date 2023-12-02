package lab4;

public class Cone extends Pyramid{
    public Cone(int num, double length,double breadth){
        super(num, length, breadth);
        setShapeType("Cone" + num);
    }
    
    public double area(){   //half of breadth is radius
        return Math.PI * (super.getBreadth()/2) * ((super.getBreadth()/2) +
            Math.sqrt(super.getLength() *super.getLength() + 
            (super.getBreadth()/2) * (super.getBreadth()/2)));
    }
}
