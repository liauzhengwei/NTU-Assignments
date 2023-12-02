package cecz2002;

public class MobilePhoneApp {
	
	public static void main(String[] args) {
		
		MobilePhone myPhone;
		myPhone = new MobilePhone();
		
		MobilePhone defaultPhone = new MobilePhone();
		defaultPhone.setOwner("Tom");
		defaultPhone.setColor("yellow");
		defaultPhone.setSize(10);
		//System.out.println("the owner of the default phone is: " + defaultPhone.getOwner());
		//System.out.println("the color of the default phone is: " + defaultPhone.getColor());
		//System.out.println("the size of the default phone's screen is: " + defaultPhone.getSize());
		
		defaultPhone.sendSMS("Jane");
		
		
		
		MobilePhone johnPhone= new MobilePhone("John", "red", 7.0);
		johnPhone.sendSMS("Jane");
		
		System.out.println("the number of SMS sent is: " + MobilePhone.getNumOfSMS());
		
		
		//defaultPhone.ring();
		
		//System.out.println(johnPhone.sendSMS("Jane"));
		
		//johnPhone.print();
		
		//MobilePhone tomPhone = new MobilePhone("Tom", "yellow", 6.5);
		//tomPhone.print();
		
		//MobilePhone clonedPhone = johnPhone;
		
		//MobilePhone clonedPhone = johnPhone.clonePhone();
		
		//johnPhone.setColor("yellow");
		//johnPhone.print();
		
		//clonedPhone.print();
	}
	

}
