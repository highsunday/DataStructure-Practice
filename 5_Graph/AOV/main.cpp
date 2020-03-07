#include <iostream>
#include "AOV.h"
#include <vector>
using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    AOV graph(14);
    graph.incertEdge(0,2);
    graph.incertEdge(1,2);
    graph.incertEdge(2,7);
    graph.incertEdge(2,6);
    graph.incertEdge(3,4);
    graph.incertEdge(4,5);
    graph.incertEdge(5,6);
    graph.incertEdge(5,14);
    graph.incertEdge(6,8);
    graph.incertEdge(6,9);
    graph.incertEdge(6,11);
    graph.incertEdge(6,12);
    graph.incertEdge(7,8);
    graph.incertEdge(9,10);
    graph.incertEdge(12,13);
    graph.printList();
    graph.preProcess();
    graph.output_topologyOrder();
    return 0;
}
