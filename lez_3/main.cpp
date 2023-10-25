/**
 * Per compilare i sorgenti:
 * 
 * g++ -c main.cpp -o main.o
 * g++ -c ops.cpp -o ops.o
 * 
 * 
 * Per linkare i file oggetto (creare l'eseguibile):
 * g++ main.o ops.o -o main.exe
 *  
 * oppure se i file oggetto sono tutti nella cartella corrente:
 * g++ *.o -o main.exe
 * 
 */


#include <iostream> // dichiarazioni di std::cout e std::endl std::cin std::cerr
#include <string>   // std::string
#include "ops.h"    // dichiarazione di stampa()

void test_io() {

  std::cout << "Hello world" << std::endl;
  // << è detto operatore di stream se usato con std::cout a sinistra

  std::string s;

  std::cout << "Inserire messaggio: ";
  std::cin  >> s;
  std::cout << "Hai inserito: " << s << std::endl;


  int n = 0;

  std::cout << "Inserire un numero intero: ";
  std::cin  >> n;
  std::cout << "Hai inserito il numero: " << n << std::endl;

}

void test_dati_semplici() {

  // I dati, in generale, non sono inizializzati. Quando vengono
  // istanziati contengono valori casuali.

  char c = '0'; // character (più piccolo dato indirizzabile / byte)

  int i = 0; // intero con segno (almeno 4 byte)
  unsigned int ui; // intero senza segno
  
  short int si = 0; // intero a metà precisione (es. 2 byte)
  long int li = 0;  // intero a doppia precisione (es. 8 byte)

  double d = 0.0;      // numero in virgola
  long double n = 0.0; // numero in virgola a doppia precisione
  float f = 0.0f;      // numero in virgola a singola precisione

  bool b = false;      // boolean

  // sizeof(tipo) ci dice da quanti byte è formato un certo tipo
  // il valore dipende dal sistema/compilatore
  std::cout<<"Dimensione di un int     : "<<sizeof(int)<<" char"<< std::endl;
  std::cout<<"Dimensione di un long int: "<<sizeof(long int)<<" char"<< std::endl;
  std::cout<<"Dimensione di un double  : "<<sizeof(double)<<" char"<< std::endl;
  std::cout<<"Dimensione di un float   : "<<sizeof(float)<<" char"<< std::endl;
  std::cout<<"Dimensione di un char    : "<<sizeof(char)<<" char"<< std::endl;

  // Per conoscere informazioni sui tipi di dati a seconda del sistema
  // studiate le funzioni dichiarate nel file della libreria <limits>
  // es:   
  // std::cout << "Minimum value for int: " << std::numeric_limits<int>::min();
}

void test_puntatori() {
  int test = 1000; // intero di appoggio

  int *pi = nullptr; // puntatore a dati di tipo intero inizializzato a "0"
  // Un puntatore contiene l'indirizzo di memoria dove "vive" un dato
  // Permette di accedere ad un dato in modo indiretto

  pi = &test; // riempiamo il puntatore con l'indirizzo di memoria di test
  // in un puntatore a interi possiamo mettere solo indirizzi di dati interi
  // in un puntatore a double possiamo mettere solo indirizzi di dati double
  // etc...
  // 
  // &nome_variabile significa ottenere l'indirizzo del dato 

  std::cout << "Contenuto di test: " << test << std::endl;
  std::cout << "Indirizzo di test: " << &test << std::endl;
  std::cout << "Contenuto di pi: "   << pi << std::endl;
  std::cout << "Indirizzo di pi: "   << &pi << std::endl;

  int test2 = 999; // altra variabile intera

  pi = &test2; // un puntatore è riassegnabile ad un altro indirizzo

  std::cout << "Contenuto del dato puntato: " << *pi << std::endl;
  // Possiamo accedere al dato puntato DEREFERENZIANDO il puntatore
  // *pi significa accedere al dato che "vive" all'indirizzo nel puntatore

  *pi = 100; // equivale a test2 = 100;

  int *pi2 = pi; // ok, copio due puntatori dello stesso tipo

  float *pf = nullptr; // puntatore ad un dato float

  //pf = pi; // errore i puntatori sono di tipo diverso

  // Aritemtica dei puntatori

  pi = pi + 1; // "sposto" il puntatore 
               // all'indirizzo contenuto in pi + 1*sizeof(int) bytes

  int v = pi2 - pi; // numero di interi (sono puntatori ad interi) 
                    // tra i due indirizzi

  // pi2 + p1; // errore, operazione non ammessa

  pi[1] = 90; // equivalente a *(pi+1) = 90; 
              // sposta il puntatore e dereferenzia automaticamente
}

void test_array_primitivi() {
  int a[5] = {0}; // array di 5 interi inizializzato a 0

  int *p = a;

  int *b[5];

  int *c;

  std::cout << "a: " << sizeof(a) << std::endl;
  std::cout << "b: " << sizeof(b) << std::endl;
  std::cout << "c: " << sizeof(c) << std::endl;

  // for(int i=0; i<5; ++i) {
  //   std::cout << "a[" << i << "] = " << p[i] << std::endl;
  // }

  double d[2][3] = {{1, 2, 3}, {4, 5, 6}};
  
  // for(int i = 0; i < 2; ++i) {
  //   for(int j = 0; j < 3; ++j)
  //     std::cout << "d[" << i << "][" << j << "] = " << d[i][j] << std::endl;
  //   std::cout << std::endl;
  // }

  double (*pd)[3] = d;

  for(int i = 0; i < 2; ++i) {
    double *ptr = pd[i];
    
    for(int j = 0; j < 3; ++j) {
      std::cout << "d[" << i << "][" << j << "] = " << ptr[j] << std::endl;
    }
    // std::cout << *(pd[i]) << std::endl;   
  }
}

void test_reference() {
  double d = 999;

  double &ref = d;

  std::cout << "Indirizzo di d: " << &d << std::endl;
  std::cout << "Indirizzo di ref: " << &ref << std::endl;
}

void test_struct() {
  struct pippo {
    int i;
    double d;
    char c;
  };

  pippo p = {1, 3.15, 'o'};

  std::cout << p.i << std::endl;
  std::cout << p.d << std::endl;
  std::cout << p.c << std::endl;

  std::cout << "Dimensione pippo: " << sizeof(pippo) << std::endl;

  pippo *ptr = &p;

  std::cout << ptr->i << std::endl;
}

void test_const() {
  const int i = 999;

  const int *ptr = &i;

  int* ptr2 = const_cast<int*>(ptr);

  int j = i;
}

void test_stringheC() {
  char str[] = "Ciao ste!"; 

  std::cout << str << std::endl;

  char *p = "Ciao ste!"; 

  std::cout << p+1 << std::endl;
}

int main(int argc, char *argv[]) {

  // stampa(); // funzione che è definita in ops.cpp

  // test_io();

  // test_dati_semplici();

  // test_puntatori();

  // test_array_primitivi();

  // test_reference();

  // test_struct();

  // test_const();

  // test_stringheC();

  // argomento numero 1 è sempre il nome dell'eseguibile quindi lo skippo

  std::cout << "Numero di argomenti: " << argc-1 << std::endl;
  for(int i = 1; i < argc; ++i) {
    std::cout << "Argomento: " << i << " " << argv[i] << std::endl;
  }

  int i = std::stoi(argv[1]);
  std::cout << "Valore dell'argomento " << i << std::endl;

  std::stringstream ss(argv[1]);
  int j;

  ss >> j;
  std::cout << "Valore dell'argomento: " << j << std::endl;

  return 0; 
  // ritorna un codice di errore al sistema operativo (che può ignorarlo)
  // == 0 : tutto ok
  // != 0 : possibile errore   
  // Ritornare sempre un valore se la funzione lo indica
}
