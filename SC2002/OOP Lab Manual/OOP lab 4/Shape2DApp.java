package lab4;

public class Shape2DApp {
    public static void main(String[] args) {
        Circle cir = new Circle(10, 1);
        Triangle tri = new Triangle(1, 25, 20);
        Rectangle rect = new Rectangle(1, 50, 20);

        System.out.println("Circle area = " + cir.area());
        System.out.println("Triangle area = " + tri.area());
        System.out.println("Rectangle area = " + rect.area());

        double totalArea = cir.area() + tri.area()+ rect.area();

        System.out.println("Total 2D area = " + totalArea);
    }
}
