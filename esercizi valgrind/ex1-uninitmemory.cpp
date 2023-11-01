#include <iostream>
#include <cstdlib> 

using namespace std;

int main(int argc, char** argv)
{
  int i;
  int *a = new int[10];
  for (i = 0; i < 9; i++)
    a[i] = i;
    
  for (i = 0; i < 9; i++){
    cout << a[i] << " ";
  }

  cout << endl;

  int b = a[9];
  delete[] a;
  return 0;
}