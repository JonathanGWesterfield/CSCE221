// main.cpp
//Tests all functionality of the My_vec class.

#include <iostream>
#include <stdexcept>
#include "TemplatedMy_vec.h"
//#include "My_vec.h"

int main(){

// Some test cases are expected to throw an exception.
// Add more try and catch blocks as necessary for your code to finish execution.

    try{

        // define an object v of My_vec type
        // insert 'B' at the rank 0 into the vector v
        // use the overloaded operator << to display vector elements
        // display the vector v size

        TemplatedMy_vec<double> Templated_v;
        Templated_v.insert_at_rank(0, 2.33);
        cout << "Templated_v after inserted 2.33 at 0: " << endl;
        cout << Templated_v << endl;
        cout << "Templated_v size: " << Templated_v.get_size()  << endl << endl;

        // insert 'A' at the rank 0  to the vector v
        // use the overloaded operator << to display vector elements
        // display the vector v size

        Templated_v.insert_at_rank(0, 5.66);
        cout << "Templated_v after inserted 5.66 at 0: " << endl;
        cout << Templated_v << endl;
        cout << "Vector Templated_v size: " << Templated_v.get_size()  << endl << endl;

        // insert 'D' at the rank 10 into the vector v
        // use the overloaded operator << to display vector elements
        // display the vector v size

        Templated_v.insert_at_rank(10, 3.412);
        cout << "Templated_v after inserted 3.412 at rank 10: " << endl;
        cout << Templated_v << endl;
        cout << "Vector Templated_v size: " << Templated_v.get_size()  << endl << endl;

        // remove a character at the rank 1 from the vector v
        // use the overloaded operator << to display vector elements
        // display the vector v size

        Templated_v.remove_at_rank(1);
        cout << "Templated_v after removing from rank 1: " << endl;
        cout << Templated_v << endl;
        cout << "Templated_vector v size: " << Templated_v.get_size()  << endl << endl;

        // replace a character at the rank 0 by the character 'E'
        // use the overloaded operator << to display vector elements
        // display the vector v size

        Templated_v.replace_at_rank(0, 6.5432);
        cout << "Templated_v after replace at rank 0 with 6.5432: " << endl;
        cout << Templated_v << endl;
        cout << "Vector Templated_v size: " << Templated_v.get_size()  << endl << endl;

        // create a copy v1 of the vector v using a copy constructor
        // use the overloaded operator << to display the vector v1
        // replace a character at the rank 2 of the vector v1 with the character 'Y'
        // use the overloaded operator << to display vector v1 elements

        TemplatedMy_vec<double> Templated_v1 = Templated_v;
        cout << Templated_v1 << endl;
        Templated_v1.replace_at_rank(2, 9.212);
        cout << "Templated_v1 after copied from Templated_v and 9.212 inserted at rank 2: " << endl;
        cout << "New: " << Templated_v1  << endl << endl;

        // define an object v2 of My_vec type
        // insert 'K' at the rank 0 into the vector v2
        // use the overloaded operator << to display vector elements
        // display the vector v2 size

        TemplatedMy_vec<double> Templated_v2;
        Templated_v2.insert_at_rank(0, 5.1313);
        cout << "Templated_v2 after inserting 5.1313 at 0: " << endl;
        cout << "Templated_v2: " << Templated_v2 << endl;
        cout << "Vector Templated_v2 size: " << Templated_v2.get_size()  << endl << endl;

        // test the assignment operator and copy the vector v1 to v2
        // Set v2 to '1','2','3','4','5'
        // use the overloaded operator << to display vector v2
        // display the vector v2 size

        Templated_v2 = Templated_v1;
        cout << "Templated_v2 after copy assignment: " << endl;
        cout << "Templated_v2: " << Templated_v2 << endl;
        cout << "Vector Templated_v2 size: " << Templated_v2.get_size() << endl << endl;


        TemplatedMy_vec<double> Templated_v3;
        Templated_v3.insert_at_rank(0, 6.4545);
        Templated_v3.insert_at_rank(1, 121.222);
        Templated_v3.insert_at_rank(2, 16.0);
        Templated_v3.insert_at_rank(3, 3.1415);
        Templated_v3.insert_at_rank(4, 3.1425);

        cout << "Templated_v3: after set to 6.4545, 121.222, 16.0, 3.1415, 3.1425: " << endl;
        cout << Templated_v3 << endl;
        cout << "Vector Templated_v3 size: " << Templated_v3.get_size()  << endl << endl;

        // test the function find_max_index using v2
        // test the function sort_max using v2

        int maxIndex = find_max_index(Templated_v3, Templated_v3.get_size());
        cout << "The index with the largest character is: " << maxIndex << endl << endl;

        sort_max(Templated_v3); // calls the function to sort the vector
        cout << "Templated_v3 sorted from least to greatest: "  << endl << endl;
        cout << Templated_v3 << endl;

        // replace in the vector v2 a character at the rank 14 with 'S'

        Templated_v2.replace_at_rank(14, 5.44444444);
        cout << "Templated_v3 after replaced at rank 14 with 5.44444444: " << endl;
        cout << Templated_v3 << endl << endl;

    }

    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
}
