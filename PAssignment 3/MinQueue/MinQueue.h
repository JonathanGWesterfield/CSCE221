//
// Created by Jonathan G. Westerfield on 7/27/17.
//

#ifndef MINQUEUE_MINQUEUE_H
#define MINQUEUE_MINQUEUE_H

#endif //MINQUEUE_MINQUEUE_H

#include <iostream>
#include "TemplateDoublyLinkedList.h"

template <class T> class MinQueue
{
private:
    int Qsize;

public:
    TemplateDoublyLinkedList<T> tdll;
    MinQueue()
    {
        Qsize = 0;
        tdll = TemplateDoublyLinkedList<T>();
    }
    ~MinQueue()
    {
        Qsize = 0;
        tdll.~TemplateDoublyLinkedList();
    }
    T dequeue();
    void enqueue(T newObj);
    int size();
    bool isEmpty();
    T min();
};

template <class T> ostream& operator<<(ostream& out, const MinQueue<T> queue)
{
    out << queue.tdll << endl;
    return out;
}

template <class T> T MinQueue<T>::dequeue()
{
    Qsize--;
    T obj = tdll.getFirst()->obj;
    tdll.removeFirst();

    return obj;
}

template <class T> void MinQueue<T>::enqueue(T newObj)
{
    Qsize++;
    tdll.insertLast(newObj);
}

template <class T> int MinQueue<T>::size()
{
    return Qsize;
}

template <class T> bool MinQueue<T>::isEmpty()
{
    return Qsize == 0;
}

template <class T> T MinQueue<T>::min()
{
    DListNode<T> *current = tdll.getFirst();
    T currMin = current->obj;
    while(current != tdll.getAfterLast())
    {
        if(current->obj < currMin  )
        {
            currMin = current->obj;
        }
        current = current->next;
    }

    return currMin;
}
