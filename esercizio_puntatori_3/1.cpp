#include <iostream>
using namespace std;

int main() {
  int N;
  cout << "Inserire numero di interi da memorizzare: ";
  cin >> N;

  //cosi fa un po' schifo
  /* int* v = new int[N];
  for(int i = 0; i < N; i++){
    cout <<"Number in pos " << i << ": ";
    cin >> *v;
    cout << endl;
    if(i+1 != N)
      v++;
  }

  int sum = 0;

  for(int i = 0; i < N; i++){
    sum += *v;
    if(i+1 != N)
      v--;
  } */

  //credo un po' meglio
  int* v = new int[N];
  int* temp = v;

  for(int i = 0; i < N; i++){
    cout << "Number in pos " << i << ": ";
    cin >> *temp; 
    temp++;
    cout << endl;
  }

  temp = v; // Reset temp to point to the start of v before using it
  int sum = 0;

  for(int i = 0; i < N; i++, temp++){
    sum += *temp;
  }

  cout << "The sum is: " << sum << endl;
  delete[] v;
}