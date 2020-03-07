//
// Created by VGH00 on 2019/12/2.
//

#ifndef TEST_ONLYMST_H
#define TEST_ONLYMST_H
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

class AdjList_MST : public AdjList {
public:
    AdjList_MST(int _nodeSize) : AdjList(_nodeSize) {
    }
    //MST
    void MST_Kruskal()
    {
        vector<edgeMST> edgeList;
        for(int i=0;i<ptrList.size();i++)
        {
            //cout<<"list "<<i<<" :";
            Node* cur=ptrList[i];
            edgeMST temp;
            if(cur!=0)
            {
                //cout<<"("<<cur->val<<", "<<cur->edgeWeight<<"),";
                if(cur->val>=i)
                {
                    temp.a=i;temp.b=cur->val;temp.wight=cur->edgeWeight;
                    edgeList.push_back(temp);
                }
                while(cur->next!=0)
                {
                    cur=cur->next;
                    //cout<<"("<<cur->val<<", "<<cur->edgeWeight<<"),";
                    if(cur->val>=i)
                    {
                        temp.a=i;temp.b=cur->val;temp.wight=cur->edgeWeight;
                        edgeList.push_back(temp);
                    }
                }
            }//cout<<endl;
        }
        sort(edgeList.begin(), edgeList.end(), compareByCost);
        vector<int> disjontList(nodeSize,-1);
        int count=0;
        for(int i=0;i<edgeList.size();i++)
        {
            //cout << "(" << edgeList[i].a << "," << edgeList[i].b << "," << edgeList[i].wight << ")" << endl;
            int thisEdge_a=edgeList[i].a , thisEdge_b=edgeList[i].b;
            while(disjontList[thisEdge_a]!=-1)
            {
                thisEdge_a=disjontList[thisEdge_a];
            }
            while(disjontList[thisEdge_b]!=-1)
            {
                thisEdge_b=disjontList[thisEdge_b];
            }
            //cout<<thisEdge_a<<","<<thisEdge_b<<endl;
            if(thisEdge_a!=thisEdge_b)
            {
                disjontList[edgeList[i].b]=thisEdge_a;
                cout << "(" << edgeList[i].a << "," << edgeList[i].b << "," << edgeList[i].wight << ")" << endl;
                count++;
                if(count==nodeSize-1)
                    break;
            }
        }
    }

    void MST_Prim(int index)
    {
        vector<bool> travesal(nodeSize,0);
        vector<edgeMST> _edgelist;
        int curNode=index;
        travesal[curNode]=1;
        Node* cur=ptrList[index];
        //init
        edgeMST temp;
        while(cur!=0)
        {
            temp.a=index;
            temp.b=cur->val;
            temp.wight=cur->edgeWeight;
            _edgelist.push_back(temp);
            push_heap(_edgelist.begin(),_edgelist.end(),greater_class());
            cur=cur->next;
        }
        /*
        cout<<"print list:"<<endl;
        for(int i=0;i<_edgelist.size();i++)
        {
            cout << "(" << _edgelist[i].a << "," << _edgelist[i].b << "," << _edgelist[i].wight << ")";
        }cout<<endl;
        */

        while(_edgelist.size()>0)
        {
            edgeMST get_edgeMST=_edgelist.front();
            pop_heap(_edgelist.begin(),_edgelist.end(),greater_class());
            _edgelist.pop_back();
            cur=ptrList[get_edgeMST.b];
            curNode=get_edgeMST.b;
            if(travesal[curNode]==0)
            {
                travesal[curNode]=1;
                /*
                cout<<"print list:"<<endl;
                for(int i=0;i<_edgelist.size();i++)
                {
                    cout << "(" << _edgelist[i].a << "," << _edgelist[i].b << "," << _edgelist[i].wight << ")";
                }cout<<endl;cout<<"end"<<endl;
                */
                cout << "(" << get_edgeMST.a << "," << get_edgeMST.b << "," << get_edgeMST.wight << ")" << endl;
                while(cur!=0)
                {
                    if(travesal[cur->edgeWeight]==0)
                    {
                        temp.a=curNode;//修改
                        temp.b=cur->val;
                        temp.wight=cur->edgeWeight;
                        _edgelist.push_back(temp);
                        push_heap(_edgelist.begin(),_edgelist.end(),greater_class());
                    }
                    cur=cur->next;
                }
            }
        }
    }
};
#endif //TEST_ONLYMST_H
