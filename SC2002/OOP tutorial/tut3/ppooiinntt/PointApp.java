package ppooiinntt;

public class PointApp {
    public static void main(String[] args){
        Cylinder cy = new Cylinder(1, 1,1,1);
        Circle cc = new Circle(1,1,1);
        Point pt = new Point(1,1);

        System.out.println("" + pt.getX());
        System.out.println("" + pt.getY());
        System.out.println("" + pt.toString());
    
        System.out.println("" + cc.getRadius());
        System.out.println("" + cc.area());
        System.out.println("" + cc.toString());
        System.out.println("" + cc.getX());

        System.out.println("" + cy.getHeight());
        System.out.println("" + cy.area());
        System.out.println("" + cy.volume());
        System.out.println("" + cy.toString());
    
    
    
    
    }
}
