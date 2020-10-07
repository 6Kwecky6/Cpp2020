#include "fraction.hpp"
#include "Set.hpp"
#include <iostream>
#include <string>

using namespace std;

void print(const string &text, const Fraction &broek) {
  cout << text << broek.numerator << " / " << broek.denominator << endl;
}

int main() {
  Fraction a(10, 20);
  Fraction b(3, 4);
  Fraction c;
  c.set(5);
  Fraction d = a / b;

  print("a = ", a);
  print("b = ", b);
  print("c = ", c);
  print("d = ", d);

  b += a;
  ++c;
  d *= d;

  print("b = ", b);
  print("c = ", c);
  print("d = ", d);

  c = a + b - d * a;
  c = -c;

  print("c = ", c);

  if (a + b != c + d)
    cout << "a + b != c + d" << endl;
  else
    cout << " a + b == c + d" << endl;
  while (b > a)
    b -= a;
  print("b = ", b);

  //My implementation -------------------------------
  print("3 - b =",3-b);
  print("b - 3 = ",b-3);

  //Part 2
  Set set1=Set();
  Set set2=Set();

  set1=set1 + 2 + 7 + 5 + 3 + 19 + 53;
  cout << "Set1: " << set1 << endl;
  set2 = set2 + 4 + 5 + 21 + 42 + 19 + 123;
  cout << "Set2: " << set2 << endl;
  cout << "Set1 + Set2: "<<set1+set2<<endl;

}
