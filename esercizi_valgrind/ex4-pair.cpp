#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	char *a = new char[5];
	a[0] = 'c';
	a[1] = 'i';
	a[2] = 'a';
	a[3] = 'o';
	a[4] = '\n';

	char *b = new char[5];
	int i;
	for(i = 0; i < 5; i++)
		*(b+i) = *(a+i);	// b[i] = a[i];

	delete[] a;
	
	for(i = 0; i < 5; i++)
		cout << b[i];

	delete [] b;

	return 0;
}