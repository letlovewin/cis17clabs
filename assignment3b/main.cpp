#include <bits/stdc++.h>
using namespace std;
// Node structure for the doubly linked list
struct Node
{
    int data;
    Node *prev;
    Node *next;

    // Constructor
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

// Doubly linked list class
class DoublyLinkedList
{
private:
    // Head and tail dummy nodes
    Node headDummy;
    Node tailDummy;

    // Private member function to delete a node traversing from the front of the list
    bool deleteFromFront(int value)
    {
        Node *current = headDummy.next;
        while (current != &tailDummy)
        {
            if (current->data == value)
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                current->prev = nullptr;
                current->next = nullptr;
                delete current;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Private member function to delete a node from the end of the list
    bool deleteFromEnd(int value)
    {
        Node *current = tailDummy.prev;
        while(current != &headDummy) {
            if(current->data == value) {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                current->prev = nullptr;
                current->next = nullptr;
                delete current;
                return true;
            }
            current = current->prev;
        }
        return false;
    }

    // Private member function to add a node traversing from the front of the list
    void addFromFront(int value)
    {
        //-inf inf
        //-inf 3 inf
        //-inf 1 3 inf
        Node *newNode = new Node(value);
        Node *current = &headDummy;
        while(value > current->data)
            current = current->next;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
        newNode->next = current;
    }

    // Private member function to add a node traversing from the end of the list
    void addFromEnd(int value)
    {
        Node *newNode = new Node(value);
        Node *current = tailDummy.prev;
        while(value < current->data)
            current = current->prev;
        newNode->next = current->next;
        current->next->prev = newNode;
        newNode->prev = current;
        current->next = newNode;
    }

public:
    // Constructor
    DoublyLinkedList() : headDummy(0), tailDummy(0)
    {
        // Connect head and tail dummy nodes
        headDummy.next = &tailDummy;
        tailDummy.prev = &headDummy;
        headDummy.data = INT_MIN;
        tailDummy.data = INT_MAX;
    }

    // Destructor to free memory
    ~DoublyLinkedList()
    {
        while (headDummy.next != &tailDummy)
        {
            Node *iterator = &headDummy;
            while (iterator->next->next != &tailDummy)
                iterator = iterator->next;
            iterator->next->next->prev = iterator;
            iterator->next = iterator->next->next;
            Node *temp = iterator->next;
            temp = nullptr;
            delete temp;
            
        }
    }

    // Function to print the elements of the list
    void printList()
    {
        Node *current = &headDummy;
        while (current->next != &tailDummy)
        {
            current = current->next;
            cout << current->data << ' ';
        }
        cout << endl;
    }

    //***DO NOT TOUCH ANYTHING BELOW THIS LINE...NOTHING...NOT A SINGLE THING...I MEAN IT!!!***//

    // Public function to delete a node based on value
    bool deleteFromList(int value)
    {
        // Determine if the value is closer to the head or tail
        int distanceFromHead = value - headDummy.next->data;
        int distanceFromTail = tailDummy.prev->data - value;

        if (distanceFromHead <= distanceFromTail)
            return deleteFromFront(value);
        else
            return deleteFromEnd(value);
    }

    // Public function to add a node to the ordered list
    void addToOrderedList(int value)
    {
        // Determine if the value is closer to the head or tail
        int distanceFromHead = value - headDummy.next->data;
        int distanceFromTail = tailDummy.prev->data - value;

        if (distanceFromHead <= distanceFromTail)
            addFromFront(value);
        else
            addFromEnd(value);
    }
};

int main()
{
    // Create a doubly linked list
    DoublyLinkedList myList;
    // Add elements to the ordered list
    myList.addToOrderedList(3);
    myList.addToOrderedList(1);
    myList.addToOrderedList(2);
    myList.addToOrderedList(5);
    myList.addToOrderedList(4);

    // Print the elements of the list
    std::cout << "Here is the current list:" << std::endl;
    myList.printList();
    std::cout << std::endl;

    // Delete a node from the list and print the updated list
    std::cout << "Trying to delete 2 from the list." << std::endl;
    bool deleted = myList.deleteFromList(2);
    if (deleted)
        std::cout << "Successfully deleted value from the list." << std::endl;
    else
        std::cout << "Value not found in the list." << std::endl;
    std::cout << std::endl;

    // Delete a node from the list and print the updated list
    std::cout << "Trying to delete 4 from the list." << std::endl;
    deleted = myList.deleteFromList(4);
    if (deleted)
        std::cout << "Successfully deleted value from the list." << std::endl;
    else
        std::cout << "Value not found in the list." << std::endl;
    std::cout << std::endl;

    // Delete a node from the list and print the updated list
    std::cout << "Trying to delete 4 from the list again.  This should be unsuccessful." << std::endl;
    deleted = myList.deleteFromList(4);
    if (deleted)
        std::cout << "Successfully deleted value from the list." << std::endl;
    else
        std::cout << "Value not found in the list." << std::endl;
    std::cout << std::endl;

    // Print the updated list
    myList.printList();
    std::cout << std::endl;

    // Delete a node from the list and print the updated list
    std::cout << "Trying to delete 5 from the list" << std::endl;
    deleted = myList.deleteFromList(5);
    if (deleted)
        std::cout << "Successfully deleted value from the list." << std::endl;
    else
        std::cout << "Value not found in the list." << std::endl;
    std::cout << std::endl;

    // Print the updated list
    myList.printList();
    std::cout << std::endl;

    // Delete a node from the list and print the updated list
    std::cout << "Trying to delete 1 from the list" << std::endl;
    deleted = myList.deleteFromList(1);
    if (deleted)
        std::cout << "Successfully deleted value from the list." << std::endl;
    else
        std::cout << "Value not found in the list." << std::endl;
    std::cout << std::endl;

    // Print the updated list
    myList.printList();
    std::cout << std::endl;

    return 0;
}