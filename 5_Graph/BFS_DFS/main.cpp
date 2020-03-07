#include <iostream>
#include <vector>
#include <deque>
#include "Adj_List.h"
#include "DFS_or_BFS.h"
using namespace std;


int main () {
    //cout<<"scscsc"<<endl;
    AdjList_DFS_or_BFS L1(8);
    L1.incertEdge(1,2);
    L1.incertEdge(1,3);
    L1.incertEdge(1,4);
    L1.incertEdge(2,4);
    L1.incertEdge(2,5);
    L1.incertEdge(3,6);
    L1.incertEdge(4,3);
    L1.incertEdge(4,7);
    L1.incertEdge(5,4);
    L1.incertEdge(5,7);
    L1.incertEdge(7,6);
    L1.printList();
    L1.DFS_start(1);
    //L1.BFS_start(0);
    return 0;
}