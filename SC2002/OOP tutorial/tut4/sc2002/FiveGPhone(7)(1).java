package cecz2002;

public final class FiveGPhone extends MobilePhone implements InterPhone{
//////////////////////////////////////////////////////////////////////////	
	private double dataRate;
	private double credit;
	
	public FiveGPhone(String owner, String color, double screenSize, double dataRate, double credit) {
		//super(owner, color, screenSize);
		super.owner = owner;
		super.color = color;
		super.screenSize = screenSize;
		
		
		this.dataRate = dataRate;
		this.credit = credit;
	}

	public double getDataRate() {
		return dataRate;
	}
	
	public double getCredit() {
		return credit;
	}
	
	public void setDataRate(double dataRate) {
		this.dataRate = dataRate;
	}
	
	public void setCredit(double credit) {
		this.credit = credit;
	}
	
	public final void ring() {
		System.out.println("play a music");
	}
	
	public String sendSMS(String receiver) {
		credit = credit - dataRate;
		System.out.println("this is a 5G phone");
		return super.sendSMS(receiver);
		////////////////////////////
	}
	
	public void print() {
		super.print();
		System.out.println("the available credit is " + credit);
	}
	
	
}

