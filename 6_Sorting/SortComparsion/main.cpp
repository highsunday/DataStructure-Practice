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
        //printCard(card);
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

void merge(vector<int> &card,int firstIndex,int rearIndex)
{
    int mid=(firstIndex+rearIndex)/2;
    //cout<<"merge("<<firstIndex<<","<<mid<<") and ("<<mid+1<<","<<rearIndex<<")"<<endl;
    vector<int> leftVec(card.begin()+firstIndex, card.begin()+mid+1);
    vector<int> rightVec(card.begin()+mid+1, card.begin()+rearIndex+1);

    //cout<<"leftVec:";printCard(leftVec);
    //cout<<"righttVec:";printCard(rightVec);
    int leftInd=0,rightInd=0;
    int flag=-1;//0:同時結束 ; 1:left先結束 ; 2:right先結束 ;
    int reviseIndex=0;
    //vector<int> res;
    while(true)
    {
        if(leftVec[leftInd]<=rightVec[rightInd])
        {
            //res.push_back(leftVec[leftInd]);
            card[firstIndex+reviseIndex]=leftVec[leftInd];
            leftInd++;
            if(leftInd==leftVec.size())
            {
                flag=1;
                reviseIndex++;
                break;
            }
        } else
        {
            //res.push_back(rightVec[rightInd]);
            card[firstIndex+reviseIndex]=rightVec[rightInd];
            rightInd++;
            if(rightInd==rightVec.size())
            {
                flag=2;
                reviseIndex++;
                break;
            }
        }
        reviseIndex++;
    }
    //cout<<"flag:"<<flag<<endl;
    if(flag==1)
    {

        while(rightInd<rightVec.size())
        {
            //cout<<"rightInd:"<<rightInd<<", rightVec.size():"<<rightVec.size()<<endl;
            card[firstIndex+reviseIndex]=rightVec[rightInd];
            //res.push_back(rightVec[rightInd]);
            rightInd++;reviseIndex++;
        }
    }
    else if(flag==2)
    {
        while(leftInd<leftVec.size())
        {
            //cout<<"leftInd:"<<leftInd<<", leftVec.size():"<<leftVec.size()<<endl;
            card[firstIndex+reviseIndex]=leftVec[leftInd];
            //res.push_back(leftVec[leftInd]);
            leftInd++;reviseIndex++;
        }
    }
    //cout<<"res:";
    //printCard(res);
    //printCard(card);

    /*for(int i=firstIndex;i<=rearIndex;i++)
    {
        //card[i]=res[i-firstIndex];
        cout<<card[i]<<",";
    }cout<<endl;*/

}
void mergeSort(vector<int> &card,int firstIndex,int rearIndex)
{
    //cout<<"firstIndex:"<<firstIndex<<", rearIndex:"<<rearIndex<<endl;
    if(firstIndex==rearIndex)
        return;
    int mid=(firstIndex+rearIndex)/2;
    mergeSort(card,firstIndex,mid);
    mergeSort(card,mid+1,rearIndex);
    merge(card,firstIndex,rearIndex);
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
void radixSort(vector<int> &card)
{
    long int digital=1;
    bool flag=true;
    //vector<int> cardTemp;
    while(flag)
    {
        flag=false;
        vector<vector<int>> radixS;
        for(int i=0;i<10;i++)
        {
            vector<int> temp;
            radixS.push_back(temp);
        }
        //cout<<"new round"<<endl;
        for(int i=0;i<card.size();i++)
        {
            int radixIndex=(card[i]/digital)%10;
            //cout<<"card[i] : "<<card[i]<<", radixIndex: "<<radixIndex<<endl;
            radixS[radixIndex].push_back(card[i]);
            if(radixIndex!=0)
                flag=true;
        }
        card.clear();
        for(int i=0;i<radixS.size();i++)
        {
            for(int j=0;j<radixS[i].size();j++)
            {
                card.push_back(radixS[i][j]);
            }
        }
        digital*=10;
    }

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


    vector<int> card_temp=card;
    clock_t start = clock();
    selectSort(card_temp);
    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    cout<<"SelectSort sorting time :"<<elapsed<<endl;

    card_temp=card;
    start = clock();
    bubbleSort(card_temp);
    stop = clock();
    elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    cout<<"BubbleSort sorting time :"<<elapsed<<endl;


    card_temp=card;
    start = clock();
    insertSort(card_temp);
    stop = clock();
    elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    cout<<"InsertSort sorting time :"<<elapsed<<endl;

    card_temp=card;
    start = clock();
    ShellSort(card_temp);
    stop = clock();
    elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    cout<<"ShellSort sorting time :"<<elapsed<<endl;

    card_temp=card;
    start = clock();
    quickSort(card_temp);
    stop = clock();
    elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    cout<<"QuickSort sorting time :"<<elapsed<<endl;

    card_temp=card;
    start = clock();
    mergeSort(card_temp,0,card_temp.size()-1);
    stop = clock();
    elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    cout<<"MergeSort sorting time :"<<elapsed<<endl;

    card_temp=card;
    start = clock();
    radixSort(card_temp);
    stop = clock();
    elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    cout<<"RadixSort sorting time :"<<elapsed<<endl;

    return 0;
}
