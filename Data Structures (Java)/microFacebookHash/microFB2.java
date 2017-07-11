package microFacebookHash;
import java.util.Hashtable;
import java.util.Scanner;

public class microFB2 { //main
	
	static Hashtable<String,PersonHash> allPeople = new Hashtable<String,PersonHash>(); //hashtable for all people
	static Hashtable<String,Boolean> allFriends = new Hashtable<String,Boolean>(); //hashtable for all friends
	
	public static void main(String[] args) {
		System.out.println("User Input:"); 
		while(true) {
			Scanner input = new Scanner(System.in);
			String command = input.nextLine(); //takes the input
			String[] tokens = command.split(" "); //divides the words into an array
			if(tokens[0].equals("X")) { //exits the facebook program
				break;
			}
			if(tokens[0].equals("P")) {
				if(allPeople.containsKey(tokens[1]) == false) { //making sure the name doesn't exist
					PersonHash p = new PersonHash(tokens[1]); //created new person
					allPeople.put(tokens[1], p); //put it in hashtable
				}
				else {System.out.println("Person can't be created");}
			}
			if(tokens[0].equals("F")) {
				if(allPeople.containsKey(tokens[1]) == true && allPeople.containsKey(tokens[2]) == true){ //making sure the people exist
					String tempkey1 = tokens[1] + "*" + tokens[2]; //token for allFriends
					String tempkey2 = tokens[2] + "*" + tokens[1]; //token for allFriends with names switched
					if(allFriends.containsKey(tempkey1) == true || allFriends.containsKey(tempkey2) == true) { //making sure they aren't friends
						System.out.println("Error: Already friends");
					}
					else {
						allPeople.get(tokens[1]).addFriend(allPeople.get(tokens[2])); //makes them friends
						allFriends.put(tempkey1, true); //adds key to allFriends
						allFriends.put(tempkey2, true); //adds the other one
					}
				}
				else {System.out.println("Person(s) can't be found");}
			}
			if(tokens[0].equals("U")) {
				if(allPeople.containsKey(tokens[1]) == true && allPeople.containsKey(tokens[2]) == true){ //making sure people exist
					String tempkey1 = tokens[1] + "*" + tokens[2]; //token for allFriends
					String tempkey2 = tokens[2] + "*" + tokens[1]; //token for allFriends with names switched
					if(allFriends.containsKey(tempkey1) == false || allFriends.containsKey(tempkey2) == false) { //checking if they are friends
						System.out.println("Error: Not already friends");
					}
					else {
						allPeople.get(tokens[1]).removeFriend(allPeople.get(tokens[2])); //remove the friends
						allFriends.remove(tempkey1); //remove the object from allFriends
						allFriends.remove(tempkey2); //and the key with the names switched
					}
				}
				else {System.out.println("Person(s) can't be found");}
			}
			
			if(tokens[0].equals("L")) {
				if(allPeople.containsKey(tokens[1]) == true) { //checking if person exists
					PersonHash p1 = allPeople.get(tokens[1]);
					System.out.println(p1.getfriend().toString()); //iterates through linked list and prints out friends' names
				}
			}
			if(tokens[0].equals("Q")) {
				String tempkey1 = tokens[1] + "*" + tokens[2]; //token for allFriends
				String tempkey2 = tokens[2] + "*" + tokens[1]; //token for allFriends with names switched
				if(allFriends.containsKey(tempkey1) == true || allFriends.containsKey(tempkey2) == true) { //checks if they are friends
					System.out.println("Yes");
				}
				else {System.out.println("No");}
			}
		}
	}
	
}
