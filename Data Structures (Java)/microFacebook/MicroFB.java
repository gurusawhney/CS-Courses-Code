package microFacebook;
import java.util.*;

public class MicroFB {
	static int maxPeople=100;
	static Person[] allPeople = new Person[maxPeople];
	static int peopleCount;
	
	static Person findPerson(String name) {
		for(Person p: allPeople) {
			if (p != null){
				if((p.getName()).equals(name)) { 
					return p;
				}
			}
		}
		return null;
	}
	
	public static void main(String[] args) {
		System.out.println("User Input:");
		while(true) {
			Scanner input = new Scanner(System.in);
			String command = input.nextLine();
			String[] tokens = command.split(" ");
			if(tokens[0].equals("X")) {
				break;
			}
			if(tokens[0].equals("P")) {
				if(findPerson(tokens[1]) == null && peopleCount < maxPeople) {
					Person p = new Person(tokens[1]);
					allPeople[peopleCount] = p;
					peopleCount += 1;
				}
				else {System.out.println("Person can't be created");}
			}
			if(tokens[0].equals("F")) {
				if(findPerson(tokens[1]) != null && findPerson(tokens[2]) != null){
					Person p1 = findPerson(tokens[1]);
					Person p2 = findPerson(tokens[2]);
					p1.addFriend(p2);
				}
				else {System.out.println("Person can't be found");}
			}
			if(tokens[0].equals("L")) {
				Person p1 = findPerson(tokens[1]);
				boolean found = false;
				for(Person p:p1.getfriends()) {
					if (p != null){
						found = true;
						System.out.print(p.getName()+" ");
					}
				}
				if (found==false) {System.out.println("No Friends");}
			}
			if(tokens[0].equals("Q")) {
				Person p1 = findPerson(tokens[1]);
				Person p2 = findPerson(tokens[2]);
				boolean found = false;
				for(Person p: p1.getfriends()) {
					if(p.getName().equals(p2.getName())) {
						System.out.println("Yes");
						found = true;
						break;
					}
				}
				if (found==false) {System.out.println("No");}				
			}
		}
	}
}
