// main.cpp
//Tests all functionality of the My_vec class.

#include <iostream>
#include <stdexcept>
#include "My_vec.h"

int main(){

// Some test cases are expected to throw an exception.
// Add more try and catch blocks as necessary for your code to finish execution.

    try{

        // define an object v of My_vec type
        // insert 'B' at the rank 0 into the vector v
        // use the overloaded operator << to display vector elements
        // display the vector v size

        My_vec v;
        v.insert_at_rank(0, 'B');
        cout << "v after inserted 'B' at 0: " << endl;
        cout << v << endl;
        cout << "Vector v size: " << v.get_size() << endl;

        // insert 'A' at the rank 0  to the vector v
        // use the overloaded operator << to display vector elements
        // display the vector v size

        v.insert_at_rank(0, 'A');
        cout << "v after inserted 'A' at 0: " << endl;
        cout << v << endl;
        cout << "Vector v size: " << v.get_size() << endl;

        // insert 'D' at the rank 10 into the vector v
        // use the overloaded operator << to display vector elements
        // display the vector v size

        v.insert_at_rank(10, 'D');
        cout << "v after inserted 'D' at rank 10: " << endl;
        cout << v << endl;
        cout << "Vector v size: " << v.get_size() << endl;

        v.insert_at_rank(8, 'D');
        cout << "v after inserted 'D' at rank 8: " << endl;
        cout << v << endl;
        cout << "Vector v size: " << v.get_size() << endl;

        // remove a character at the rank 1 from the vector v
        // use the overloaded operator << to display vector elements
        // display the vector v size

        v.remove_at_rank(1);
        cout << "v after removing from rank 1: " << endl;
        cout << v << endl;
        cout << "Vector v size: " << v.get_size() << endl;

        // replace a character at the rank 0 by the character 'E'
        // use the overloaded operator << to display vector elements
        // display the vector v size

        v.replace_at_rank(0, 'E');
        cout << "v after replace at rank 0 with 'E': " << endl;
        cout << v << endl;
        cout << "Vector v size: " << v.get_size() << endl;

        // create a copy v1 of the vector v using a copy constructor
        // use the overloaded operator << to display the vector v1
        // replace a character at the rank 2 of the vector v1 with the character 'Y'
        // use the overloaded operator << to display vector v1 elements

        My_vec v1 = v;
        cout << v1 << endl;
        v1.replace_at_rank(2, 'Y');
        cout << "v1 after copied from v and 'Y' inserted at rank 2: " << endl;
        cout << "New: " << v1 << endl;

        // define an object v2 of My_vec type
        // insert 'K' at the rank 0 into the vector v2
        // use the overloaded operator << to display vector elements
        // display the vector v2 size

        My_vec v2;
        v2.insert_at_rank(0, 'K');
        cout << "V2 after inserting 'K' at 0: " << endl;
        cout << "V2: " << v2 << endl;
        cout << "Vector v2 size: " << v2.get_size() << endl;

        // test the assignment operator and copy the vector v1 to v2
        // Set v2 to '1','2','3','4','5'
        // use the overloaded operator << to display vector v2
        // display the vector v2 size

        v2 = v1;
        cout << "V2 after copy assignment: " << endl;
        cout << "V2: " << v2 << endl;
        cout << "Vector v2 size: " << v2.get_size() << endl << endl;


        My_vec v3;
        v3.insert_at_rank(0, '1');
        v3.insert_at_rank(1, '2');
        v3.insert_at_rank(2, '3');
        v3.insert_at_rank(3, '4');
        v3.insert_at_rank(4, '5');

        cout << "V3: after set to 1, 2, 3, 4, 5: " << endl;
        cout << v3 << endl;
        cout << "Vector v3 size: " << v3.get_size() << endl;

        // test the function find_max_index using v2
        // test the function sort_max using v2

        int maxIndex = find_max_index(v3, v3.get_size());
        cout << "The index with the largest character is: " << maxIndex << endl << endl;

        sort_max(v3); // calls the function to sort the vector
        cout << "V3 sorted from greatest to least: " << endl;
        cout << v3 << endl;

        // replace in the vector v2 a character at the rank 14 with 'S'

        v2.replace_at_rank(14, 'S');
        cout << "v3 after replaced at rank 14 with 'S': " << endl;
        cout << v3 << endl;

    }

    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
}
