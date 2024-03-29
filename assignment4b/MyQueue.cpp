#include "MyQueue.h"
#include <bits/stdc++.h>
using namespace std;

MyQueue::MyQueue()
{
    dummy.value = INT_MIN;
    dummy.next = nullptr;
}
MyQueue::MyQueue(MyQueue &rhs)
{
    dummy.value = INT_MIN; // basically empty queue and just clone while we iterate
    dummy.next = nullptr;
    if (rhs.dummy.next != nullptr) 
    {
        Node *iterator = rhs.dummy.next;
        Node *dummy_ptr = &dummy;
        while (iterator != nullptr)
        {
            Node *new_node = new Node;
            new_node->value = iterator->value;
            new_node->next = nullptr;
            dummy_ptr->next = new_node;

            // jump to the next node after the new node has been linked
            dummy_ptr = dummy_ptr->next;
            iterator = iterator->next;
        }
    }
}
MyQueue &MyQueue::operator=(MyQueue &rhs)
{
    if (rhs.dummy.next != nullptr)
    {
        while (dummy.next != nullptr) //delete everything pre-emptively
        {
            Node *iterator = &dummy;
            while (iterator->next->next != nullptr)
                iterator = iterator->next;
            delete iterator->next;
            iterator->next = nullptr;
        }
        Node *iterator = rhs.dummy.next;
        Node *dummy_ptr = &dummy;
        while (iterator != nullptr)
        {
            Node *new_node = new Node;
            new_node->value = iterator->value;
            new_node->next = nullptr;
            dummy_ptr->next = new_node;

            // jump to the next node after the new node has been linked
            dummy_ptr = dummy_ptr->next;
            iterator = iterator->next;
        }
    }
    return *this;
}
void MyQueue::push(int v)
{
    Node *new_node = new Node;
    new_node->value = v;
    if (dummy.next != nullptr)
        new_node->next = dummy.next;
    dummy.next = new_node;
}
int MyQueue::pop()
{
    if(dummy.next==nullptr) //stop segmentation fault
        return INT_MIN;
    Node *iterator = &dummy;
    while (iterator->next->next != nullptr)
        iterator = iterator->next;
    int result = iterator->next->value;
    delete iterator->next;
    iterator->next = nullptr;
    return result;
}
int MyQueue::peek()
{
    if(dummy.next==nullptr) //stop segmentation fault
        return INT_MIN;
    Node *iterator = &dummy;
    while (iterator->next->next != nullptr)
        iterator = iterator->next;
    int result = iterator->next->value;
    return result;
}
int MyQueue::size()
{
    Node *iterator = &dummy;
    int quant = 0;
    while (iterator->next != nullptr)
    {
        quant++;
        iterator = iterator->next;
    }
    return quant;
}
void MyQueue::printQueue()
{
    if (dummy.next == nullptr)
    {
        cout << "Empty queue" << endl;
        return;
    }
    Node *iterator = &dummy;
    vector<int> result;
    while (iterator->next != nullptr)
    {
        iterator = iterator->next;
        result.push_back(iterator->value);
    }
    for(int i = result.size()-1; i > -1; i--)
        cout << result[i] << ' ';
    cout << endl;
}
MyQueue::~MyQueue()
{
    while (dummy.next != nullptr)
    {
        Node *iterator = &dummy;
        while (iterator->next->next != nullptr)
            iterator = iterator->next;
        delete iterator->next;
        iterator->next = nullptr;
    }
    // dummy should be deleted anyway since the class is destructed
}