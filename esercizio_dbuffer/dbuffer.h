#ifndef DBUFFER_H
#define DBUFFER_H

namespace dbuffer {

  /**
   * @brief Dato che rappresenta un array di interi dinamico.
   * 
   * Dato che rappresenta un array di interi dinamico.
  */
  struct dynamic_buffer {
    unsigned int size;
    int *buffer;
  };

  /**
   * @brief Stampa contenuto di un dynamic_buffer.
   * 
   * Stampa il contenuto di un dynamic_buffer.
   * 
   * @param db dynamic_buffer da stampare.
  */
  void print_dbuffer(const dynamic_buffer &db);

  /**
   * @brief Inizializza un dynamic_buffer "a 0".
   * 
   * Inizializza un dynamic_buffer ad un array di interi vuoto.
   * 
   * @param db dynamic_buffer da inizializzare.
   * 
   * @post db.size = 0
   * @post db.buffer = nullptr
  */
  void initialize_dbuffer(dynamic_buffer &db);

  /**
   * @brief Alloca spazio per il dbuffer nella memoria.
   * 
   * Alloca spazio passato in size a partire dal puntatore buffer. In caso size
   * non sia passato, viene utilizzato size = 10 come valore di default.
   * 
   * @param db dynamic_buffer da allocare.
   * @param size Grandezza di dbuffer (numero di valori che può salvare).
   * 
   * @post db.size = size
   * @post db.buffer != nulltpr
  */
  void allocate_dbuffer(dynamic_buffer &db, const unsigned int size = 10);

  /**
   * @brief Dealloca spazio del dbuffer nella memoria.
   * 
   * Dealloca spazio dbuffer nella memoria.
   * 
   * @param db dynamic_buffer da deallocare.
   * 
   * @post db.buffer = nullptr
   * @post db.buffer = 0
  */
  void deallocate_dbuffer(dynamic_buffer &db);

  /**
   * @brief Riempie dbuffer con valore passato.
   * 
   * Riempie dbuffer con lo stesso valore value in ogni posizione dell'array.
   * 
   * @param db dynamic_buffer su cui si salvano i valori.
   * @param value Valore che vuole essere salvato in ogni posizione.
   * 
   * @post db.buffer[i] = value per i da 0 a db.size
  */
  void fill_dbuffer(dynamic_buffer &db, int value);

  /**
   * @brief Riempie dbuffer con valori passati.
   * 
   * Riempie dbuffer con i valori che gli vengono passati in un array della
   * stessa dimensione di size.
   * 
   * @param db dynamic_buffer su cui si salvano i valori.
   * @param values Array con i valori da salvare.
   * @param nvalues Numero di valori all'interno di values.
   * 
   * @pre values != nullptr
   * @pre nvalues = db.size
   * @post db.buffer[i] = values[i] per i da 0 a db.size
  */
  void fill_dbuffer(dynamic_buffer &db, int *values, unsigned int nvalues);

  /**
   * @brief Copia dbuffer all'interno di un nuovo dbuffer.
   * 
   * Copia dbuffer src all'interno di dbuffer dst. Non ritorna lo stesso
   * puntatore ma utilizza una nuova area di memoria.
   * 
   * @param src dbuffer che deve essere clonato.
   * @param dst dbuffer clone di src.
   * 
   * @post src.size = dst.size
   * @post src.buffer[i] = dst.buffer[i] con i=0 a size
  */
  void clone_dbuffer(const dynamic_buffer &src, dynamic_buffer &dst);
}
#endif 