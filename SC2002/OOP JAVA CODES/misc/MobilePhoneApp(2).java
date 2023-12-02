package cecz2002;

import java.util.*;

public class MobilePhoneApp {
	
	public static void main(String[] args) {
		
		MobilePhone defaultPhone = new MobilePhone();
		defaultPhone.setOwner("Tom");
		defaultPhone.setColor("yellow");
		defaultPhone.setSize(10);
		
		MobilePhone johnPhone= new MobilePhone("John", "red", 7.0);

		johnPhone.ring("Tom");
		
		FiveGPhone janePhone = new FiveGPhone("Jane", "white", 5.0, 0.5, 20.0);
		janePhone.ring("John");
		janePhone.sendSMS("John");
		janePhone.print();
		
		
		
		
	}
	

}
