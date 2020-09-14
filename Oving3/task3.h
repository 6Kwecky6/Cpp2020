//
// Created by Kwecky on 04/09/2020.
//

#ifndef OVING3_TASK3_H
#define OVING3_TASK3_H

#include <string>
#include <iostream>

using namespace std;
const double tax = 1.2;

class Commodity{
private:
    string name;
    int id;
    double price;

public:
    Commodity(const string &name_, int id_, double price_);
    const string &get_name() const;
    int get_id() const;
    double get_price() const;
    double get_price_with_sales_tax() const;
    double get_price(const double &quantity) const;
    double get_price_with_sales_tax(const double &quantity) const;
    void set_price(const double &price_);
};

Commodity::Commodity(const string &name_, int id_, double price_) : name(name_),id(id_),price(price_){}
const string &Commodity::get_name() const{
    return name;
}
int Commodity::get_id() const {
    return id;
}
double Commodity::get_price(const double &quantity) const {
    return price*quantity;
}
double Commodity::get_price_with_sales_tax(const double &quantity) const {
    return price*quantity*tax;
}

double Commodity::get_price() const {
    return price;
}
double Commodity::get_price_with_sales_tax() const {
    return price*tax;
}
void Commodity::set_price(const double &price_) {
    price= price_;
}

#endif //OVING3_TASK3_H
