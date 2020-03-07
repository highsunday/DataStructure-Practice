//
//  StackImplement.cpp
//  Stack
//
//  Created by 高昊 on 2019/10/17.
//  Copyright © 2019年 高昊. All rights reserved.
//

#include "StackImplement.hpp"
using namespace std;

stack::stack(int stackSize)
{
    maxStackSize=stackSize;
    first=0;
    stackList=new int[maxStackSize];
}

bool stack::IsFull()
{
    if(first==maxStackSize-1)
    {
        return true;
    }
    else
        return false;
}

void stack::Add(const int& element)
{
    if(!IsFull())
    {
        stackList[first]=element;
        first++;
    }
    else{
        throw ("stack is full");
    }
}

bool stack::IsEmpty()
{
    if(first==0)
    {
        return true;
    }
    else return false;
}

int stack::Pop()
{
    int element;
    if(!IsEmpty())
    {
        first--;
        element=stackList[first];
    }
    else{
        throw ("stack is empty");
    }
    return element;
}





