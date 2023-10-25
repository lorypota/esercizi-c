#include <iostream>
#include <cassert>

typedef unsigned int size_type; //<< tipo che definisce la dimensione di un array

/**
 * @brief Stampa i caratteri della stringa
 * 
 * Funzione che stampa i caratteri della stringa C di input 
 * un carattere per riga.
 * 
 * @param str puntatore alla stringa C di input
 * 
 * @pre str != nullptr
*/
void stampa_caratteri(const char *str) {
  assert(str != nullptr);

  while(*str != '\0'){
    std::cout << *str << std::endl;
    str++;
  }
}

/**
 * @brief Calcola la lunghezza di una stringa
 * 
 * Funzione che calcola la lunghezza di una stringa C
 * 
 * @param str puntatore alla stringa C di input
 * 
 * @return la lunghezza della stringa C senza terminatore
 * 
 * @pre str != nullptr
*/
size_type calcola_lunghezza(const char *str) {
  assert(str != nullptr);

  size_type length = 0;
  while(*str != '\0'){
    length++;
    str++;
  }
  return length;
}

/**
 * 
*/
void inverti_stringa(const char *str) {
  int i = 0;
  while(*str != '\0') {
    i++;
    str++;
  }

  char new_string[i];

  str = 0;
}

int main(int argc, char *argv[]) {
  
  if(argc > 1) {

    stampa_caratteri(argv[1]);

    std::cout << "Lunghezza stringa: " << calcola_lunghezza(argv[1]) << std::endl;
  
  }
  return 0;
}
