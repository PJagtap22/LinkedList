#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev; //Add a prev pointer for doubly linked list

    Node(int val)
    { // constructor initiazes data and sets next to NULL
        data = val;
        next = NULL;
        prev = NULL; //Initialize prev pointer to NULL
    }
};

class List
{
private: // private head which is pointer to 1st node
    Node *head;

public:
    List()
    { // constructor initializes head to NULL
        head = NULL;
    }
    //creates a deep copy of the other list by iterating through the nodes of 
    //other and creating new nodes with the same data in the current list. It 
    //ensures that the new list is independent of the original list.
    List(const List &other) : head(NULL) { // copy constructor
        Node *otherCurrent = other.head;
        Node *current = NULL;
        Node *prevNode = NULL;

        while (otherCurrent != NULL)
        {
            Node *newNode = new Node(otherCurrent->data);
            newNode->prev = prevNode; //Set the previous node's pointer
            if (prevNode != NULL)
            {
                prevNode->next = newNode;
            }
            if (current == NULL)
            {
                head = newNode;
                current = newNode;
            }
            else
            {
                current->next = newNode;
                current = newNode;
            }
            otherCurrent = otherCurrent->next;
        }
    }
    // Overloade assingment operator
    // It checks for self-assignment (when you try
    // to assign a list to itself) and returns the
    // current instance if self-assignment is
    // detected to avoid memory leaks.
    List &operator=(const List &other)
    {
        if (this == &other)
        {
            return *this; // self-assignment
        }

        // clearing the exisiting list (deallocating memory for all nodes)
        while (head != NULL)
        {
            Node *temp = head;                                                                                                                                                                                  
            head = head->next;
            delete temp;
        }

        // copies elements from other list to the current list in a
        // similar way to copy constructor
        Node *otherCurrent = other.head;
        Node *current = NULL;
        Node *prevNode = NULL;

        while (otherCurrent != NULL)
        {
            Node *newNode = new Node(otherCurrent->data);
            newNode->prev = prevNode;
            if (prevNode != NULL)
            {
                prevNode->next = newNode;
            }
            prevNode = newNode;

            if (current == NULL)
            {
                head = newNode;
                current = newNode;
            }
            else
            {
                current->next = newNode;
                current = newNode;
            }
            otherCurrent = otherCurrent->next;
        }
        return *this;
    }

    // Adding new element at the end of the list
    void add(int value)
    {
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current; //Set the previous node's pointer
        }
    }

    void display()
    {
        Node *current = head;
        while (current != NULL)
        {
            cout << current->data << " <-> "; //Display both next and previous nodes
            current = current->next;
        }
        cout << endl;
    }
    // When the list object goes out of scope, destructor deallocates memory for all nodes.
    ~List()
    {
        while (head != NULL)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// adding, copying and assigning
int main() {
    List list1;
    list1.add(1);
    list1.add(2);
    list1.add(3);

    List list2(list1); // copy of list1

    cout << "Original list1: ";
    list1.display();
    cout << "Copied list2: ";
    list2.display();

    list2.add(4);

    cout << "Modified list2: ";
    list2.display();

    // test assignment operator
    List list3;
    list3 = list1;

    cout << "Assigned list3: ";
    list3.display();

    return 0;
}
