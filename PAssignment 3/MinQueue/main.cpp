#include <iostream>
#include "MinQueue.h"

using namespace std;

int main()
{
    MinQueue<int> queue = MinQueue<int>();

    cout << endl << "Filling the queue with elements" << endl;
    for(int i = 100; i >= 0; i--)
    {
        queue.enqueue(i);
    }

    cout << "Queue: " << queue << endl << endl;

    queue.enqueue(-23);

    for(int i = 100; i >= 0; i-=2)
    {
        queue.enqueue(i);
    }

    cout << "Queue: " << queue << endl << endl;

    cout << "Minimum in Queue: " << queue.min() << endl;
    cout << "Size of Queue: " << queue.size() << endl;

    cout << "Dequeue 100 times" << endl;
    for(int i = 100; i >= 0; i--)
    {
        queue.dequeue();
    }

    cout << "Queue: " << queue << endl << endl;

    cout << "Dequeuing until list is empty" << endl;
    while(!queue.isEmpty())
    {
        queue.dequeue();
    }

    cout << "Size of Queue: " << queue.size() << endl << endl;

    return 0;
}