#include <cstdio>
#include <iostream>

int main(int argc, char** argv)
{
  int i;
  int *a;

  for (i=0; i < 10; i++){
    a = new int[100];
    //.. use the array ..
    delete[] a;
  }

  return 0;
}