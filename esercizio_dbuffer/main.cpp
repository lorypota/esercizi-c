#include <iostream>
#include "dbuffer.h"

int main() {
  using namespace dbuffer;

  dynamic_buffer db;

  initialize_dbuffer(db);
  print_dbuffer(db);

  allocate_dbuffer(db);
  fill_dbuffer(db, 5);
  print_dbuffer(db);

  int *values = new int[10];
  for(unsigned int i = 0; i < 10; ++i) {
    values[i] = i;
  }
  fill_dbuffer(db, values, 10);
  print_dbuffer(db);
  delete[] values;
  values = nullptr;

  dynamic_buffer db2;
  initialize_dbuffer(db2);
  clone_dbuffer(db, db2);
  print_dbuffer(db2);

  deallocate_dbuffer(db);
  deallocate_dbuffer(db2);

  return 0;
}