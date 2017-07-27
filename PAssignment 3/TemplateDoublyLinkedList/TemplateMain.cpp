#include "TemplateDoublyLinkedList.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>

using namespace std;

int main ()
{
    // Construct a linked list with header & trailer
    cout << "Create a new list" << endl;
    TemplateDoublyLinkedList<string> dll;
    cout << "list: " << dll << endl << endl;


    // Insert 10 nodes at back with value 10,20,30,..,100
    cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
    for (int i = 10; i <= 100; i += 10)
    {
        stringstream ss;
        ss << i;
        dll.insertLast(ss.str());
    }
    cout << "list: " << dll << endl << endl;


    // Insert 10 nodes at front with value 10,20,30,..,100
    cout << "Insert 10 nodes at front with value 10,20,30,..,100" << endl;
    for (int i = 10; i <= 100; i += 10)
    {
        stringstream ss;
        ss << i << "SS";
        dll.insertFirst(ss.str());
    }
    cout << "list: " << dll << endl << endl;


    // Copy to a new list
    cout << "Copy to a new list" << endl;
    TemplateDoublyLinkedList<string> dll2(dll);
    cout << "list2: " << dll2 << endl << endl;


    // Assign to another new list
    cout << "Assign to another new list" << endl;
    TemplateDoublyLinkedList<string> dll3;
    dll3 = dll;
    cout << "list3: " << dll3 << endl << endl;


    // Delete the last 10 nodes
    cout << "Delete the last 10 nodes" << endl;
    for (int i = 0; i < 10; i++)
    {
        dll.removeLast();
    }
    cout << "list: " << dll << endl << endl;

    cout << "First object in list: " << dll.first() << endl << endl;

    cout << "Last object in list: " << dll.last() << endl << endl;


    // Delete the first 10 nodes
    cout << "Delete the first 10 nodes" << endl;
    for (int i = 0; i < 10; i++)
    {
        dll.removeFirst();
    }
    cout << "list: " << dll << endl << endl;


    // Check the other two lists
    cout << "Make sure the other two lists are not affected." << endl;
    cout << "list2: " << dll2 << endl;
    cout << "list3: " << dll3 << endl << endl;

    // more testing...
    // add tests for insertAfter, insertBefore
    // add tests for removeAfter, removeBefore
    // add tests for DoublyLinkedListLength

    cout << endl << "\n\nFurther Testing for the insertAfter/Before() functions" << endl << endl;

    // Insert 10 nodes at back with value 10,20,30,..,100
    cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
    for (int i = 10; i <= 100; i += 10)
    {
        stringstream ss;
        ss << i << "SOS";
        dll.insertFirst(ss.str());
    }
    cout << "list: " << dll << endl << endl;

    DListNode<string> *current = dll.getFirst();
    while(current->obj != "30SOS")
    {
        current = current->next;
    }

    cout << "List: " << dll << endl << endl;


    // inserts 69 after 30
    cout << "Inserting \"INSERT AFTER\" AFTER 30SOS" << endl;
    dll.insertAfter(*current, "INSERTAFTER");
    cout << "list: " << dll << endl << endl;


    // inserts 69 before 30
    cout << "Inserting \"INSERT BEFORE\" BEFORE 30SOS" << endl;
    dll.insertBefore(*current, "INSERTBEFORE");
    cout << "list: " << dll << endl << endl;


    // removes 69 after 30
    cout << "Removing \"INSERTAFTER\" AFTER 30SOS" << endl;
    dll.removeAfter(*current);
    cout << "list: " << dll << endl << endl;

    // removes 69 before 30
    cout << "Removing \"INSERTAFTER\" AFTER 30SOS" << endl;
    dll.removeBefore(*current);
    cout << "list: " << dll << endl << endl;


    return 0;
}
