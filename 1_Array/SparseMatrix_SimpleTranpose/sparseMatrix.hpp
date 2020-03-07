//
//  sparseMatrix.hpp
//  SparseMatrix_SimpleTranpose
//
//  Created by 高昊 on 2019/10/6.
//  Copyright © 2019年 高昊. All rights reserved.
//

#ifndef sparseMatrix_hpp
#define sparseMatrix_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class sparseMatrix
{
public:
    //int degree;
    int colSize,RowSize;
    struct traple { int row; int col; int val; };
    vector<traple> MatricElement;
    
public:
    sparseMatrix();
    sparseMatrix(vector<vector<int>>);
    void setMatrix(vector<vector<int>>);
    void printElementList();
    void simpleTranpose();
    void fastTranpose();
    sparseMatrix multiplication(sparseMatrix Matrix2);
};

#endif /* sparseMatrix_hpp */
