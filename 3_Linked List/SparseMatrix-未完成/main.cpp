#include <iostream>
using namespace std;

//head or non-head node
class node
{
public:
    bool head;
    node* down;//to down node
    node* right;//to right node
    node* next;//to next head

    //non node field
    int col;
    int row;
    int val;
};

class SparseMatrix
{
private:
    node* matrixHead;
public:
    SparseMatrix(int rowSize, int colSize)
    {
        //產生 Matrix head
        matrixHead=new node;
        matrixHead->head=1;
        matrixHead->col=colSize;
        matrixHead->row=rowSize;
        int headNum;
        if(rowSize>=colSize)
            headNum=rowSize;
        else
            headNum=colSize;
        //連接head
        node* cur=matrixHead;
        for(int i=0;i<headNum;i++)
        {
            node* newNode=new node;
            newNode->head=1;
            newNode->down=newNode;
            newNode->right=newNode;
            cur->next=newNode;
            cur=cur->next;
        }
        cur->next=matrixHead;
    }

    void inputElement()
    {
        while(true)
        {
            int r,c,v;
            cout<<"輸入稀疏矩陣元素(輸入-1離開)";
            cout<<"輸入row:";
            cin>>r;
            if(r<0) break;
            cout<<"輸入col:";
            cin>>c;
            if(c<0) break;
            cout<<"輸入val:";
            cin>>v;
            if(v<0) break;
            cout<<"新元素:"<<"("<<r<<","<<c<<","<<v<<")"<<endl;

            node* newNode=new node;
            newNode->col=c;
            newNode->row=r;
            newNode->val=v;
            newNode->head=0;
            node* cur=matrixHead;
            //第r Row
            for(int i=0;i<r;i++)
            {
                cur=cur->next;
            }
            node* rightPtr=cur;
            while(!(rightPtr->right->head==1)&&!(rightPtr->right->col)>c)
            {
                rightPtr=rightPtr->right;
            }
            newNode->right=rightPtr->right;
            rightPtr->right=newNode;

            //第c col
            cur=matrixHead;
            for(int i=0;i<c;i++)
            {
                cur=cur->next;
            }
            node* downPtr=cur;
            while(!(downPtr->down->head==1)&&!(rightPtr->down->row)>r)
            {
                downPtr=downPtr->down;
            }
            newNode->down=downPtr->down;
            downPtr->down=newNode;
        }
    }

    void printMatrix()
    {

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    SparseMatrix M1=SparseMatrix(4,4);
    M1.inputElement();
    return 0;
}