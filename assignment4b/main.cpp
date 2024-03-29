#include <iostream>
#include "MyQueue.h"

using namespace std;

int main() {

  //Test the MyQueue() constructor and the printQueue() & push(int) member functions
  cout << "I am testing MyQueue(), printQueue(), and push(int)" << endl;
  MyQueue A;
  cout << "I am printing out the empty MyQueue object A" << endl;
  A.printQueue();
  cout << endl;
  A.push(1);
  A.push(2);
  A.push(3);
  A.push(4);
  A.push(5);
  A.push(6);
  cout << "I am printing out MyQueue object A containing 1 2 3 4 5 6" << endl;
  A.printQueue();
  cout << endl;
  cout << endl;

  //Test the copy constructor
  cout << "I am testing the MyQueue copy constructor" << endl;
  MyQueue B = A;
  cout << "I am printing out MyQueue Object B containing 1 2 3 4 5 6" << endl;
  B.printQueue();
  cout << endl;
  cout << endl;

  //Test the int peek() the int pop() and the int size() member functions
  cout << "I am testing peek: the top of the queue is " << A.peek() << endl;
  cout << "I didn't remove anything from the queue though...see" << endl;
  A.printQueue();
  cout << endl;
  cout << "And the size of A is: " << A.size() << endl;
  cout << endl;
  cout << "Now I am testing pop: the item that I am removing is " << A.pop() << endl;
  cout << "So now 1 should be removed from the top of the queue..." << endl;
  A.printQueue();
  cout << "And the size of A is: " << A.size() << endl;
  cout << endl;
  cout << endl;

  //Test the overloaded assignment operator
  cout << "Time to test the assignment (=) operator." << endl;
  A.pop();
  B = A;
  cout << "MyQueue object B should now hold 3 4 5 6" << endl;
  B.printQueue();
  cout << endl;
  cout << endl;

  //What happens when I try to peek into an empty queue?
  cout << "Let's Find out what happens when I peek or pop an empty MyQueue" << endl;
  MyQueue C;
  cout << "Here I try to peek into an empty queue " << C.peek() << endl;
  cout << "Here I try to pop from an empty queue " << C.pop() << endl;
  cout << endl;
  cout << endl;

  //Let's check the cascading effect of the overloaded assignment operator
  A.pop();
  A.pop();
  C = B = A;
  cout << "The contents of MyQueue object A are:" << endl;
  A.printQueue();
  cout << endl;
  cout << "The contents of MyQueue object B are:" << endl;
  B.printQueue();
  cout << endl;
  cout << "The contents of MyQueue object C are:" << endl;
  C.printQueue();
  cout << endl;
  cout << endl;

  //Let's Destroy a MyQueue object a
  cout << "Testing the destructor" << endl;
  cout << "Destructor called" << endl;
  A.~MyQueue();
  cout << "This program still runs" << endl;
}
