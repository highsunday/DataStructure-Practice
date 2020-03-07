//
// Created by VGH00 on 2019/12/4.
//

#ifndef AOV_AOV_H
#define AOV_AOV_H
#include "Adj_List.h"
class AOV: public AdjList
{
public:
    vector<int> counterList;
    AOV(int _nodeSize):AdjList( _nodeSize)
    {
        for(int i=0;i<nodeSize;i++)
            counterList.push_back(0);
    };

    void preProcess()
    {
        for(int i=0;i<nodeSize;i++)
        {
            Node* cur=ptrList[i];
            if(cur==0)
            {

            }
            else
            {
                counterList[cur->val]++;
                while(cur->next!=0)
                {
                    cur=cur->next;
                    counterList[cur->val]++;
                }
            }
        }

        /*cout<<"print node degree"<<endl;
        for(int i=0;i<nodeSize;i++)
            cout<<i<<":"<<counterList[i]<<endl;*/
    };


    void output_topologyOrder()
    {
        vector<int> res;
        int roundCounter=0;
        bool is_nodeOutput[nodeSize];
        for(int i=0;i<nodeSize;i++)
            is_nodeOutput[i]=0;

        while(roundCounter<nodeSize)
        {
            for(int i=0;i<nodeSize;i++)
            {
                if(is_nodeOutput[i]==0 && counterList[i]==0)
                {
                    //cout<<counterList[i]<<endl;
                    res.push_back(i);
                    is_nodeOutput[counterList[i]]=true;

                    Node* cur=ptrList[i];
                    if(cur!=0)
                    {
                        counterList[cur->val]--;
                        while(cur->next!=0)
                        {
                            cur=cur->next;
                            counterList[cur->val]--;
                        }
                    }
                    roundCounter++;
                }
            }
        }

        cout<<"topology order:"<<endl;
        for(int i=0;i<res.size();i++)
        {
            cout<<res[i]<<",";
        }cout<<endl;
    }
};
#endif //AOV_AOV_H
