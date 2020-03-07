//
//  Queue.cpp
//  Queue
//
//  Created by 高昊 on 2019/10/20.
//  Copyright © 2019年 高昊. All rights reserved.
//

#include "Queue.hpp"
using namespace std;
queue::queue(int stackSize)
{
    maxQueueSize=stackSize;
    first=0;
    rear=0;
    queueList=new int[maxQueueSize];
}

bool queue::IsFull()
{
    if(rear==maxQueueSize)
    {
        return true;
    }
    else
        return false;
}

void queue::Add(const int& element)
{
    if(!IsFull())
    {
        queueList[rear]=element;
        rear++;
        if(rear==maxQueueSize&&first!=0)
        {
            //進行shift
            for(int i=0;i<rear-first;i++)
            {
                queueList[i]=queueList[first+i];
            }
            rear=rear-first;
            first=0;
        }
    }
    else{
            throw ("queue is full");
    }
}

bool queue::IsEmpty()
{
    if(first==rear)
    {
        return true;
    }
    else return false;
}

int queue::Pop()
{
    int element;
    if(!IsEmpty())
    {
        element=queueList[first];
        first++;
    }
    else{
        throw ("queue is empty");
    }
    return element;
}

void queue::peintQ()
{
    cout<<"printQ"<<endl;
    cout<<"first:"<<first<<", rear:"<<rear<<endl;
    for(int i=0;i<maxQueueSize;i++)
    {
        cout<<queueList[i]<<",";
    }cout<<endl;
}
