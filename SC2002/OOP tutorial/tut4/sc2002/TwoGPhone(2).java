package cecz2002;

public class TwoGPhone extends MobilePhone implements InterPhone{
	
	public TwoGPhone(String owner, String color, double screenSize) {
		super.owner = owner;
		super.color = color;
		super.screenSize = screenSize;
	}
	
	public String sendSMS(String receiver) {
		System.out.println("this is a 2G phone");
		return super.sendSMS(receiver);
	}

	public void ring() {
		System.out.println("ring, ring, ring");
	}
	
}
