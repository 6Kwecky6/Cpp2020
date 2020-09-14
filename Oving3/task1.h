//
// Created by Kwecky on 04/09/2020.
//

#ifndef OVING3_TASK1_H
#define OVING3_TASK1_H
const double pi = 3.141592;

class Circle {
public:
    Circle(double radius_);//Constructor must be named the same as the class
    double get_area() const;
    double get_circumference() const;
private://private must be followed by colon, kind of like with a Python loop or something
    double radius;
}; //Class must end with semi colon

// ==> Implementasjon av klassen Circle


Circle::Circle(double radius_) : radius(radius_) {} //Public isn't a thing outside of a class, and attribute takes in a variable, not the other way around

double Circle::get_area() const{ //get_area needs to specify const here as well, also looses accuracy, since it returns an int
    return pi * radius * radius;
}

double Circle::get_circumference() const { //doesn't have a type for this method
    return 2.0 * pi * radius; //Doesn't need to go through the circumference variable
}
#endif //OVING3_TASK1_H
