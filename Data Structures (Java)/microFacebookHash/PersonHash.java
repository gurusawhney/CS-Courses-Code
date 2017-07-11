package microFacebookHash;

public class PersonHash {

	private String name; //name
	private int numFriends = 0; //number of friend and useful iterator for linked list
	private MyList1<PersonHash> friend; //linked list of friends
	
	public PersonHash(String n) { //constructor
        name = n;
        numFriends = 0;
        friend = new MyList1<PersonHash>();
	}
	
	public String getName(){return name;} //gets name
	public int getNumFriends(){return numFriends;} //gets number of friends
	public MyList1<PersonHash> getfriend() {return friend;} //gets the friends
	
	public void setname(String newname) { name =  newname; } //sets the names
	public void setNumFriends(int num) { numFriends = num; } //sets the number of friends

	public String toString() { //returns name of Person for toString method
		String s = name;
		return s;
	}
	
	public void addFriend(PersonHash p) { //adds a friend into the linked list of the person
		if (p == null) { //person doesn't exist
			System.out.println("Error:Person can't be found.");
    		return;
    	}
		else if(this == p) { //person is the same
    		System.out.println("Error:They are the same person.");
    		return;
    	}
		else {
			for (int i = 0; i < numFriends; i++) { //iterates through linked list
	    		if (friend.getValue() == p) { //if the person meant to be added is found
	    			System.out.println("Error:They are already friends");
	    			return;
	    		}
	    		friend.getNext(); //the iterator
	    	}
			friend.addFirst(p); //adds the friend to the beginning of the list
    		numFriends += 1; //increases the number of friends
    		p.getfriend().addFirst(this); //adds this object to the person's linked list
    		p.setNumFriends(p.getNumFriends()+1); //increases the persons number of friends
		}

	}
	
	public void removeFriend(PersonHash p) {
		if (p == null) { //person doesn't exist
			System.out.println("Error:Person can't be found.");
    		return;
    	}
		else if(this == p) { //person is the same
    		System.out.println("Error:They are the same person.");
    		return;
    	}
		else {
			boolean found = false;
			for (int i = 0; i < numFriends; i++) { //iterates through linked list
	    		if (friend.getValue() == p) { //if the person meant to be added is found
	    			found = true;
	    		}
	    		else {friend.getNext();} //the iterator
	    	}
			if (found = false) {
				System.out.println("Error:Person can't be found.");
				return;
			}
			friend.deleteAfter(friend.locateBefore(p)); //adds the friend to the end of the list
    		numFriends -= 1; //increases the number of friends
    		p.getfriend().deleteAfter(p.getfriend().locateBefore(this)); //adds this object to the person's linked list
    		p.setNumFriends(p.getNumFriends()-1); //increases the persons number of friends
		}
	}
}
