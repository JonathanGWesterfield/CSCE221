//
// Created by Jonthan Westerfield on 7/31/17.
//

#ifndef MAZE_GENERATEMAZE_H
#define MAZE_GENERATEMAZE_H

#endif //MAZE_GENERATEMAZE_H

#include <iostream>
#include <vector>

using namespace std;

struct mazeNode
{
    int north, south, east, west;
    mazeNode()
    {
        north = generateRand();
        south = generateRand();
        east = generateRand();
        west = generateRand();

        if((north == 0) && (south == 0) && (east == 0) && (west == 0))
        {
            south = 1; // to make sure a node isn't inaccessible
        }
    }

    int generateRand()
    {
        return rand() % 2;
    }
};

ostream& operator<<(ostream& out, const mazeNode& maze);




class GenerateMaze
{
private:
    vector<vector<mazeNode> > maze;
    int mazeSize;

public:
    GenerateMaze();
    GenerateMaze(int size);
    ~GenerateMaze();
    vector<vector<mazeNode> > getMaze() const
    {
        return maze;
    }
    void setEmptyMaze(); // size 4 gives 4^2=16
    void setMaze();
    void outputMaze();
};
