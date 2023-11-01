#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
  /* char str[10]; */
  /* cin.width(10); */
  string str;
  // cin >> str; this stops at the first whitespace character
  getline(cin, str); //this doesn't stop at the first whitespace character
  cout << str << endl;

  return 0;
}