#ifndef STRINGHEC_H
#define STRINGHEC_H

typedef unsigned int size_type; ///< tipo che definisce la dimensione di un array

/**
  @brief Stampa i caratteri della stringa 

  Funzione che stampa i caratteri della stringa C di input
  un carattere per riga.

  @param str puntatore alla stringa C di input

  @pre str!=nullptr
*/
void stampa_caratteri(const char *str);

/**
  @brief Funzione che calcola la lunghezza di una stringa C

  Funzione che calcola la lunghezza di una stringa C

  @param str puntatore alla stringa C di input

  @return la lunghezza della stringa C senza terminatore

  @pre str!=nullptr
*/
size_type calcola_lunghezza(const char *str);


/**
  @brief Funzione che inverte la stringa

  Funzione che inverte la stringa in-place

  @param str puntatore alla stringa C di input
  @pre str!=nullptr
*/
void inverti_stringa(char *str);

/**
  @brief Funzione che clona la stringa di input
  
  Funzione che clona la stringa di input (str) in una nuova
  stringa C allocata dinamicamente. L'ownership della
  stringa risultato è ceduta al chiamante. La stringa str è
  lunga n caratteri.

  @param str puntatore stringa C di input

  @return puntatore alla copia della stringa C di input in cao di successo. 

  @pre str!=nullptr

  @throw std::bad_alloc in caso di fallimento della new

  @post il puntatore di ritorno (result) != nullptr
  @post n == lunghezza(result)
  @post str[i] == result[i] per i = 0 a n
*/
char *clona_stringa(const char *str);

/**
  @brief Funzione che concatena due stringhe in input
  
  Funzione che concatena due stringhe (s1 e s2) di input in una nuova
  stringa. L'ownership della stringa risultato è ceduta al 
  chiamante. s1 è lunga n1 caratteri, s2 è lunga n2 caratteri. 

  @param s1 puntatore ad una stringa C di input
  @param s2 puntatore ad una stringa C di input

  @return puntatore ad una nuova stringa lunga n=(n1+n2) caratteri  

  @pre s1!=nullptr
  @pre s2!=nullptr

  @throw std::bad_alloc in caso di fallimento della new

  @post il puntatore di ritorno (result) != nullptr
  @post n = n1 + n2
  @post s1[i] == result[i] per i= 0 a n1
  @post result[i+n1] = s2[i] per i = 0 a n2  
*/
char *concatena_stringhe(const char *s1, const char *s2);

/**
  @brief Funzione che cerca una sottostringa in una stringa non
  costante.
  
  Funzione che cerca una sottostringa token nella stringa di 
  input non costante. La stringa di input è lunga n1 caratteri. La stringa
  token è lunga nt caratteri.

  @param s1 puntatore alla stringa C di input
  @param st puntatore alla stringa C token di input

  @return puntatore alla posizione della stringa token in s1 o nullptr

  @pre s1!=nullptr
  @pre st!=nullptr
  @pre n1>0
  @pre nt>0
  @pre nt<=n1

  @post result==nullptr se token non trovato
  @post result[i]==st[i] per i=0 a nt se token trovato
*/
char *trova_occorrenza(const char *s1, const char *st);

/**
  @brief Funzione che sovrascrive le occorrenze di un token
  
  Funzione che cerca una sottostringa token nella stringa di 
  input passata e la sovrascrive con una nuova stringa di uguale 
  lunghezza passata in input. La stringa di input è lunga n1 
  caratteri. Il token è lungo nt caratteri e la stringa sostitutiva
  è lunga n2 caratteri.

  @param s1 puntatore alla stringa C di input
  @param st puntatore alla stringa C token di input
  @param s2 puntatore alla stringa C da usare per sovrascivere

  @pre s1!=nullptr
  @pre st!=nullptr
  @pre s2!=nullptr
  @pre n1>0
  @pre nt>0
  @pre nt<=n1
  @pre nt==n2
*/
void rimpiazza_tk(char *s1, const char *st, const char *s2);

#endif 