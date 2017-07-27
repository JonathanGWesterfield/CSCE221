#ifndef TEMPLATEDOUBLYLINKEDLIST_TEMPLATEDOUBLYLINKEDLIST_H
#define TEMPLATEDOUBLYLINKEDLIST_TEMPLATEDOUBLYLINKEDLIST_H

#endif //TEMPLATEDOUBLYLINKEDLIST_TEMPLATEDOUBLYLINKEDLIST_H

#include <cstdlib>
#include <iostream>
#include <stdexcept>
using namespace std;

//template<class T> class TemplateDoublyLinkedList; // class declaration
//template<class T> class DListNode;

// list node
template<class T> struct DListNode
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
    TemplateDoublyLinkedList() : head(), tail() // constructor
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
    T first() const; // return the first object
     T last() const; // return the last object
    void insertFirst(T newobj); // insert to the first of the list
    void insertLast(T newobj); // insert to the last of the list
    T removeFirst(); // remove the first node
    T removeLast(); // remove the last node
    void insertAfter(DListNode<T> &p, T newobj);
    void insertBefore(DListNode<T> &p, T newobj);
    void removeAfter(DListNode<T> &p);
    void removeBefore(DListNode<T> &p);

};

// output operator
template <class T> ostream& operator<<(ostream& out, const TemplateDoublyLinkedList<T>& dll)
{
    DListNode<T> *current = dll.getFirst();
    while(current->next != NULL) // traverses until it hits the tail's NULLPTR
    {
        out << current->obj << " ";
        current = current->next;
    }

    return out;
}
// return the list length
template <class T> int TemplateDoublyLinkedListLength(TemplateDoublyLinkedList<T>& dll)
{
    return 0;
}






// CODE STARTS HERE








// extend range_error from <stdexcept>
struct EmptyDLinkedListException : std::range_error {
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

template <class T> TemplateDoublyLinkedList<T>::~TemplateDoublyLinkedList()
{
    if(head.next == &tail)
    {
        cout << "List was empty" << endl;
        return;
    }
    DListNode<T> *prevNode;
    DListNode<T> *current;

    current = head.next; // moves to first node in the list

    while(current != &tail) // run until it hits tail
    {
        prevNode = current;
        current = current->next; // moves to next object
        delete prevNode; // deletes the object that was just left
    }

    head.next = &tail;
    tail.prev = &head;

    cout << "Destructor called\nList deleted" << endl;
}

template <class T> TemplateDoublyLinkedList<T>& TemplateDoublyLinkedList<T>::operator=(const TemplateDoublyLinkedList& dll)
{
    // Delete the whole list
    this->~TemplateDoublyLinkedList();

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
}

// remove the last object from the list
template<class T> T TemplateDoublyLinkedList<T>::removeLast()
{
    if(isEmpty())
    {
        throw EmptyDLinkedListException("List is empty\nFunction: removeLast()");
    }
    DListNode<T> *current;
    current = tail.prev;
    current->prev->next = &tail;
    tail.prev = current->prev;
    T obj = current->obj; // returns the element in the node
    delete current; // deletes the last object
    current = NULL; // sets null pointer

    return obj; // returns what the deleted node had
}

template<class T> T TemplateDoublyLinkedList<T>::first() const
{
    if(isEmpty())
    {
        throw EmptyDLinkedListException("List is empty\nFunction: first()");
    }
    return head.next->obj;
}

template<class T> T TemplateDoublyLinkedList<T>::last() const
{
    if(isEmpty())
    {
        throw EmptyDLinkedListException("List is empty\nFunction: last()");
    }
    return tail.prev->obj;
}

// insert the new object after the node p
template <class T> void TemplateDoublyLinkedList<T>::insertAfter(DListNode<T> &p, T newObj)
{
    if(p.next == &tail) // redundant but oh well
    {
        insertLast(newObj);
        return;
    }
    if(&p == &tail)
    {
        throw EmptyDLinkedListException("Can't insert past the tail in the list\nFunction: insertAfter()");
    }

    DListNode<T> *newNode = new DListNode<T>(newObj, &p, p.next);
    p.next->prev = newNode; // sets the next nodes prev to the new node
    p.next = newNode; // sets p's next node to the new node
    // TODO: Test if this works
}

// insert the new object before the node p
template <class T> void TemplateDoublyLinkedList<T>::insertBefore(DListNode<T> &p, T newObj)
{
    if(p.prev == &head) // redundant but oh well
    {
        insertFirst(newObj);
        return;
    }
    if(&p == &head)
    {
        throw EmptyDLinkedListException("Can't insert before the head in the list\nFunction: insertBefore()");
    }

    DListNode<T> *newNode = new DListNode<T>(newObj, p.prev, &p);
    p.prev->next = newNode;
    p.prev = newNode;
}

// remove the node after the node p
template <class T> void TemplateDoublyLinkedList<T>::removeAfter(DListNode<T> &p)
{
    if(isEmpty())
    {
        throw EmptyDLinkedListException("List is empty\nFunction: removeAfter()");
    }
    if(&p == &tail)
    {
        throw EmptyDLinkedListException("Can't remove past the tail in the list\nFunction: removeAfter()");
    }
    if(p.next == &tail) // for if this is the last element for some reason
    {
        throw EmptyDLinkedListException("Can't remove the tail in the list\nFunction: removeAfter()");
    }

    DListNode<T> *current;
    current = &p; // goes to node p
    current = current->next; // moves to the node after p
    p.next = current->next; // sets p's next to the node after current
    current->next->prev = &p; // sets the node after current's prev to p
    // cout << "The node containing " << current->obj << ", after " << &p << " has been deleted. " << endl;
    delete current; // deletes the node after p
    current = NULL; // frees the dangling pointer
}

// remove the node before the node p
template <class T> void TemplateDoublyLinkedList<T>::removeBefore(DListNode<T> &p)
{
    if(isEmpty())
    {
        throw EmptyDLinkedListException("List is empty\nFunction: removeBefore()");
    }
    if(&p == &head)
    {
        throw EmptyDLinkedListException("Can't remove before the head in the list\nFunction: removeBefore()");
    }
    if(p.prev == &head) // for if this is the last element for some reason
    {
        throw EmptyDLinkedListException("Can't remove the head in the list\nFunction: removeBefore()");
    }

    DListNode<T> *current;
    current = &p; // goes to node p
    current = current->prev; // moves to the node before p
    p.prev = current->prev;
    current->prev->next = &p;
    // cout << "The node containing " << current->obj << ", before " << &p << " has been deleted. " << endl;
    delete current; // deletes the node after p
    current = NULL; // frees the dangling pointer
}