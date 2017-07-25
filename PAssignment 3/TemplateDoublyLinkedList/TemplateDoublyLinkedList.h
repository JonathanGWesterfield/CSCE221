#ifndef TEMPLATEDOUBLYLINKEDLIST_TEMPLATEDOUBLYLINKEDLIST_H
#define TEMPLATEDOUBLYLINKEDLIST_TEMPLATEDOUBLYLINKEDLIST_H

#endif //TEMPLATEDOUBLYLINKEDLIST_TEMPLATEDOUBLYLINKEDLIST_H

#include <cstdlib>
#include <iostream>
#include <stdexcept>
using namespace std;
template<class T> class TemplateDoublyLinkedList; // class declaration

// list node
template<class T> class DListNode
{
public:
    T obj;
    DListNode<T> *prev, *next;
    DListNode(T element = T(), DListNode<T> *previous = NULL, DListNode<T> *next = NULL)
    {
        this -> obj = element;
        this -> prev = previous;
        this -> next = next;
    }
};



// doubly linked list
template<class T> class TemplateDoublyLinkedList
{
private:
    DListNode<T> head, tail;

public:
    TemplateDoublyLinkedList() : head(0), tail(0) // constructor
    {
        head.next = &tail;
        tail.prev = &head;
    }
    TemplateDoublyLinkedList(const TemplateDoublyLinkedList<T>& dll); // copy constructor
    ~TemplateDoublyLinkedList(); // destructor
    TemplateDoublyLinkedList& operator=(const TemplateDoublyLinkedList<T>& dll); // assignment operator
    // return the pointer to the first node
    DListNode<T> *getFirst() const
    {
        return head.next;
    }
    // return the pointer to the tail
    const DListNode<T> *getAfterLast() const
    {
        return &tail;
    }
    // return if the list is empty
    bool isEmpty() const
    {
        return head.next == &tail;
    }
    // T first() const; // return the first object
    // T last() const; // return the last object
    void insertFirst(T newobj); // insert to the first of the list
    T removeFirst(); // remove the first node
    void insertLast(T newobj); // insert to the last of the list
    T removeLast(); // remove the last node
    /*void insertAfter(DListNode<T> &p, T newobj);
    void insertBefore(DListNode<T> &p, T newobj);
    void removeAfter(DListNode<T> &p);
    void removeBefore(DListNode<T> &p);
    bool isEmpty(); // checks if the linked list is empty*/

};

// output operator
template <class T> ostream& operator<<(ostream& out, const TemplateDoublyLinkedList<T>& dll);
// return the list length
template <class T> int TemplateDoublyLinkedListLength(TemplateDoublyLinkedList<T>& dll);






// CODE STARTS HERE








// extend range_error from <stdexcept>
/*struct EmptyDLinkedListException : std::range_error {
    explicit EmptyDLinkedListException(char const* msg = NULL): range_error(msg) {}
};

// copy constructor
template <class T> TemplateDoublyLinkedList<T>::TemplateDoublyLinkedList(const TemplateDoublyLinkedList& dll)
{
    // Initialize the list
    this -> head.next = &tail;
    this -> tail.prev = &head;

    DListNode<T> *current;
    current = dll.getFirst(); // sets traversing node to the first object in the list

    while(current != dll.getAfterLast()) // goes through the list and deep copies all elements
    {
        this -> insertLast(current->obj); // inserts deep copy into the new list
        current = current->next; // moves to next object
    }
}

template <class T> TemplateDoublyLinkedList<T>& TemplateDoublyLinkedList<T>::operator=(const TemplateDoublyLinkedList& dll)
{
    // Delete the whole list

    while(!this->isEmpty()) // while this class isn't empty
    {
        this->removeLast();
    }
    head = 0;
    tail = 0;
    head.next = &tail;
    tail.prev = &head; // sets the list to empty by pointing the ends at each other

    // Performs a deep copy of the list
    // Initialize the list
    this -> head.next = &tail;
    this -> tail.prev = &head;

    DListNode<T> *current;
    // TODO: Something is wrong with this function it does not work
    current = dll.getFirst(); // sets traversing node to the first object in the list

    while(current != dll.getAfterLast()) // goes through the list and deep copies all elements
    {
        this -> insertLast(current->obj); // inserts deep copy into the new list
        current = current->next; // moves to next object
    }
    return *this;
}

// insert the new object as the first one
template <class T> void TemplateDoublyLinkedList<T>::insertFirst(T newObj)
{
    if(isEmpty()) // if address are the same for head and tail
    {
        DListNode<T> *newNode = new DListNode<T>(newObj, &head, &tail);
        head.next = newNode;
        tail.prev = newNode;
        return;
    }
    DListNode<T> *newNode = new DListNode<T>(newObj, &head, head.next);
    head.next->prev = newNode; // asks what this means - possibly means the prev pointer for the next
    // is pointing to this new node
    head.next = newNode;
    return;
}

// insert the new object as the last one
template <class T> void TemplateDoublyLinkedList<T>::insertLast(T newObj)
{
    if(isEmpty())
    {
        DListNode<T> *newNode = new DListNode<T>(newObj, &head, &tail);
        head.next = newNode;
        tail.prev = newNode;
        return;
    }
    DListNode<T> *newNode = new DListNode<T>(newObj, tail.prev, &tail);
    tail.prev->next = newNode;
    tail.prev = newNode;
    return;
}

// remove the first object from the list
template <class T> T TemplateDoublyLinkedList<T>::removeFirst()
{
    if(isEmpty())
    {
        throw EmptyDLinkedListException("List is empty\nFunction: removeFirst()");
    }
    DListNode<T> *current; // creates a node to move down the list
    current = head.next; // moves to the next node
    head.next = current->next;
    current->next->prev = &head; // should set the next node's prev to head
    T obj = current->obj; // returns the element in the node
    delete current; // deletes the current (first) node
    current = NULL; // gets rid of the dangling pointer

    return obj; // returns what the deleted node had
}**/