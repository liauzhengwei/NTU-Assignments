package absclass.method;

public abstract class Figure
{
   private String color;
   public  Figure()           { color      = "black"; }
   public  Figure( String c ) { this.color = c;       }
   
   public String getColor() { return color; }

   // abstract methods - no method body
   public abstract double findArea()      ;
   public abstract double findPerimeter() ;
   public abstract void   print()         ;
}

