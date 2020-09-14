#include <iostream>
using namespace std;

int main() {
    const short len = 5;
    double temp = 0;
    int low = 0;
    int medium = 0;
    int high = 0;
    cout << "Du skal skrive inn 5 temperaturer." <<endl;
    for(int i=1;i<=len;i++){
        cout << "Temparatur nr " << i << ": ";
        cin >>temp;
        if(temp<10.0) low++; //Temp is lower than 10 degrees
        else if(temp>20.0) high++; //Temp is higher than 20 degrees
        else medium++;//Temp is between 10 and 20 degrees
    }
    cout << "Antall under 10 er " << low <<endl
    << "Antall mellom 10 og 20 er " << medium << endl
    << "Antall over 20 er " << high<< endl;
}