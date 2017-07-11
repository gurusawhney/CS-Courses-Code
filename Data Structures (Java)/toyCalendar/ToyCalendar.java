package toyCalendar;
import java.sql.Date;
import java.util.*;

class ToyCalendar { 
	public static GOrderedList <Event> allEvents; //list that contains all events
	public static GOrderedList <Category> allCategories; //list that contains all categories
	
	public static void main(String[] args) {
		System.out.println("User Input:");
		GOrderedList<Category> Cheader = new GOrderedList<Category>(); //header for allCategories
		allCategories = Cheader;
		GOrderedList<Event> Eheader = new GOrderedList<Event>(); //header for allEvents
		allEvents = Eheader;
		while(true) {
			Scanner input = new Scanner(System.in); //taking in user input
			String command = input.nextLine(); 
			String[] tokens = command.split(" "); //breaking down every command
			if(tokens[0].equals("X")) { //ends program
				break;
			}
			if(tokens[0].equals("A")) { //adds event to the calendar
				Event newevent = new Event(tokens[1],Date.valueOf(tokens[2])); //makes a new event
				allEvents.add(newevent); //adds it to allEvents
				if(tokens.length>3) { //checking for categories that should be added to object
					for(int i = 3; i<tokens.length; i++) {
						Category newcategory = new Category(tokens[i]); //creates a new category
						if(allCategories.searchBefore(newcategory).getNext() != null && allCategories.searchBefore(newcategory).getNext().getValue().compareTo(newcategory) == 0) { //checking if a category already exists in allCategories
							newevent.getCategories().add(allCategories.searchBefore(newcategory).getNext().getValue()); //adds the existing category from allCategories to the Event's categories linked list
							allCategories.searchBefore(newcategory).getNext().getValue().getEvents().add(newevent); //adds the event to the Category's event linked list
						}
						else {
							allCategories.add(newcategory); //if it doesn't exist, the category gets added to the new category
							newcategory.getEvents().add(newevent); //event is added to Category's event linked list
							newevent.getCategories().add(newcategory); //category is added to Event's categorie linked list
						}
					}
				}
			}
			if(tokens[0].equals("AC")) { //edits event and adds category for it
				Category newcategory = new Category(tokens[2]); //constructs new category
				GOrderedList<Event> temp = Eheader; //iterating through the nodes in allEvents to find the event that is going to get edited
			    while (temp.getNext() != null) {
			    	if (temp.getNext().getValue().getName().compareTo(tokens[1]) == 0){ //when found. The following code mimics what was done in command "A"
			    		if(allCategories.searchBefore(newcategory).getNext() != null && allCategories.searchBefore(newcategory).getNext().getValue().compareTo(newcategory) == 0) {
			    			allCategories.searchBefore(newcategory).getNext().getValue().getEvents().add(temp.getNext().getValue());
			    			temp.getNext().getValue().getCategories().add(allCategories.searchBefore(newcategory).getNext().getValue());
			    		}
			    		else {
			    			allCategories.add(newcategory); 
			    			newcategory.getEvents().add(temp.getValue());
			    		    temp.getNext().getValue().getCategories().add(newcategory);
			    		}
			    	}
			    	temp = temp.getNext(); //iterator
			    }
			}
			if(tokens[0].equals("C")) { //lists out all categories
				GOrderedList<Category> temp = Cheader; //iterating through the nodes in allCategories
				while(temp.getNext() != null) {
					if(temp.getNext().getValue() != null) {
						System.out.println(temp.getNext().getValue().toString());//prints out the name of the Categories using toString()
					}
					temp = temp.getNext();
				}				
			}
			if(tokens[0].equals("E")) { //lists all events with same name
				GOrderedList<Event> temp = Eheader; //iterating through the nodes in allEvents
			    while (temp.getNext() != null) {
			    	if (temp.getNext().getValue().getName().compareTo(tokens[1]) == 0) { //checking that the name is equal to the user's input 
			    		System.out.println(temp.getNext().getValue().toString()); //prints out the Event information using toString()
			    	}
			    	temp = temp.getNext();
			    }
			}
			if(tokens[0].equals("L")) { //Lists all events made
				GOrderedList<Event> temp = Eheader; //iterating through nodes in allEvents
				while(temp.getNext() != null) {
					if(temp.getNext().getValue() != null) {
						System.out.println(temp.getNext().getValue().toString()); //prints out each Event information using toString()
					}
					temp = temp.getNext();
				}				
			}
			else if(tokens[0].equals("LD")) { //searches events with same name
				Date date = Date.valueOf(tokens[1]); //constructs a new date object
				GOrderedList<Event> temp = Eheader; //iterating through nodes in allEvents
			    while (temp.getNext() != null) {
			    	if (temp.getNext().getValue().getDate().compareTo(date) == 0) { //checking if date of event is equal to user's input
			    		System.out.println(temp.getNext().getValue().toString()); //prints out te event information using toString()
			    	}
			    	temp = temp.getNext();
			    }
			}
			else if(tokens[0].equals("LC")) { //searches events with the same category
				GOrderedList<Category> temp = Cheader; //iterating through nodes in allCategories
				while (temp.getNext() != null) {
					if (temp.getNext().getValue().getName().compareTo(tokens[1]) == 0) { //checking if name of category is equal to user's input
						System.out.println(temp.getNext().getValue().getEvents().toString()); //prints out the GOrderedlist events using toString()
				    }
					temp = temp.getNext();
				}	
			}
		}
	
	}
}

