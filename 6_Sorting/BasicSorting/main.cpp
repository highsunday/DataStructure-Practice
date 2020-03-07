#include <iostream>
#include<vector>
#include <stdio.h>
#include <stdlib.h> /* 亂數相關函數 */
using namespace std;

/*
 *  simple sorting method:
 *      1. inserttion sort
 *      2. selection sort
 *      3. bubble sort
 * */
vector<int> test={9,4,1,6,7,3,8,2,5};
//vector<int> test={9,4,1};

void printCard(vector<int> card)
{
    //cout<<"print card:"<<endl;
    for(int i=0;i<card.size();i++)
    {
        cout<<card[i]<<",";
    }cout<<endl;
}

void selectSort(vector<int> &card)
{
    for(int i=0;i<card.size()-1;i++)
    {
        int minNum=card[i];
        int minIndex=i;
        for(int j=i+1;j<card.size();j++)
        {
            if(card[j]<minNum)
            {
                minNum=card[j];
                minIndex=j;
            }
        }
        //swap(i,j)
        int temp=card[i];
        card[i]=card[minIndex];
        card[minIndex]=temp;
    }
}

void insertSort(vector<int> &card)
{
    for(int i=1;i<card.size();i++)
    {
        int key=card[i];
        int j=i-1;
        //init
        while(j>=0&&card[j]>key)
        {
            //cout<<i<<","<<j<<endl;
            card[j+1]=card[j];
            j--;
        }
        card[j+1]=key;
        //cout<<"j:"<<j<<endl;
        //printCard(card);
    }
}

void bubbleSort(vector<int> &card)
{
    for(int i=card.size();i>1;i--)
    {
        for(int j=0;j<i-1;j++)
        {
            if(card[j]>card[j+1])
            {
                int temp=card[j];
                card[j]=card[j+1];
                card[j+1]=temp;
            }
        }
        printCard(card);
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> card;
    srand( 0 );
    for(int i=0;i<10;i++)
    {
        int randNum=rand();
        card.push_back(randNum);
    }

    /*
    printCard(test);
    selectSort(test);
    printCard(test);
    */


    printCard(card);
    insertSort(card);
    printCard(card);


    /*
    printCard(card);
    bubbleSort(card);
    printCard(card);
    */

    return 0;
}
