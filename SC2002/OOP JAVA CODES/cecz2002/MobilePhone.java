package cecz2002;

import java.util.*;

public class MobilePhone {

	public static final int MAX_SCREEN_SIZE = 10;
	
	private String owner;
	private String color;
	private double screenSize;
	private App app;
	private ArrayList<App> appStore;
	
	private static int numOfSMS;
	
	public MobilePhone() {
		//owner = "xyz";
		//color = "white";
		//screenSize = 5.0;
		this("xyz", "white", 5.0);
	}
	
	public MobilePhone(String owner, String color, double screenSize) {
		this.owner = owner;
		this.color = color;
		this.screenSize = screenSize;
		
	}
	
	public MobilePhone(String owner, String color, double screenSize, App app, ArrayList<App> appStore) {
		this(owner, color, screenSize);
		this.app = app;
		this.appStore = appStore;
	}
	
	public String getOwner() {
		return owner;
	}
	
	public String getColor() {
		return color;
	}
	
	public double getSize() {
		return screenSize;
	}
	
	public App getApp() {
		return app;
	}
	
	public ArrayList<App> getAppStore(){
		return appStore;
	}
	
	public void setAppStore(ArrayList<App> appStore) {
		this.appStore = appStore;
	}
	
	public static int getNumOfSMS() {
		return numOfSMS;
	}
	
	public void setOwner(String owner) {
		this.owner = owner;
	}
	
	public void setSize(double screenSize) {
		
		if (screenSize > MAX_SCREEN_SIZE) {
			this.screenSize = MAX_SCREEN_SIZE;
		}else {
			this.screenSize = screenSize;
		}
		
	}
	
	public void setColor(String col) {
		color = col;
		
	}
	
	public void setApp(App app) {
		this.app = app;
	}
	
//	public MobilePhone clonePhone() {
//		MobilePhone clonedPhone = new MobilePhone(owner, color, screenSize);
//		return clonedPhone;
//	}
	
	public void ring() {
		System.out.println("ring, ring, ring!");
	}
	
	public String sendSMS(String receiver) {
		this.ring();
		numOfSMS++;
		System.out.println("hello " + receiver + ", this is " + this.owner);
		return "successfully sent";
	}
	
	public void print() {
		System.out.println("The owner is " + this.owner + "; The color is " 
				+ this.color + "; The screen size is " + this.screenSize);
	}
	
}
