package lab4;

public class Rectangle extends Shape{
    public Rectangle(int num, double length, double breadth){
        super(num,length,breadth);
        setShapeType("Rectangle" + num);
    }

    public double area(){
        return super.getLength() * super.getBreadth();
    }
}
