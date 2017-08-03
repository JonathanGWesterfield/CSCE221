#include <iostream>
#include "GenerateMaze.h"
#include "myGraph.h"

int main()
{
    myGraph graph;
    graph.readInfo("/Users/jonathanw/Desktop/CSCE221/PAssignment 4-Final/Maze/mazeInput.txt");
    graph.setEmptyVisited();
    graph.depthFirstSearch(0);

}