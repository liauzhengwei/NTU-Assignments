public class TestArray3
{
   public static void main( String[] args )
   {
      int[] a ;
      a = new int[4] ;

      int[] b = { 2 , 4 , 6 , 8  };

      myMethod( a , b );

      System.out.print( "array a:"); printArray(a);
      System.out.print( "array b:"); printArray(b);
   }	
   public static void myMethod( int [] p , int [] q )
   {
      p = q ;
      p[1] = 5;   // it modifies the contents referenced by who? a or b?

      System.out.print( "array p:"); printArray(p);
      System.out.print( "array q:"); printArray(q);
   }
   public static void printArray( int [] arr )
   {
      for ( int value : arr )
         System.out.print( " " + value );

      // The following for loop works in the same way
      // as the enhanced for loop above
      //for ( int i = 0 ; i < arr.length ; i ++ )
      //   System.out.print( " " + arr[i] );

      System.out.println( "" );
   }
}
