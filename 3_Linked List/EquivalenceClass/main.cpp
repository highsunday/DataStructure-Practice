#include <iostream>
#include <vector>
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
    };
    Node(int Data)
    {
        data=Data;
        link=0;
    }
};
class EquivalenceClass
{
public:
    int size;//0~ (size-1)
    Node* array;
    Node** ptrArray;
    EquivalenceClass(int Size,int debug)//debug mode
    {
        size=Size;
        if(size<=0)
        {
            throw "size 不可小於或等於0";
        }
        array=new Node[size];
        ptrArray=new Node*[size];
        //init linked list array
        for(int i=0;i<size;i++)
        {
            array[i].data=i;
            array[i].link=0;
            ptrArray[i]=array+i;
        }
        //0=4 3=1 6=10 8=9 7=4 6=8 3=5 2=11 11=0
        Node* newNode1=new Node(4);
        ptrArray[0]->link=newNode1;
        ptrArray[0]=newNode1;
        Node* newNode2=new Node(0);
        ptrArray[4]->link=newNode2;
        ptrArray[4]=newNode2;

        newNode1=new Node(3);
        ptrArray[1]->link=newNode1;
        ptrArray[1]=newNode1;
        newNode2=new Node(1);
        ptrArray[3]->link=newNode2;
        ptrArray[3]=newNode2;

        newNode1=new Node(6);
        ptrArray[10]->link=newNode1;
        ptrArray[10]=newNode1;
        newNode2=new Node(10);
        ptrArray[6]->link=newNode2;
        ptrArray[6]=newNode2;

        newNode1=new Node(8);
        ptrArray[9]->link=newNode1;
        ptrArray[9]=newNode1;
        newNode2=new Node(9);
        ptrArray[8]->link=newNode2;
        ptrArray[8]=newNode2;

        newNode1=new Node(7);
        ptrArray[4]->link=newNode1;
        ptrArray[4]=newNode1;
        newNode2=new Node(4);
        ptrArray[7]->link=newNode2;
        ptrArray[7]=newNode2;

        newNode1=new Node(6);
        ptrArray[8]->link=newNode1;
        ptrArray[8]=newNode1;
        newNode2=new Node(8);
        ptrArray[6]->link=newNode2;
        ptrArray[6]=newNode2;

        newNode1=new Node(3);
        ptrArray[5]->link=newNode1;
        ptrArray[5]=newNode1;
        newNode2=new Node(5);
        ptrArray[3]->link=newNode2;
        ptrArray[3]=newNode2;

        newNode1=new Node(2);
        ptrArray[11]->link=newNode1;
        ptrArray[11]=newNode1;
        newNode2=new Node(11);
        ptrArray[2]->link=newNode2;
        ptrArray[2]=newNode2;

        newNode1=new Node(0);
        ptrArray[11]->link=newNode1;
        ptrArray[11]=newNode1;
        newNode2=new Node(11);
        ptrArray[0]->link=newNode2;
        ptrArray[0]=newNode2;
    }
    EquivalenceClass(int Size)
    {
        size=Size;
        if(size<=0)
        {
            throw "size 不可小於或等於0";
        }
        array=new Node[size];
        ptrArray=new Node*[size];
        //init linked list array
        for(int i=0;i<size;i++)
        {
            array[i].data=i;
            array[i].link=0;
            ptrArray[i]=array+i;
        }
        while(true)
        {
            //input two 等價 element which 介於 0~size-1
            int n1,n2;
            cout<<"input two 等價 element which 介於 0~"<<size-1<<" (or 其他數字 to exit)"<<endl;
            cin>>n1;
            if(n1<0||n1>size-1)
                break;
            cin>>n2;
            if(n2<0||n2>size-1)
                break;
            cout<<"n1:"<<n1<<", n2:"<<n2<<endl;
            Node* newNode1=new Node(n2);
            ptrArray[n1]->link=newNode1;
            ptrArray[n1]=newNode1;
            Node* newNode2=new Node(n1);
            ptrArray[n2]->link=newNode2;
            ptrArray[n2]=newNode2;
        }
    }
    void checkEquivalence(int Val)
    {
        vector<int> stack;
        bool isEquivalence[size];
        for(int i=0;i<size;i++)
        {
            //cout<<"isEquivalence:"<<isEquivalence[i]<<endl;
            isEquivalence[i]=0;
        }
        if(Val<0||Val>=size)
        {
            throw "this number is out of range";
        }
        Node* cur;
        cur=array+Val;
        //cout<<"first:"<<cur->data<<endl;
        isEquivalence[cur->data]=true;
        cur=cur->link;
        while(cur!=NULL)
        {
            //cout<<"then:"<<cur->data<<endl;
            isEquivalence[cur->data]=true;
            stack.push_back(cur->data);
            cur=cur->link;
        }
        /*for(int i=0;i<stack.size();i++)
        {
            cout<<"stack中的元素："<<stack[i]<<endl;
        }*/
        while(stack.size()>0)
        {
            int temp=stack.back();
            stack.pop_back();
            cur=array+temp;
            cur=cur->link;
            while(cur!=NULL)
            {
                if(isEquivalence[cur->data]==false)
                {
                    //cout<<"then:"<<cur->data<<endl;
                    isEquivalence[cur->data]=true;
                    stack.push_back(cur->data);
                }
                cur=cur->link;
            }
        }
        cout<<"哪些與"<<Val<<"等價:";
        for(int i=0;i<size;i++)
        {
            if(isEquivalence[i]==true)
            {
                cout <<i<<", ";
            }
        }cout<<"為等價"<<endl;
    }
};
int main() {
    //std::cout << "Hello, World!" << std::endl;
    EquivalenceClass e1(12);
    e1.checkEquivalence(5);
    //e1.checkEquivalence(0);
    e1.checkEquivalence(9);
    return 0;
}