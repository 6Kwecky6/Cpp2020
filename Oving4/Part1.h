//
// Created by Kwecky on 13/09/2020.
//

#ifndef OVING4_PART1_H
#define OVING4_PART1_H
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void task1(double input){
    vector<double> num = {12.4,2.21,65.4,4.3,22.6};
    cout << "Vector: ";
    for(auto &decimal:num) {
        cout << decimal << ", ";
    }
    cout << endl;
    cout << "Front(): " << num.front() << endl << "Back()" << num.back() <<endl;
    double new_num = 191.8;
    num.emplace(num.begin()+1,new_num);
    cout << "Vector: ";
    for(auto &decimal:num) {
        cout << decimal << ", ";
    }
    cout << endl;

    auto res = find(num.begin(),num.end(), input);
    if(res==num.end()){
        cout<< "Did not find the number" <<endl;
    }else{
        cout << "Found the number at "<< res-num.begin()<< endl;
    }

}
#endif //OVING4_PART1_H
