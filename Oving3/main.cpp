#include <iostream>
#include "task1.h"
#include "task3.h"

using namespace std;

int main() {
    //Task 2
    cout <<"<--------Starting task 1-2------------>" << endl;
    Circle circle(5.);
    double area = circle.get_area();

    cout << "Arealet er lik " << area << endl;

    double circumference = circle.get_circumference();
    cout << "Omkretsen er lik " << circumference << endl;
    //Task 3
    cout <<"<--------Starting task 3------------>" << endl;
    const double quantity = 2.5;
    Commodity commodity("Norvegia", 123, 73.50);

    cout << "Varenavn: " << commodity.get_name() << ", varenr: " << commodity.get_id() << " Pris pr enhet: " << commodity.get_price() << endl;

    cout << "Kilopris: " << commodity.get_price() << endl;
    cout << "Prisen for " << quantity << " kg er " << commodity.get_price(quantity) << " uten moms" << endl;
    cout << "Prisen for " << quantity << " kg er " << commodity.get_price_with_sales_tax(quantity) << " med moms" << endl;

    commodity.set_price(79.60);
    cout << "Ny kilopris: " << commodity.get_price() << endl;
    cout << "Prisen for " << quantity << " kg er " << commodity.get_price(quantity) << " uten moms" << endl;
    cout << "Prisen for " << quantity << " kg er " << commodity.get_price_with_sales_tax(quantity) << " med moms" << endl;

    cout <<"<--------Starting task 4------------>" << endl;
    cout <<"Please give the first word: ";
    string w1,w2,w3;
    cin >> w1;
    cout<<"Now, another one please ";
    cin>> w2;
    cout<< "Last one now ";
    cin >>w3;
    string sentence = w1+", "+w2+", "+w3+".";
    cout << "The combined sentence is: "<< endl <<sentence;
    cout << "Word 1 length: " << w1.length()<<endl<<
    "Word 2 length: " << w2.length()<<endl<<
    "Word 3 length: " << w3.length()<<endl<<
    "Length of the entire sentence: " << sentence.length() <<endl;

    //size_t length = sentence.length();
    string sentence2 = sentence;
    cout<<sentence2<<endl;
    for(int i = 9;i<12;i++) {
        sentence2[i] = 'X';
    }
    cout<<"sentence value: "<< endl<<sentence<< endl<<"sentence2 value: "<< endl<<sentence2<< endl;
    string start_sentence = sentence.substr(0,6);
    cout<<"sentence value: "<< endl<<sentence<< endl<<"start_sentence value: "<< endl<<start_sentence<< endl;
    if(sentence.find("hallo")==string::npos){
        cout<<"there are no hallo in the sentence"<<endl;
    }else{
        cout<<"Yes, there are hallo in this sentence"<<endl;
    }
    int i = 0;
    while(sentence.find("er",i)!=string::npos){
        i=sentence.find("er",i);
        cout << "'er' has been found at pos " << i<< endl;
        i++;
    }
}