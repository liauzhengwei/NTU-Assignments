package lab4;

public class Cylinder extends Cuboid{
    public Cylinder(int num,double length, double breadth){
        super(num,length,breadth);
        setShapeType("Cylinder" + num);
    }

    public double area(){   //half of breadth is radius
        return Math.PI * (super.getBreadth()/2) * (super.getBreadth()/2) * 2 +
                Math.PI * super.getBreadth() * super.getLength();
    }
}



