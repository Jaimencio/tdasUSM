#include <iostream>
#include <limits>

#define INVALID_ELEMENT std::numeric_limits<int>::min()
#define MAXIMOSTACK 100

typedef int tElemPila;
//typedef char tElemPila;

class tPila {
	private:
	  unsigned int maxSize; // tamaño maximo de la pila
	  unsigned int top; // tamaño actual de la pila
	  tElemPila *stackArray; // arreglo con los elementos de la pila

	public:
	  //constructor
	  tPila ();
	  tPila (int capacity);

	  //destructor
	  ~tPila ();

	  //reinicializa la pila
	  void clear ();

	  //inserta un elemento en el tope de la pila
	  int push (tElemPila item);

	  // elimina el elemento que está en el tope de la pila
	  void pop ();

	  // retorna una copia del elemento que está en el tope de la pila
	  tElemPila topValue ();

	  // retorna el tamaño de una pila
	  int size ();
};

