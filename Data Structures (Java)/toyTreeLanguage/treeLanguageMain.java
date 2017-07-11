package toyTreeLanguage;
import java.util.*;

public class treeLanguageMain {
	static Hashtable<String,Variable> SymbolTable = new Hashtable<String,Variable>(); //holds all the variables
	static Hashtable<String,Function> FunctionTable = new Hashtable<String,Function>(); //holds all the functions
	static Scanner input = new Scanner(System.in); //static scanner allows the read input whenever
	
	public static void readFunctionDef(String[] tokens) { //reads the definition of the function
		LinkedList<ExpressionTree> functionbody = new LinkedList<ExpressionTree>(); //builds the linked list of expression trees
		System.out.println("Defining " + tokens[1]); //output statement
		while(true) {
			String funccomand = input.nextLine(); 
			String[] functokens = funccomand.split(" ");
			if(functokens[0].equals("END")) {break;}
			else {
				ExpressionTree tree = constructExpTree(functokens); //builds the expression tree
				functionbody.addLast(tree); //adds it to the linked list
			}
		}
		Function func = new Function(tokens[1],functionbody); //builds the function
		FunctionTable.put(tokens[1], func); //adds the function to the hash table
	}
	private static ExpressionTree constructExpTree(String[] tokens) { //takes the input of the line
		for(int i = 0; i < tokens.length; i++) {
			if(tokens[i].equals("ASSIGN")) { //if the first word is ASSIGN
				Variable tempvar = new Variable(tokens[i+1]); //makes new variable
				if (SymbolTable.containsKey(tokens[i+1])) { //tests to see if it already exists
					Variable oldvar = SymbolTable.get(tokens[i+1]);
					tempvar = oldvar;
				}
				SymbolTable.put(tokens[i+1], tempvar); //puts the initialized variable into hash table for future use
				String[] remainingcommand = Arrays.copyOfRange(tokens,i+2,tokens.length); 
				ExpressionTree righttree = constructExpTree(remainingcommand); //builds expression tree of what the variable is being assigned to
				VariableLeaf tempvarleaf = new VariableLeaf(tempvar); //builds variable leaf to be used in the assignment node
				Assignment assign = new Assignment(tempvarleaf,righttree); //builds the assignment node to evaluate
				return assign;
			}
			else if(tokens[i].equals("*")) { //arithmetic operation
				String[] remainingcommand = Arrays.copyOfRange(tokens,i+1,tokens.length); //destructs the prefix notation
				String[] firsthalf = Arrays.copyOfRange(remainingcommand, 0, tokens.length/2);
				String[] secondhalf = Arrays.copyOfRange(remainingcommand, tokens.length/2, remainingcommand.length);
				ArithExpression arith = new ArithExpression(Operator.times,constructExpTree(firsthalf),constructExpTree(secondhalf)); //builds expression tree to evaluate
				return arith;
			}
			else if(tokens[i].equals("/")) { //arithmetic operation
				String[] remainingcommand = Arrays.copyOfRange(tokens,i+1,tokens.length); //destructs the prefix notation
				String[] firsthalf = Arrays.copyOfRange(remainingcommand, 0, tokens.length/2);
				String[] secondhalf = Arrays.copyOfRange(remainingcommand, tokens.length/2, remainingcommand.length);
				ArithExpression arith = new	ArithExpression(Operator.divide,constructExpTree(firsthalf),constructExpTree(secondhalf)); //builds expression tree to evaluate
				return arith;
			}
			else if(tokens[i].equals("+")) { //arithmetic operation
				String[] remainingcommand = Arrays.copyOfRange(tokens,i+1,tokens.length); //destructs the prefix notation
				String[] firsthalf = Arrays.copyOfRange(remainingcommand, 0, tokens.length/2);
				String[] secondhalf = Arrays.copyOfRange(remainingcommand, tokens.length/2, remainingcommand.length);
				ArithExpression arith = new	ArithExpression(Operator.plus,constructExpTree(firsthalf),constructExpTree(secondhalf)); //builds expression tree to evaluate
				return arith;
			}
			else if(tokens[i].equals("-")) { //arithmetic operation
				String[] remainingcommand = Arrays.copyOfRange(tokens,i+1,tokens.length); //destructs the prefix notation
				String[] firsthalf = Arrays.copyOfRange(remainingcommand, 0, tokens.length/2);
				String[] secondhalf = Arrays.copyOfRange(remainingcommand, tokens.length/2, remainingcommand.length);
				ArithExpression arith = new	ArithExpression(Operator.minus,constructExpTree(firsthalf),constructExpTree(secondhalf)); //builds expression tree to evaluate
				return arith;
			}
			else if(tokens[i].equals("FOR")) { //if first word is FOR
				int splitter = i+1;
				while(true) {
					if(tokens[splitter].equals("FOR") || tokens[splitter].equals("ASSIGN") || tokens[splitter].equals("CALL")) {
						break;
					}
					else splitter++;
				}
				String[] loopnumber = Arrays.copyOfRange(tokens,i+1,splitter); //splits for loop and the statement
				String[] remainingcommand = Arrays.copyOfRange(tokens,splitter,tokens.length);
				Loop loop = new Loop(constructExpTree(loopnumber),constructExpTree(remainingcommand)); //builds expression tree to evaluate
				return loop;
			}
			else if(tokens[i].equals("CALL")) {  //if first word is CALL
				Function tempfunc =	FunctionTable.get(tokens[i+1]); //finds the function from the hash table
				Call call = new Call(tempfunc); //builds expression tree to evaluate
				return call;
			}
			else if(isInteger(tokens[i]) == true) { //if there is a number in the output
				NumberLeaf numleaf = new NumberLeaf(Integer.parseInt(tokens[i])); //it builds a number leaf expression tree to evaluate
				return numleaf;
			}
			else if(SymbolTable.containsKey(tokens[i]) == true) { //if there is a variable in the output that exists
				VariableLeaf varleaf = new VariableLeaf(SymbolTable.get(tokens[i])); //it builds a variable leaf expression tree to evaluate
				return varleaf;
			}
			else { System.out.println("Cannot Understand Statement");} //error catching if input is not correctly formatted
		}
		return null;
	}
	public static boolean isInteger(String s) { //checks if the string is an integer
		try { 
	        Integer.parseInt(s); 
	    } catch(NumberFormatException e) { 
	        return false; 
	    } catch(NullPointerException e) {
	        return false;
	    }
	    return true;
	}
	public static void executeStatement(String[] tokens) { //builds and evaluates the expression tree based on what is read
		constructExpTree(tokens).evaluate();
	}
	public static void main(String[] args) { //main function
		System.out.println("User Input:"); 
		while(true) {
			String command = input.nextLine(); //takes the input
			String[] tokens = command.split(" "); //builds array for implementation
			if(tokens[0].equals("DEFINE")) { 
				readFunctionDef(tokens); //calls function to define the function
			}
			else executeStatement(tokens); //just builds and evaluates the expression tree
			System.out.println(SymbolTable.toString()); //displays all stored variables for running/debugging purposes for developers
			System.out.println(FunctionTable.toString()); //displays all stored functions for running/debugging purposes for developers
		}
	}
}
