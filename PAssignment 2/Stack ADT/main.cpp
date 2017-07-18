#include <iostream>
#include "StackADT.h"

using namespace std;

vector<int> computeVectorSpan(vector<int> &x)
{
    // vector<int> x = {6, 3, 4, 5, 2};
    vector<int> s(x.size());

    int j = 1;
    for(int i = 0; i <= x.size(); i++)
    {
        j = 1;
        while (j <= i && (x[i-j] <= x[i]))
        {
            j= j + 1;
        }
        s[i] = j;
    }

    return s;
}


int main()
{
    vector<int> x = {6, 3, 4, 5, 2};
    vector<int> y = {1, 5, 8, 3, 7, 7, 2, 9, 5, 3, 5};
    vector<int> z = {1, 7, 3, 9, 6, 5, 9, 2, 5, 3, 7, 9, 1, 6, 3, 9};

    StackADT<int> stack;

    // computes using the span function above using loops
    vector<int> span1_1 = computeVectorSpan(x);
    vector<int> span1_2 = computeVectorSpan(y);
    vector<int> span1_3 = computeVectorSpan(z);

    // computes span using the stack span function
    vector<int> span2_1 = stack.computeStackSpan(x);
    vector<int> span2_2 = stack.computeStackSpan(y);
    vector<int> span2_3 = stack.computeStackSpan(z);

    cout << "Span using vector" << endl;
    cout << "Vector x: ";
    for(int i = 0; i < x.size(); i++) // prints out vector x
    {
        cout << x[i] << " ";
    }

    cout << endl;

    cout << "Span x:   ";
    for(int i = 0; i < span1_1.size(); i++) // prints out the span of x
    {
        cout << span1_1[i] << " ";
    }

    cout << endl << endl;

    cout << "Span using stack" << endl;
    cout << "Vector x: ";
    for(int i = 0; i < x.size(); i++) // prints out vector x
    {
        cout << x[i] << " ";
    }

    cout << endl;

    cout << "Span x:   ";
    for(int i = 0; i < span2_1.size(); i++) // prints out the span of x
    {
        cout << span2_1[i] << " ";
    }

    cout << endl << endl;

    cout << "Span using vector" << endl;
    cout << "Vector y: ";
    for(int i = 0; i < y.size(); i++) // prints out vector y
    {
        cout << y[i] << " ";
    }

    cout << endl;

    cout << "Span y:   ";
    for(int i = 0; i < span1_2.size(); i++) // prints out the span of y
    {
        cout << span1_2[i] << " ";
    }

    cout << endl << endl;

    cout << "Span using stack" << endl;
    cout << "Vector y: ";
    for(int i = 0; i < y.size(); i++) // prints out vector x
    {
        cout << y[i] << " ";
    }

    cout << endl;

    cout << "Span y:   ";
    for(int i = 0; i < span2_2.size(); i++) // prints out the span of x
    {
        cout << span2_2[i] << " ";
    }

    cout << endl << endl;

    cout << "Span using vector" << endl;
    cout << "Vector z: ";
    for(int i = 0; i < z.size(); i++) // prints out vector z
    {
        cout << z[i] << " ";
    }

    cout << endl;

    cout << "Span z:   ";
    for(int i = 0; i < span1_3.size(); i++) // prints out the span of z
    {
        cout << span1_3[i] << " ";
    }

    cout << endl << endl;

    cout << "Span using stack" << endl;
    cout << "Vector z: ";
    for(int i = 0; i < z.size(); i++) // prints out vector x
    {
        cout << z[i] << " ";
    }

    cout << endl;

    cout << "Span z:   ";
    for(int i = 0; i < span2_3.size(); i++) // prints out the span of x
    {
        cout << span2_3[i] << " ";
    }

    cout << endl << endl;

    return 0;
}