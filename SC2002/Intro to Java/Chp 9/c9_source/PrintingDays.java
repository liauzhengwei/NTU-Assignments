public class PrintingDays 
{
	public static void main(String[] args)
	{
		int i;	
		int[] days = {31,28,31,30,31,30,31,31,30,31,30,31};	
		
		// print the number of days in each month 
		for ( i=0 ; i < days.length ; i++ )
			System.out.println("Month " + (i+1) + " has " +  days[i] + " days.");
	}
}


