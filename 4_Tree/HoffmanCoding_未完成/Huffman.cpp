#include "Huffman.h"

Huffman::Huffman()
{
    header=0;
}

void Huffman::insertNode(Node* newNode)
{
    Node2* newNode2= new Node2();
    newNode2->ptr=newNode;
    Node2* cur=header;
    if( header==0)
    {
        header=newNode2;
    }
    else
    {
        while(cur->next!=0)
        {
            cur=cur->next;
        }
        cur->next=newNode2;
    }
}

void Huffman::HoffmannCoding()
{
    Node2* cur=header;
    int freq_sum=0;
    //cout<<(char)cur->ptr->ascii<<","<<cur->ptr->freq<<endl;
    freq_sum+=cur->ptr->freq;
    Node2* cur2=cur->next;
    if(cur->next==0)
        return;
    //cout<<(char)cur2->ptr->ascii<<","<<cur2->ptr->freq<<endl;
    freq_sum+=cur2->ptr->freq;
    Node* newNode=new Node(-1,freq_sum);
    newNode->left=cur->ptr;
    newNode->right=cur2->ptr;
    Node2* newNode2=new Node2();
    newNode2->ptr=newNode;
    //pop���e���node
    header=cur->next->next;
    //insert noe node
    cur=header;
    Node2* last=header;
    while(cur!=0)
    {
        if(freq_sum<=cur->ptr->freq)
            break;
        last=cur;
        cur=cur->next;
    }
    if(last!=0)
    {
        newNode2->next=last->next;
        last->next=newNode2;
    }
    else{
        header=newNode2;
    }
}
void Huffman::printHoffmannResult()
{
    map.erase(map.begin(),map.end());
    printHoffmannResult(header->ptr,"");
}

void Huffman::printHoffmannResult(Node* cur,string coding)
{
    if(cur==0)
        return;
    printHoffmannResult(cur->left,coding+"1");
    if(cur->ascii!=-1)
    {
        cout<<(char)cur->ascii<<"=>"<<coding<<endl;
        map[(char)cur->ascii]=coding;
    }
    printHoffmannResult(cur->right,coding+"0");
}

string Huffman::HoffmannDecoding(vector<int> Content)
{
    string res;
    Node* cur;cur=header->ptr;
    for(int i=0;i<Content.size();i++)
    {
        //cout<<Content[i];
        if(Content[i]==1)
        {
            cur=cur->left;
        }else{
            cur=cur->right;
        }
        if(cur->ascii!=-1)
        {
            //cout<<"ascii:"<<(char)cur->ascii<<endl;
            res+=(char)cur->ascii;
            cur=header->ptr;
        }
    }//cout<<endl;
    cout<<"res:"<<res.size()<<endl;

    return res;
}
