#include "misc.h"
#include <iostream>


void print_array(const char *varname,const int *ar, int size) {
	std::cout<<varname<<" [ ";
	for(int i = 0; i < size; ++i) std::cout<<ar[i]<<" ";
	std::cout<<"]"<<std::endl;
}

void fill_array(int *ar, int size, int value) {
	for(int i = 0; i < size; ++i) ar[i] = value;
}

int *clone_array(const int *ar, int size) {
	int *temp = new int[size];

	for (int i = 0; i < size; ++i) {
		temp[i] = ar[i];
	}

	return temp;
}
