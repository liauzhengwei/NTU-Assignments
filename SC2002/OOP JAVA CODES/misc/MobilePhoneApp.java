package cecz2002;

import java.util.*;

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
		//defaultPhone.sendSMS("Jane");
		
		MobilePhone johnPhone= new MobilePhone("John", "red", 7.0);
		//johnPhone.sendSMS("Jane");
		//System.out.println("the number of SMS sent is: " + MobilePhone.getNumOfSMS());
			
		//defaultPhone.ring();
		//System.out.println(johnPhone.sendSMS("Jane"));
		//johnPhone.print();
		//MobilePhone clonedPhone = johnPhone;
		//MobilePhone clonedPhone = johnPhone.clonePhone();
		//johnPhone.setColor("yellow");
		//johnPhone.print();
		//clonedPhone.print();
		

		
		
		App app = new App("facebook", 0.0);
		App app2 = new App("twitter", 0.0);
		App app3 = new App("Angry Bird", 2.0);
		
		ArrayList<App> appStore = new ArrayList<App>();
		appStore.add(app);
		appStore.add(app2);
		appStore.add(app3);
		
		MobilePhone tomPhone = new MobilePhone("Tom", "yellow", 6.5, app, appStore);
		//tomPhone.print();
		tomPhone.getApp().print();
		tomPhone.getAppStore().get(2).print();

	}
	

}
