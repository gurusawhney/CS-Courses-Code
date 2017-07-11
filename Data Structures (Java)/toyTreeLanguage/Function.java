package toyTreeLanguage;
import java.util.LinkedList;

public class Function {
	private String name;
	private LinkedList<ExpressionTree> statements = new LinkedList<ExpressionTree>();
	
	public Function(String newname, LinkedList<ExpressionTree> newstatements) { //constructor with name and linked list
		name = newname;
		statements = newstatements;
	}
	
	public String toString() {return name + "-linkedlist";} //returns name for output statements
	public String getName() {return name;} //returns name
	public LinkedList<ExpressionTree> getStatements() {return statements;} //returns the linked list of statements
}
