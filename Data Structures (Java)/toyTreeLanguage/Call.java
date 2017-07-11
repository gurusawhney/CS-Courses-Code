package toyTreeLanguage;

public class Call extends ExpressionTree {
	private Function myFunction; //extra data field function
	
	public Call(Function func) { //constructor with function
		label = Operator.call;
		myFunction = func;
	}
	
	public String toString() { //empty toString just in case its accidentally called
		return "";
	}
	
	int evaluate() {
		System.out.println("Calling "+ myFunction.getName()); //returns output statement in constructor since its used simultaneously 
		for(int num=0; num<myFunction.getStatements().size(); num++){ //goes through the linked list of ExpressionTree's
	    	  myFunction.getStatements().get(num).evaluate(); //evaluates each tree
	    }
		return 0; //returns a value since necessary
	}
	
}

