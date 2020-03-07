#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

string input="A(B(D,E(H,I)),C(F,G))";

class BinaryTree_Array{
public:
    vector<string> treeArray;
    int MaxDepth;

    BinaryTree_Array(string input)
    {
        MaxDepth=0; //empty
        treeArray.push_back("");
        int curIndex=1;
        for(int i=0;i<input.size();i++)
        {
            //cout<<input[i]<<endl;
            string thisChar=input.substr(i,1);
            if(thisChar=="(")
            {
                curIndex=curIndex*2;
            }
            else if(thisChar==")")
            {
                curIndex=curIndex/2;
            }
            else if(thisChar==",")
            {
                curIndex=curIndex+1;
            }
            else{
                //cout<<thisChar<<":"<<curIndex<<endl;
                insert(thisChar,curIndex);
            }
        }
    }

    void insert(string data,int index)
    {
        //cout<<"index/2: "<<index/2<<", treeArray.size():"<<treeArray.size()<<endl;
        //cout<<"treeArray[index/2]: "<<treeArray[index/2]<<endl;
        if((index/2>treeArray.size()||treeArray[index/2]=="")&&(index/2!=0))
        {
            cout<<"invalid insertion : no parent"<<endl;
            throw "invalid insertion : no parent";
        }
        else{
            if(index>treeArray.size()-1)
            {
                MaxDepth+=1;
                for(int i=pow(2,MaxDepth-1);i<pow(2,MaxDepth);i++)
                {
                    treeArray.push_back("");
                }
            }
            //cout<<"treeArray.size():"<<treeArray.size()<<endl;
            if( treeArray[index]!="")
            {
                throw "invalid insertion : the node is already exist";
            }
            else
                treeArray[index]=data;
        }
    }

    void printArray()
    {
        cout<<"print array: ";
        cout<<"array MaxDepth is: "<<MaxDepth<<endl;
        for(int i=1;i<treeArray.size();i++)
        {
            cout<<treeArray[i]<<",";
        }cout<<endl;
    }
};
int main() {
    cout << "Test Binary tree using linked list" <<endl;
    BinaryTree_Array tree1(input);
    tree1.printArray();
    /*
    tree1.insert("A",1);
    tree1.insert("B",2);
    tree1.insert("C",3);
    tree1.insert("D",4);
    tree1.insert("E",5);
    tree1.insert("H",10);
    tree1.insert("I",11);*/
    //tree1.printArray();
    return 0;
}