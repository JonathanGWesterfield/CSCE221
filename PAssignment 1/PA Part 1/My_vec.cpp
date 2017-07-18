//
// Created by Jonthan Westerfield on 7/6/17.
//

#include <stdio.h>
#include <iostream>
#include "My_vec.h"

using namespace std;

// class constructor
My_vec::My_vec()
{
    size = 0;
    capacity = 10;
    ptr = new char[capacity];

    return;
}

//copy constructor
My_vec::My_vec(const My_vec &vec)
{
    cout << "Copy Constructor Called" << endl;
    this -> size = vec.size;
    this -> capacity = vec.capacity;
    this -> ptr = new char[vec.capacity];

    for(int i = 0; i < capacity; i++)
    {
        ptr[i] = vec.ptr[i];
    }
}

// copy assignment. '=' operator overload
// will allow a vector to be copied with oly the equals sign
My_vec& My_vec::operator=(const My_vec& vec)
{
    delete[] ptr;  // deletes the information at the old address
    size = vec.size;
    capacity = vec.capacity;
    ptr = new char[vec.capacity];
    for(int i = 0; i < size ; i++)
    {
        ptr[i] = vec.ptr[i];
    }

    return *this; // return reference
}

char& My_vec::operator[](int r) const
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

char& My_vec::operator[](int r)
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
My_vec::~My_vec()
{
    delete ptr;
    ptr = NULL;
}


// gets the size of the vector from the 'size' data member
int My_vec::get_size() const
{
    return size;
}

// determines if the vector is empty
bool My_vec::is_empty() const
{
    return size == 0;
}

// this is good
char& My_vec::elem_at_rank(int r) const
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
void My_vec::replace_at_rank(int r, const char &elem)
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
void My_vec::insert_at_rank(int r, const char &elem)
{
    int oldCapacity = capacity;
    int initial_size = size;
    if(r < 0 || r >= capacity)
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
    else
    {
        size = r + 1;
    }

    if (size > capacity)
    {
        int newCapacity = capacity * 2;
        char* newVec = new char[newCapacity];

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
        ptr[i] = '_';
    }
    ptr[r] = elem;

    return;
}


// removes element at index - works
void My_vec::remove_at_rank(int r)
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
ostream& operator<<(ostream& out, const My_vec& vec)
{
    for(int i = 0; i < vec.get_size(); i++)
    {
        // cout << vec.elem_at_rank(i);
        out << vec.elem_at_rank(i) << ' ';
    }

    cout << endl;

    return out;
}

// this works
int find_max_index(const My_vec& v,int size)
{
    if(v.is_empty())
    {
        cerr << "Error: Vector is empty"  << endl << endl;
        cerr << "find_max_index" << endl;
        return -1; // returns -1 to indicate that there was an error. Can't have index of -1
        // exit(EXIT_FAILURE);
    }
    char max = v[0]; // using the overloaded [] operator
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

void sort_max(My_vec &vec)
{
    My_vec v2 = vec; // copy using overloaded operator

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

    // performs a swap to reverse the vector into the correct order
    for(int i = 0; i < v2.get_size() / 2; i++)
    {
        char temp = v2[i];
        v2[i] = v2[v2.get_size() - 1 - i];
        v2[v2.get_size() - 1 - i] = temp;
    }

    vec = v2; // sends back the ordered vector

    // deallocates the old vectors to release memory
    v2.~My_vec();
}

