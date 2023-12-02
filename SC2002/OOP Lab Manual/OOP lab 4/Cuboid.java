package lab4;

public class Cuboid extends Rectangle{
    public Cuboid(int num,double length, double breadth){
        super(num,length,breadth);
        setShapeType("Cuboid" + num);
    }

    public double area(){
        return 4 * super.getLength() * super.getBreadth() + 
        2 * super.getBreadth() * super.getBreadth();
    }
}
