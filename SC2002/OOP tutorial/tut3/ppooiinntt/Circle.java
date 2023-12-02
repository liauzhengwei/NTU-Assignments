package ppooiinntt;

public class Circle extends Point{
    private double radius;

    public Circle(){    //constructor can use methods from parent thru inheritance
        super(1,1);radius = 0;
    ///////////////////////
    }
    public Circle(int x,int y,double rad){
    //////////////////////////////////////        
        super(x,y);radius = rad;
        ///////////////////////
    }

    public double getRadius(){
        return this.radius;
    }

    public void setRadius(double radius){
        this.radius = radius;
    }

    public String toString(){
        return "Radius of circle is " + radius + " for point [" + Integer.toString(super.getX()) + "," + 
        Integer.toString(super.getY()) + "]";
        //////////////////////////////
    }
    

    public double area(){
        //pi r^2
        return Math.PI * radius * radius;
    }
}
