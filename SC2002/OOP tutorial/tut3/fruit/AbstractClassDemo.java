package fruit;

import java.awt.Color;
import java.util.ArrayList;
import java.util.List;

public class AbstractClassDemo {
	public static void main(String args[]){
		Fruit mango = new Mango(Color.YELLOW, true); 
		Fruit banana = new Banana(Color.YELLOW, false);
		Fruit strawberry = new Strawberry(Color.RED, true);
		
		List<Fruit> platter = new ArrayList<>();
		
		platter.add(mango);
		platter.add(strawberry);
		platter.add(banana);
		
		serve(platter);
	}
	
	public static void serve(List<Fruit> fruits){
		System.out.println("Preparing fruits to serve");
		for (Fruit f: fruits){
			f.prepare();}
	}
}


abstract class Fruit { 
private Color color; 
private boolean seasonal; 

public Fruit(Color color, boolean seasonal) 
{ this.color = color; this.seasonal = seasonal; } 

public abstract void prepare();

public Color getColor() { return color; } 
public boolean isSeasonal() { return seasonal; } 
}

class Mango extends Fruit { 

public Mango(Color color, boolean seasonal) { super(color, seasonal); } 

@Override 
public void prepare() { System.out.println("Cut the Mango"); } 

}

class Banana extends Fruit { 
public Banana(Color color, boolean seasonal) { super(color, seasonal);  } 

@Override 
public void prepare() { System.out.println("Peal the Banana"); } 
}

class Strawberry extends Fruit { 
public Strawberry(Color color, boolean seasonal) { super(color, seasonal);  } 

@Override 
public void prepare() { System.out.println("Wash the Strawberry"); } 
}