package lab4;

public class Square extends Shape{
    public Square(int num, double length){
        super(num,length);
        setShapeType("Square" + num);
    }

    public double area(){
        return super.getLength() * super.getLength();
    }
}



