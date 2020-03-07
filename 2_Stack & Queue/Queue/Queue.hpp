//
//  Queue.hpp
//  Queue
//
//  Created by 高昊 on 2019/10/20.
//  Copyright © 2019年 高昊. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include <iostream>

class queue
{
public:
    int maxQueueSize;
    int first;
    int rear;
    int* queueList;
    
    queue(int maxQueueSize);
    bool IsFull();
    void Add(const int&);
    bool IsEmpty();
    int Pop();
    //void shift();//將element搬移到前面
    void peintQ();
    
};

#endif /* Queue_hpp */
