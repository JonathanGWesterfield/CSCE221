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
    int n; // represents the size of the graph

public:
    void readInfo(std::string inputFile);
    void depthFirstSearch(int i);
    void setEmptyVisited();

};


#endif //MAZE_MYGRAPH_H
