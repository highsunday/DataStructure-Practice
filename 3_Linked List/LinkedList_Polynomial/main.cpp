#include <iostream>
#include<vector>
using namespace std;
class node
{
public:
    int coff;
    int exp;
};
class Polynomial
{
private:
    vector<node> poly;
public:
    Polynomial()
    {
        while(true)
        {
            node newNode;
            cout<<"input 係數 (or zero to exit):"<<endl;
            cin>>newNode.coff;
            if(newNode.coff==0)
                break;
            cout<<"input 指數:"<<endl;
            cin>>newNode.exp;
            poly.push_back(newNode);
        }
    }

    Polynomial(int zero)
    {
    }

    void printLinst()
    {
        cout<<"the Polynomial is :";
        for(int i=0;i<poly.size();i++)
        {
            cout<<poly[i].coff<<"x^"<<poly[i].exp<<"+";
        }cout<<endl;
    }

    void add(Polynomial Poly2)
    {
        vector<node> newPoly;
        int i=0, j=0;
        while(i<poly.size() and j<Poly2.poly.size())
        {
            if(poly[i].exp>Poly2.poly[j].exp)
            {
                newPoly.push_back(poly[i]);
                //cout<<"("<<poly[i].coff<<","<<poly[i].exp<<")"<<endl;
                i++;
            }
            else if(poly[i].exp<Poly2.poly[j].exp)
            {
                newPoly.push_back(Poly2.poly[j]);
                //cout<<"("<<Poly2.poly[j].coff<<","<<Poly2.poly[j].exp<<")"<<endl;
                j++;
            }
            else// 相等
            {
                node newNode;
                newNode.coff=poly[i].coff+Poly2.poly[j].coff;
                newNode.exp=poly[i].exp;
                newPoly.push_back(newNode);
                //cout<<"("<<newNode.coff<<","<<newNode.exp<<")"<<endl;
                i++;j++;
            }
        }
        //加上未完結的list元素
        while(i<poly.size())
        {
            newPoly.push_back(poly[i]);
            i++;
        }
        while(j<Poly2.poly.size())
        {
            newPoly.push_back(Poly2.poly[j]);
            j++;
        }
        poly=newPoly;
        /*cout<<"new poly is :";
        for(int i=0;i<newPoly.size();i++)
        {
            cout<<newPoly[i].coff<<"x^"<<newPoly[i].exp<<"+";
        }cout<<endl;*/
    }

    void multiple(Polynomial Poly2)
    {
        if(poly.size()==0||Poly2.poly.size()==0)
        {
            throw "the Polynomial can not be empty ";
        }
        Polynomial res(0);
        for(int i=0;i<Poly2.poly.size();i++)
        {
            Polynomial temp(0);
            for(int j=0;j<poly.size();j++)
            {
                node newNode;
                newNode.coff=poly[j].coff*Poly2.poly[i].coff;
                newNode.exp=poly[j].exp+Poly2.poly[i].exp;
                temp.poly.push_back(newNode);
            }
            cout<<"sub list"<<endl;
            temp.printLinst();
            res.add(temp);
        }
        poly=res.poly;
    }
};

int main() {
    //std::cout << "Hello, World!" << std::endl;
    Polynomial poly1;//=new Polynomial();
    poly1.printLinst();

    Polynomial poly2;//=new Polynomial();
    poly2.printLinst();

    //poly1.add(poly2);
    poly1.multiple(poly2);
    poly1.printLinst();

    return 0;
}