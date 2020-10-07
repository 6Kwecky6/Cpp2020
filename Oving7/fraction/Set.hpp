//
// Created by kwecky on 07.10.20.
//

#ifndef FRACTION_SET_HPP
#define FRACTION_SET_HPP

#include <iostream>
#include <vector>

class Set{
public:
    std::vector<int> vector;
    Set(){
        vector = std::vector<int>();
    }

    //Union operator. Set1 + Set2= Set3
    Set operator+(const Set &other)const{
        Set res = *this;
        for(int other_int:other.vector){
            bool exists = false;
            for(int this_int:vector){
                if(other_int==this_int){
                    exists=true;
                    break;
                }

            }
            if(!exists) res.vector.emplace_back(other_int);

        }
        return res;

    }

    //Add operator. Set + int = newSet
    Set operator+(const int &other)const{
        Set res = *this;
        bool exists=false;
        for(int i :vector){
            if(i==other){
                exists=true;
                break;
            }
        }
        if(!exists) res.vector.emplace_back((other));

        return res;
    }


    //Copy external set to current set. Set1=Set2
    Set &operator=(const Set &other){
        vector = other.vector;
        return *this;

    }


};
//Add operator. int + Set = newSet
Set operator+(const int &integer,const Set &set){
    Set res = set;
    bool exists=false;
    for(int i:set.vector){
        if(i==integer){
            exists=true;
            break;
        }
    }
    if(!exists) res.vector.emplace_back(integer);
    return res;

}
//Print Set. out<<Set; prints {1, 2, 3, 4, 5}
std::ostream &operator<<(std::ostream &out,const Set &set){
    out<<"{";
    for(int i:set.vector){
        if(i!=set.vector.back()){
            out<<i<<", ";
        }else{
            out<<i<<"}";
        }

    }
    return out;
}

#endif //FRACTION_SET_HPP
