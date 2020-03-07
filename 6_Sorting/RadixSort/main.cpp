#include <iostream>
#include<vector>
#include <stdio.h>
#include <stdlib.h> /* 亂數相關函數 */
using namespace std;

vector<int> test={129,454,1,64,78,3,81,2,5};

void printCard(vector<int> card)
{
    cout<<"print card:"<<endl;
    for(int i=0;i<card.size();i++)
    {
        cout<<card[i]<<",";
    }cout<<endl;
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
    for(int i=0;i<1000;i++)
    {
        int randNum=rand();
        card.push_back(randNum);
    }
    printCard(card);
    radixSort(card);
    printCard(card);
    cout<<"ok"<<endl;
    return 0;
}
