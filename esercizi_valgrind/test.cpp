#include <iostream>

int main() {
  int *buffer = new int[10];
  std::cout<<buffer[3]<<std::endl; // uso di celle non inizializzate
  delete[] buffer;
  return 0;
}