#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

void generate_vector(std::vector<int> &vector,int min_range,int max_range){
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(min_range,max_range);
    for(int i=0;i<20;i++){
        int num_v1=dist(mt);
        vector.push_back(num_v1);

    }
}

void generate_vector(std::vector<double> &vector,const int &min_range,const int &max_range){
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(min_range,max_range);
    for(int i=0;i<20;i++){
        double num_v1=dist(mt);
        vector.push_back(num_v1);

    }
}

template <typename Type>
void print(const Type val){
    std::cout<<' '<<val;
}

template <typename Type1,typename Type2>
bool eq(const std::vector<Type1> &vec1, const std::vector<Type2> &vec2){
    return std::equal(vec1.begin(),vec1.end(),vec2.begin(),vec2.end(),[](Type1 val1,Type2 val2){
        return std::abs(val1-val2)<=2;
    });
}

int main() {
    //Generates vectors
    std::vector<int> v1;
    std::vector<double> v2;

    generate_vector(v1,-50,50);
    generate_vector(v2,-50,50);
    std::vector<int> v3(20);
    std::copy(v1.begin(),v1.end(),v3.begin());
    v3[10]+=4;//Deviating one number
    //Print generators
    std::cout<<"v1: ";
    std::for_each(v1.begin(),v1.end(),print<int>);
    std::cout<<std::endl<<"v2: ";
    std::for_each(v2.begin(),v2.end(),print<double>);
    std::cout<<std::endl<<"v3: ";
    std::for_each(v3.begin(),v3.end(),print<int>);
    std::cout<<std::endl;
    //Start part a)
    auto first_high = std::find_if(v1.begin(),v1.end(),[](int &i){
        return i>15;
    });

    std::cout<<"The first number higher than 15 in v1 is "<<*first_high<<std::endl;
    //Start part b)
    if(eq(v1,v2)){//probably not equal
        std::cout<<"The v1 vector are equal to v2"<<std::endl;
    }else{
        std::cout<<"The the v1 vector are not equal to v2"<<std::endl;
    }

    if(eq(v1,v3)){//Will never be equal
        std::cout<<"The v1 vector are equal to v3"<<std::endl;
    }else{
        std::cout<<"The the v1 vector are not equal to v3"<<std::endl;
    }

    //v1.begin()+7 means that the iterator points at the first value in the vector, then skips 7 numbers down the line in the vector.
    // Meaning that this equal will only check the first 7 instances in the vector
    if(std::equal(v1.begin(),v1.begin()+7,v3.begin(),v3.begin()+7,[](int val1,int val2){ //This should be equal always
        return std::abs(val1-val2)<=2;
    })){
        std::cout<<"The v1 vector are equal to v3"<<std::endl;
    }else{
        std::cout<<"The the v1 vector are not equal to v3"<<std::endl;
    }
    //Start part c)
    std::vector<int> v4(20);
    std::replace_copy_if(v1.begin(),v1.end(),v4.begin(),[](int val){
        //This should bitshift right then left, efficiently eliminating the bit to the right that also symbolizes if it's odd.
        //If number is still the same after the shift, it's an even number
        //I think this is lighter on the cpu since it handles bit operands well on contrary to modulus
        return ((val>>1)<<1)!=val;
    },100);
    std::cout<<"v4: ";
    std::for_each(v4.begin(),v4.end(),print<int>);
    std::cout<<std::endl;


    return 0;
}