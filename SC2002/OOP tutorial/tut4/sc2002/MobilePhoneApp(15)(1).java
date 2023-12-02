package cecz2002;

import java.util.*;

public class MobilePhoneApp {
	
	public static void main(String[] args) {
		
		//MobilePhone defaultPhone = new MobilePhone();
		//defaultPhone.setOwner("Tom");
		//defaultPhone.setColor("yellow");
		//defaultPhone.setSize(10);
		
		//MobilePhone johnPhone= new MobilePhone("John", "red", 7.0);

		//johnPhone.ring("Tom");
		
		MobilePhone janePhone = new FiveGPhone("Jane", "white", 5.0, 0.5, 20.0);
		janePhone.sendSMS("John");
		//janePhone.print();
		
		janePhone = new TwoGPhone("Jane", "white", 5.0);
		janePhone.sendSMS("John");
		
		InterPhone tomPhone = new FiveGPhone("Tom", "red", 6.0, 0.5, 30.0);
		tomPhone.ring();
		
		tomPhone = new TwoGPhone("Tom", "red", 6.0);
		tomPhone.ring();
		
	}
	

}
