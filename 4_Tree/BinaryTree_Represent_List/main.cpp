#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
/*
* Binary tree using list
* Support initial, insert
*
*/
string input="A(B(D,E(H,I)),C(F,G))";

class Node
{
    public:
    Node* leftChild;
    Node* rightChild;
    string data;

    Node()
    {
        leftChild=0;
        rightChild=0;
        data="";
    };

    Node(string str)
    {
        leftChild=0;
        rightChild=0;
        data=str;
    };
};

class BinaryTree_List
{
public:
    Node* head;

    vector<string> treeArray;

    BinaryTree_List(string input)
    {
        head=new Node();
        //Node* cur=head;

        //test
        vector<Node*> stack1;
        Node* leftChild;Node* rightChild;
        bool flag=false;//true:left ; false:right
        for(int i=0;i<input.size();i++)
        {
            Node* thisChar=new Node(input.substr(i,1));
            //cout<<thisChar<<endl;
            stack1.push_back(thisChar);


            if(thisChar->data==")")
            {
                Node* thatChar;
                do
                {
                    thatChar=stack1.back();
                    //cout<<"thatChar:"<<thatChar<<endl;
                    if(thatChar->data==",")
                    {
                        flag=true;
                    }
                    else if(thatChar->data!="("&&thatChar->data!=")")
                    {
                        if(flag)
                        {
                            leftChild=thatChar;
                        }
                        else{
                            rightChild=thatChar;
                        }
                    }
                    stack1.pop_back();
                }while(thatChar->data!="("&&stack1.size()>0);
                if(stack1.size()>0)
                {
                    thatChar=stack1.back();
                    //cout<<"parent:"<<thatChar<<endl;
                }
                cout<<leftChild->data<<" is left child of "<<thatChar->data<<endl;
                cout<<rightChild->data<<" is right child of "<<thatChar->data<<endl;
                insert(thatChar,leftChild,0);
                insert(thatChar,rightChild,1);
                leftChild=0;rightChild=0;flag=false;
                head=thatChar;
            }
        }
    }
    void insert(Node* parent,string data,bool left_or_right)// 0:left ; 1:right
    {
         Node* newNode=new Node(data);
        if(left_or_right==0) //left
        {
            parent->leftChild=newNode;
        }
        else{ //right
            parent->rightChild=newNode;
        }
    }
    void insert(Node* parent,Node* child,bool left_or_right)// 0:left ; 1:right
    {
        if(left_or_right==0) //left
        {
            parent->leftChild=child;
        }
        else{ //right
            parent->rightChild=child;
        }
    }
    void processInput(string input)
    {
        vector<string> stack1;
        string leftChild;string rightChild;
        bool flag=false;//true:left ; false:right
        for(int i=0;i<input.size();i++)
        {

            string thisChar=input.substr(i,1);
            //cout<<thisChar<<endl;
            stack1.push_back(thisChar);


            if(thisChar==")")
            {
                string thatChar;
                do
                {
                    thatChar=stack1.back();
                    //cout<<"thatChar:"<<thatChar<<endl;
                    if(thatChar==",")
                    {
                        flag=true;
                    }
                    else if(thatChar!="("&&thatChar!=")")
                    {
                        if(flag)
                        {
                            leftChild=thatChar;
                        }
                        else{
                            rightChild=thatChar;
                        }
                    }
                    stack1.pop_back();
                }while(thatChar!="("&&stack1.size()>0);
                if(stack1.size()>0)
                {
                    thatChar=stack1.back();
                    //cout<<"parent:"<<thatChar<<endl;
                }
                cout<<leftChild<<" is left child of "<<thatChar<<endl;
                cout<<rightChild<<" is right child of "<<thatChar<<endl;
                leftChild="";rightChild="";flag=false;
            }
        }
    }

    void printTree(Node *current) //LVR inorder
    {
        if (current) {                          // if current != NULL
            printTree(current->leftChild);        // L
            cout << current->data << " ";   // V
            printTree(current->rightChild);       // R
        }
    }

    /* //有點奇怪，先不考慮
    void deleteNode(Node *current,bool left_or_right)// 0:left ; 1:right
    {
        Node *cur;
        if(left_or_right==0)//刪除左兒子
        {
            cur=current->leftChild;
        }else//刪除右兒子
        {
            cur=current->rightChild;
        }

        if(cur==0)
        {
            cout<<"此node不存在"<<endl;
            return;
        }

        //case 1: 此node為leaf
        if(cur->leftChild==0&&cur->rightChild==0)
        {
            if(left_or_right==0)
            {
                current->leftChild=0;
            }else
            {
                current->rightChild=0;
            }
        }
        //case 2: 此node有兩個兒子
        else if(cur->leftChild!=0&&cur->rightChild!=0)
        {
            cur->leftChild->rightChild=cur->rightChild;
            if(left_or_right==0)
            {
                current->leftChild=cur;
            }else
            {
                current->rightChild=cur;
            }
        }
        //case 3: 此node有一個兒子
        else{
            Node* temp;
            if(cur->leftChild==0)
            {
                temp=current->rightChild;
            }
            else{
                temp=current->leftChild;
            }
            if(left_or_right==0)
            {
                current->leftChild=temp;
            }else
            {
                current->rightChild=temp;
            }
        }

    }*/
};
int main() {
    cout << "Test Binary tree using linked list" << std::endl;

    /* //手動input
    BinaryTree_List tree1(input);
    Node* cur=tree1.head;
    tree1.insert(cur,"A",0);
    cur=cur->leftChild;
    tree1.insert(cur,"B",0);
    tree1.insert(cur,"C",1);
    cur=cur->leftChild;
    tree1.insert(cur,"D",0);
    tree1.insert(cur,"E",1);
    cur=cur->rightChild;
    tree1.insert(cur,"H",0);
    tree1.insert(cur,"I",1);
    cur=tree1.head->leftChild->rightChild;
    tree1.insert(cur,"F",0);
    tree1.insert(cur,"G",1);

    tree1.printTree(tree1.head);
    */

    // string input
    BinaryTree_List tree1(input);
    tree1.printTree(tree1.head);

    return 0;
}