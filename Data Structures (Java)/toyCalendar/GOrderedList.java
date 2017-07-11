package toyCalendar;

class GOrderedList<T extends Comparable<? super T>>  {
	private T value;
	private GOrderedList<T> next;
	
	// Note: No setValue() method or setNext() methods are provided, 
	// since those could require reordering the list.
	  
	public T getValue() {return value; }
	public GOrderedList<T> getNext() {return next; }

	// If X is in the list, returns the previous node.
	// If X is not in the list, returns the node for the greatest element less 
	// than  X.

	public GOrderedList<T> searchBefore(T x) { // Locate node containing x
		GOrderedList<T> n = this;
	    while (true) {
	       if (n.next==null) return n;
	       if (n.next.value.compareTo(x) >= 0) return n;
	       n = n.next;
	    } 
	}

	// Is element x in the list. Note the use of the left to right evaluation of 
	// && (if the condition n.net != null is false, then the conjunction returns
	// false without evaluating n.next.value.equals(x).

	public boolean inList(T x) {
		GOrderedList<T> n = searchBefore(x);
	    return n.next != null && n.next.value.equals(x); 
	}

	// Adds x to the ordered list, if it is not already there.
	
	public void add(T x) {
		GOrderedList<T> n = searchBefore(x);
	    if (n.next == null || !(n.next.value.equals(x))) {
	    	GOrderedList<T> newNode = new GOrderedList<T>();
	        newNode.value = x;
	        newNode.next = n.next;
	        n.next = newNode;
	    }
	}
	       
	// Deletes x from the ordered list, if it is there.

	public void delete(T x) {
	    GOrderedList<T> n = searchBefore(x);
	    if (n.next != null && n.next.value.equals(x)) {
	    	n.next = n.next.next;
		}
	}
	
	public int numBetween(T Lower, T Upper) {
		int counter = 0;
		GOrderedList<T> a = next;
	    while (a != null) {
	    	if(a.value.compareTo(Lower) > 0 && a.value.compareTo(Upper) < 0) {
	    		counter += 1;
	    	}
	        a = a.next;
	    }
		return counter;
	}

	public String toString() {
		GOrderedList<T> a = next;
	    String s = "";
	    while (a != null) {
	    	s = s + a.value.toString() + " ";
	        a = a.next;
	    }
	    return s;
	}
}
