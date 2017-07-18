//
// Created by Jonthan Westerfield on 7/8/17.
//

#ifndef PASSIGNMENT_1_TEMPLATEDTemplatedMy_vec_H
#define PASSIGNMENT_1_TEMPLATEDTemplatedMy_vec_H

#endif //PASSIGNMENT_1_TEMPLATEDTemplatedMy_vec_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

template<class T> class TemplatedMy_vec
{
    //member variables
    int size, capacity;
    T *ptr;

public:
    //member functions
    TemplatedMy_vec();
    ~TemplatedMy_vec();
    TemplatedMy_vec(const TemplatedMy_vec& vec);
    TemplatedMy_vec& operator=(const TemplatedMy_vec& vec);
    int get_size() const;
    int get_capacity() const;
    T& operator[](int i) const;
    T& operator[](int i);
    bool is_empty() const;
    T& elem_at_rank(int r) const;
    void insert_at_rank(int r, const T& elem);
    void replace_at_rank(int r, const T& elem);
    void remove_at_rank(int r);

};

template <class T> ostream& operator<<(ostream& out, const TemplatedMy_vec<T>& vec);
template <class T> int find_max_index(const TemplatedMy_vec<T>& v,int size);
template <class T> void sort_max(TemplatedMy_vec<T>& vec);

// class constructor
template <class T> TemplatedMy_vec<T>::TemplatedMy_vec()
{
    size = 0;
    capacity = 10;
    ptr = new T[capacity];

    return;
}

//copy constructor
template <class T> TemplatedMy_vec<T>::TemplatedMy_vec(const TemplatedMy_vec &vec)
{
    cout << "Copy Constructor Called" << endl;
    this -> size = vec.size;
    this -> capacity = vec.capacity;
    this -> ptr = new T[vec.capacity];

    for(int i = 0; i < capacity; i++)
    {
        ptr[i] = vec.ptr[i];
    }
}

// copy assignment. '=' operator overload
// will allow a vector to be copied with only the equals sign
template <class T> TemplatedMy_vec<T>& TemplatedMy_vec<T>::operator=(const TemplatedMy_vec<T>& vec)
{
    delete[] ptr;  // deletes the information at the old address
    size = vec.size;
    capacity = vec.capacity;
    ptr = new T[vec.capacity];
    for(int i = 0; i < size ; i++)
    {
        ptr[i] = vec.ptr[i];
    }

    return *this; // return reference to this new copy
}

template <class T> T& TemplatedMy_vec<T>::operator[](int r) const
{
    if(r < 0 || r >= size)
    {
        cerr << "Error: Element out of range" << endl;
        cerr << "Function: overloaded [] operator" << endl << endl;
    }
    else
    {
        return ptr[r];
    }

}

template <class T> T& TemplatedMy_vec<T>::operator[](int r)
{
    if(r < 0 || r >= size)
    {
        cerr << "Error: Element out of range" << endl;
        cerr << "Function: overloaded [] operator" << endl << endl;
    }
    else
    {
        return ptr[r];
    }
}

// Class destructor
template <class T> TemplatedMy_vec<T>::~TemplatedMy_vec()
{
    delete ptr;
    ptr = NULL;
}


// gets the size of the vector from the 'size' data member
template <class T> int TemplatedMy_vec<T>::get_size() const
{
    return size;
}

// determines if the vector is empty
template <class T> bool TemplatedMy_vec<T>::is_empty() const
{
    return size == 0; // will return true if size is actually 0
}

// this is good
template <class T> T& TemplatedMy_vec<T>::elem_at_rank(int r) const
{
    if(r < 0 || r >= size)
    {
        cerr << "Error: Cannot retrieve" << endl << "Element out of range" << endl;
        cerr << "Function: elem_at_rank"  << endl << endl;
        // exit(EXIT_FAILURE);
    }
    else
    {
        return ptr[r];
    }

}

//this is good
template <class T> void TemplatedMy_vec<T>::replace_at_rank(int r, const T &elem)
{
    if(r < 0 || r > size)
    {
        cerr << "Error: Cannot replace at element " << r <<  "\nElement out of range" << endl;
        cerr << "Function: replace_at_rank"  << endl << endl;
        return;
        //exit(EXIT_FAILURE);
    }

    ptr[r] = elem;

    return;
}

// This is ok maybe
template <class T> void TemplatedMy_vec<T>::insert_at_rank(int r, const T &elem)
{
    int oldCapacity = capacity;
    int initial_size = size;
    if(r < 0 || r >= capacity) // keeps from inserting out of the vector range - doesn't have to do with size
    {
        cerr << "Error: Out of range" << endl;
        cerr << "insert_at_rank"  << endl << endl;
        return;
        //throw "Error: Out of range\ninsert_at_rank";
        //exit(EXIT_FAILURE);
    }
    else if (r <= size)
    {
        size += 1;
    }
        //TODO: create an exception so that the program can continue running
    else
    {
        size = r + 1;
    }

    if (size >= capacity)
    {
        int newCapacity = capacity * 2;
        T* newVec = new T[newCapacity];

        for (int i = 0; i < capacity; i++)
        {
            newVec[i] = ptr[i];
        }

        capacity *= 2;
        delete[] ptr; // deletes the old info to prevent memory leaks
        ptr = newVec; // copies the new array to the old pointer
        newVec = NULL; // gets rid of the dangling pointer
    }

    for(int i = size - 1; i >= r; i--)
    {
        ptr[i] = ptr[i - 1];
    }

    // since an array can't have null values in the array, they need to be replaced with "null" values
    // this will replace the null values with '_' so that there aren't problems with the array or segment faults
    for (int i = initial_size; i < r; i++)
    {
        if(isalpha(elem))
        {
            ptr[i] = '_'; // replaces nulls with '_' if it is a letter for char arrays3
        }
        else
        {
            ptr[i] = 0; // replaces nulls with 0 if it is a number value
        }
    }
    ptr[r] = elem;

    return;
}


// removes element at index - works
template <class T> void TemplatedMy_vec<T>::remove_at_rank(int r)
{
    if(r < 0 || r >= size)
    {
        cerr << "Error: Cannot remove" << endl << "Element is out of range" << endl;
        cerr << "Function: remove_at_rank"  << endl << endl;
        return;
        //exit(EXIT_FAILURE);
    }

    size -= 1;

    for(int i = r; i < size; i++)
    {
        ptr[i] = ptr[i + 1];
    }

    return;
}

// this works
template <class T> ostream& operator<<(ostream& out, const TemplatedMy_vec<T>& vec)
{
    for(int i = 0; i < vec.get_size(); i++)
    {
        // cerr << vec.elem_at_rank(i);
        out << vec.elem_at_rank(i) << ' ';
    }

    cerr << endl;

    return out;
}

// this works
template <class T> int find_max_index(const TemplatedMy_vec<T>& v,int size)
{
    if(v.is_empty())
    {
        cerr << "Error: Vector is empty"  << endl << endl;
        cerr << "find_max_index" << endl;
        return -1; // returns -1 to indicate that there was an error. Can't have index of -1
        // exit(EXIT_FAILURE);
    }
    T max = v[0]; // using the overloaded [] operator
    int maxIndex = 0;

    for(int i = 0; i < v.get_size(); i++)
    {
        if (max < v[i])
        {
            max = v[i];
            maxIndex = i;
        }
    }

    return maxIndex;
}

template <class T> void sort_max(TemplatedMy_vec<T> &vec)
{
    TemplatedMy_vec<T> v2 = vec; // copy using overloaded operator

    // TemplatedMy_vec sortedVec;

    int count = 0;
    int maxIndex;

    // sorts from greatest to least
    while(!vec.is_empty())
    {
        maxIndex = find_max_index(vec, vec.get_size());
        v2[count] = vec[maxIndex];
        vec.remove_at_rank(maxIndex);
        count++;
    }

    //performs a swap to reverse the array to the correct order
    for(int i = 0; i < v2.get_size() / 2; i++)
    {
        T temp = v2[i];
        v2[i] = v2[v2.get_size() - 1 - i];
        v2[v2.get_size() - 1 - i] = temp;
    }

    vec = v2; // sends back the ordered vector

    // deallocates the old vectors to release memory
    v2.~TemplatedMy_vec();
    // sortedVec.~TemplatedMy_vec();
}

