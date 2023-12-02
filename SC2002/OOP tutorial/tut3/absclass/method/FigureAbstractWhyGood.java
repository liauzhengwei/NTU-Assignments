package absclass.method;

public class FigureAbstractWhyGood {
	public static void main( String[] args )
	 {
	  Figure f1 = new Rectangle( "Red" , 10 , 10 );
	  Figure f2 = new Circle( "Orange" , 5 );
	  
	  System.out.println("The two Figures have the same area? " + equalArea(f1,f2));
	 }
	
	//the method for comparing the areas of the two figures
	public static boolean equalArea(Figure fig1, Figure fig2){
		return fig1.findArea() == fig2.findArea();
	}
}
