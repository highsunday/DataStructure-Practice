//
//  main.cpp
//  circularQueue
//
//  Created by 高昊 on 2019/10/20.
//  Copyright © 2019年 高昊. All rights reserved.
//

#include <iostream>
#include "circularQueue.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    circularQueue q1(5);
    q1.peintQ();
    q1.Add(1);
    q1.peintQ();
    q1.Add(2);
    q1.peintQ();
    int temp=-1;
    temp=q1.Pop();
    cout<<"pop:"<<temp<<endl;
    q1.peintQ();
    temp=q1.Pop();
    cout<<"pop:"<<temp<<endl;
    q1.peintQ();
    q1.Add(3);
    q1.peintQ();
    q1.Add(4);
    q1.peintQ();
    q1.Add(5);
    q1.peintQ();
    q1.Add(6);
    q1.peintQ();
    temp=q1.Pop();
    cout<<"pop:"<<temp<<endl;
    q1.peintQ();
    temp=q1.Pop();
    cout<<"pop:"<<temp<<endl;
    //q1.Add(6);
    q1.peintQ();
    
    
    return 0;
}
