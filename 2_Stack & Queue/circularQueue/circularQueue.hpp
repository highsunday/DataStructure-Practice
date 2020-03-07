//
//  circularQueue.hpp
//  circularQueue
//
//  Created by 高昊 on 2019/10/20.
//  Copyright © 2019年 高昊. All rights reserved.
//

#ifndef circularQueue_hpp
#define circularQueue_hpp

#include <stdio.h>
#include <iostream>

class circularQueue
{
public:
    int maxQueueSize;
    int first;
    int rear;
    int* queueList;
    
    circularQueue(int maxQueueSize);
    bool IsFull();
    void Add(const int&);
    bool IsEmpty();
    int Pop();
    void peintQ();
    
};

#endif /* circularQueue_hpp */
