package toyCalendar;
import java.sql.Date;

public class Event implements Comparable<Event> {
	String name;
	Date date;
	GOrderedList<Category> categories = new GOrderedList<Category>();
	
	public int compareTo(Event e) //Compares the date of the events to order
	{
		return date.compareTo(e.date);
	}
	
	public Event(String newname, Date newdate){ //constructor
		name = newname;
		date = newdate; //Note: GOrderedList not included because they are edited through class functions
	}
	
	public String getName() {return name;} //getter
	public Date getDate() {return date;} //getter
	public GOrderedList<Category> getCategories() {return categories;} //getter
	
	public String toString() { //what is printed out
		return name+" "+date.toString()+" "+categories.toString();
	}
}