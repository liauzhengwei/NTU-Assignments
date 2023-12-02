public class PrintingDays2 
{
	public static void main(String[] args)
	{
		int i=0;	
		int[] days = {31,28,31,30,31,30,31,31,30,31,30,31};	
		
		// print the number of days in each month 
		for ( int arrayValue: days ) {
		
			System.out.println("Month " + (i+1) + " has " +  arrayValue + " days.");
			i++;
			}
	}
}


