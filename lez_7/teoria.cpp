#include <iostream>
using namespace std;
/* using namespace pluto; */
int global;

void f() {
  int j = 0;
}

void g() {
  static int x = 0;
}

void a() {
  int *p = nullptr;
  int n = 90;

  p = new int[n];

  *(p+1) = 9;
  delete[] p;
  p = nullptr;
}

namespace pluto {
  int global;

  void a(){

  }
}

void funct(int i) {
  //uso i
}

void funct2(int *pi) {
  int valore = *pi; // int valore = ii;

  *pi = 0; //ii = 0;
}

void funct4(int *pi, int sz) {

}

void funct3(int &ri) { // int &ri = ii;
 ri = 10; // ii = 10;
}

void funct_b(const int i) {

}

void funct2_b(const int* pi) {
  int x = *pi;
  // *pi = 0; errore
  pi = nullptr;
}

void funct3_b(const int &ri) {
  int x = ri;
  //ri = 0; errore
  
}

int main(int argc, char* argv[]) {
  /* int j = global; //errore */

  int ii = 100;

  funct(ii);
  funct(900);

  funct2(&ii);

  funct3(ii);

  int array[10];
  funct4(array, 10);

  return 0;
}
