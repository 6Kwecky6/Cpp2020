//
// Created by kwecky on 22.10.20.
//

#ifndef TASK8_PART2_H
#define TASK8_PART2_H
template <typename Type_1, typename Type_2>
class Pair{
public:
    Type_1 a;
    Type_2 b;

    Pair(const Type_1 &a,const Type_2 &b):a(a),b(b){}

    Pair operator+(const Pair &other)const{
        auto new_a = a+other.a;
        auto new_b = b+other.b;
        return Pair(new_a,new_b);
    }

    bool operator<(const Pair &other)const{
        auto total_this = a+b;
        auto total_other = other.a+other.b;
        return total_this<total_other;
    }

    bool operator>(const Pair &other)const{
        auto total_this = a+b;
        auto total_other = other.a+other.b;
        return total_this>total_other;
    }

};

#endif //TASK8_PART2_H
