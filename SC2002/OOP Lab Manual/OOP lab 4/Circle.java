package lab4;

public class Circle extends Shape{

    public Circle(double radius, int num){
        super(radius,num);
        setShapeType("Circle" + num);
    }

    public double area(){
        return Math.PI * super.getRadius() * super.getRadius();   
    }
}
