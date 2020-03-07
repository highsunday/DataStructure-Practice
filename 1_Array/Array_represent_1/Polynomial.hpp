//
//  Polynomial.hpp
//  Array_represent_1
//
//  Created by 高昊 on 2019/10/1.
//  Copyright © 2019年 高昊. All rights reserved.
//

#ifndef Polynomial_hpp
#define Polynomial_hpp

#include <stdio.h>
class Polynomial
{
public:
    int sizeArray;
    int* Array;
    
public:
    Polynomial(int);
    Polynomial PolynomialAdd(Polynomial pol2);
    Polynomial Polynomial_Multi(Polynomial pol2);
    double Eval(double x);
    
    void setPolynomial();
    void printPolynomial();
};
#endif /* Polynomial_hpp */
