// DoublyLinkedList.cpp
#include <iostream>
#include "Dll.h"
using namespace std;

Node::Node(int val)
{
    data = val;
    next = NULL;
    prev = NULL;
}

List::List()
{
    head = NULL;
}

List::List(const List &other) : head(NULL)
{
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
}

List &List::operator=(const List &other)
{
    if (this == &other)
    {
        return *this;
    }

    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

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

void List::add(int value)
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
        newNode->prev = current;
    }
}

void List::display()
{
    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << "<->";
        current = current->next;
    }
    cout << "NULL" << endl;
}

List::~List()
{
    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}
