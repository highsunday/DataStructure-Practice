#include <iostream>
#include "FloydWarshall.h"
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    FloydWarshall  graph(6);
    graph.incertEdge(0,1,10);
    graph.incertEdge(0,5,8);
    graph.incertEdge(1,3,2);
    graph.incertEdge(2,1,1);
    graph.incertEdge(3,2,-2);
    graph.incertEdge(4,1,-4);
    graph.incertEdge(4,3,-1);
    graph.incertEdge(5,4,1);
    graph.process_costMatrix();
    //graph.printMatrix();
    graph.All_Pair_ShortestPath();
    return 0;
}
