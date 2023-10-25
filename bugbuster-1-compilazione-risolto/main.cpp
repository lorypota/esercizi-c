#include "file1.h"
#include "file2.h"
#include <iostream>


int main() {

	std::cout<<"dentro il main"<<std::endl;

	funzione1_1();
	
	funzione2_2();
}
/*
L'output del programma deve essere:

dentro il main
dentro funzione1_1
dentro funzione1_2
dentro funzione3_2
dentro funzione2_1
dentro funzione2_2
dentro funzione3_2
dentro funzione1_2
*/