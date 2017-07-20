#include <iostream>

using namespace std;

int maxNum(int x[], int lowIndex, int highIndex)
{
    if (lowIndex == highIndex)
    {
        return x[lowIndex];
    }
    if(lowIndex < highIndex)
    {
        if(x[lowIndex] < x[highIndex])
        {
            return maxNum(x, lowIndex + 1, highIndex);
        }
        return maxNum(x, lowIndex, highIndex - 1);
    }
}

int main() {
    int x[] = {1, 6, 8, 4, 8, 3, 2, 3};
    cout << maxNum(x, 0, 7) << endl;
    return 0;
}