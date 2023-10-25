#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

int main(int argc, char *argv[]) {
  int nintervals = 0;

  cout << "Inserire numero di intervalli: ";
  cin >> nintervals;

  // assert(nintervals > 0);

  if(nintervals <= 0) {
    cerr << "Inserire un valore valido" <<endl;
    return 0;
  }
  

  double delta = M_PI / nintervals;

  double result = 0.0;

  double x1 = 0.0, x2 = delta;
  for(int i = 0; i < nintervals; ++i) {
    result += (sin(x1)+sin(x2));
    x1 = x2;
    x2 = x2 + delta;
  }

  result *= 0.5 * delta;

  cout << "Il risultato dell'integrale e': " << result << endl;

  return 0;
}