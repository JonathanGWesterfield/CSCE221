//
// Created by Jonathan G. Westerfield on 7/12/17.
//

#ifndef STACK_ADT_STACKADT_H
#define STACK_ADT_STACKADT_H

#endif //STACK_ADT_STACKADT_H

#include <vector>
#include <iostream>
#include <typeinfo>

using namespace std;

template <class T> class StackADT
{
    int stackSize;
    vector<T> stackVec;

public:
    StackADT();
    ~StackADT();
    StackADT(const StackADT& orgStack);
    void push(const T &elem);
    void pop();
    T top();
    bool empty();
    int getStackSize() const;
    void printStackTrace() const;
    T getStack();
    StackADT& operator=(const StackADT& orgStack);
    T& operator[](int r) const;
    T& operator[](int r);
    T& at(int r) const;
    vector<int> computeStackSpan(const vector<T> &x);
};

template<class T> StackADT<T>::StackADT()
{
    stackVec = {};
    stackSize = stackVec.size();
    // vector<T> stackVec;
}

template<class T> StackADT<T>::~StackADT()
{
    stackVec.clear();
    cout << "Destructor has been called" << endl;
    cout << "Stack has been removed" << endl << endl;
}

template <class T> StackADT<T>::StackADT(const StackADT<T> &orgStack) // copy constructor
{
    stackVec = orgStack.stackVec;
    stackSize = orgStack.stackSize; // uses vector class' built in assignment operator
}

// overloaded copy assignment operator
template <class T> StackADT<T>& StackADT<T>::operator=(const StackADT<T>& orgStack)
{
    if(this != &orgStack) // makes sure we avoid self copy: x = x by comparing the address
    {
        cout << "Copy Assgnment called" << endl;
        stackSize = orgStack.stackSize;
        stackVec = orgStack.stackVec; // uses vector class' built in assignment operator
    }
    else
    {
        cerr << "Copy Assignment failed" << endl << endl;
    }
}

template <class T> T& StackADT<T>::operator[](int r) const
{
    if(r < 0 || r >= stackVec.size())
    {
        cerr << "Error: Element out of range" << endl;
        cerr << "Function: overloaded [] operator" << endl << endl;
    }
    else
    {
        return stackVec[r];
    }
}

template <class T> T& StackADT<T>::operator[](int r)
{
    if(r < 0 || r >= stackVec.size())
    {
        cerr << "Error: Element out of range" << endl;
        cerr << "Function: overloaded [] operator" << endl << endl;
    }
    else
    {
        return stackVec[r];
    }
}

template <class T> T& StackADT<T>::at(int r) const
{
    if(r < 0 || r >= stackVec.size())
    {
        cerr << "Error: Element out of range" << endl;
        cerr << "Function: overloaded [] operator" << endl << endl;
    }
    else
    {
        return stackVec[r];
    }
}

// puts an element on the top of the stack
template <class T> void StackADT<T>::push(const T &elem)
{
    stackVec.push_back(elem);
    stackSize = stackVec.size();
}

// takes element off the top of the stack
template <class T> void StackADT<T>:: pop()
{
    if(stackSize == 0)
    {
        cerr << "Stack is empty\nCan't pop off the top" << endl;
        cerr << "Function: pop()" << endl;
        return;
    }
    stackVec.pop_back();
    stackSize = stackVec.size();
}

template <class T> T StackADT <T>::top()
{
    if(stackSize == 0)
    {
        cerr << "Stack was empty\nCould not get the top of the stack" << endl;
        cerr << "Function: top()" << endl;
        throw "Function: top()"; // returns a type casted -1 to force a return
    }

    return stackVec.at(stackVec.size() - 1); // gets the last element in the vector
}

template <class T> bool StackADT<T>::empty()
{
    /*if(stackSize == 0)
    {
        cerr << "Stack has zero size" << endl;
        cerr << "Function: empty()" << endl;
        throw "Stack has zero size";
    }*/
    if(stackVec.size() == 0)
        return true;
    else
        return false;
}


template <class T> int StackADT<T>::getStackSize() const
{
    return stackSize;
}

template <class T> void StackADT<T>::printStackTrace() const
{
    cout << "stack from top to bottom" << endl << endl;
    for(int i = getStackSize() - 1; i >= 0; i--)
    {
        cout << stackVec.at(i) << endl;
    }
    cout << endl << endl;

    return;
}

template <class T> vector<int> StackADT<T>::computeStackSpan(const vector<T> &x)
{
    StackADT<T> stack;
    // vector<int> x = {6, 3, 4, 5, 2};
    vector<T> s(x.size());

    for(int i = 0 ; i < x.size(); ++i) // n iterations
    {
        while(!stack.empty() && x[stack.top()] <= x[i]) // only runs once per for loop - 1 operation
        {
            stack.pop(); // 1 operation
        }
        if(stack.empty()) // only runs once per for loop
        {
            s[i] = i + 1; // 2 operations: assignment and addition
        }
        else // only runs once per for loop
        {
            s[i] = i - stack.top(); // 2 operations: assignment and subtraction
        }

        stack.push(i); // 1 operation
    }

    return s; // 1 operation
}
































