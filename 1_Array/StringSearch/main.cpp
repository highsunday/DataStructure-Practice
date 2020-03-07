//
//  main.cpp
//  StringSearch
//
//  Created by 高昊 on 2019/10/13.
//  Copyright © 2019年 高昊. All rights reserved.
//

#include <iostream>
#include <string>
#include "StringSearch.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    //cout << "Hello, World!\n";
    string s="bacbabababacaababaca";
    cout<<"s:"<<s<<endl;
    string p="ababaca";
    cout<<"p:"<<p<<endl;
    //string p="11101101101";
    //cout<<"index:"<<StringSearch::BF_StringSearch(s, p)<<endl;
    vector<int> res;
    res=StringSearch::KMP_StringSearch(s, p);
    cout<<"res:";
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<",";
    }cout<<endl;
    
    return 0;
}
