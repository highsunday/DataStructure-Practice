//
// Created by VGH00 on 2019/12/4.
//

#ifndef FLOYDWARSHALL_ADJ_MATRIX_H
#define FLOYDWARSHALL_ADJ_MATRIX_H
#include <iostream>
#include <vector>
using namespace std;
//優點:容易實做
//適合用於已知node個數,node數不會再增減的情況
//否則難以實作
class AdjMatrix
{
protected:
    int nodeSize;
    int edgeSize;
    vector<vector<int>> Matrix;

public:
    AdjMatrix(int _nodeSize);
    //void incertVertex(int val);
    void incertEdge(int index1, int index2);
    void incertEdge(int index1, int index2,int weight);
    //void deleteVertex(int val);//*
    void deleteEdge(int index1, int index2);//*
    bool isEmpty();
    bool existEdge(int index1, int index2);
    int retDegree(int index);
    void printMatrix();//*
};
#endif //FLOYDWARSHALL_ADJ_MATRIX_H
