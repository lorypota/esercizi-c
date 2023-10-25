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
 * @brief Funzione che inverte la stringa
 * 
 * Funzione che inverte la stringa in-place
 * 
 * @param str puntatore alla stringa C di input
 * 
 * @pre str!=nullptr
*/
void inverti_stringa(char *str) {
  assert(str != nullptr);

  size_type n = calcola_lunghezza(str);
  char *str1 = str + n - 1;
  char tmp;

  for(; str < str1; str++, str1--) {
    std::swap(*str, *str1);
    /* tmp = (*str);
    *str = *str1;
    *str1 = tmp; */
  }
}

/**
 * @brief Funzione che clona la stringa di input
 * 
 * Funzione che clona la stringa di input in una nuova
 * stringa C allocata dinamicamente. L'ownership della
 * stringa risultato è ceduta al chiamante.
 * 
 * @param str puntatore stringa C di input
 * 
 * @return puntatore alla copia della stringa C di input in caso di successo. 
 * 
 * @pre str != nullptr
 * 
 * @throw std::bad_alloc in caso di fallimento della new
 * 
 * @post il puntatore di ritorno (result) != nullptr
 * @post lunghezza_stringa(str) == lunghezza_stringa(result)
 * @post str[i] == result[i]
*/
char *clona_stringa(const char *str) {
  assert(str != nullptr);

  char *result = nullptr;

  size_type n = calcola_lunghezza(str);

  try {
    result = new char[n+1];
  } catch(std::bad_alloc &e) {
    std::cerr << "Impossibile allocare la copia." << std::endl;
    return nullptr;
  }

  for(size_type i = 0; i <= n ; ++i) 
    result[i] = str[i];

  return result;
}

/**
 * @brief Funzione che concatena le due stringhe di input
 * 
 * Funzione che che concatena le due stringhe di input
 * all'interno di una stringa C allocata dinamicamente. 
 * L'ownership della stringa risultato è ceduta al chiamante.
 * 
 * @param str1 puntatore stringa C di input
 * @param str2 puntatore stringa D di input
 * 
 * @return puntatore alla concatenazione delle stringhe delle stringhe C e D di input in caso di successo.
 * 
 * @pre str1 != nullptr
 * @pre str2 != nullptr
 * 
 * @throw std::bad_alloc in caso di fallimento della new
 * 
 * @post il puntatore di ritorno (result) != nullptr
 * @post lunghezza_stringa(result) == lunghezza_stringa(str1) + lunghezza_stringa(str2)
*/
char *concatena_stringhe(const char *str1, const char *str2) {
  assert(str1 != nullptr);
  assert(str2 != nullptr);

  char *result = nullptr;

  size_type n = calcola_lunghezza(str1);
  size_type m = calcola_lunghezza(str2);

  try {
    result = new char[n+m+1];
  } catch(std::bad_alloc &e) {
    std::cerr << "Impossibile allocare lo spazio per la stringa concatenata." << std::endl;
    return nullptr;
  }

  for(size_type i = 0; i < n ; ++i) 
    result[i] = str1[i];

  for(size_type j = n; j <= m+n ; ++j) 
    result[j] = str2[j-n];

  return result;
}

char *trova_occorrenza(const char *s1, const char *st) {
  assert(s1 != nullptr);
  assert(st != nullptr);

  if (*st == '\0') return (char *)s1;

  size_type n = calcola_lunghezza(s1);
  size_type m = calcola_lunghezza(st);

  bool match;

  for(size_type i = 0; i <= n - m; ++i) {
    match = true;
    if(s1[i] == st[0]) {
      for(size_type j = 1; j < m && match; ++j) {
        if(s1[j+i] != st[j]) {
          match = false;
        }
      }
      if(match) {
        return (char *) &s1[i];
      }
    }
  }

  return nullptr;
}

void rimpiazza_tk(char *s1, const char *st, const char *rimpiazzo){
  assert(s1 != nullptr);
  assert(st != nullptr);
  assert(rimpiazzo != nullptr);
  assert(calcola_lunghezza(st) == calcola_lunghezza(rimpiazzo));

  size_type n = calcola_lunghezza(st);

  //occorrenza = trova_occorrenza(occorrenza + n, st) è più efficiente in quanto non ricontrolla le parti già scritte
  //però non riesco a farlo
  for(char *occorrenza = trova_occorrenza(s1, st); occorrenza != nullptr; occorrenza = trova_occorrenza(s1, st)) {
    /* std::cout << occorrenza << std::endl;
    std::cout << "Next search starts at: " << occorrenza + n << std::endl; */
    for(size_type i = 0; i < n; ++occorrenza, ++i) {
      *occorrenza = rimpiazzo[i];
    }
  }
}

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
