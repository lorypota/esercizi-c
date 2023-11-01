#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv)
{
  int i;
  int *a;
  a = new int[10];
  delete[] a;
  a = new int[11];

  for (i = 0; i < 11; i++)
    a[i] = i;

  for (i = 0; i < 11; i++)
    cout << a[i] << " ";

  delete[] a;
  a = new int[11];
  a[10] = 11;
  cout << "- " << a[10];
  cout << endl;
  delete[] a;
  
  return 0;
}