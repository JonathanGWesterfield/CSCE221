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

    while(current != dll.getAfterLast()) // goes through the list and deep copies all elements
    {
        this -> insertLast(current->obj); // inserts deep copy into the new list
        current = current->next; // moves to next object
    }
}

// assignment operator
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& dll)
{
  // Delete the whole list

    this->~DoublyLinkedList();

    DListNode *current;
    // TODO: Something is wrong with this function it does not work
    current = dll.getFirst(); // sets traversing node to the first object in the list

    while(current != dll.getAfterLast()) // goes through the list and deep copies all elements
    {
        this -> insertLast(current->obj); // inserts deep copy into the new list
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
void DoublyLinkedList::insertAfter(DListNode &p, int newObj)
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

    DListNode *newNode = new DListNode(newObj, &p, p.next);
    p.next->prev = newNode; // sets the next nodes prev to the new node
    p.next = newNode; // sets p's next node to the new node
    // TODO: Test if this works
}

// insert the new object before the node p
void DoublyLinkedList::insertBefore(DListNode &p, int newObj)
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

    DListNode *newNode = new DListNode(newObj, p.prev, &p);
    p.prev->next = newNode;
    p.prev = newNode;
}

// remove the node after the node p
void DoublyLinkedList::removeAfter(DListNode &p)
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

    DListNode *current = new DListNode();
    current = &p; // goes to node p
    current = current->next; // moves to the node after p
    p.next = current->next; // sets p's next to the node after current
    current->next->prev = &p; // sets the node after current's prev to p
    cout << "The node containing " << current->obj << ", after " << &p << " has been deleted. " << endl;
    delete current; // deletes the node after p
    current = NULL; // frees the dangling pointer
}

// remove the node before the node p
void DoublyLinkedList::removeBefore(DListNode &p)
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

    DListNode *current = new DListNode();
    current = &p; // goes to node p
    current = current->prev; // moves to the node before p
    p.prev = current->prev;
    current->prev->next = &p;
    cout << "The node containing " << current->obj << ", before" << &p << " has been deleted. " << endl;
    delete current; // deletes the node after p
    current = NULL; // frees the dangling pointer
}

// return the list length
int DoublyLinkedListLength(DoublyLinkedList& dll)
{
    int count = 0;
    DListNode *current = dll.getFirst();
    while(current != dll.getAfterLast()) // run to end of the list
    {
        count++; // counts number of nodes in the list
        current = current->next;
    }
    return count;
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

DListNode* find(const DoublyLinkedList dll, int findObj) // returns a specific node to insert in the middle of th list
{
    DListNode *current = dll.getFirst();
    while(current != dll.getAfterLast())
    {
        if(current->obj = findObj) // if we find what we are looking for, return the node's pointer
        {
            cout << "We found " << current->obj << " when we were looking for " << findObj << endl << endl;
            return current;
        }

        current = current->next; // increments through the list

        if(current == dll.getAfterLast())
        {
            cout << "We didn't find what we were looking for" << endl << endl;
            DListNode *NodeNotFound = new DListNode(-99999);
            return NodeNotFound;
        }
    }
}
