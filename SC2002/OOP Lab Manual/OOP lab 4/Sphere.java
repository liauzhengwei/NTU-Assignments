package lab4;

public class Sphere extends Circle {
    public Sphere(double radius, int num){
        super(radius, num);
        setShapeType("Sphere" + num);
    }

    public double area(){
        return Math.PI * super.getRadius() * super.getRadius() * 4;
    }
}
