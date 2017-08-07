//
// Created by Jonthan Westerfield on 8/2/17.
//

#ifndef MAZE_MYGRAPH_H
#define MAZE_MYGRAPH_H

#include <iostream>
#include <fstream>>
#include <vector>

class myGraph
{
    std::string outputFilename = "MazeOutput.txt";
    std::ofstream output;
    std::vector<std::vector<int> > inputInfo;
    std::vector<std::vector<int> > adjMatrix;
    std::vector<int> visited;
    std::vector<int> pathRoomNumbers;
    std::vector<std::vector<char>> charMaze;
    int n; // represents the size of the graph
    int pathLength = 0;

public:
    void readInfo(std::string inputFile);
    bool depthFirstSearch(int i);
    void setEmptyVisited();
    void printMaze();
    bool isFoundFromPath(int tracker);
    void printAdjMatrix();
    void printPathLength();
    void printPath();
    void outputInfo();

};


#endif //MAZE_MYGRAPH_H
