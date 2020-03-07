#include <iostream>
#include<vector>
using namespace std;

class DisjointSet
{
public:
    vector<int> setList;
    vector<int> weight;
    DisjointSet(int Size)
    {
        for(int i=0;i<Size;i++)
        {
            setList.push_back(-1);
            weight.push_back(1);
        }
    }

    void printList()
    {
        for(int i=0;i<setList.size();i++)
        {
            cout<<i<<":"<<setList[i]<<endl;
        }
    }

    void unionSets(int set1,int set2)
    {
        setList[set2]=set1;
    }

    void unionSets_Weighted(int set1,int set2) //使用weighted rule
    {

    }

    int find(int val)
    {
        int res;
        while(setList[val]!=-1)
        {
            val=setList[val];
        }
        res=val;
        cout<<val<<"屬於 set"<<res<<endl;
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    DisjointSet disjointSet(10);
    //disjointSet.printList();
    disjointSet.unionSets(0,1);
    disjointSet.unionSets(1,2);
    disjointSet.unionSets(2,3);
    disjointSet.unionSets(3,4);
    disjointSet.unionSets(4,5);
    disjointSet.unionSets(5,6);
    disjointSet.unionSets(6,7);
    disjointSet.unionSets(7,8);
    disjointSet.unionSets(8,9);
    disjointSet.printList();
    disjointSet.find(8);
    return 0;
}