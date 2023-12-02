package cecz2002;

public class MobilePhone {

	private String owner;
	private String color;
	private double screenSize;
	
	
	public void ring() {
		System.out.println("ring, ring, ring!");
	}
	
	public String sendSMS(String receiver) {
		
		System.out.println("hello " + receiver + ", this is " + owner);
		return "successfully sent";
		
	}
	
}
