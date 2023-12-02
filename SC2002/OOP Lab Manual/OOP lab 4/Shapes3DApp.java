package lab4;
import java.util.*;

public class Shapes3DApp {
    public static void main(String[] args) {
        /*no selection 

        //Pyramid py = new Pyramid("py", 25, 20);
        Sphere sp = new Sphere(10, "sp");
        //Cuboid cu = new Cuboid("cu", 50, 20);
        Cylinder cy = new Cylinder("cy", 50, 20);
        Cone co = new Cone("co", 25, 20);


        //System.out.println("Pyramid area = " + py.area());
        System.out.println("Sphere area = " + sp.area());
        //System.out.println("Cuboid area = " + cu.area());
        System.out.println("Cylinder area = " + cy.area());
        System.out.println("Cone area = " + co.area());
        
        //double overlap = py.getBreadth()* py.getBreadth() * 2 ;
        double overlap = Math.PI * (cy.getBreadth()/2) * (cy.getBreadth()/2) * 2 ;

        //double totalArea = py.area() + sp.area() + cu.area() - overlap;
        double totalArea = cy.area() + sp.area() + co.area() - overlap;
        System.out.println("Total 3D area = " + totalArea);
        */

        int sp = 1;
        int py =1;
        int cu =1;
        int co =1;
        int cy=1;

        int numShapes = 0;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of shapes: ");
        numShapes = sc.nextInt();
        int count =0;
        Shape[] shapes = new Shape[numShapes];

        do{ 
            count++;
            System.out.println("Select shape " + count +": ");
            /*System.out.println("1.Square");
            System.out.println("2.Triangle");
            System.out.println("3.Circle");
            System.out.println("4.Rectangle");
            */
            System.out.println("1.Sphere");
            System.out.println("2.Pyramid");
            System.out.println("3.Cuboid");
            System.out.println("4.Cylinder");
            System.out.println("5.Cone");

            int choice = 0;
            choice = sc.nextInt();
            
            switch(choice){
                case 1:
                    System.out.println("Enter radius of sphere: ");
                    double rad = sc.nextDouble();
                    shapes[count-1] = new Sphere(rad, sp);
                    sp++;
                    break;
                case 2:
                    System.out.println("Enter height of Pyramid: ");
                    double height = sc.nextDouble();
                    System.out.println("Enter base width of Pyramid: ");
                    double base = sc.nextDouble();
                    shapes[count-1] = new Pyramid(py, height, base);
                    py++;
                    break;
                case 3:
                    System.out.println("Enter height of Cuboid: ");
                    double hght = sc.nextDouble();
                    System.out.println("Enter base width of Cuboid: ");
                    double bse = sc.nextDouble();
                    shapes[count-1] = new Cuboid(cu, hght, bse);
                    cu++;
                    break;
                case 4:
                    System.out.println("Enter height of Cylinder: ");
                    double hht = sc.nextDouble();
                    System.out.println("Enter Diameter of Cylinder: ");
                    double dia = sc.nextDouble();
                    shapes[count-1] = new Cylinder(cy, hht, dia);
                    cy++;
                    break;
                case 5:
                    System.out.println("Enter height of Cone: ");
                    double ht = sc.nextDouble();
                    System.out.println("Enter Diameter of Cone: ");
                    double diam = sc.nextDouble();
                    shapes[count-1] = new Cone(co, ht, diam);
                    co++;
                    break;
            }
            numShapes--;
        }while (numShapes!=0);

        for (int i = 0; i < shapes.length; i++) {
            System.out.println(shapes[i].getShapeType());

            if(shapes[i] instanceof Sphere){
                Sphere sp1 = (Sphere)shapes[i];
                System.out.println("Area of Sphere: "+ sp1.area());
            }
            else if(shapes[i] instanceof Cylinder){
                Cylinder cy1 = (Cylinder)shapes[i];
                System.out.println("Area of Cylinder: "+ cy1.area());
            }
            else if(shapes[i] instanceof Cone){
                Cone co1 = (Cone)shapes[i];
                System.out.println("Area of Cone: "+ co1.area());
            }
            else if(shapes[i] instanceof Pyramid){
                Pyramid py1 = (Pyramid)shapes[i];
                System.out.println("Area of Pyramid: "+ py1.area());
            }
            else if(shapes[i] instanceof Cuboid){
                Cuboid cu1 = (Cuboid)shapes[i];
                System.out.println("Area of Cuboid: "+ cu1.area());
            }
        }
    }
}
