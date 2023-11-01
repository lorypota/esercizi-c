/**
  @file main.cpp

  @brief File principale di progetto

  File di test dell'esercizio sui puntatori e stringhe C 
*/

#include <iostream>
#include <cassert>
#include "stringheC.h"

int main(int argc, char *argv[]) {
  
  if(argc > 1) {

    stampa_caratteri(argv[1]);
    std::cout<<"-----------"<<std::endl;

    std::cout << "Lunghezza stringa: " << calcola_lunghezza(argv[1]) << std::endl;
    std::cout<<"-----------"<<std::endl;

    char *clone = clona_stringa(argv[1]);
    std::cout << "Stringa clonata: " << clone << std::endl;
    std::cout<<"-----------"<<std::endl;

    inverti_stringa(clone);
    std::cout << "Stringa invertita: " << clone << std::endl;
    std::cout<<"-----------"<<std::endl;

    delete[] clone;
    clone = nullptr;
  }

  if(argc > 2) {
    char *concatenazione = concatena_stringhe(argv[1], argv[2]);
    std::cout << "Stringhe concatenate: " << concatenazione << std::endl;
    delete[] concatenazione;
    concatenazione = nullptr;
    std::cout<<"-----------"<<std::endl;

    char *match = trova_occorrenza(argv[1], argv[2]);
    if(match == nullptr) {
      std::cout << "Nessun match trovato." << std::endl;
    } else {
      std::cout << "Match trovato: " << match << std::endl;
    }
    std::cout<<"-----------"<<std::endl;
  }

  if(argc > 3) {
    rimpiazza_tk(argv[1], argv[2], argv[3]);
    std::cout << "Sovrascrivendo ogni occorrenza: " << argv[1] << std::endl;
    std::cout<<"-----------"<<std::endl;
  }

  return 0;
}
