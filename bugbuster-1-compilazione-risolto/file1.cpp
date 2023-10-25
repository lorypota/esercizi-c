#include "file1.h"
#include "file2.h"
#include <iostream>

void funzione1_1() {

	std::cout << "dentro funzione1_1" << std::endl;

	funzione1_2();
	
	funzione3_2();
	
	funzione2_1();

}

void funzione2_1() {

	std::cout << "dentro funzione2_1" << std::endl;
}

