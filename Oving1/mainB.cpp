//
// Created by Kwecky on 18/08/2020.
//
#include <iostream>
#include <fstream>
using namespace std;

void read_temperatures(double temperatures[], int length);

int main(){
    const short len = 5;
    double temp[len];
    int low = 0;
    int medium = 0;
    int high = 0;
    read_temperatures(temp,len);

    for(int i=1;i<=len;i++){
        if(temp[i-1]<10.0) low++; //Temp is lower than 10 degrees
        else if(temp[i-1]>20.0) high++; //Temp is higher than 20 degrees
        else medium++;//Temp is between 10 and 20 degrees
    }
    cout << "Antall under 10 er " << low <<endl
         << "Antall mellom 10 og 20 er " << medium << endl
         << "Antall over 20 er " << high<< endl;
}

void read_temperatures(double temperatures[], int length){
    const char fileName[] = "../degree.log"; //Regner med du har exe filen i egen build mappe
    ifstream  log;
    log.open(fileName);
    if(!log){
        cout << "Feil ved åpning av log." << endl;
        exit(EXIT_FAILURE);
    }

    for(int i = 0;i<length;i++){
        log >> temperatures[i]; //Is this legal?

    }
    log.close();
}