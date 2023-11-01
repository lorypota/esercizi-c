#ifndef MISC_H
#define MISC_H

void print_array(const char *varname, const int *a, int size);

void fill_array(int *a, int size, int value);

int *clone_array(const int *a, int size);

#endif