#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    //a)
    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;

    cout << "Var name" << setw(16) << "Content" << setw(16) << "Address" << endl
         << "i" << setw(16) << i << setw(16) << &i << endl
         << "j" << setw(16) << j << setw(16) << &j << endl
         << "p" << setw(16) << p << setw(16) << &p << endl
         << "q" << setw(16) << q << setw(16) << &q << endl;

    //b)
    // Note for before running:
    //*p = 7 => i = 7
    //*q += 4 => j = 9
    //*q = *p + 1 => j = i +1 = 8
    //p = q => p now contains the location that q points at, in other words p = 8
    //Print: 8 8
    *p = 7;
    *q += 4;
    *q = *p + 1;
    p = q;
    cout << *p << " " << *q << endl;
    //Correct

    char input[5];
    cin >> input;
    cout << input;
    return 0;
}
