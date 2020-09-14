//
// Created by Kwecky on 30/08/2020.
//

int main(){
    int a = 5;
    int &b = a;//Reference types must be linked to a variable when being initialized
    int *c;
    c = &b;
    a = b + *c;//Neither a nor b are pointers
    b = 2; //reference types doesn't need the & sign after initialisation to point to it's reference
    return 0;
}