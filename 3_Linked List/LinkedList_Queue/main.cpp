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

class queue
{
public:
    int maxSize;
    int curSize;
    node* first;
    node* rear;

    queue(int MaxSize)
    {
        maxSize=MaxSize;
        curSize=0;
        first=0;
        rear=0;
    }
    void add(int Val)
    {
        node* newNode=new node(Val);
        if(isFull())
        {
            throw "the queue is full";
        }
        if(first==0)
        {
            first=newNode;
            rear=first;
            curSize++;
        }
        else
        {
            rear->link=newNode;
            rear=newNode;
            curSize++;
        }

    }
    int pop()
    {
        if(isEmpty())
        {
            throw "the queue is empty";
        }
        int res=first->data;
        first=first->link;
        curSize--;
        return res;
    }
    bool isFull()
    {
        if(curSize==maxSize)
        {
            return true;
        }
        else
            return false;
    }
    bool isEmpty()
    {
        if(curSize==0)
        {
            return true;
        }
        else
            return false;
    }
    void print()
    {
        cout<<"print queue(newNode前rear後):"<<endl;
        node* cur=first;
        while(cur!=NULL)
        {
            cout<<cur->data<<",";
            cur=cur->link;
        }cout<<endl;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    queue q(5);
    q.add(1);
    q.add(2);
    q.add(3);
    q.add(4);
    q.add(5);
    //q.add(6);
    q.print();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.print();
    return 0;
}