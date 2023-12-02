package cecz2002;

public class MobilePhone {

	private String owner;
	private String color;
	private double screenSize;
	
	public MobilePhone() {
		owner = "xyz";
		color = "white";
		screenSize = 5.0;
	}
	
	public MobilePhone(String owner, String color, double screenSize) {
		this.owner = owner;
		this.color = color;
		this.screenSize = screenSize;
	}
	
	public void setColor(String col) {
		color = col;
		
	}
	
	public MobilePhone clonePhone() {
		MobilePhone clonedPhone = new MobilePhone(owner, color, screenSize);
		return clonedPhone;
	}
	
	public void ring() {
		System.out.println("ring, ring, ring!");
	}
	
	public String sendSMS(String receiver) {
		this.ring();
		System.out.println("hello " + receiver + ", this is " + this.owner);
		return "successfully sent";
	}
	
	public void print() {
		System.out.println("The owner is " + this.owner + "; The color is " 
				+ this.color + "; The screen size is " + this.screenSize);
	}
	
}
