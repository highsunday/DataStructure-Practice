//
// Created by VGH00 on 2019/12/6.
//

#ifndef ADJ_MULTILIST_ADJ_MULTILIST_H
#define ADJ_MULTILIST_ADJ_MULTILIST_H
#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    int leftNode;//leftNode 值比 rightNode 小
    int rightNode;
    Node* leftPtr;
    Node* rightPtr;

    Node(int _leftNode,int _rightNode)
    {
        leftNode=_leftNode;
        rightNode=_rightNode;
        leftPtr=0;
        rightPtr=0;
    }
};
class AdjMultiList
{
public:
    int nodeSize;
    vector<Node*> nodeToInitEdge;//紀錄每個點所指到的第一個邊
    //vector<Node*> edgeIndex;//記錄每個邊的記憶體位置
    AdjMultiList(int _nodeSize)
    {
        nodeSize=_nodeSize;
        for(int i=0;i<nodeSize;i++)
        {
            nodeToInitEdge.push_back(0);
        }
    }
    //insert edge
    void insertEdge(int startIndex,int endIndex)
    {
        Node* newNode;
        newNode=new Node(startIndex,endIndex);
        if(nodeToInitEdge[startIndex]==0)
        {
            nodeToInitEdge[startIndex]=newNode;
        }
        else
        {
            Node* cur;
            Node* last;
            cur=nodeToInitEdge[startIndex];
            while(cur!=0)
            {
                last=cur;
                if(cur->leftNode==startIndex)
                {
                    cur=cur->leftPtr;
                }
                else if(cur->rightNode==startIndex)
                {
                    cur=cur->rightPtr;
                }
                else{
                    cout<<"error : Point to a wrong node"<<endl;
                    throw "error : Point to a wrong node";
                }
            }
            if(last->leftNode==startIndex)
            {
                last->leftPtr=newNode;
            }
            else if(last->rightNode==startIndex)
            {
                last->rightPtr=newNode;
            }
        }

        if(nodeToInitEdge[endIndex]==0)
        {
            nodeToInitEdge[endIndex]=newNode;
        }
        else
        {
            Node* cur;
            Node* last;
            cur=nodeToInitEdge[endIndex];
            while(cur!=0)
            {
                last=cur;
                if(cur->leftNode==endIndex)
                {
                    cur=cur->leftPtr;
                }
                else if(cur->rightNode==endIndex)
                {
                    cur=cur->rightPtr;
                }
                else{
                    cout<<"error : Point to a wrong node"<<endl;
                    throw "error : Point to a wrong node";
                }
            }
            if(last->leftNode==endIndex)
            {
                last->leftPtr=newNode;
            }
            else if(last->rightNode==endIndex)
            {
                last->rightPtr=newNode;
            }
        }
    }
    //delete edge
    void deleteEdge(int startIndex,int endIndex)
    {
        // init
        Node *cur;
        Node* last2;
        cur=nodeToInitEdge[startIndex];
        bool flagStartIndex=false;
        if(cur->leftNode==startIndex)
        {
            if(cur->rightNode==endIndex)
            {
                nodeToInitEdge[startIndex]=cur->leftPtr;
                flagStartIndex=true;
            }
        }
        if(!flagStartIndex)
        {
            Node* last;
            bool flag=0;//0:left ; 1:right
            while(true)
            {
                if(cur->leftNode==startIndex)
                {
                    if(cur->rightNode==endIndex)
                    {
                        break;
                    }
                    flag=0;
                    last=cur;
                    cur=cur->leftPtr;
                } else
                {
                    flag=1;
                    last=cur;
                    cur=cur->rightPtr;
                }
            }
            //cout<<"("<<cur->leftNode<<","<<cur->rightNode<<")"<<endl;
            //cout<<"("<<last->leftNode<<","<<last->rightNode<<")"<<endl;

            if(flag==0)
            {
                last->leftPtr=cur->leftPtr;
            } else
            {
                last->rightPtr=cur->rightPtr;
            }
        }

        cur=nodeToInitEdge[endIndex];
        bool flagEndIndext=false;
        if(cur->rightNode==endIndex)
        {
            if(cur->leftNode==startIndex)
            {
                nodeToInitEdge[endIndex]=cur->rightPtr;
                flagEndIndext=true;
            }
        }

        if(!flagEndIndext)
        {
            cout<<"here"<<endl;
            Node* last;
            bool flag=0;//0:left ; 1:right
            while(true)
            {
                if(cur->rightNode==endIndex)
                {
                    if(cur->leftNode==startIndex)
                    {
                        break;
                    }
                    flag=1;
                    last=cur;
                    cur=cur->rightPtr;
                } else
                {
                    flag=0;
                    last=cur;
                    cur=cur->leftPtr;
                }
            }
            cout<<"("<<cur->leftNode<<","<<cur->rightNode<<")"<<endl;
            cout<<"("<<last->leftNode<<","<<last->rightNode<<")"<<endl;

            if(flag==0)
            {
                last->leftPtr=cur->leftPtr;
            } else
            {
                last->rightPtr=cur->rightPtr;
            }
        }
    }
    //print
    void printMultiList()
    {
        Node* cur;
        cout<<"===printAdjMultiList==="<<endl;
        for(int i=0;i<nodeSize;i++)
        {
            cout<<"Node "<<i<<" :";
            cur=nodeToInitEdge[i];
            while(cur!=0)
            {
                cout<<"("<<cur->leftNode<<","<<cur->rightNode<<")";
                if(i==cur->leftNode)
                {
                    cur=cur->leftPtr;
                }
                else if(i==cur->rightNode)
                {
                    cur=cur->rightPtr;
                }
                else{
                    cout<<"error : Point to a wrong node"<<endl;
                    throw "error : Point to a wrong node";
                }
            }cout<<endl;
        }
    }
};
#endif //ADJ_MULTILIST_ADJ_MULTILIST_H
