#include <iostream>
#include <cmath> // std::sqrt
#include "nsqrt.h" // nsqrt

/*
  Codice main dell'esercizio 1

  Compilate eseguendo il programma make:
  make 
*/

int main() {

  double x = 0.0;

  std::cout << "Dare un valore reale positivo: ";
  std::cin >> x; 

  if (x<0) {
    std::cerr << "Inserire un valore reale positivo." << std::endl;
    return 0;
  }

  double radix = nsqrt(x, 1e-3);

  std::cout << "Il valore di nsqrt(x) è    : " << radix << std::endl;
  std::cout << "Il valore di std::sqrt(x) è: " << std::sqrt(x) << std::endl;


  return 0;
}