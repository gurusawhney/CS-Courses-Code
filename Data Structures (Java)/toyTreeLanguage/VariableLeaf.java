package toyTreeLanguage;

public class VariableLeaf extends ExpressionTree {
	private Variable myVariable; //extra data field variable
	
	public VariableLeaf(Variable var) { //constructor with variable
		label = Operator.variable;
		myVariable = var;
	}
	public String getName() {return myVariable.getName();} //returns name
	public Variable getVariable() {return myVariable;} //returns variable
	
	public String toString() { //returns name for output statement
		return myVariable.getName();
	}
	
	int evaluate() { //evaluation returns value of variable
		return treeLanguageMain.SymbolTable.get(myVariable.getName()).getValue();
	}
}

