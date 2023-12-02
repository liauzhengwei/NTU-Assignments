package tut5;
//package tut5;

public class TestPolygon {
    public static void main(String[] args) {
        Rectangle rect = new Rectangle("bob", 10, 30);
        Triangle tri = new Triangle("bill", 50, 40);

        Polygon p;
    
        //printArea(rect);
        //printArea(tri);       //static binding

        p = rect;               //dynamic binding
        printArea(p);

        p = tri;
        printArea(p);
    }

    public static void printArea(Rectangle r){
        System.out.println("Area of the rectangle is " +r.calArea());
    }
    public static void printArea(Triangle t){
        System.out.println("Area of the triangle is " + t.calArea());
    }

    public static void printArea(Polygon p){    //dynamic binding
        if(p instanceof Rectangle){
            printArea((Rectangle)p);
        }
        else if(p instanceof Triangle){
            printArea((Triangle) p);
        }
    }

}
