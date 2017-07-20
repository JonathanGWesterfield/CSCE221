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
  header.next = &trailer; trailer.prev = &header;
  
  /* Complete this function */
}

// assignment operator
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& dll)
{
  // Delete the whole list
  /* Complete this function */
}

// insert the new object as the first one
void DoublyLinkedList::insertFirst(int newobj)
{ 
    /* Complete this function */
}

// insert the new object as the last one
void DoublyLinkedList::insertLast(int newobj)
{
    /* Complete this function */
}

// remove the first object from the list
int DoublyLinkedList::removeFirst()
{ 
    /* Complete this function */
}

// remove the last object from the list
int DoublyLinkedList::removeLast()
{
    /* Complete this function */
}

// destructor
DoublyLinkedList::~DoublyLinkedList()
{
    /* Complete this function */
}

// return the first object
int DoublyLinkedList::first() const
{ 
    /* Complete this function */
}

// return the last object
int DoublyLinkedList::last() const
{
    /* Complete this function */
}

// insert the new object after the node p
void DoublyLinkedList::insertAfter(const DListNode &p, int newobj)
{
    /* Complete this function */
}

// insert the new object before the node p
void DoublyLinkedList::insertBefore(const DListNode &p, int newobj)
{
    /* Complete this function */
}

// remove the node after the node p
void DoublyLinkedList::removeAfter(const DListNode &p)
{
    /* Complete this function */
}

// remove the node before the node p
void DoublyLinkedList::removeBefore(const DListNode &p)
{
    /* Complete this function */
}

// return the list length
int DoublyLinkedListLength(DoublyLinkedList& dll)
{
    /* Complete this function */
}

// output operator
ostream& operator<<(ostream& out, const DoublyLinkedList& dll)
{
  
  /* Complete this function */
  
  return out;
}
