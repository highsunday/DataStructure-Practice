#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#include <bitset>
#include "Huffman.h"

using namespace std;

//needed to be revise
bool sort_by_freq( const asciiCode & lhs, const asciiCode & rhs )
{
    return lhs.freq < rhs.freq;
}

string inFileName="input2.txt";
string outFileName="output2.txt";
string resFileName="result2.txt";

int main (int argc, char *argv[]) { //需要在main中傳入一個參數


    bool encoding;
    if(*argv[1]=='1') //等於1為encoding;等於0為decoding
    {
        encoding=true;
    }
    else if(*argv[1]=='0')
    {
        encoding=false;
    }

    cout<<"encoding:"<<encoding<<endl;
    string line;
    vector<string> content;
    fstream myfile (inFileName);
    if (myfile.is_open())
    {
        while ( myfile.good() )
        {
            getline (myfile,line);
            //cout << line << endl;
            content.push_back(line);
        }
        myfile.close();
    }
    else cout << "Unable to open file";

    //cout<<"vector size is : "<<content.size()<<endl;

    vector<asciiCode> countArray;
    for(int i=0;i<128;i++)
    {
        asciiCode temp;
        temp.index=i;
        temp.freq=0;
        countArray.push_back(temp);
    }

    for(int i=0;i<content.size();i++)
    {
        for(int j=0;j<content[i].size();j++)
        {
            //cout<<content[i][j]<<":"<<(int)content[i][j]<<endl;
            countArray[(int)content[i][j]].freq++;
        }
    }
    sort( countArray.begin(), countArray.end(), sort_by_freq );

    Huffman nodeList;
    for(int i=0;i<countArray.size();i++)
    {
        if(countArray[i].freq>0)
        {
            //cout<<countArray[i].index<<","<< (char)(countArray[i].index)<<","<<countArray[i].freq<<endl;
            Node* newNode=new Node(countArray[i].index,countArray[i].freq);
            nodeList.insertNode(newNode);
        }
    }
    Node2* cur2=nodeList.header;
    while(cur2->next!=0)
    {
        nodeList.HoffmannCoding();
        cur2=nodeList.header;
    }
    nodeList.printHoffmannResult();

    //part2 output encoding txt
    if(encoding==true)
    {
        cout<<"進行壓縮"<<endl;
        string bitList="";
        for(int i=0;i<content.size();i++)
        {
            //cout<<content[i];
            for(int j=0;j<content[i].size();j++)
            {
                char thisCh=content[i][j];
                string temp="";
                unordered_map<char,string>::iterator iter;
                iter=nodeList.map.find(thisCh);
                if(iter!=nodeList.map.end())
                {
                    //cout<<thisCh<<"->"<<iter->second<<endl;
                    temp=iter->second;
                    bitList+=temp;
                }
                else
                {
                    cout<<"not found"<<endl;
                    throw "char not found error";
                }
            }
        }//cout<<endl;
        //cout<<bitList<<endl;
        if(bitList.size()>4294967295)
        {
            throw "string can't store such number of data";
        }



        ofstream output2 (outFileName, ios::out | ios::binary);
        int last=0;
        if(!output2)     //�ˬd�ɮ׬O�_���\�}��
        {
            cerr << "Can't open file!\n";
            exit(1);     //�b�����`���ΤU�A���_�{��������
        } else{
            for(int i=0;i<bitList.size()-8;i+=8)//last one
            {
                //cout<<"i:"<<i<<", bitList.size():"<<bitList.size()<<endl;
                string temp=bitList.substr(i,8);
                reverse(temp.begin(), temp.end());
                bitset<8> buffer = bitset<8>(temp);
                output2.write((char*) &buffer, 1);
                /*for(int i=0;i<8;i++)
                {
                    cout<<buffer[i];
                }cout<<endl;
                cout<<"buffer1:"<<(char*) &buffer<<endl;*/
                last=i;
            }
            char* charList;
            bitset<8> buffer2;// = bitset<8>(bitList.substr(last,bitList.size()-last));
            string temp_str=bitList.substr(last+8,bitList.size()-last);
            cout<<"temp_str:"<<temp_str<<endl;
            for(int j=0;j<8;j++)
            {
                if(j<temp_str.size())
                {
                    if((temp_str[j])=='1')
                        buffer2[j] = (bool)(1);
                    else
                        buffer2[j] = (bool)(0);
                }
                else{
                    buffer2[j] = (bool)(0);
                }
            }
            //cout<<buffer2<<endl;
            output2.write((char*) &buffer2, 1);
            //cout<<"buffer2:"<<(char*) &buffer2<<endl;
            output2<<8-temp_str.size();//�̫�@��byte�ѽX��
            output2.close();
        }
    }
    else
    {
        cout<<"進行解壓縮"<<endl;
        vector<int> decodingContent;
        ifstream decodeFile(outFileName,ios::binary);
        if(decodeFile)
        {
            char c;
            cout<<"scussessfull open"<<endl;
            while ( decodeFile.get(c) )
            {
               // cout<<"c:"<<c<<":";
                for (int i = 0; i < 8; i++) // or (int i = 0; i < 8; i++)  if you want reverse bit order in bytes
                {
                    //cout << ((c >> i) & 1);
                    decodingContent.push_back(((c >> i) & 1));
                }//cout<<endl;
                //cout<<buffer2;
            }
            decodeFile.close();
        }
        else{
            cout<<"fail to open"<<endl;
            throw "error";
        }

        int res=0,count=0;
        cout<<endl;
        for(int i=decodingContent.size()-8;i<decodingContent.size();i++)
        {
            //cout<<decodingContent[i]<<endl;
            if(decodingContent[i]==1)
            {
                res+=pow(2,count);
                //cout<<"count:"<<count<<","<<pow(2,count)<<", res:"<<res<<endl;
            }
            count++;
        }//cout<<endl;
        //cout<<"res:"<<res-30<<endl;
        int leaveBits=res-48;
        cout<<"leaveBits:"<<leaveBits<<endl;
        for(int i=0;i<leaveBits+8;i++)
        {
            decodingContent.pop_back();
        }

        cout<<"test decodingContent:"<<endl;
        cout<<"the size is :"<<decodingContent.size()<<endl;
        /*for(int i=0;i<decodingContent.size();i++)//data
        {
            cout<<decodingContent[i];
        }*/

        string res2=nodeList.HoffmannDecoding(decodingContent);
        fstream resFile(resFileName, ios::out);
        if(!resFile)     //�ˬd�ɮ׬O�_���\�}��
        {
            cerr << "Can't open file!\n";
            exit(1);     //�b�����`���ΤU�A���_�{��������
        } else{
            resFile<<res2<<endl;
            resFile.close();
        }
    }
    return 0;
}
