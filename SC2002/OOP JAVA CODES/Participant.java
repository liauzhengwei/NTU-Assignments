import java.util.ArrayList;

public class Participant {
	private ArrayList<Game> glist = new ArrayList<Game>();
	private String name ;
	public Participant(String name) {
		this.name = name;
	}
	public void join(Game g) {
		glist.add(g);  // partcipant note game's ref
	}
	public void printGames() {
		System.out.println(name + " joins :");
		for (Game g : glist)
			System.out.println("*****"+ g.getName());
	}
	public String getName() { return name; }
}