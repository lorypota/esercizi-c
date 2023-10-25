
// g++ -c main.cpp -o main.o
// g++ main.o -o main.exe

#include <iostream>
#include <string>
// #include "ops.h"

using namespace std;

int main() {
  cout << "Hello world" << endl;

  string s;

  cout << "Inserire msg: ";
  cin >> s;
  cout << "Hai inserito: " << s << endl;

  double n = 0;

  cin >> n;
  cout << "Hai inserito: " << n << endl;

  // stampa();

  int i;
  unsigned int ui;

  short int si;
  long int li;

  float f;
  char c;

  bool b;

  cout << sizeof(int) <<endl;

  return 0;
}