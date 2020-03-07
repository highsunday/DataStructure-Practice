//
//  main.cpp
//  Array_represent_2
//
//  Created by 高昊 on 2019/10/2.
//  Copyright © 2019年 高昊. All rights reserved.
//

#include <iostream>
#include " Polynomial_v2.hpp"

using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    Polynomial_v2 p1=Polynomial_v2();
    p1.setPolynomial();
    p1.printPolynomial();
    Polynomial_v2 p2=Polynomial_v2();
    p2.setPolynomial();
    p2.printPolynomial();
    /*Polynomial_v2 p3=Polynomial_v2();
    p3=p1.PolynomialAdd(p2);
    p3.printPolynomial();*/
    Polynomial_v2 p3=Polynomial_v2();
    p3=p1.Polynomial_Multi(p2);
    p3.printPolynomial();
    return 0;
}
