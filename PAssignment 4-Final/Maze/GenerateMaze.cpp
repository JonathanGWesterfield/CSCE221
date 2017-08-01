//
// Created by Jonthan Westerfield on 7/31/17.
//

#include "GenerateMaze.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <ctime>

GenerateMaze::GenerateMaze()
{
    cout << "Default constructor called" << endl;
}

GenerateMaze::GenerateMaze(int size)
{
    this -> mazeSize = size;
    // setEmptyMaze();
    setMaze();
    cout << "setMaze Function complete" << endl;
    if(maze.size() == 0)
        cout << "Maze empty" << endl;
    else
        outputMaze();
}

GenerateMaze::~GenerateMaze() {} // destructor

void GenerateMaze::setEmptyMaze()
{
    vector<vector<mazeNode>> tempMaze(mazeSize, vector<mazeNode>(mazeSize, mazeNode()));
    maze = tempMaze;
}

void GenerateMaze::setMaze()
{
    cerr << "Maze size: " << mazeSize << endl;
    for (int i = 0; i < mazeSize; i++)
    {
        vector<mazeNode> row;
        cout << "row has been created " << i << " time(s)" << endl;
        for (int j = 0; j < mazeSize; j++)
        {
            cout << "new mazeNode will be created at " << i << " " << j << endl;
            mazeNode node = mazeNode();
            cout << "new mazeNode has been created at " << i << " " << j << endl;
            row.push_back(node);
            cout << "new mazeNode has been inserted at " << i << " " << j << endl << endl;
        }
        maze.push_back(row);
        cout << "row has been inserted into maze " << i << " time(s)" << endl << endl;
    }
    return;

}

void GenerateMaze::outputMaze()
{
    cout << "Starting the output function" << endl;
    for(int i = 0; i < mazeSize; i++)
    {
        for(int j = 0; j < mazeSize; j++)
        {
            cout << maze[i][j].north << " " << maze[i][j].east << " " << maze[i][j].south <<
                 " " << maze[i][j].north << endl;
        }
    }
}

ostream& operator<<(ostream& out, const mazeNode& node) // output operator for the mazeNode class
{
    out << node.north << " " << node.east << " " << node.south << " " << node.west;
}