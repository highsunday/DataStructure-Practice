//
//  main.cpp
//  Stack
//
//  Created by 高昊 on 2019/10/17.
//  Copyright © 2019年 高昊. All rights reserved.
//

#include <iostream>
#include "StackImplement.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    stack stack1(5);
    stack1.Add(1);
    stack1.Add(3);
    stack1.Add(4);
    stack1.Add(5);
    cout<<stack1.Pop()<<endl;
    cout<<stack1.Pop()<<endl;
    cout<<stack1.Pop()<<endl;
    cout<<stack1.Pop()<<endl;
    stack1.Add(4);
    stack1.Add(5);
    cout<<stack1.Pop()<<endl;
    cout<<stack1.Pop()<<endl;
    return 0;
}
