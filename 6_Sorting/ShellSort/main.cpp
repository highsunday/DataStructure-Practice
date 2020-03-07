#include <iostream>
#include<vector>
#include <stdio.h>
#include <stdlib.h> /* 亂數相關函數 */
#include <time.h>
using namespace std;

vector<int> test={9,4,1,6,7,3,8,2,5};
//vector<int> test={9,4,1};

void printCard(vector<int> card)
{
    cout<<"print card:"<<endl;
    for(int i=0;i<card.size();i++)
    {
        cout<<card[i]<<",";
    }cout<<endl;
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


void sub_ShellSort(vector<int> &card,int gap)
{
    //cout<<"sub_ShellSort -> gap : "<<gap<<endl;

    for(int basic=0; basic<gap; basic++)
    {
        for(int i=basic+gap;i<card.size();i+=gap)
        {
            int key=card[i];
            int j=i-gap;
            //init
            while(j>=0&&card[j]>key)
            {
                //cout<<i<<","<<j<<endl;
                card[j+gap]=card[j];
                j-=gap;
            }
            card[j+gap]=key;
            //cout<<"j:"<<j<<endl;
            //printCard(card);
        }
    }
    //printCard(card);
    if(gap==1)
        return;
    sub_ShellSort(card,gap/2);
}

void ShellSort(vector<int> &card)
{
    int gap=card.size()/2;
    sub_ShellSort(card,gap);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> card;
    srand( 0 );
    for(int i=0;i<100000;i++)
    {
        int randNum=rand();
        card.push_back(randNum);
    }

    // printCard(card);
    clock_t start = clock();
    ShellSort(card);
    clock_t stop = clock();
    //printCard(card);
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    cout<<"sorting time :"<<elapsed<<endl;
    return 0;
}
