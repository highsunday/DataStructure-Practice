#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

#ifndef HUFFMAN_H
#define HUFFMAN_H

class Node
{
public:
    Node* left;
    Node* right;
    int freq;
    int ascii;
    Node()
    {
        left=0;
        right=0;
        freq=0;
        ascii=-1;
    }
    Node(int ascii_,int frq_)
    {
        left=0;
        right=0;
        freq=frq_;
        ascii=ascii_;
    }
};

struct asciiCode{
    int index;
    int freq;
};

class Node2
{
public:
    Node* ptr;
    Node2* next;
    Node2()
    {
        ptr=0;
        next=0;
    }
};

class Huffman
{
    public:
    unordered_map<char, string> map;
    Node2* header;
    Huffman();
    void insertNode(Node*);
    void HoffmannCoding();
    void printHoffmannResult();
    void printHoffmannResult(Node*,string);
    string HoffmannDecoding(vector<int> Content);
};

#endif // HUFFMAN_H
