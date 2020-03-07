#include <iostream>
#include <vector>
using namespace std;
string test="A(B(E(K,L),F),C(G),D(H(M),I,J))";

class Node
{
public:
    bool isHeader;
    Node* right;
    union {
        char data;
        Node* down;
    };
    Node()
    {
        isHeader=true;
        right=0;
        down=0;
    }
    Node(char a)
    {
        isHeader=false;
        right=0;
        data=a;
    }
};

class Tree_genList
{
public:
    Node* header;
    Tree_genList(string input)
    {
        vector<char> queue;
        vector<Node*> stack;
        header=new Node();
        Node* cur=header;
        //test
//        Node* newNode=new Node('x');
//        cur->right=newNode;
//        cur=newNode;
        //
        for(int i=0;i<input.size();i++)
        {
            //cout<<"input:"<<input.substr(i,1)<<endl;
            char thisChar=input[i];
            if(thisChar=='(')
            {

                for(int j=0;j<queue.size()-1;j++)
                {
                    //cout<<j<<endl;
                    //³s±µ
                    //cout<<"inner loop:"<<queue[j]<<endl;
                    Node* newNode=new Node(queue[j]);
                    cur->right=newNode;
                    cur=newNode;
                }
                Node* newHead=new Node();
                cur->right=newHead;
                cur=newHead;
                stack.push_back(cur);
                //cout<<"outer loop:"<<queue[queue.size()-1]<<endl;
                Node* newNode=new Node(queue[queue.size()-1]);
                cur->down=newNode;
                cur=newNode;
                queue.clear();
            }
            else if(thisChar==')')
            {
                for(int j=0;j<queue.size();j++)
                {
                    //³s±µ
                    Node* newNode=new Node(queue[j]);
                    //cout<<"outer loop:"<<queue[j]<<endl;
                    cur->right=newNode;
                    cur=newNode;
                }
                queue.clear();
                cur->right=0;
                cur=stack.back();
                stack.pop_back();
            }
            else if(thisChar==',')
            {

            }
            else
            {
                queue.push_back(thisChar);
            }

        }
    }

};

int main() {
    cout<<"test Tree_genList:"<<endl;
    Tree_genList tree1(test);
    Node* cur=tree1.header;
    cur=cur->right->down;
    cout<<cur->data<<endl;
    cur=cur->right->down;
    cout<<cur->data<<endl;
    cur=cur->right->down;
    cout<<cur->data<<endl;
    cur=cur->right;
    cout<<cur->data<<endl;
    cur=cur->right;
    cout<<cur->data<<endl;
    return 0;
}