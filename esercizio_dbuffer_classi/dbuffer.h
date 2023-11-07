#ifndef DBUFFER_H
#define DBUFFER_H

class DBuffer{
private:
  unsigned int size;
  int *buffer;

public:
  DBuffer(void);
  DBuffer(const DBuffer& src);
  ~DBuffer();
  void stampa();
  void inizializza();
  void alloca_mem(unsigned int size = 10);
  void dealloca_mem();
  void riempi(int value);
  void riempi(int *values, unsigned int size);
};

#endif