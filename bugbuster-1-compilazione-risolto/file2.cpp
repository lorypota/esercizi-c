#include "file2.h"
#include <iostream>

void funzione1_2() {

	std::cout<<"dentro funzione1_2"<<std::endl;

}

void funzione2_2() {

	std::cout<<"dentro funzione2_2"<<std::endl;

	funzione3_2();
	funzione1_2();
}

void funzione3_2() {

	std::cout<<"dentro funzione3_2"<<std::endl;
		
}