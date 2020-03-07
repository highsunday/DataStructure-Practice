#include <iostream>
#include<vector>
#include <stdlib.h> /* 亂數相關函數 */
//merge sort (recursive版)
using namespace std;

vector<int> test={5,3,8,6,2,7,1,4};

void printCard(vector<int> card)
{
    //<<"print card:"<<endl;
    for(int i=0;i<card.size();i++)
    {
        cout<<card[i]<<",";
    }cout<<endl;
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

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> card;
    srand( 0 );
    for(int i=0;i<1000;i++)
    {
        int randNum=rand();
        card.push_back(randNum);
    }

    printCard(card);
    mergeSort(card,0,card.size()-1);
    printCard(card);

    return 0;
}