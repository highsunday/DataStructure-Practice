//
// Created by VGH00 on 2019/12/3.
//

#ifndef DIJKSTRA_SHORTESTPATH_H
#define DIJKSTRA_SHORTESTPATH_H
#include "Adj_List.h"
class ShortestPath:public AdjList
{
public:
    ShortestPath(int _nodeSize) : AdjList(_nodeSize) {
    }

    void Dijkstra(int startIndex)
    {
        vector<int> costList(nodeSize,INT32_MAX);
        vector<bool> travselList(nodeSize,0);
        costList[startIndex]=0;

        //init
        Node* cur=ptrList[startIndex];
        travselList[startIndex]=1;
        while(cur!=0)
        {
            int thisIndex=cur->val;
            if(costList[startIndex]+cur->edgeWeight<costList[thisIndex])
                costList[thisIndex]=costList[startIndex]+cur->edgeWeight;
            cur=cur->next;
        }

        cout<<"=========new round : round init=================="<<endl;
        for(int i=0;i<nodeSize;i++)
        {
            cout<<i<<":"<<costList[i]<<endl;
        }

        //process
        for(int round=0;round<nodeSize-1;round++)
        {
            int minCost=INT32_MAX;
            int minIndex=-1;
            for(int i=0;i<nodeSize;i++)
            {
                if(costList[i]<minCost && travselList[i]==0)
                {
                    minCost=costList[i];
                    minIndex=i;
                }
            }
            travselList[minIndex]=1;
            //cout<<"minIndex:"<<minIndex<<endl;
            cur=ptrList[minIndex];
            while(cur!=0)
            {
                int thisIndex=cur->val;
                if(costList[minIndex]+cur->edgeWeight<costList[thisIndex])
                    costList[thisIndex]=costList[minIndex]+cur->edgeWeight;
                cur=cur->next;
            }
            cout<<"=========new round : round "<<round<<"=================="<<endl;
            for(int i=0;i<nodeSize;i++)
            {
                cout<<i<<":"<<costList[i]<<endl;
            }
        }
    }

    void Bellman_Ford(int startIndex) {
        vector<int> costList(nodeSize,INT32_MAX);
        costList[startIndex]=0;

        //process
        for(int round=0;round<nodeSize-1;round++)
        {
            vector<int> copy_costList=costList;
            for(int i=0;i<nodeSize;i++)
            {
                Node* cur=ptrList[i];
                while(cur!=0)
                {
                    if(costList[i]<INT32_MAX)
                    {
                        int thisIndex=cur->val;
                        if(costList[i]+cur->edgeWeight<costList[thisIndex])
                            costList[thisIndex]=costList[i]+cur->edgeWeight;
                    }
                    cur=cur->next;
                }
                /*cout<<"================"<<endl;
                for(int i=0;i<nodeSize;i++)
                {
                    cout<<i<<":"<<costList[i]<<endl;
                }*/
            }
            //cout<<"=========new round : round "<<round<<"=================="<<endl;
            bool flag=true;//改前與改後都一樣
            for(int i=0;i<nodeSize;i++)
            {
                //cout<<i<<":"<<costList[i]<<endl;
                if(costList[i]!=copy_costList[i])
                    flag=false;
            }
            if(flag)
            {
                cout<<"early break in round "<<round<<endl;
                break;
            }
        }
        for(int i=0;i<nodeSize;i++)
        {
            cout<<i<<":"<<costList[i]<<endl;
        }
    }
};
#endif //DIJKSTRA_SHORTESTPATH_H
