//
//  main.cpp
//  SparseMatrix_SimpleTranpose
//
//  Created by 高昊 on 2019/10/6.
//  Copyright © 2019年 高昊. All rights reserved.
//
#include "sparseMatrix.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> v1;
    v1={{1,2},{3,4},{5,6}};
    sparseMatrix M1;
    cout<<"M1:"<<endl;
    M1.setMatrix(v1);
    //M1.fastTranpose();
    
    
    
    vector<vector<int>> v2;
    v2={{4,1},{2,0}};
    sparseMatrix M2;
    cout<<"M2:"<<endl;
    M2.setMatrix(v2);
    //M2.fastTranpose();
    
    
    
    sparseMatrix M3;
    cout<<"矩陣相乘:"<<endl;
    M3=M1.multiplication(M2);//M3=M1*M2
    cout<<"M3:"<<endl;
    //M3.printElementList();
    
    
    return 0;
}
