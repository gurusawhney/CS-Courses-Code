package toyTreeLanguage;

public class Assignment extends ExpressionTree {
	
	public Assignment(VariableLeaf varleaf, ExpressionTree rightarg) { //constructor
		label = Operator.assign;
		left = varleaf;
		right = rightarg; 
	}
	
	public String toString() { //empty toString just in case its accidentally called
		return "";
	}

	int evaluate() { //returns the value assigned
		System.out.println("Assigning "+ right.evaluate() +" to "+ left.toString()); //returns output statement in constructor since its used simultaneously
		Variable tempvar = new Variable(left.toString(),right.evaluate()); //stores value for variable
		if (treeLanguageMain.SymbolTable.containsKey(left.toString())) { //tests to see if it already exists
			treeLanguageMain.SymbolTable.replace(left.toString(),tempvar); //replaces the variable with the new value
		}
		else {
			treeLanguageMain.SymbolTable.put(left.toString(),tempvar); //stores it into the hash table
		}
		return right.evaluate(); 
	}	
}