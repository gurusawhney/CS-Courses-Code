package toyCalendar;

public class Category implements Comparable<Category> {
	String name;
	GOrderedList<Event> events = new GOrderedList<Event>();
	
	public String getName() {return name;} //getter
	public GOrderedList<Event> getEvents() {return events;} //getter
	
	public Category(String newname) { //constructor
		name = newname;
	}
	
	public String toString() { //what is printed out 
		return name;
	}
	
	public int compareTo(Category c) //You are comparing the names of the categories to order
	{
		return name.compareTo(c.name);
	}
}