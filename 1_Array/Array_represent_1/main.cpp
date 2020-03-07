//
//  main.cpp
//  Array_represent_1
//
//  Created by 高昊 on 2019/10/1.
//  Copyright © 2019年 高昊. All rights reserved.
//
#include "Polynomial.hpp"
#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    Polynomial p1=Polynomial(3);
    p1.setPolynomial();
    p1.printPolynomial();
    Polynomial p2=Polynomial(2);
    p2.setPolynomial();
    p2.printPolynomial();
    /*Polynomial p3=Polynomial(0);
    p3=p1.PolynomialAdd(p2);
    p3.printPolynomial();*/
    Polynomial p3=Polynomial(0);
    p3=p1.Polynomial_Multi(p2);
    p3.printPolynomial();
    return 0;
}
