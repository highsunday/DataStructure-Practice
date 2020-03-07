//
// Created by VGH00 on 2019/12/2.
//

#ifndef TEST_ONLYDFS_OR_BFS_H
#define TEST_ONLYDFS_OR_BFS_H
#include "Adj_List.h"

struct edgeMST{
    int a;
    int b;
    int wight;
};

static bool compareByCost(const edgeMST &a, const edgeMST &b)
{
    return a.wight < b.wight;
}

class greater_class{
public:
    bool operator()(const edgeMST& s1, const edgeMST& s2)
    {
        return s1.wight > s2.wight;
    }
};

class AdjList_DFS_or_BFS : public AdjList {
public:
    AdjList_DFS_or_BFS(int _nodeSize) : AdjList(_nodeSize) {
    }
    //DFS BFS
    void DFS(Node* start ,vector<bool> &v)
    {

        while(start!=0)
        {
            if(v[start->val]==1)
                start=start->next;
            else
                break;
        }
        if(start==0)
            return;
        v[start->val]=true;
        cout<<start->val<<endl;
        DFS(ptrList[start->val] ,v);
        DFS(start->next ,v);

    }

    void DFS_start(int index)
    {
        cout<<"enter DFS"<<endl;
        Node* root=ptrList[index];
        vector<bool> isNode_travelsal(nodeSize,0);
        isNode_travelsal[index]=true;
        cout<<index<<endl;
        DFS(root ,isNode_travelsal);
    }

    void BFS_start(int index)
    {
        Node* root=ptrList[index];
        cout<<"enter BFS"<<endl;
        vector<bool> isNode_travelsal(nodeSize,0);
        deque<Node *> Queue;
        //init
        isNode_travelsal[index]=true;
        cout<<index<<endl;
        Node* cur=root;
        while(cur!=0)
        {
            Queue.push_back(cur);
            cur=cur->next;
        }
        //process
        while(Queue.size()>0)
        {
            cur=Queue.front();
            Queue.pop_front();
            cout<<cur->val<<endl;
            isNode_travelsal[cur->val]=true;
            cur=ptrList[cur->val];
            while(cur!=0)
            {
                if(!isNode_travelsal[cur->val]&&isNode_travelsal[cur->val]==false)
                {
                    isNode_travelsal[cur->val]=true;
                    Queue.push_back(cur);
                }
                cur=cur->next;
            }
        }

    }
};

#endif //TEST_ONLYDFS_OR_BFS_H
