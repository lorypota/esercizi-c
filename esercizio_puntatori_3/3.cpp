#include <iostream>
#include <cassert>

struct node {
  int value;
  node *next;
};

struct list {
  int size;
  node* first;
};

int main() {
  using namespace std;

  //chiedo a utente lunghezza lista
  int N;
  cout << "Inserire lunghezza lista: ";
  cin >> N;
  assert(N > 0);

  //faccio inserire a utente tutti i valori dei nodi nella lista
  list lista;
  lista.size = N;
  lista.first = nullptr;
  node* current = nullptr;

  for(int i = 0; i < N; ++i) {
    node* newNode = new node();
    newNode->next = nullptr;
    cout << "Inserire valore nodo n." << i <<": ";
    cin >> newNode->value;

    if(lista.first == nullptr) {
      lista.first = newNode;
    } else {
      current->next = newNode;
    }
    current = newNode;
  }

  //stampo la lista
  current = lista.first;
  cout << "Lista valori salvati: ";
  for(int i = 0; i < N; ++i) {
    cout << current->value << " ";
    current = current->next;
  }
  cout << endl;

  //svuoto la lista
  current = lista.first;
  for(int i = 0; i < N; ++i) {
    node* prev = current;
    current = current->next;
    delete prev;
  }
  lista.first = nullptr;

  return 0;
}