#include <iostream>
#include <cassert>
#include "dbuffer.h"

DBuffer::DBuffer(void) : size(0), buffer(nullptr) { }

DBuffer::DBuffer(const DBuffer& src) {
  size = src.size;
  if(src.buffer != nullptr) {
    buffer = new int[size];
    for(unsigned int i = 0; i < size; i++) {
      buffer[i] = src.buffer[i];
    }
  }
}

DBuffer::~DBuffer() {
  dealloca_mem();
}

void DBuffer::stampa() {
  std::cout << "[ ";
  for(int i = 0; i < size; i++){
    std::cout << buffer[i] << " ";
  }
  std::cout << "]"<< std::endl;
}

void DBuffer::inizializza() {
  size = 0;
  buffer = nullptr;
}

void DBuffer::alloca_mem(unsigned int size) {
  dealloca_mem();
  this->size = size;
  buffer = new int[size];
}

void DBuffer::dealloca_mem() {
  delete[] buffer;
  inizializza();
}

void DBuffer::riempi(int value) {
  for(unsigned int i = 0; i < size; i++) {
    buffer[i] = value;
  }
}

void DBuffer::riempi(int *values, unsigned int size) {
  assert(this->size == size);
  for(unsigned int i = 0; i < size; i++) {
    buffer[i] = values[i];
  }
}

int main(){
  using namespace std;

  cout << "Testing DBuffer class..." << endl;

  cout << "Creating a buffer of 5 integers." << endl;
  DBuffer dbuffer;
  dbuffer.alloca_mem(5); // Allocates memory for 5 integers

  cout << "Filling the buffer with the value 1." << endl;
  dbuffer.riempi(1); // Fills the buffer with 1s
  dbuffer.stampa(); // Should print: [ 1 1 1 1 1 ]

  cout << "Creating a copy of the current buffer." << endl;
  DBuffer dbuffer_copy = dbuffer; // Invokes the copy constructor
  dbuffer_copy.stampa(); // Should print: [ 1 1 1 1 1 ]

  cout << "Changing the original buffer to 2s." << endl;
  dbuffer.riempi(2);
  dbuffer.stampa(); // Should print: [ 2 2 2 2 2 ]

  cout << "The copy should remain unchanged." << endl;
  dbuffer_copy.stampa(); // Should still print: [ 1 1 1 1 1 ]

  cout << "Changing original buffers to [ 4, 2, 2, 3, 1 ]" << endl;
  int vals[] = {4, 2, 2, 3, 1};
  dbuffer.riempi(vals, 5);
  dbuffer.stampa();

  cout << "Testing complete. Exiting program will trigger destructors." << endl;
  
  return 0;
}