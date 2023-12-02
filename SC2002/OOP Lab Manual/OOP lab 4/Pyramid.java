package lab4;

public class Pyramid extends Triangle{
    public Pyramid(int num, double length,double breadth){
        super(num, length, breadth);
        setShapeType("Pyramid" + num);
    }

    public double area(){
        return 4* super.getLength() * super.getBreadth() * 0.5f +
        super.getBreadth() * super.getBreadth();
    }
    
}
