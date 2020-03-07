//
// Created by VGH00 on 2019/12/4.
//

//
// Created by 高昊 on 2019/11/25.
//

#include "Adj_Matrix.h"

AdjMatrix::AdjMatrix(int _nodeSize)
{
    nodeSize=_nodeSize;
    edgeSize=0;
    for(int i=0;i<nodeSize;i++)
    {
        vector<int> temp(nodeSize,0);
        Matrix.push_back(temp);
    }
}

void AdjMatrix::printMatrix()
{
    cout<<"print Matrix:"<<endl;
    for(int i=0;i<nodeSize;i++)
    {
        for(int j=0;j<nodeSize;j++)
        {
            cout<<Matrix[i][j]<<",";
        }cout<<endl;
    }
}

void AdjMatrix::incertEdge(int index1, int index2)
{
    if(index1>=nodeSize||index2>=nodeSize)
    {
        cout<<"error : index is too high"<<endl;
        throw "error : index is too high";
    }

    if(Matrix[index1][index2]==0)
    {
        edgeSize++;
    }
    Matrix[index1][index2]=1;
}

void AdjMatrix::incertEdge(int index1, int index2, int weight)
{
    if(index1>=nodeSize||index2>=nodeSize)
    {
        cout<<"error : index is too high"<<endl;
        throw "error : index is too high";
    }

    if(Matrix[index1][index2]==0)
    {
        edgeSize++;
    }
    Matrix[index1][index2]=weight;

}

void AdjMatrix::deleteEdge(int index1, int index2)
{
    if(index1>=nodeSize||index2>=nodeSize)
    {
        cout<<"error : index is too high"<<endl;
        throw "error : index is too high";
    }

    if(Matrix[index1][index2]==1)
    {
        edgeSize--;
    }
    Matrix[index1][index2]=0;
}

bool AdjMatrix::isEmpty()
{
    if(nodeSize==0)
        return true;
    else
        return false;
}

bool AdjMatrix::existEdge(int index1, int index2)
{
    if(index1>=nodeSize||index2>=nodeSize)
    {
        cout<<"error : index is too high"<<endl;
        throw "error : index is too high";
    }

    if(Matrix[index1][index2]==1)
        return true;
    else
        return false;
}

int AdjMatrix::retDegree(int index)
{
    if(index>=nodeSize)
    {
        cout<<"error : index is too high"<<endl;
        throw "error : index is too high";
    }

    int res=0;
    for(int i=0;i<nodeSize;i++)
    {
        if(Matrix[index][i]==1)
            res++;
    }
    return res;
}
