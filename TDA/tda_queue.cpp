#include <limits>
#include "../ArrayList/arraylist.cpp"

#define INVALID_ELEMENT std::numeric_limits<int>::min()
#define MAXIMOQUEUE 100

typedef int tElemCola;
//typedef char tElemCola;

class tCola {
  unsigned int maxSize; // tamaño maximo de la cola
  unsigned int first;   // primer elemento de la cola
  unsigned int length;  // tamaño de la cola

  tElemCola *queueArray; // arreglo con los elementos de la pila

public:
  //constructor
  tCola ();
  tCola (int capacity);

  //destructor
  ~tCola ();

  //reinicializa la cola
  void clear ();
  // inserta un elemento al final de la cola
  int enqueue (tElemCola item);
  // elimina el elemento que está en el frente cola
  void dequeue ();
  // retorna una copia del elemento que está en el frente de la cola
  tElemCola frontValue ();
  // retorna el tamaño de una cola
  int size ();

};

