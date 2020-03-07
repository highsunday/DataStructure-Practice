#include <iostream>
#include <stdio.h>
#include <stdlib.h> /* 亂數相關函數 */
#include <time.h>
#include "Heap.h"
using  namespace std;


void printCard(vector<int> card)
{
    //cout<<"print card:"<<endl;
    for(int i=0;i<card.size();i++)
    {
        cout<<card[i]<<",";
    }cout<<endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    cout<<"Heap Sort (Heap Sort,由大至小排列)"<<endl;

    vector<int> card;
    srand( 0 );
    for(int i=0;i<100000;i++)
    {
        int randNum=rand();
        card.push_back(randNum);
    }

    printCard(card);
    clock_t start = clock();
    Heap maxHeap1;
    for(int i=0;i<card.size();i++)
    {
        maxHeap1.insert(card[i]);
    }

    vector<int> res;
    for(int i=0;i<card.size();i++)
    {
        int temp=maxHeap1.deleteMax();
        res.push_back(temp);
    }
    clock_t stop = clock();
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<",";
    }cout<<endl;

    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    cout<<"HeapSort sorting time :"<<elapsed<<endl;
    return 0;
}