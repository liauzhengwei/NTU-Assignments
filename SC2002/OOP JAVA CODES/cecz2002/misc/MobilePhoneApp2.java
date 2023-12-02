package cecz2002;

public class MobilePhoneApp {
	
	public static void main(String[] args) {
		
		MobilePhone myPhone;
		myPhone = new MobilePhone();
		
		MobilePhone defaultPhone = new MobilePhone();
		
		
		MobilePhone johnPhone= new MobilePhone("John", "red", 7.0);
		
		//defaultPhone.ring();
		
		System.out.println(johnPhone.sendSMS("Jane"));
		
		johnPhone.print();
		
		//MobilePhone tomPhone = new MobilePhone("Tom", "yellow", 6.5);
		//tomPhone.print();
		
		//MobilePhone clonedPhone = johnPhone;
		
		//MobilePhone clonedPhone = johnPhone.clonePhone();
		
		//johnPhone.setColor("yellow");
		//johnPhone.print();
		
		//clonedPhone.print();
	}
	

}
