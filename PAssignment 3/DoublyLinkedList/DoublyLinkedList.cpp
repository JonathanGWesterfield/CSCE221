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
  head.next = &tail; tail.prev = &head;
  
  /* Complete this function */
}

// assignment operator
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& dll)
{
  // Delete the whole list
  /* Complete this function */
    //TODO: Finish this
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
        throw EmptyDLinkedListException("List is empty\nFunction: removeFirst");
    }
    //TODO: finish this
}

// remove the last object from the list
int DoublyLinkedList::removeLast()
{
    /* Complete this function */
    //TODO: Finish this
}

// destructor
DoublyLinkedList::~DoublyLinkedList()
{
    /* Complete this function */
    //TODO: Finish this
}

// return the first object
int DoublyLinkedList::first() const
{ 
    /* Complete this function */
    //TODO: Finish this
}

// return the last object
int DoublyLinkedList::last() const
{
    /* Complete this function */
    //TODO: Finish this
}

// insert the new object after the node p
void DoublyLinkedList::insertAfter(const DListNode &p, int newObj)
{
    /* Complete this function */
    //TODO: Finish this
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
    DListNode *current = new DListNode(0, head.prev, head.next);
    while(current->next != NULL) // traverses until it hits the tail's NULLPTR
    {
        current = current->next;
        out << current->obj << " ";
    }
  
  return out;
}
