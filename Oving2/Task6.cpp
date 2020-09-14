//
// Created by Kwecky on 30/08/2020.
//
#include <iostream>
#include <iomanip>

using namespace std;

int find_sum(const int *table, int length);

int main(){
    const int len = 20;
    int table[len];
    int *tablePtr = table;
    for(int i = 0; i < len; i++){
        *tablePtr = i;
        tablePtr++;

    }
    cout << "First 10" << setw(16) << "Next 5" << setw(16) << "Last 5" <<setw(16) << "Total" << endl
         << find_sum(table,10) << setw(16) << find_sum(table+10,5) << setw(16) << find_sum(table+len-5,5) << setw(16)<< find_sum(table,len)<<endl;

    return 0;
}

int find_sum(const int *table, int length){
    int res = 0;
    for(int i=0;i<length;i++){
        res += *table;
        table++;

    }
    return res;

}