package toyTreeLanguage;

public class Loop extends ExpressionTree {
	
	public Loop(ExpressionTree leftarg, ExpressionTree rightarg) { //constructor
		label = Operator.loop;
		left = leftarg;
		right = rightarg;
	}
	
	public String toString() {  //empty toString just in case its accidentally called
		return "";
	}

	int evaluate() {
		for(int i=0;i<left.evaluate();i++) { //looping through given number
			right.evaluate(); //evaluates the right side
		}
		return 0; //returns a value since necessary
	}
}

