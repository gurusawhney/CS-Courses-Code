package toyTreeLanguage;

public class NumberLeaf extends ExpressionTree {
	private int value; //extra data field int
	
	public NumberLeaf(int val) { //constructor with int data field
		label = Operator.number;
		value = val;
	}
	
	public String toString() { //returns value for output statements
		return Integer.toString(value);
	}
	
	int evaluate() { //evaluation
		return value;
	}
}

