//
//  StringSearch.cpp
//  StringSearch
//
//  Created by 高昊 on 2019/10/13.
//  Copyright © 2019年 高昊. All rights reserved.
//

#include "StringSearch.hpp"

int StringSearch::BF_StringSearch(string s1,string s2)
{
    int count=0;
    for(int i=0;i<s1.length()-s2.length()+1;i++)
    {
        //cout<<s1[i];
        bool flag=true;
        //int index=i;
        for(int j=0;j<s2.length();j++)
        {
            count++;
            if(s2[j]!=s1[i+j])
            {
                count++;
                flag=false;
                break;
            }
        }
        if(flag)
        {
            //cout<<"比對了"<<count<<"次"<<endl;
            return i;
        }
    }
    //cout<<"比對了"<<count<<"次"<<endl;
    return -1;
}

vector<int> StringSearch::KMP_StringSearch(string s1,string s2)
{
    StringSearch temp;
    vector<int> FF=temp.build_FailureFunction(s2);
    //KMP
    int pos_S=0,pos_P=0;
    vector<int> res;
    while((pos_S<s1.size())&&(pos_P<s2.size()))
    {
        if(s1[pos_S]==s2[pos_P])
        {
            pos_S++;pos_P++;
            if(pos_P==s2.size())
            {
                res.push_back(pos_S-pos_P);
                cout<<"pos_S:"<<endl;
                pos_P=FF[pos_P-1]+1;
            }

        }
        else{
            if(pos_P==0)
            {
                pos_S++;
            }
            else if(pos_P>0)
            {
                pos_P=FF[pos_P-1]+1;
            }
        }
    }
    
    return res;
}

vector<int> StringSearch::build_FailureFunction(string s2)
{
    //cout<<"build Failure Function"<<endl;
    //cout<<"the string pattern is : "<<s2<<endl;
    //init
    vector<int> FF;
    for(int i=0;i<s2.length();i++)
    {
        FF.push_back(0);
    }
    
    FF[0]=-1;
    int j=0;
    for(int i=1;i<s2.length();i++)
    {
        if(s2[i]==s2[j])
        {
            FF[i]=FF[i-1]+1;
            j++;
        }
        else
        {
        while(s2[i]!=s2[j]&&(j>0))
        {
            //cout<<s2[i]<<", "<<s2[j]<<", ";
            j=FF[j];
            if(j==-1)
                j=0;
            //cout<<j<<endl;
        }
        if(s2[i]==s2[j])
        {
            FF[i]=FF[j]+1;
            j++;
        }
        else{
            FF[i]=-1;
        }
        }
    }
    return FF;
}
