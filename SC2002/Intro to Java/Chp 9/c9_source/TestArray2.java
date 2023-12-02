public class TestArray2
{
   public static void main( String[] args )
   {
      int[] a = { 1 , 2 , 3 , 4  };
      int[] b = { 2 , 4 , 6 , 8  };
      int[] tmp ;   // tmp is an array variable without refercing to any contents here

      System.out.print( "array a:"); printArray(a);
      System.out.print( "array b:"); printArray(b);

		tmp = a ;
		a   = b ;
		b   = tmp ;

      System.out.print( "array a:"); printArray(a);
      System.out.print( "array b:"); printArray(b);
   }
	
	public static void printArray( int [] arr )
	{
	   for ( int i = 0 ; i < arr.length ; i ++ )
		   System.out.print( " " + arr[i] );
	   System.out.println( "");
	}
}