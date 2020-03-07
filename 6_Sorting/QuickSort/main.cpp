#include <iostream>
#include<vector>
#include <stdio.h>
#include <stdlib.h> /* 亂數相關函數 */
using namespace std;

vector<int> test={1,4,3,2,5,9,10,7,6,8};

void printCard(vector<int> card)
{
    cout<<"print card:"<<endl;
    for(int i=0;i<card.size();i++)
    {
        cout<<card[i]<<",";
    }cout<<endl;
}

void quickSort_Part(vector<int> &card,int firstIndex,int rearIndex)
{
    int keyIndex=rearIndex;
    int orignalFirstIndex=firstIndex;
    rearIndex--;

    while(firstIndex<rearIndex)
    {
        while(card[firstIndex]<=card[keyIndex] && firstIndex<=rearIndex)
        {
            firstIndex++;
            //cout<<"while condition : "<<"card[firstIndex]:"<<card[firstIndex]<<", card[keyIndex]:"<<card[keyIndex]<<endl;
        }
        while(card[rearIndex]>=card[keyIndex] && rearIndex>=0)
        {
            rearIndex--;
        }
        //cout<<"firstIndex:"<<firstIndex<<", rearIndex:"<<rearIndex<<endl;
        if(firstIndex<rearIndex) {
            int temp = card[firstIndex];
            card[firstIndex] = card[rearIndex];
            card[rearIndex] = temp;
        }
    }
    if(card[keyIndex]<card[firstIndex])
    {
        int temp=card[keyIndex];
        card[keyIndex]=card[firstIndex];
        card[firstIndex]=temp;
    }
    cout<<"pivot :"<<firstIndex<<", the value is :"<<card[firstIndex]<<endl;
    printCard(card);
    int first1=orignalFirstIndex,rear1=firstIndex-1;
    if(rear1>first1)
    {
        quickSort_Part(card,first1,rear1);
    }
    int first2=firstIndex+1,rear2=keyIndex;
    if(rear2>first2)
    {
        quickSort_Part(card,first2,rear2);
    }
}
void quickSort(vector<int> &card)
{
    int first=0;
    int rear=card.size()-1;
    quickSort_Part(card,first,rear);
    //printCard(card);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> card;
    srand( 0 );
    for(int i=0;i<100;i++)
    {
        int randNum=rand();
        card.push_back(randNum);
    }

    printCard(test);
    quickSort(test);
    printCard(test);

    return 0;
}
