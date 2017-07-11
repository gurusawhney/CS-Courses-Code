package toyTreeLanguage;

abstract class ExpressionTree {
	protected Operator label;
	protected ExpressionTree left;
	protected ExpressionTree right;
	
	abstract int evaluate();	
}


	
	
	
	
	
