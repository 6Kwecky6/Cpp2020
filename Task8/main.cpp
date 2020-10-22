#include <iostream>
#include "Part1.h"
#include "Part2.h"



int main() {
    //Part 1
    int a=2;
    int b=6;
    int c=2;
    double a_double=1.976765;
    double b_double=4.865446;
    double c_double=1.976768;
    double d_double=1.976765;
    double e_double=1.976756;
    std::cout
    <<"Template test should return false: "<<equal(a,b)<<std::endl
    <<"Template test should return true: "<<equal(a,c)<<std::endl
    <<"Overloading test should return false: "<<equal(a_double,b_double)<<std::endl
    <<"Overloading test should return true: "<<equal(a_double,c_double)<<std::endl
    <<"Overloading test should return true: "<<equal(a_double,d_double)<<std::endl
    <<"Overloading test should return true: "<<equal(a_double,e_double)<<std::endl;
    //Part2
    Pair<double, int> p1(3.5, 14);
    Pair<double, int> p2(2.1, 7);
    std::cout << "p1: " << p1.a << ", " << p1.b << std::endl;
    std::cout << "p2: " << p2.a << ", " << p2.b << std::endl;

    if (p1 > p2)
        std::cout << "p1 er størst" << std::endl;
    else
        std::cout << "p2 er størst" << std::endl;

    auto sum = p1 + p2;
    std::cout << "Sum: " << sum.a << ", " << sum.b << std::endl;
    return 0;
}