//
//  LinkedList.hpp
//  LinkedList
//
//  Created by 高昊 on 2019/10/21.
//  Copyright © 2019年 高昊. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Node
{
public:
    string data;
    Node* link;
public:
    Node(string);
};


#endif /* LinkedList_hpp */
