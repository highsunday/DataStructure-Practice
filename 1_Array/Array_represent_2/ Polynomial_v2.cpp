//
//   Polynomial_v2.cpp
//  Array_represent_2
//
//  Created by 高昊 on 2019/10/2.
//  Copyright © 2019年 高昊. All rights reserved.
//

#include " Polynomial_v2.hpp"
#include <iostream>

using namespace std;

Polynomial_v2::Polynomial_v2() {
    degree=-1;
}

void Polynomial_v2::setPolynomial() {
    cout << "設置多項式(press Ctrl+Z to quit):"<<endl;
    while (true)
    {
        int cof;
        int power;
        cout << "係數:";
        cin >> cof;
        if (cof == 0)
        {
            break;
        }
        cout << "級數:";
        cin >> power;
        if(power>degree)
        {
            degree=power;
        }
        PolyVector.push_back(cof);
        PolyVector.push_back(power);
    }
}

void Polynomial_v2::printPolynomial()
{
    cout<<"多項式為:"<<endl;
    for(int i=0;i<PolyVector.size()-2;i+=2)
    {
        cout<<PolyVector[i]<<"x^"<<PolyVector[i+1]<<"+";
    }
    cout<<PolyVector[PolyVector.size()-2]<<"x^"<<PolyVector[PolyVector.size()-1]<<endl;
}

Polynomial_v2 Polynomial_v2::PolynomialAdd(Polynomial_v2 pol2)
{
    Polynomial_v2 addRes=Polynomial_v2();
    //尚未完成...
    int pos_1=0;
    int pos_2=0;
    int firstEnd=0;//1:1先結束; 0:同時結束; -1:2先結束
    while(1)
    {
        if(pos_1>=PolyVector.size())
        {
            firstEnd=1;
            break;
        }
        if(pos_2>=pol2.PolyVector.size())
        {
            firstEnd=-1;
            break;
        }
        int temp;
        if(PolyVector[pos_1+1]==pol2.PolyVector[pos_2+1])
        {
            temp=PolyVector[pos_1]+pol2.PolyVector[pos_2];
            addRes.PolyVector.push_back(temp);
            addRes.PolyVector.push_back(PolyVector[pos_1+1]);
            //cout<<"temp:"<<temp<<endl;
            //cout<<"temp:"<<temp<<endl;
            pos_1+=2;
            pos_2+=2;
        }
        else if(PolyVector[pos_1+1]<pol2.PolyVector[pos_2+1])
        {
            temp=PolyVector[pos_1];
            addRes.PolyVector.push_back(temp);
            addRes.PolyVector.push_back(PolyVector[pos_1+1]);
            //cout<<"temp:"<<temp<<endl;
            pos_1+=2;
        }
        else
        {
            temp=PolyVector[pos_2];
            addRes.PolyVector.push_back(temp);
            addRes.PolyVector.push_back(PolyVector[pos_2+1]);
            //cout<<"temp:"<<temp<<endl;
            pos_2+=2;
        }
    }
    if(firstEnd==1)
    {
        while(pos_2<pol2.PolyVector.size())
        {
            //cout<<"here1:"<<pol2.PolyVector[pos_2]<<", "<<pol2.PolyVector[pos_2+1]<<endl;
            int temp=pol2.PolyVector[pos_2];
            addRes.PolyVector.push_back(temp);
            addRes.PolyVector.push_back(pol2.PolyVector[pos_2+1]);
            pos_2+=2;
        }
    }
    else if(firstEnd==-1)
    {
        for(pos_1;pos_1<PolyVector.size();pos_1+=2)
        {
            cout<<"here2"<<endl;
            int temp=PolyVector[pos_1];
            addRes.PolyVector.push_back(temp);
            addRes.PolyVector.push_back(PolyVector[pos_1+1]);
        }
    }
    return addRes;
}

Polynomial_v2 Polynomial_v2::Polynomial_Multi(Polynomial_v2 pol2) 
{
    Polynomial_v2 mutiRes=Polynomial_v2();
    vector<int> temp;
    for(int i=0;i<PolyVector.size();i+=2)
    {
        int mutiRes=1;
        int mutiDegree=0;
        for(int j=0;j<pol2.PolyVector.size();j+=2)
        {
            mutiRes=PolyVector[i]*pol2.PolyVector[j];
            mutiDegree=PolyVector[i+1]+pol2.PolyVector[j+1];
            temp.push_back(mutiRes);
            temp.push_back(mutiDegree);
        }
    }
    
    /*cout<<"temp :"<<endl;
    for(int i=0;i<temp.size();i++)
    {
        cout<<temp[i]<<",";
    }cout<<endl;*/
    
    for(int i=0;i<temp.size();i+=2)
    {
        int thisDegree=temp[i+1];
        int sum=temp[i];
        for(int j=i+2;j<temp.size();j+=2)
        {
            if(temp[j+1]==temp[i+1])
            {
                sum+=temp[j];
                temp[j]=0;
            }
        }
        if(sum!=0)
        {
            mutiRes.PolyVector.push_back(sum);
            mutiRes.PolyVector.push_back(thisDegree);
        }
    }
    return mutiRes;
}
