
public class Days
{
   public static void main( String[] args )
   {
      int[] days ;         // This declare an array variable, named days
                           // Note that we have a memory slot only for days itself 
                           // to hold the memory address of the actual array data; 
                           // since it is not refercing to any data at this moment,
                           // it stores value NULL at this moment.

      days = new int[12];  // Here we allocate memory of size equals to 12 integers
                           // And the starting memory address is assigned to days
                           // Hence, days stores a non-NULL memory address now.

      // We can also do the above two things in one line of java code statement
      //int[] days = new int[12];
   }
}
