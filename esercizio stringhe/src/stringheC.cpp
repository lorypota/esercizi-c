/**
  @file stringheC.cpp

  @brief File delle funzioni che manipolano le stringhe C

  Soluzione dell'esercizio sui puntatori e stringhe C.
*/

#include "stringheC.h"
#include <cassert>
#include <iostream>

void stampa_caratteri(const char *str) {
  assert(str!=nullptr);

  while(*str!='\0') {
    std::cout << *str << std::endl;
    str++; // str = str + 1;
  }
}

size_type calcola_lunghezza(const char *str) {
  assert(str!=nullptr);

  size_type length = 0;
  while(*str!='\0') {
    length++;
    str++; // str = str + 1;
  }

  return length;
}

void inverti_stringa(char *str) {
  assert(str!=nullptr);

  size_type n = calcola_lunghezza(str);
  char *str1 = str + n - 1;
  //char tmp;

  for(; str < str1; str++, str1--) {
    std::swap(*str, *str1);
    //tmp = (*str);
    //*str = *str1;
    //*str1 = tmp;
    //str++;
    //str1--;
  }
}

char *clona_stringa(const char *str) {
  assert(str!=nullptr);

  char *result = nullptr;

  size_type n = calcola_lunghezza(str);

//  try {
    result = new char[n+1];
//  }
//  catch(std::bad_alloc &e) {
//    std::cerr << "Impossibile allocare la copia." << std::endl;
//    return nullptr;
//  }

  for(size_type i = 0; i <= n ; ++i) 
    result[i] = str[i];

  return result;
}

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

  assert(n>0);
  assert(m>0);
  assert(m<=n);

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

  size_type n = calcola_lunghezza(s1);
  size_type m = calcola_lunghezza(st);
  size_type k = calcola_lunghezza(rimpiazzo);

  assert(n > 0);
  assert(m > 0);
  assert(m <= n);
  assert(n == k);

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
