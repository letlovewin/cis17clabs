//
//  MyQueue.h
//
//  This contains all of the header files for the MyQueue class.

#ifndef MyQueue_h
#define MyQueue_h

#include "Node.h"

using namespace std;

class MyQueue{
  private:
    Node dummy;
  public:
    MyQueue();
    MyQueue(MyQueue& rhs);
    MyQueue &operator=(MyQueue& rhs);
    void push(int v);
    int pop();
    int peek();
    int size();
    void printQueue();
    ~MyQueue();
};
#endif /* MyQueue_h */