//
// Created by kwecky on 22.10.20.
//

#ifndef TASK8_PART1_H
#define TASK8_PART1_H

template <typename Type> bool equal(Type &a, Type &b){
    return a==b;
}
bool equal(double &a,double &b){
    double abs=a-b;
    if(abs<0)abs*=-1;
    return abs<0.00001;
}

#endif //TASK8_PART1_H
