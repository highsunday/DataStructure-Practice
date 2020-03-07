//
// Created by VGH00 on 2019/12/4.
//

#ifndef FLOYDWARSHALL_FLOYDWARSHALL_H
#define FLOYDWARSHALL_FLOYDWARSHALL_H
#include "Adj_Matrix.h"
using namespace std;
class FloydWarshall:public AdjMatrix
{
public:
    vector<vector<int>> costMatrix;
    FloydWarshall(int _nodeSize): AdjMatrix(_nodeSize) {
    };
    void process_costMatrix()
    {
        for(int i=0;i<nodeSize;i++)
        {
            vector<int> temp;
            for(int j=0;j<nodeSize;j++)
            {
                if(i!=j&&Matrix[i][j]==0)
                    temp.push_back(INT32_MAX);
                else
                    temp.push_back(Matrix[i][j]);
            }
            costMatrix.push_back(temp);
        }
    }
    void printMatrix()
    {
        cout<<"print Matrix:"<<endl;
        for(int i=0;i<nodeSize;i++)
        {
            for(int j=0;j<nodeSize;j++)
            {
                cout<<costMatrix[i][j]<<",";
            }cout<<endl;
        }
    }

    void All_Pair_ShortestPath()
    {
        for(int round=0;round<nodeSize;round++)
        {
            for(int i=0;i<nodeSize;i++)
            {
                for(int j=0;j<nodeSize;j++)
                {
                    if(i!=round && j!=round)
                    {
                        if(costMatrix[i][round]!=INT32_MAX && costMatrix[round][j]!=INT32_MAX)
                        {
                            if(costMatrix[i][j]>costMatrix[i][round]+costMatrix[round][j])
                            {
                                costMatrix[i][j]=costMatrix[i][round]+costMatrix[round][j];
                            }
                        }
                    }
                }
            }
        }
        cout<<"all pair shortest path:"<<endl;
        printMatrix();
    }
};
#endif //FLOYDWARSHALL_FLOYDWARSHALL_H
