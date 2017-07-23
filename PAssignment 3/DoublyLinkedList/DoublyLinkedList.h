#include <cstdlib>
#include <iostream>
using namespace std;
class DoublyLinkedList; // class declaration

// list node
struct DListNode
{
    int obj;
    DListNode *prev, *next;
    DListNode(int element = 0, DListNode *previous = NULL, DListNode *next = NULL)
    {
        this -> obj = element;
        this -> prev = previous;
        this -> next = next;
    }
};

// doubly linked list
class DoublyLinkedList
{
private:
    DListNode head, tail;

public:
    DoublyLinkedList() : head(0), tail(0) // constructor
    {
        head.next = &tail;
        tail.prev = &head;
    }
    DoublyLinkedList(const DoublyLinkedList& dll); // copy constructor
    ~DoublyLinkedList(); // destructor
    DoublyLinkedList& operator=(const DoublyLinkedList& dll); // assignment operator
    // return the pointer to the first node
    DListNode *getFirst() const
    {
        return head.next;
    }
    // return the pointer to the tail
    const DListNode *getAfterLast() const
    {
        return &tail;
    }
    // return if the list is empty
    bool isEmpty() const
    {
        return head.next == &tail;
    }
    int first() const; // return the first object
    int last() const; // return the last object
    void insertFirst(int newobj); // insert to the first of the list
    int removeFirst(); // remove the first node
    void insertLast(int newobj); // insert to the last of the list
    int removeLast(); // remove the last node
    void insertAfter(DListNode &p, int newobj);
    void insertBefore(DListNode &p, int newobj);
    void removeAfter(DListNode &p);
    void removeBefore(DListNode &p);
    bool isEmpty(); // checks if the linked list is empty

};

// output operator
ostream& operator<<(ostream& out, const DoublyLinkedList& dll);
// return the list length
int DoublyLinkedListLength(DoublyLinkedList& dll);
DoublyLinkedList& find(DoublyLinkedList dll, int findObj);
