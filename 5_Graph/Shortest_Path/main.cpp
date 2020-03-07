#include <iostream>
#include "ShortestPath.h"
using namespace std;
//Dijkstra and Bellman Ford Algorithm
int main() {
    std::cout << "Hello, World!" << std::endl;
    ShortestPath graph1(6);
    graph1.incertEdge(0,1,10);
    graph1.incertEdge(0,5,8);
    graph1.incertEdge(1,3,2);
    graph1.incertEdge(2,1,1);
    graph1.incertEdge(3,2,-2);
    graph1.incertEdge(4,1,-4);
    graph1.incertEdge(4,3,-1);
    graph1.incertEdge(5,4,1);
    graph1.printList_Weight();
    //graph1.Dijkstra(4);
    graph1.Bellman_Ford(0);
    return 0;
}
