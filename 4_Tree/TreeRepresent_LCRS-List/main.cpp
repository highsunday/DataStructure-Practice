#include <iostream>
#include <vector>
using namespace std;

string test="(A(B(E(K,L),F),C(G),D(H(M),I,J)))";

//left Child/right Sibling representation
class Node
{
public:
    string data;
    Node* down;
    Node* right;

    Node()
    {
        down=0;right=0;
    }

    Node(string str)
    {
        data=str;
        down=0;right=0;
    }
};
class LCRS_tree
{
public:
    Node* head;
    LCRS_tree(string str)
    {
        vector<Node*> stack1;
        vector<int> stack2;

        bool down_or_right=0; // 1:down ; 0:right
        head=new Node();
        Node* cur=head;
        stack1.push_back(cur);
        int counter=0;
        for(int i=0;i<str.size();i++)
        {
            //cout<<str[i]<<","<<endl;
            string thisChar=str.substr(i,1);
            if(thisChar=="(")
            {
                stack2.push_back(counter);
                counter=0;
                down_or_right=1;
            }
            else if(thisChar==")")
            {
                //counter=0;
                //cout<<"start to pop:"<<endl;
                //cout<<"counter: "<<counter<<endl;
                for(int j=counter;j>0;j--)
                {
                    Node* temp=stack1.back();
                    //cout<<"pop : "<<temp->data<<endl;
                    stack1.pop_back();
                }
                cur=stack1.back();
                counter=stack2.back();
                stack2.pop_back();
                //cout<<" cur : "<<cur->data<<endl;
            }
            else if(thisChar==",")
            {
                down_or_right=0;
            }
            else{
                //cout<<"trace data : (init) "<<cur->data<<endl;
                counter++;
                Node* newNode=new Node(thisChar);

                if(down_or_right==1)
                {
                    cur->down=newNode;
                    cur=cur->down;
                    //cout<<"trace data : (down) "<<cur->data<<endl;
                }
                else if(down_or_right==0)
                {
                    cur->right=newNode;
                    cur=cur->right;
                    //cout<<"trace data : (right) "<<cur->data<<endl;
                }
                stack1.push_back(cur);
            }
        }
    }
    void printTree(Node *current) //LVR inorder
    {
        if (current) {                          // if current != NULL
            printTree(current->down);        // L
            cout << current->data << " ";   // V
            printTree(current->right);       // R
        }
    }
};

int main() {
    std::cout << "Test Left Child Right Sibling tree" << std::endl;
    LCRS_tree L1(test);
    L1.printTree(L1.head);
//    while(cur!=NULL)
//    {
//        cout<<cur->data<<endl;
//        cur=cur->right;
//    }
    return 0;
}