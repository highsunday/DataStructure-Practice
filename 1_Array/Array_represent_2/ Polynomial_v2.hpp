//
//   Polynomial_v2.hpp
//  Array_represent_2
//
//  Created by 高昊 on 2019/10/2.
//  Copyright © 2019年 高昊. All rights reserved.
//

/***********************************************************
 * 改善空間:
 *      Polynomial_Multi 尚有可以優化的空間
 *      將一組資料整合成一個pair會比分開還要更容易操作以及增加可讀性
 **********************************************************/
#ifndef _Polynomial_v2_hpp
#define _Polynomial_v2_hpp

#include <stdio.h>
#include <vector>
using namespace std;

class Polynomial_v2
{
public:
    int degree;
    vector<int> PolyVector;
    
public:
    Polynomial_v2();
    Polynomial_v2 PolynomialAdd(Polynomial_v2 pol2);
    Polynomial_v2 Polynomial_Multi(Polynomial_v2 pol2);
    double Eval(double x);
    
    void setPolynomial();
    void printPolynomial();
};
#endif /* _Polynomial_v2_hpp */
