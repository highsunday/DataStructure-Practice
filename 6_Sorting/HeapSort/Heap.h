//
// Created by 高昊 on 2019/12/10.
//
#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
class Heap
{
public:
    vector<int> treeArray;
    int MaxDepth;
    int NodeNum;
    Heap()
    {
        MaxDepth=0;
        NodeNum=0;
        treeArray.push_back(0);//不會用到的
    }
    void insert(int data)
    {
        NodeNum++;
        if(MaxDepth==0)
        {
            MaxDepth++;
            treeArray.push_back(data);
        }
        else
        {
            if(NodeNum==pow(2,MaxDepth))
            {
                MaxDepth++;
            }
            treeArray.push_back(data);
            adjustInsert(NodeNum);
        }
    }
    int deleteMax()
    {
        if(NodeNum==0)
        {
            cout<<"the tree is empty"<<endl;
            throw "the tree is empty";
        }
        int res=treeArray[1];
        treeArray[1]=treeArray[NodeNum];
        NodeNum--;
        adjustDelete();
        treeArray.pop_back();
        return res;
    }
    void adjustInsert(int index)
    {
        int lastIndex=index;
        int curIndex=lastIndex/2;
        //cout<<"index:"<<index<<", curIndex:"<<curIndex<<endl;
        while(curIndex>0)
        {
            //cout<<"val:"<<treeArray[curIndex]<<", "<<treeArray[lastIndex]<<endl;
            if(treeArray[curIndex]<treeArray[lastIndex])
            {
                //cout<<curIndex<<"與"<<lastIndex<<"交換"<<endl;
                int temp=treeArray[lastIndex];
                treeArray[lastIndex]=treeArray[curIndex];
                treeArray[curIndex]=temp;
            }
            lastIndex=curIndex;
            curIndex=curIndex/2;
        }
    }
    void adjustDelete()
    {
        int curIndex=1;
        //cout<<"init:"<<treeArray[curIndex]<<endl;
        while(curIndex<=NodeNum)
        {

            //find left-child or right-child to exxchange
            int flag=0;//0:no change ; 1:left; 2:right
            if(curIndex*2>NodeNum)
                break;
            if(curIndex*2+1>NodeNum)
            {
                if(treeArray[curIndex*2]>treeArray[curIndex])
                {
                    int temp=treeArray[curIndex*2];
                    treeArray[curIndex*2]=treeArray[curIndex];
                    treeArray[curIndex]=temp;
                    curIndex=curIndex*2;
                    //cout<<"end"<<endl;
                } else
                    break;
            }
            else
            {
                int bigger;
                if(treeArray[curIndex*2]>treeArray[curIndex*2+1])
                {
                    bigger=treeArray[curIndex*2];
                    flag=1;
                }
                else
                {
                    bigger=treeArray[curIndex*2+1];
                    flag=2;
                }
                if(bigger>treeArray[curIndex])
                {
                    if(flag==1)
                    {
                        //cout<<"flag=1"<<endl;
                        //cout<<curIndex<<"與"<<curIndex*2<<"交換"<<endl;
                        int temp=treeArray[curIndex*2];
                        treeArray[curIndex*2]=treeArray[curIndex];
                        treeArray[curIndex]=temp;
                        curIndex=curIndex*2;
                        //cout<<"end"<<endl;
                    }
                    else
                    {
                        //cout<<"flag=2"<<endl;
                        //cout<<curIndex<<"與"<<curIndex*2+1<<"交換"<<endl;
                        int temp=treeArray[curIndex*2+1];
                        treeArray[curIndex*2+1]=treeArray[curIndex];
                        treeArray[curIndex]=temp;
                        curIndex=curIndex*2+1;
                    }
                }
                else
                {
                    flag=0;
                    break;
                }
            }
        }
    }
    void printArray()
    {
        cout<<"print array: ";
        //cout<<"array MaxDepth is: "<<MaxDepth<<endl;
        //cout<<"NodeNum is :"<<NodeNum<<endl;
        for(int i=1;i<treeArray.size();i++)
        {
            cout<<treeArray[i]<<",";
        }cout<<endl;
    }
};
#endif //HEAP_HEAP_H
