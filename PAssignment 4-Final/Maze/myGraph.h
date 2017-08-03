//
// Created by Jonthan Westerfield on 8/2/17.
//

#ifndef MAZE_MYGRAPH_H
#define MAZE_MYGRAPH_H

#include <iostream>
#include <vector>

class myGraph
{
    std::vector<std::vector<int> > inputInfo;
    std::vector<std::vector<int> > adjMatrix;
    std::vector<int> visited;
    std::vector<int> pathRoomNumbers;
    int n; // represents the size of the graph
    int pathLength = 0;

public:
    void readInfo(std::string inputFile);
    bool depthFirstSearch(int i);
    void setEmptyVisited();
    void printAdjList();
    void printPathLength();
    void printPath();

};


#endif //MAZE_MYGRAPH_H
