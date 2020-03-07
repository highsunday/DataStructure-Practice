//
//  sparseMatrix.cpp
//  SparseMatrix_SimpleTranpose
//
//  Created by 高昊 on 2019/10/6.
//  Copyright © 2019年 高昊. All rights reserved.
//

#include "sparseMatrix.hpp"
using namespace std;

sparseMatrix::sparseMatrix(vector<vector<int>> v_2d)
{
    setMatrix(v_2d);
}

sparseMatrix::sparseMatrix()
{
    colSize=0;
    RowSize=0;
}

void sparseMatrix::setMatrix(vector<vector<int>> v_2d)
{
    colSize=v_2d[0].size();
    RowSize=v_2d.size();
    for(int i=0;i<v_2d.size();i++)
    {
        for(int j=0;j<v_2d[0].size();j++)
        {
            //cout<<v_2d[i][j]<<",";
            if(v_2d[i][j]!=0)
            {
                traple temp;
                temp.col=j;
                temp.row=i;
                temp.val=v_2d[i][j];
                MatricElement.push_back(temp);
            }
        }//cout<<endl;
    }
    printElementList();
}

void sparseMatrix::printElementList()
{
    for(int i=0;i<MatricElement.size();i++)
    {
        cout<<MatricElement[i].row<<","<<MatricElement[i].col<<","<<MatricElement[i].val<<endl;
    }cout<<endl;
}

void sparseMatrix::simpleTranpose()
{
    vector<traple> newV;
    for(int i=0;i<colSize;i++)
    {
        for(int j=0;j<MatricElement.size();j++)
        {
            if(MatricElement[j].col==i)
            {
                traple temp;
                temp.col=MatricElement[j].row;
                temp.row=MatricElement[j].col;
                temp.val=MatricElement[j].val;
                newV.push_back(temp);
            }
        }
    }
    cout<<"new:"<<endl;
    MatricElement=newV;
    printElementList();
}

void sparseMatrix::fastTranpose()
{
    vector<traple> newV;
    vector<int> rowSize;
    vector<int> rowIndex;
    for(int i=0;i<RowSize;i++)
    {
        rowSize.push_back(0);
    }
    for(int i=0;i<MatricElement.size();i++)
    {
        //cout<<MatricElement[i].row<<endl;
        rowSize[MatricElement[i].col]+=1;//轉置前的col會變轉置後的row
    }
    
    int temp2=0;
    for(int i=0;i<rowSize.size();i++)
    {
        rowIndex.push_back(temp2);
        temp2+=rowSize[i];
    }
    
    //test
    /*
    cout<<"rowSize:"<<endl;
    for(int i=0;i<rowSize.size();i++)
    {
        cout<<rowSize[i]<<",";
    }cout<<endl;
    
    
    cout<<"rowIndex:"<<endl;
    for(int i=0;i<rowIndex.size();i++)
    {
        cout<<rowIndex[i]<<",";
    }cout<<endl;
    */
    
    vector<traple> NewMatricElement;
    for(int i=0;i<MatricElement.size();i++)
    {
        traple temp;
        temp.row=0;
        temp.col=0;
        temp.val=0;
        NewMatricElement.push_back(temp);
    }
    
    
    for(int i=0;i<MatricElement.size();i++)
    {
        int j=rowIndex[MatricElement[i].col];
        //cout<<"j:"<<j<<endl;
        //cout<<"col:"<<MatricElement[i].col<<endl;
        NewMatricElement[j].row=MatricElement[i].col;
        //cout<<"row:"<<MatricElement[i].row<<endl;
        NewMatricElement[j].col=MatricElement[i].row;
        //cout<<"val:"<<MatricElement[i].val<<endl;
        NewMatricElement[j].val=MatricElement[i].val;
        rowIndex[MatricElement[i].col]+=1;
    }
    MatricElement=NewMatricElement;
    //printElementList();
}

sparseMatrix sparseMatrix::multiplication(sparseMatrix Matrix2)
{
    //orignalMatrix*Matrix2
    sparseMatrix res;
    //cout<<"M1:"<<this->colSize<<","<<this->RowSize<<endl;
    //cout<<"M2:"<<Matrix2.colSize<<","<<Matrix2.RowSize<<endl;
    if(this->colSize!=Matrix2.RowSize)
    {
        cout<<"矩陣無法相乘"<<endl;
        return res;
    }
    //init
    vector<vector<int>> newVector;
    for(int i=0;i<this->RowSize;i++)
    {
        vector<int> temp;
        for(int j=0;j<Matrix2.colSize;j++)
        {
            temp.push_back(0);
        }
        newVector.push_back(temp);
    }
    //實作矩陣相乘
    //cout<<"M1:"<<endl;
    //this->printElementList();
    //cout<<"M2:"<<endl;
    
    Matrix2.fastTranpose();
    //Matrix2.printElementList();
    
    for(int i=0;i<this->MatricElement.size();i++)
    {
        //cout<<"M1:"<<this->MatricElement[i].row<<","<<this->MatricElement[i].col<<","<<this->MatricElement[i].val<<endl;
        for(int j=0;j<Matrix2.MatricElement.size();j++)
        {
            if(Matrix2.MatricElement[j].col==this->MatricElement[i].col)
            {
                //cout<<"M2:"<<Matrix2.MatricElement[j].row<<","<<Matrix2.MatricElement[j].col<<","<<Matrix2.MatricElement[j].val<<endl;
                newVector[this->MatricElement[i].row][Matrix2.MatricElement[j].row]+=this->MatricElement[i].val*Matrix2.MatricElement[j].val;
                //cout<<"row:"<<this->MatricElement[i].row<<", col:"<<Matrix2.MatricElement[j].row<<", 加上"<<this->MatricElement[i].val*Matrix2.MatricElement[j].val<<endl;
            }
        }
    }
    
    //test vector
    /*
    for(int i=0;i<newVector.size();i++)
    {
        for(int j=0;j<newVector[i].size();j++)
        {
            cout<<newVector[i][j]<<",";
        }cout<<endl;
    }
    cout<<endl;*/
    
    res.setMatrix(newVector);
    return res;
}



