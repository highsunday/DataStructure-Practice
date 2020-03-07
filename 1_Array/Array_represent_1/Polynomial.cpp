//
//  Polynomial.cpp
//  Array_represent_1
//
//  Created by 高昊 on 2019/10/1.
//  Copyright © 2019年 高昊. All rights reserved.
//

#include "Polynomial.hpp"
#include <iostream>
#include<math.h>
using namespace std;

Polynomial::Polynomial(int sizeArray) {
    this->sizeArray=sizeArray;
    //cout<<"constructor: the size of Array is "<<sizeArray<<endl;
    Array = new int [sizeArray];
    for(int i=0;i<sizeArray;i++)
    {
        Array[i]=0;
        //cout<<Array[i]<<",";
    }//cout<<endl;
}

void Polynomial::setPolynomial() {
    cout<<"設置多項式："<<endl;
    for(int i=0;i<sizeArray;i++)
    {
        int temp;
        cout<<"第"<<i<<"階的係數為："<<endl;
        cin>>temp;
        Array[i]=temp;
    }
    cout<<"設置完成"<<endl;
}

void Polynomial::printPolynomial()
{
    cout<<"多項式為:"<<endl;
    if(sizeArray>=1)
    {
        cout<<Array[0]<<"+";
    }
    for(int i=1;i<sizeArray-1;i++)
    {
        cout<<Array[i]<<"x^"<<i<<"+";
    }
    cout<<Array[sizeArray-1]<<"x^"<<sizeArray-1<<endl;
}

Polynomial Polynomial::PolynomialAdd(Polynomial pol2)
{
    bool firstLarge=(pol2.sizeArray<=this->sizeArray) ? true : false;
    int max_degree= (pol2.sizeArray>=this->sizeArray) ? pol2.sizeArray : this->sizeArray;
    int min_degree= (pol2.sizeArray<=this->sizeArray) ? pol2.sizeArray : this->sizeArray;
    Polynomial addRes=Polynomial(max_degree);
    for(int i=0;i<min_degree;i++)
    {
        addRes.Array[i]=this->Array[i]+pol2.Array[i];
    }
    for(int i=min_degree;i<max_degree;i++)
    {
        if(firstLarge)
        {
            addRes.Array[i]=this->Array[i];
            cout<<"第"<<i<<"項："<<this->Array[i]<<endl;
        }
        else
        {
            addRes.Array[i]=pol2.Array[i];
            cout<<"第"<<i<<"項："<<pol2.Array[i]<<endl;
        }
    }
    return addRes;
}

double Polynomial::Eval(double x)
{
    double res=0;
    if(sizeArray>=1)
    {
        res+=Array[0];
    }
    
    for(int i=0;i<sizeArray;i++)
    {
        int temp=pow(x,i+1);
        res+=Array[i]*temp;
    }
    return res;
}

Polynomial Polynomial::Polynomial_Multi(Polynomial pol2)
{
    Polynomial multiRes=Polynomial((pol2.sizeArray-1)+(this->sizeArray-1)+1);
    int position=0;
    for(int i=0;i<pol2.sizeArray;i++)
    {
        for(int j=0;j<this->sizeArray;j++)
        {
            int temp=Array[j]*pol2.Array[i];
            //cout<<i<<", "<<j<<", "<<position<<" : "<<temp<<endl;
            multiRes.Array[position+j]+=temp;
        }
        position+=1;
    }
    return multiRes;
}
