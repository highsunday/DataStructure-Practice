//
//  circularQueue.cpp
//  circularQueue
//
//  Created by 高昊 on 2019/10/20.
//  Copyright © 2019年 高昊. All rights reserved.
//

#include "circularQueue.hpp"

using namespace std;
circularQueue::circularQueue(int stackSize)
{
    maxQueueSize=stackSize;
    first=0;
    rear=0;
    queueList=new int[maxQueueSize];
}

bool circularQueue::IsFull()
{
    if((rear+1)%maxQueueSize==first)
    {
        return true;
    }
    else
        return false;
    
}

void circularQueue::Add(const int& element)
{
    if(!IsFull())
    {
        queueList[rear]=element;
        rear=(rear+1)%maxQueueSize;
    }
    else{
        throw ("queue is full");
    }
}

bool circularQueue::IsEmpty()
{
    if(first==rear)
    {
        return true;
    }
    else return false;
}

int circularQueue::Pop()
{
    int element;
    if(!IsEmpty())
    {
        element=queueList[first];
        first=(first+1)%maxQueueSize;
    }
    else{
        throw("queue is empty");
    }
    return element;
}

void circularQueue::peintQ()
{
    cout<<"printQ"<<endl;
    cout<<"first:"<<first<<", rear:"<<rear<<endl;
    for(int i=0;i<maxQueueSize;i++)
    {
        cout<<queueList[i]<<",";
    }cout<<endl;
}

