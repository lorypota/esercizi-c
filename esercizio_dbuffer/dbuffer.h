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
   * Stampa il contenuto di un dynamic_buffer
   * 
   * @param db dynamic_buffer da stampare
  */
  void print_dbuffer(const dynamic_buffer &db);

  /**
   * @brief Inizializza un dynamic_buffer "a 0".
   * 
   * Inizializza un dynamic_buffer ad un array di interi vuoto.
   * 
   * @param db dynamic_buffer da inizializzare
   * 
   * @post db.size = 0
   * @post db.buffer = nullptr
  */
  void initialize_dbuffer(dynamic_buffer &db);


}
#endif 