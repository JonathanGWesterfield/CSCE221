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

    // outputs the input file data to an ouptut file
    output.open(outputFilename);
    if(output.is_open())
    {
        cout << "Writing to output files " << endl;
        // prints out the input from the file
        for(int i = 0; i < inputInfo.size(); i++)
        {
            output << i << ": ";
            for(int j = 0; j < inputInfo[i].size(); j++)
            {
                output << inputInfo[i][j] << " ";
            }
            output << endl;
        }
        output << endl << endl;
    }
    else
    {
        cout << endl << "OUTPUT FILE COULD NOT BE OPENED" << endl;
        cout << "Function: readInfo()" << endl;
        exit(EXIT_FAILURE);
    }


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


    /*// prints out the Adjacency matrix
    for(int i = 0; i < adjMatrix.size(); i++)
    {
        for(int j = 0; j < adjMatrix[i].size(); j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << "Finished readInfo()" << endl;
    cout << endl << endl;*/

    // prints the adjacency list to the output
    if(output.is_open())
    {
        output << "Adjacency Matrix: " << endl << endl;
        for(int i = 0; i < adjMatrix.size(); i++)
        {
            for(int j = 0; j < adjMatrix[i].size(); j++)
            {
                output << adjMatrix[i][j] << " ";
            }
            output << endl;
        }
        output << endl << endl;
    }
    else
    {
        cout << endl << "OUTPUT FILE COULD NOT BE OPENED" << endl;
        cout << "Function: readInfo()" << endl;
        exit(EXIT_FAILURE);
    }


    return;
}

void myGraph::setEmptyVisited()
{
    for(int i = 0; i < this->n; i++)
    {
        visited.push_back(0);
    }
    return;
}

bool myGraph::depthFirstSearch(int i)
{
    // gives the length of the path that it finds
    ++pathLength; // counts the number of times this runs
    int j;
    pathRoomNumbers.push_back(i);
    visited[i] = 1;
    printf("\n%d",i);

    if(i == n - 1)
    {
        return true; // means the end of the maze was found
    }

    bool found = false;
    for(j = 0; j < n; j++)
    {
        if(!visited[j] && adjMatrix[i][j] == 1)
        {
            if(depthFirstSearch(j))
            {
                found = true;
                return found;
            }
        }
    }

    if(!found)
    {
        pathRoomNumbers.pop_back();
    }

    return found;
}

void myGraph::printMaze()
{
    cout << "Attempting to print the maze" << endl << endl;
    // initializes the maze with "empty" X elements
    for(int i = 0; i < sqrt(n); i++)
    {
        vector<char> row;
        for(int j = 0; j < sqrt(n); j++)
        {
            row.push_back('X');
        }
        charMaze.push_back(row);
    }

    // determines the path through the maze
    int tracker = 0;
    for(int i = 0; i < sqrt(n); i++)
    {
        vector<char> row;
        for(int j = 0; j < sqrt(n); j++)
        {
            if(isFoundFromPath(tracker))
                charMaze[i][j] = 'O';
            tracker++;
        }
    }

    // prints out the text maze
    for(int i = 0; i < sqrt(n); i++)
    {
        for(int j = 0; j < sqrt(n); j++)
        {
            cout << charMaze[i][j] << " ";
        }
        cout << endl;
    }

    if(output.is_open())
    {
        output << "Solved Maze: " << endl << endl;
        // prints to output file
        for(int i = 0; i < sqrt(n); i++)
        {
            for(int j = 0; j < sqrt(n); j++)
            {
                output << charMaze[i][j] << " ";
            }
            output << endl;
        }
        output << endl << endl << endl;
    }
    else
    {
        cout << endl << "OUTPUT FILE COULD NOT BE OPENED" << endl;
        cout << "Function: printMaze()" << endl;
        exit(EXIT_FAILURE);
    }

    return;
}

bool myGraph::isFoundFromPath(int tracker)
{
    for(int i = 0; i < pathRoomNumbers.size(); i++)
    {
        if(tracker == pathRoomNumbers[i])
            return true;
    }

    return false;
}

void myGraph::outputInfo()
{
    // prints the path and its length to the output file
    if(output.is_open())
    {
        output << "All room numbers of the entry-exit path: " << endl;
        for(int i = 0; i < pathRoomNumbers.size(); i++)
        {
            output << pathRoomNumbers.at(i) << " ";
        }
        output << endl << endl << endl;

        output << "Path length: " << pathRoomNumbers.size() << endl << endl << endl;
    }
}

void myGraph::printAdjMatrix()
{
    // prints out the Adjacency matrix
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

void myGraph::printPathLength()
{
    cout << "Entry-exit path length: " << pathRoomNumbers.size() << endl << endl << endl;
    return;
}

void myGraph::printPath()
{
    cout << "All room numbers of the entry-exit path: " << endl;
    for(int i = 0; i < pathRoomNumbers.size(); i++)
    {
        cout << pathRoomNumbers.at(i) << " ";
    }
    cout << endl << endl << endl;
}


