package lab4;

public class Shape {
    private String shapeType;
    private double length;
    private double breadth;
    private double radius;
    private int num;

    public Shape(double radius, int num){  //circle
        this.num = num;
        this.radius = radius;
    }

    public Shape(int num,double length){    //square
        this.num = num;
        this.length = length;
    }

    public Shape(int num,double length, double breadth){    //rect,tri
        this.num = num;
        this.length = length;
        this.breadth = breadth;
    }

    public void setShapeType(String shapeType){
        this.shapeType = shapeType;
    }

    public String getShapeType(){
        return this.shapeType;
    }

    public double getRadius(){
        return this.radius;
    }

    public double getLength(){
        return this.length;
    }

    public double getBreadth(){
        return this.breadth;
    }

    public int getnum(){
        return this.num;
    }

    public void setLength(double length){
        this.length = length;
    }

    public void setBreadth(double breadth){
        this.breadth = breadth;
    }

    public void setnum(int num){
        this.num = num;
    }

    public void setRadius(double radius){
        this.radius = radius;
    }
}
