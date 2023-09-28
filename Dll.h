// DoublyLinkedList.h

#ifndef Dll_H
#define Dll_H

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val);
};

class List
{
private:
    Node *head;

public:
    List();
    List(const List &other);
    List &operator=(const List &other);
    void add(int value);
    void display();
    ~List();
};

#endif // DOUBLYLINKEDLIST_H
