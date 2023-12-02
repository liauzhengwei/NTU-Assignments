public class TestArray1
{
   public static void main( String[] args )
   {
      int[] a = { 1 , 2 , 3 , 4 };
      int[] b = { 2 , 4 , 6 , 8 };

      System.out.print( "array a:"); printArray(a);
      System.out.print( "array b:"); printArray(b);

      a = b ;   // array variable a will store the memory address of {2,4,6,8}
                // hence, it stores the memory address that is currently stored in b
                // note: {1,2,3,4} is no longer referenced by any array variable any more.

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