//
// Created by Kwecky on 30/08/2020.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double number = 14.4;
    double *numberPtr=&number;
    double &numberRef=number;
    cout << "Direct ref" << setw(16) << "Pointer" << setw(16) << "Reference" << endl
         << number << setw(16) << *numberPtr << setw(16) << numberRef << endl;

    return 0;
}