#include <iostream>
#include "Adj_Matrix.h"
//#include "Adj_List.h"
#include "Adj_MultiList.h"
using namespace std;

int main() {
    /*
    cout << "Adj Matrix!" << std::endl;
    AdjMatrix M1(7);
    M1.printMatrix();
    M1.incertEdge(0, 1);
    M1.incertEdge(0, 2);
    M1.incertEdge(0, 3);
    M1.incertEdge(1, 3);
    M1.incertEdge(1, 4);
    M1.incertEdge(2, 5);
    M1.incertEdge(3, 2);
    M1.incertEdge(3, 5);
    M1.incertEdge(3, 6);
    M1.incertEdge(4, 3);
    M1.incertEdge(4, 6);
    M1.incertEdge(6, 5);
    M1.printMatrix();
    cout<<"0 degree : "<<M1.retDegree(0)<<endl;
    cout<<"3 degree : "<<M1.retDegree(3)<<endl;
    cout<<"5 degree : "<<M1.retDegree(5)<<endl;
     */

 /*
    cout << "Adj List!" << std::endl;
    AdjList L1(5);
    L1.incertEdge(0,1);
    L1.incertEdge(0,3);
    L1.incertEdge(0,2);
    L1.incertEdge(1,3);
    L1.incertEdge(2,4);
    L1.incertEdge(2,1);
    L1.incertEdge(3,2);
    L1.incertEdge(3,4);
    L1.printList();
    //L1.deleteEdge(1,3);
    //L1.printList();
    if(L1.existEdge(1,3))
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    cout<<"1 degree :"<<L1.retDegree(1)<<endl;
    cout<<"0 degree :"<<L1.retDegree(0)<<endl;
    cout<<"4 degree :"<<L1.retDegree(4)<<endl;
    */

    cout<<"Adj Multi List!" << std::endl;
    AdjMultiList graph1(4);
    graph1.insertEdge(0,1);
    graph1.insertEdge(0,2);
    graph1.insertEdge(0,3);
    graph1.insertEdge(1,2);
    graph1.insertEdge(1,3);
    graph1.insertEdge(2,3);

    graph1.deleteEdge(0,2);
    graph1.deleteEdge(1,3);
    graph1.printMultiList();

    return 0;
}
