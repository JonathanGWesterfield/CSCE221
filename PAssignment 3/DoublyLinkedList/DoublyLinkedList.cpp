#include "DoublyLinkedList.h"
#include <stdexcept>

// extend range_error from <stdexcept>
struct EmptyDLinkedListException : std::range_error {
  explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};

// copy constructor
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& dll)
{
    // Initialize the list
    this -> head.next = &tail;
    this -> tail.prev = &head;

    DListNode *current;
    current = dll.getFirst(); // sets traversing node to the first object in the list

    DListNode *newNode = new DListNode(current->obj,&head, &tail); // creates the first object in the list
    head.next = newNode;
    tail.prev = newNode;
    while(current != dll.getAfterLast()) // goes through the list and deep copies all elements
    {
        insertLast(current->obj); // inserts deep copy into the new list
        current = current->next; // moves to next object
    }
}

// assignment operator
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& dll)
{
  // Delete the whole list

    DListNode *previous, *current;
    current = head.next;
    while(!this->isEmpty()) // while this class isn't empty
    {
        this->removeLast();
    }
    head = 0;
    tail = 0;
    head.next = &tail;
    tail.prev = &head; // sets the list to empty by pointing the ends at each other

  /* Performs a deep copy of the list */
    // Initialize the list
    this -> head.next = &tail;
    this -> tail.prev = &head;

    current = dll.getFirst(); // sets traversing node to the first object in the list

    DListNode *newNode = new DListNode(current->obj,&head, &tail); // creates the first object in the list
    head.next = newNode;
    tail.prev = newNode;
    while(current != dll.getAfterLast()) // goes through the list and deep copies all elements
    {
        insertLast(current->obj); // inserts deep copy into the new list
        current = current->next; // moves to next object
    }
    return *this;
}

bool DoublyLinkedList::isEmpty()
{
    if(&head == &tail) // checks if address of head and tail are the same which means list is empty
        return true;
    return false;
}

// insert the new object as the first one
void DoublyLinkedList::insertFirst(int newObj)
{
    if(isEmpty()) // if address are the same for head and tail
    {
        DListNode *newNode = new DListNode(newObj, &head, &tail);
        head.next = newNode;
        tail.prev = newNode;
        return;
    }
    DListNode *newNode = new DListNode(newObj, &head, head.next);
    head.next->prev = newNode; // asks what this means - possibly means the prev pointer for the next
    // is pointing to this new node
    head.next = newNode;
    return;
}

// insert the new object as the last one
void DoublyLinkedList::insertLast(int newObj)
{
    if(isEmpty())
    {
        DListNode *newNode = new DListNode(newObj, &head, &tail);
        head.next = newNode;
        tail.prev = newNode;
        return;
    }
    DListNode *newNode = new DListNode(newObj, tail.prev, &tail);
    tail.prev->next = newNode;
    tail.prev = newNode;
    return;
}

// remove the first object from the list
int DoublyLinkedList::removeFirst()
{
    if(isEmpty())
    {
        throw EmptyDLinkedListException("List is empty\nFunction: removeFirst()");
    }
    DListNode *current = new DListNode(); // creates a node to move down the list
    current = head.next; // moves to the next node
    head.next = current->next;
    current->next->prev = &head; // should set the next node's prev to head
    int obj = current->obj; // returns the element in the node
    delete current; // deletes the current (first) node
    current = NULL; // gets rid of the dangling pointer

    return obj; // returns what the deleted node had
}

// remove the last object from the list
int DoublyLinkedList::removeLast()
{
    if(isEmpty())
    {
        throw EmptyDLinkedListException("List is empty\nFunction: removeLast()");
    }
    DListNode *current;
    current = tail.prev;
    current->prev->next = &tail;
    tail.prev = current->prev;
    int obj = current->obj; // returns the element in the node
    delete current; // deletes the last object
    current = NULL; // sets null pointer

    return obj; // returns what the deleted node had

}

// destructor
DoublyLinkedList::~DoublyLinkedList()
{
    DListNode *prevNode;
    DListNode *current;

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

// return the first object
int DoublyLinkedList::first() const
{
    if(isEmpty())
    {
        throw EmptyDLinkedListException("List is empty\nFunction: first()");
    }
    DListNode *current;
    current = head.next; // sets it to the first node
    return current->obj; // returns the objects element
}

// return the last object
int DoublyLinkedList::last() const
{
    if(isEmpty())
    {
        throw EmptyDLinkedListException("List is empty\nFunction: last()");
    }
    DListNode *current;
    current = tail.prev;
    return current->obj;
}

// insert the new object after the node p
void DoublyLinkedList::insertAfter(const DListNode &p, int newObj)
{
    if(p.next == &tail) // for if this is the last element for some reason
    {
        insertLast(newObj);
        return;
    }
    DListNode *copyP= new DListNode(p.obj, p.prev, p.next); // creates a copy of p

    DListNode *newNode = new DListNode(newObj, copyP->prev, copyP->next); // sets previous to p and next to p's next
    copyP->next->prev = newNode; // sets the next object's prev to the new node
    copyP->next = newNode; // sets the new node to next

    delete copyP; // deletes the copy
    copyP = NULL; // frees the dangling pointer

    // TODO: check this to make sure it works
}

// insert the new object before the node p
void DoublyLinkedList::insertBefore(const DListNode &p, int newObj)
{
    /* Complete this function */
    //TODO: Finish this
}

// remove the node after the node p
void DoublyLinkedList::removeAfter(const DListNode &p)
{
    /* Complete this function */
    //TODO: Finish this
}

// remove the node before the node p
void DoublyLinkedList::removeBefore(const DListNode &p)
{
    /* Complete this function */
    //TODO: Finish this
}

// return the list length
int DoublyLinkedListLength(DoublyLinkedList& dll)
{
    /* Complete this function */
    //TODO: Finish this
}

// output operator
ostream& operator<<(ostream& out, const DoublyLinkedList& dll) // TODO: test this
{
    DListNode *current = dll.getFirst();
    while(current->next != NULL) // traverses until it hits the tail's NULLPTR
    {
        out << current->obj << " ";
        current = current->next;
    }
  
  return out;
}
