package microFacebook;

public class Person {
	static int maxFriends = 10;
	private String name;
	private int numFriends = 0;
	private Person[] friends = new Person[maxFriends];
	
	public Person(String n) {
        name = n;
	}
	
	public String getName(){return name;}
	public int getNumFriends(){return numFriends;}
	public Person[] getfriends() {return friends;}
	
	public void setname(String newname) { name =  newname; }
	public void setNumFriends(int num) { numFriends = num; }
	
	public void addFriend(Person q) {
		if (q == null) {
			System.out.println("Error:Person can't be found.");
    		return;
    	}
		else if(this == q) {
    		System.out.println("Error:They are the same person.");
    		return;
    	}
		else if(numFriends == maxFriends || q.getNumFriends() == maxFriends) {
			System.out.println("Error:Not enough room to friend");
		}
		else {
			for (int i = 0; i < friends.length; i++) {
	    		if (friends[i] == q) {
	    			System.out.println("Error:They are already friends");
	    			return;
	    		}
	    	}
		}
		friends[numFriends] = q;
		numFriends += 1;
		q.getfriends()[q.getNumFriends()] = this;
		q.setNumFriends(q.getNumFriends()+1);
	}
}
