package cecz2002;

import java.util.*;

public class MobilePhone {

	
	
	protected String owner;
	protected String color;
	protected double screenSize;
	
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
	
	public String getOwner() {
		return owner;
	}
	
	public String getColor() {
		return color;
	}
	
	public double getSize() {
		return screenSize;
	}
	
	public void setOwner(String owner) {
		this.owner = owner;
	}
	
	public void setSize(double screenSize) {
		if (screenSize > InterPhone.MAX_SCREEN_SIZE) {
			this.screenSize = InterPhone.MAX_SCREEN_SIZE;
		}else {
			this.screenSize = screenSize;
		}
	}
	
	public void setColor(String col) {
		color = col;
		
	}
	

	
	
	public void ring(String caller) {
		System.out.println("ring, ring, ring, this is " + caller);
	}
	
	public String sendSMS(String receiver) {
		//this.ring();
		System.out.println("hello " + receiver + ", this is " + this.owner);
		return "successfully sent";
	}
	
	public void print() {
		System.out.println("The owner is " + this.owner + "; The color is " 
				+ this.color + "; The screen size is " + this.screenSize);
	}
	
}
