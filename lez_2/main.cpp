#include <iostream>
#include <string>

using namespace std;

int main() {
  int test = 1000;

  int *pi = nullptr;

  pi = &test;

  cout << "Contenuto di test: " << test << endl;
  cout << "Indirizzo di test: " << &test << endl;
  cout << "Contenuto di pi: " << pi << endl;
  cout << "Inirizzo di pi: " << &pi  << endl;


  int test2 = 999;

  pi = &test2;

  cout << "Contenuto del dato puntato: " << *pi << endl;

  *pi = 100; // test2 = 100;
}