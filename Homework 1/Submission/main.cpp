#include <iostream>
#include <vector>

using namespace std;

int count = 0;
int binSearch(vector<int> L, int k, int low, int high, int& count, bool isAscending)
{
    if(isAscending)
    {
        count++;
        int midPos = 0;
        int e = 0;
        // while(midPos != k)
        if (low > high)
        {
            return -9999;
        }
        else
        {
            midPos = (low + high) / 2;
            e = L.at(midPos);
            if (k == e)
            {
                return e;
            }
            else if (k < e)
            {
                return binSearch(L, k, low, midPos - 1, count, true);
            }
            else
            {
                return binSearch(L, k, midPos + 1, high, count, true);
            }
        }
    }
    else
    {
        count++;
        int midPos = 0;
        int e = 0;
        // while(midPos != k)
        if(low > high)
        {
            return -9999;
        }
        else
        {
            midPos = (low + high) / 2;
            e = L.at(midPos);
            if(k == e)
            {
                return e;
            }
            else if(k < e)
            {
                return binSearch(L, k, midPos + 1, high, count, false);

            }
            else
            {
                return binSearch(L, k, low, midPos - 1, count, false);
            }
        }
    }

}

int main() {

    try
    {
        vector<int> ascSearchVec = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
        vector<int> ascVec;
        vector<int> descSearchVec = {2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
        vector<int> descVec;

        for(int i = 1; i <= 2047; i++)
        {
            ascVec.push_back(i);
        }

        for(int i = 15; i > 0; i--)
        {
            descVec.push_back(i);
        }


        int count = 0;

        int searchNumber = 2047;
        int searchFound = binSearch(ascVec, searchNumber, 0, ascVec.size() - 1, count, true);

        cout << "The number " << searchNumber << " was looked for " << endl;
        cout << "The Result " << searchFound << " was located" << endl;
        cout << "The search ran for " << count << " times!" << endl;
        return 0;
    }
    catch(exception &e)
    {
        cerr << e.what() << endl;
    }
}

