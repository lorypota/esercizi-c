#include <iostream>
#include <random>
#include <ctime>
#include <cassert>
using namespace std;

int main() {
  int N;
  cout << "Inserire N: ";
  cin >> N;

  int M;
  cout << "Inserire M: ";
  cin >> M;

  //creo matrice NxM
  int** matrix = new int*[N];
  int** row_temp = matrix;
  for(int i = 0; i < N; ++i, ++row_temp) {
    *row_temp = new int[M];
  }
  row_temp = matrix;

  //setto tutti gli elementi a 0
  for(int i = 0; i < N; ++i) {
    int* col_temp = *row_temp;
    for(int j = 0; j < M; ++j) {
      *col_temp = 0;
      col_temp++;
    }
    row_temp++;
  }
  row_temp = matrix;

  //definisco p che punta a elemento (0, 0)
  int* p = *row_temp;

  //faccio inserire K all'utente 
  int K;
  cout << "Inserire K: ";
  cin >> K;
  assert(K >= 0);

  //genero (i, j) casuali K volte e incremento di 1 ogni volta la casella (i, j)
  std::mt19937 rnd(time(0));
  cout << "Spostamenti: ";
  for (int k = 0; k < K; ++k) {
    int i = rnd() % N;
    int j = rnd() % M;

    cout << "(" << i << ", " << j << ") ";

    for(; i > 0; i--, row_temp++);

    int* col_temp = *row_temp;
    for(; j > 0; j--, col_temp++);
    (*col_temp)++;

    row_temp = matrix;

  }
  cout << endl;

  //stampo la matrice
  for(int i = 0; i < N; ++i) {
    int* col_temp = *row_temp;
    for(int j = 0; j < M; ++j) {
      cout << " " << *col_temp << " ";
      col_temp++;
    }
    row_temp++;
    cout << endl;
  }
  row_temp = matrix;

  //libero la memoria
  for(int i = 0; i < N; ++i, ++row_temp) {
    delete[] *row_temp;
  }
  delete[] matrix;
}