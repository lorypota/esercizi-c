#define i 10 
#include <iostream>
#include "misc.h"

int main(int argc, char*argv[]) {
	
	int *array = new int[i];
	
	std::cout<<"Filling array with 0s"<<std::endl;
	fill_array(array, i, 0); 
	print_array("array", array, i);

	std::cout<<"Setting array values"<<std::endl;
	for(int c = 0, j = 0;  c < i; ++c, j+=100) 
		array[c] = c + j;
	
	print_array("array", array, i);
	
	std::cout<<"Cloning array"<<std::endl;
	int *clone = clone_array(array, i);
	print_array("clone", clone, i);
	
	std::cout<<"Filling clone with 0s"<<std::endl;
	fill_array(clone, i, 0);
	print_array("clone", clone, i);
	
	delete[] clone; 
	clone = nullptr;

	std::cout<<"array after destroying clone"<<std::endl;
	print_array("array", array, i);
	
	return 0;
}

/*
L'output del programma deve essere:

Filling array with 0s
array [ 0 0 0 0 0 0 0 0 0 0 ]
Setting array values
array [ 0 101 202 303 404 505 606 707 808 909 ]
Cloning array
clone [ 0 101 202 303 404 505 606 707 808 909 ]
Filling clone with 0s
clone [ 0 0 0 0 0 0 0 0 0 0 ]
array after destroying clone
array [ 0 101 202 303 404 505 606 707 808 909 ]

*/