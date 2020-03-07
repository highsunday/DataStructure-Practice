#include <iostream>
using namespace std;

class error{};

class node
{
public:
    int data;
    node* llink; //to last one
    node* rlink; //to first one
};

class DoubleLink
{
public:
    node* header;

    DoubleLink()
    {
        header=new node();
        header->llink=header;
        header->rlink=header;
    }

    void insertFirst(int element) //新增到linked list的第一個node
    {
        node* cur=header;
        if(cur->llink==cur)
        {
            //為empty linked list
            node* newNode=new node();
            newNode->data=element;
            newNode->llink=cur;
            newNode->rlink=cur;
            cur->llink=newNode;
            cur->rlink=newNode;
        }
        else
        {
            //不為empty
            node* newNode=new node();
            newNode->data=element;
            newNode->llink=cur;
            newNode->rlink=cur->rlink;
            cur->rlink->llink=newNode;
            cur->rlink=newNode;
        }
    }

    void insertBehindX(int x, int element)//insert 元素到x之後; 找不到則return錯誤
    {
        node* cur=header;
        if(cur->rlink==header)
        {
            try{
                throw error();
            }
            catch (error e)
            {
                cout<<"為empty list"<<endl;
                throw "error";
            }
        }
        cur=cur->rlink;
        while(cur->data!=x)
        {
            cur=cur->rlink;
            if(cur==header)
            {
                try{
                    throw error();
                }
                catch (error e)
                {
                    cout<<"找不到x"<<endl;
                    throw "error";
                }
            }
        }
        //此時cur指向x的node
        node* newNode=new node();
        newNode->data=element;
        newNode->llink=cur;
        newNode->rlink=cur->rlink;
        cur->rlink->llink=newNode;
        cur->rlink=newNode;
    }

    void deleteX(int x)
    {
        node* cur=header;
        if(cur->rlink==cur)
        {
            try {
                throw error();
            }
            catch(error e)
            {
                cout<<"為empty linked list"<<endl;
                throw "error";
            }
        }
        cur=cur->rlink;
        while(cur->data!=x)
        {
            cur=cur->rlink;
            if(cur==header)
            {
                try{
                    throw error();
                }
                catch (error e)
                {
                    cout<<"找不到x"<<endl;
                    throw "error";
                }
            }
        }
        //此時cur指向x
        node* deleteNode=cur;
        cur->llink->rlink=cur->rlink;
        cur->rlink->llink=cur->llink;
        delete deleteNode;
    }

    void print() //依照順序印出
    {
        node* cur=header;
        cout<<"依照順序印出"<<endl;
        if(cur->rlink==cur)
        {
            cout<<"為empty linked list"<<endl;
        }
        cur=cur->rlink;//指向第一個元素
        while(cur!=header)
        {
            cout<<cur->data<<endl;
            cur=cur->rlink;
        }
    }

    void printReverse() //反方向印出
    {
        node* cur=header;
        cout<<"依照反方向印出"<<endl;
        if(cur->llink==cur)
        {
            cout<<"為empty linked list"<<endl;
        }
        cur=cur->llink;//指向第一個元素
        while(cur!=header)
        {
            cout<<cur->data<<endl;
            cur=cur->llink;
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    DoubleLink link1;
    link1.insertFirst(1);
    link1.insertFirst(2);
    link1.insertBehindX(1,5);
    link1.insertBehindX(1,9);
    link1.insertFirst(3);
    link1.print();
    link1.deleteX(3);
    link1.print();
    return 0;
}