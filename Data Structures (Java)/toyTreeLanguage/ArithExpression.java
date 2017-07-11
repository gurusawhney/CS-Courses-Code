package toyTreeLanguage;

public class ArithExpression extends ExpressionTree {
	
	public ArithExpression(Operator oper, ExpressionTree leftarg, ExpressionTree rightarg) { //constructor
		label = oper;
		left = leftarg;
		right = rightarg;
	}
	
	public String toString() { //empty toString just in case its accidentally called
		return "";
	}
			
	int evaluate() {
		if (label == Operator.minus) { return (left.evaluate()-right.evaluate());} //evaluation of -
		else if (label == Operator.plus) {return (left.evaluate()+right.evaluate());} //evaluation of +
		else if (label == Operator.divide) {return (left.evaluate()/right.evaluate());} //evaluation of /
		else if (label == Operator.times) {return (left.evaluate()*right.evaluate());} //evaluation of *
		else return 0; //returns a value for all conditions
	}
	
}

