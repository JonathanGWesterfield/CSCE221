//
// Created by Jonthan Westerfield on 8/2/17.
//
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include "myGraph.h"

using namespace std;

void myGraph::readInfo(std::string inputFile)
{
    cout << "Beginning readInfo() " << endl;
    ifstream ifs;
    ifs.open(inputFile);

    if(!ifs.is_open())
    {
        cout << "INPUT FILE COULD NOT BE OPENED" << endl;
        exit(EXIT_FAILURE);
    }

    // reads from the file
    int val_read = 0;
    n = 0; // counts the entries to get the size of the files
    for(int i = 0; !ifs.eof(); i++)
    {
        vector<int> row;
        for(int j = 0; (j < 4) && (!ifs.eof()); j++)
        {
            ifs >> val_read;
            row.push_back(val_read);
        }
        n++;
        inputInfo.push_back(row);
    }

    ifs.close();

    // prints out the input from the file
    for(int i = 0; i < inputInfo.size(); i++)
    {
        cout << i << ": ";
        for(int j = 0; j < inputInfo[i].size(); j++)
        {
            cout << inputInfo[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;

    // creates the adjMatrix and fills it with zeros
    for(int i = 0; i < n; i++)
    {
        vector<int> matRow;
        for(int j = 0; j < n; j++)
        {
            matRow.push_back(0);
        }
        adjMatrix.push_back(matRow);
    }


    // sets up the adjMatrix
    for(int i = 0; i < n; i++)
    {
        if(inputInfo[i][0] == 1)
        {
            adjMatrix[i][i - sqrt(n)] = 1;
        }
        if(inputInfo[i][1] == 1)
        {
            adjMatrix[i][i + 1] = 1;
        }
        if(inputInfo[i][2] == 1)
        {
            adjMatrix[i][i + sqrt(n)] = 1;
        }
        if(inputInfo[i][3] == 1)
        {
            adjMatrix[i][i - 1] = 1;
        }
    }

    for(int i = 0; i < adjMatrix.size(); i++)
    {
        for(int j = 0; j < adjMatrix[i].size(); j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;

    return;
}

void myGraph::setEmptyVisited()
{
    for(int i = 0; i < this->n; i++)
    {
        visited.push_back(0);
    }

}

void myGraph::depthFirstSearch(int i)
{
    int j;
    printf("\n%d",i);
    visited[i] = 1;

    for(j = 0; j < n; j++)
    {
        if(!visited[j] && adjMatrix[i][j] == 1)
        {
            depthFirstSearch(j);
        }
    }
}


