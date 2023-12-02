package ppooiinntt;

public class Cylinder extends Circle{
    private double height;

    public Cylinder(){
        super(1,1,1);height = 0;
    }

    public Cylinder(int x, int y,double radius,double ht){
        super(x,y,radius);height = ht;
    }



    public double getHeight(){
        return height;
    }

    public void setHeight(int height){
        this.height = height;
    }
    
    public String toString(){
            return "Height of the Cylinder is " + height + " with radius " + super.getRadius()
            + " of point [" + Integer.toString(super.getX()) + "," + Integer.toString(super.getY())
            +"]";
    }

    public double area(){
        //2 pi r^2 + 2pi rh
        return (super.area() * 2 + 2 * Math.PI * super.getRadius() * height);
    }

    public double volume(){
        //pi r^2 h
        return super.area() * height;
    }
}
