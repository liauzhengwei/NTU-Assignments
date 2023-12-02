package lab4;

public class Triangle extends Shape{
    public Triangle(int num, double length, double breadth){
        super(num,length,breadth);
        setShapeType("Triangle" + num);
    }

    public double area(){
        return 0.5f * super.getLength() * super.getBreadth();
    }
}
