package toyTreeLanguage;

public class Variable {
	private String name;	
	private int value;
	
	public Variable(String n) {name = n;}	//constructor with just name	
	public Variable(String n, int v) {		//constructor with name and value
		name = n;
		value = v;
	}
	
	public String toString() {	//method for output statement
		return Integer.toString(value);
	}
	public String getName() {return name;} //returns the name
	public int getValue(){return value;} //returns the value
	public void setValue(int newval) {value = newval;} //assigns the value
}
