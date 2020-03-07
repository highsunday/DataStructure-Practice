#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node* link;

    node()
    {
        data=0;
        link=0;
    }
    node(int Data)
    {
        data=Data;
        link=0;
    }
};

class stack
{
public:
    int maxSize;
    int curSize;
    node* first;
    stack(int MaxSize)
    {
        first=0;
        maxSize=MaxSize;
        curSize=0;
    }
    void add(int Val)
    {
        if(isFull())
        {
            throw "stack is full";
        }
        if(first==NULL)
        {
            cout<<"目前stack為空"<<endl;
            node *newNode=new node(Val);
            first=newNode;
            cout<<"add new element: the val is "<<Val<<endl;
            curSize++;
        }
        else
        {
            node *newNode=new node(Val);
            newNode->link=first;
            first=newNode;
            curSize++;
        }

    }
    int pop()
    {
        if(isEmpty())
        {
            throw "stack is empty";
        }
        int res=first->data;
        first=first->link;
        curSize--;
        return res;

    }

    bool isEmpty()
    {
        if(curSize==0)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if(curSize==maxSize)
            return true;
        else
            return false;
    }
    void print()
    {
        cout<<"印出stack(first在前面):";
        node *cur=first;
        while(cur!=NULL)
        {
            cout<<cur->data<<",";
            cur=cur->link;
        }cout<<endl;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    stack s(5);
    s.add(5);
    s.add(4);
    s.add(3);
    s.print();
    cout<<"pop掉"<<s.pop()<<endl;
    s.print();
    cout<<"pop掉"<<s.pop()<<endl;
    s.print();
    cout<<"pop掉"<<s.pop()<<endl;
    s.print();
    //cout<<"pop掉"<<s.pop()<<endl;
    //s.print();
    return 0;
}
