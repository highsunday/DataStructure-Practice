//
//  StackImplement.hpp
//  Stack
//
//  Created by 高昊 on 2019/10/17.
//  Copyright © 2019年 高昊. All rights reserved.
//

#ifndef StackImplement_hpp
#define StackImplement_hpp

#include <stdio.h>
#include <iostream>


class stack
{
public:
    int maxStackSize;
    int first;
    int* stackList;
    
    stack(int maxStackSize);
    bool IsFull();
    void Add(const int&);
    bool IsEmpty();
    int Pop();
};
#endif /* StackImplement_hpp */
