#include <iostream>
#include "Adj_List.h"
#include "MST.h"
using  namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    AdjList_MST graph1(7);
    graph1.incertEdge(0,1,28);graph1.incertEdge(1,0,28);
    graph1.incertEdge(0,5,10);graph1.incertEdge(5,0,10);
    graph1.incertEdge(1,2,16);graph1.incertEdge(2,1,16);
    graph1.incertEdge(1,6,14);graph1.incertEdge(6,1,14);
    graph1.incertEdge(2,3,12);graph1.incertEdge(3,2,12);
    graph1.incertEdge(3,4,22);graph1.incertEdge(4,3,22);
    graph1.incertEdge(3,6,18);graph1.incertEdge(6,3,18);
    graph1.incertEdge(4,5,25);graph1.incertEdge(5,4,25);
    graph1.incertEdge(4,6,24);graph1.incertEdge(6,4,24);

    /*AdjList_MST graph1(9);
    graph1.incertEdge(1,2,3);graph1.incertEdge(2,1,3);
    graph1.incertEdge(1,3,5);graph1.incertEdge(3,1,5);
    graph1.incertEdge(2,4,4);graph1.incertEdge(4,2,4);
    graph1.incertEdge(3,4,12);graph1.incertEdge(4,3,12);
    graph1.incertEdge(4,5,9);graph1.incertEdge(5,4,9);
    graph1.incertEdge(4,8,8);graph1.incertEdge(8,4,8);
    graph1.incertEdge(5,6,4);graph1.incertEdge(6,5,4);
    graph1.incertEdge(5,7,5);graph1.incertEdge(7,5,5);
    graph1.incertEdge(5,8,1);graph1.incertEdge(8,5,1);
    graph1.incertEdge(6,7,6);graph1.incertEdge(7,6,6);
    graph1.incertEdge(7,8,20);graph1.incertEdge(8,7,20);*/
    graph1.printList_Weight();
    //graph1.MST_Kruskal();
    graph1.MST_Prim(0);
    return 0;
}