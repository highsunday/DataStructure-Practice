#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* link;
    
    Node()
    {
        data=0;
        link=0;
    }
    
    Node(int d)
    {
        data=d;
        link=0;
    }
};

class LinkedList
{
public:
    Node* first;
    LinkedList(int Data)
    {
        Node* newP=new Node(Data);
        first=newP;
    }
    void print()
    {
        Node* cur;
        cur=first;
        cout<<"print linked list:";
        while(cur!=0)
        {
            cout<<cur->data<<",";
            cur=cur->link;
        }
        cout<<endl;
    }
    void addFront(int newd)
    {
        Node* newP=new Node(newd);
        newP->link=first;
        first=newP;
    }
    void deleteNode(int dd)
    {
        /*if(first!=NULL)
        {
            cout<<"pop掉"<<first->data<<endl;
            first=first->link;
        }
        else{
            throw "pop from empty linked list";
        }*/
        
        while(first!=NULL&&first->data==dd)
        {
            first=first->link;
        }
        Node* cur;
        Node* last;
        cur=first;
        last=first;
        while(cur!=NULL)//非第一？
        {
            if(cur->data==dd)
            {
                last->link=cur->link;
            }
            last=cur;
            cur=cur->link;
        }
    }
    
    void reverse()
    {
        Node* cur=first;
        if(first==NULL)
        {
            return;
        }
        Node* next=first->link;//excetion
        Node* last=NULL;
        while(next!=NULL)
        {
            //cout<<"next:"<<next->data<<endl;
            //cout<<"cur:"<<cur->data<<endl;
            //cout<<"last:"<<last->data<<endl;
            cur->link=last;
            last=cur;
            cur=next;
            next=next->link;
        }
        cur->link=last;
        first=cur;
    }
    
    void concat(Node* list2)
    {
        Node* cur=first;
        if(cur==NULL)
        {
            first=list2;
            return;
        }
        while(cur->link!=NULL)
        {
            cur=cur->link;
        }
        cur->link=list2;
    }
};

int main() {
    // your code goes here
    cout<<"hello world"<<endl;
    //Node n1(1);
    //cout<<n1.data<<endl;
    LinkedList LL(1);
    LL.deleteNode(1);
    /*LL.addFront(2);
    LL.addFront(3);
    LL.addFront(4);
    LL.addFront(5);
    LL.addFront(6);*/
    LL.print();
    //LL.reverse();
    //LL.print();
    
    LinkedList LL2(7);
    LL2.addFront(8);
    LL2.addFront(9);
    LL2.addFront(10);
    LL2.print();
    LL2.concat(LL.first);
    LL2.print();
    return 0;
}
