#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node* left;
    Node* right;
    Node(int key_)
    {
        key=key_;
        left=0;
        right=0;
    }
};

class BST
{
public:
    Node* header;
    BST()
    {
        header=0;
    }
    void insert(int newKey)
    {
        //cout<<"inert:"<<newKey<<endl;
        Node* newNode=new Node(newKey);
        if(header==0)
        {
            header=newNode;
        }
        else{
            Node* cur=header;
            while(!(cur->key>=newKey&&cur->left==0)&&!(cur->key<newKey&&cur->right==0))
            {
                if(cur->key==newKey)
                {
                    cout<<"error: the key is already existing"<<endl;
                    throw "error: the key is already existing";
                }
                else if(cur->key>newKey)
                {
                    cur=cur->left;
                }
                else{
                    cur=cur->right;
                }
            }
            if(cur->key>newKey)
            {
                cur->left=newNode;
                //cout<<"the "<<cur->key<<" left"<<endl;
            }
            else{
                cur->right=newNode;
                //cout<<"the "<<cur->key<<" right"<<endl;
            }
        }
    }

    bool find(int key)
    {
        Node* cur=header;
        do
        {
            if(cur->key==key)
            {
                return true;
            }
            else if(cur->key>key)
            {
                cur=cur->left;
            }
            else
            {
                cur=cur->right;
            }
        }while(cur!=0);
        return false;
    }

    void deleteKey(int key)
    {
        Node* cur=header;
        Node* last=header;
        bool flagFind=false;
        bool left_or_right=0;//0:left ; 1:right
        do
        {
            if(cur->key==key)
            {
                flagFind=true;
                break;
            }
            else if(cur->key>key)
            {
                last=cur;
                cur=cur->left;
                left_or_right=0;
            }
            else
            {
                last=cur;
                cur=cur->right;
                left_or_right=1;
            }
        }while(cur!=0);

        if(flagFind)
        {
            cout<<"find the node"<<endl;
        } else{
            cout<<"error : this node do not existing"<<endl;
            throw "error : this node do not existing";
        }
        cout<<"the number:"<<last->key<<endl;

        //case 1 : no child
        if(cur->left==0&&cur->right==0)
        {
            if(left_or_right)
            {
                last->right=0;
            }
            else
            {
                last->left=0;
            }
        }
        //case 2 : two child
        else if(cur->left!=0&&cur->right!=0)
        {
            Node*leftMax=cur->left;
            if(leftMax->right==0)
            {
                leftMax->right=cur->right;
                if(last==cur)
                {
                    header=leftMax;
                }
                else
                {
                    if(left_or_right)
                    {
                        last->right=leftMax;
                    }
                    else
                    {
                        last->left=leftMax;
                    }
                }
            }
            else{
                Node* last2;
                while(leftMax->right!=0)
                {
                    last2=leftMax;
                    leftMax=leftMax->right;
                }
                if(leftMax->left==0)
                {
                    last2->right=0;
                    if(left_or_right)
                    {
                        last->right=leftMax;
                    }
                    else
                    {
                        last->left=leftMax;
                    }
                }
                else
                {
                    last2->right=leftMax->left;
                    if(left_or_right)
                    {
                        last->right=leftMax;
                    }
                    else
                    {
                        last->left=leftMax;
                    }
                }
            }

        }
        //case 3 : one child
        else
        {
            Node *ptr;
            if(cur->left!=0)
            {
                ptr=cur->left;
            }
            else if(cur->right!=0)
            {
                ptr=cur->right;
            }

            if(left_or_right)
            {
                last->right=ptr;
            }
            else
            {
                last->left=ptr;
            }
        }
    }

    void printTree(Node* ptr) //LVR
    {
        if(ptr==0)
            return;
        printTree(ptr->left);
        cout<<ptr->key<<",";
        printTree(ptr->right);
    }

    void printTreeVLR(Node* ptr) //VLR
    {
        if(ptr==0)
            return;
        cout<<ptr->key<<",";
        printTreeVLR(ptr->left);
        printTreeVLR(ptr->right);

    }
};

int main() {
    //std::cout << "Hello, World!" << std::endl;
    BST tree;
    tree.insert(5);
    tree.insert(1);
    tree.insert(8);
    tree.insert(0);
    tree.insert(6);
    tree.insert(10);
    tree.deleteKey(5);
    tree.deleteKey(8);
    tree.deleteKey(0);
    tree.deleteKey(6);
    cout<<"LVR:";
    tree.printTree(tree.header);cout<<endl;
    cout<<"VLR:";
    tree.printTreeVLR(tree.header);cout<<endl;
    /*Node*cur=tree.header;
    cout<<cur->key<<endl;
    cur=cur->left;
    cout<<cur->key<<endl;
    cur=cur->left;
    cout<<cur->key<<endl;*/

    return 0;
}