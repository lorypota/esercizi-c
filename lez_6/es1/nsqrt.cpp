#include "nsqrt.h"
#include <cmath> // std::fabs
#include <cassert> // assert

double nsqrt(double x, double epsilon) {
  assert(x>0);
  assert(epsilon>0);

  double s = x/2;

  while (std::fabs(s*s-x) >= epsilon) {
    s = (s*s+x)/(2*s);
  }

  return s;
}