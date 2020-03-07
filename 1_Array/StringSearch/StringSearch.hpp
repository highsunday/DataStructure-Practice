//
//  StringSearch.hpp
//  StringSearch
//
//  Created by 高昊 on 2019/10/13.
//  Copyright © 2019年 高昊. All rights reserved.
//

#ifndef StringSearch_hpp
#define StringSearch_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class StringSearch
{
private:
    static vector<int> build_FailureFunction(string s2);
public:
    static int BF_StringSearch(string s1,string s2);//暴力法, O(mn)
    static vector<int> KMP_StringSearch(string s1,string s2);//KMP algorithm, O(m+n)
};
#endif /* StringSearch_hpp */
