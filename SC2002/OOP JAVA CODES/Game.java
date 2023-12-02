import java.util.ArrayList;

public class Game {
	private ArrayList<Participant> plist = new ArrayList<Participant>();
	private String name ;
	public Game(String name) {
		this.name = name;
	}
	public void register(Participant p) {
		plist.add(p);  // game has participant's ref
		p.join(this);  // game gives its ref
	}
	public void printParticipants() {
			System.out.println("Participants for " + name);
			for (Participant p : plist)
				System.out.println( "----" + p.getName());
	}
	public String getName() { return name; }

	public static void main(String[] args) {
		Participant p1 = new Participant("Alice");
		Participant p2 = new Participant("Bob");
		Participant p3 = new Participant("Cindy");
		Participant p4 = new Participant("Danny");
		Participant p5 = new Participant("Ethan");

		Game g1 = new Game("Soccer");
		Game g2 = new Game("Volley Ball");
		Game g3 = new Game("Basketball");

		g1.register(p1);
		g1.register(p2);
		g2.register(p1);
		g2.register(p3);
		g2.register(p5);
		g3.register(p1);
		g3.register(p2);
		g3.register(p3);
		g3.register(p4);
		g3.register(p5);

		g1.printParticipants() ;
		g2.printParticipants() ;
		g3.printParticipants() ;

		p1.printGames();
		p2.printGames();
		p3.printGames();
		p4.printGames();
		p5.printGames();
	}
}