#include "tda_arraylist.cpp"
#include <iostream>
using namespace std;

tLista::tLista() {
  maxSize = MAXSIZE; // tamano maximo de la lista
  listSize = 0; // lista vacía
  curr = 0;
  listArray = new tElemLista[maxSize];
}

tLista::~tLista() {
  delete[] listArray;
}

void tLista::clear(){
  listSize = 0;
  curr = 0;
}

int tLista::insert (tElemLista item){
  unsigned int i = 0;
  if( listSize >= maxSize ) 
	return -1; //lista de largo maximo no se llena
  for (i = listSize; i > curr; i--)
    listArray[i] = listArray[i-1];
  listArray[i] = item;
  listSize++;
  return i;
  // retorna posición de inserción
}

// agrega un elemento al final de la lista
int tLista::append(tElemLista item) {
    if (listSize >= maxSize) 
      return -1;   //lista llena, no se inserta
    listArray[listSize++] = item;
    return 1;       // inserción exitosa
}

tElemLista tLista::erase (){
  tElemLista item;
  unsigned int i;

  if (curr >= listSize) 
	return -1;
  item = listArray[curr];
  for (i = curr; i < listSize-1; i++)
    listArray[i] = listArray[i+1];
  if (curr = listSize-1)
	curr--;
  listSize--;
  return item;
}

void tLista::moveToStart (){
  curr = 0;
}

void tLista::moveToEnd (){
  curr = listSize-1;
}

void tLista::prev (){
  if( curr != 0 ) curr--;
}

void tLista::next (){
  if( curr < listSize ) curr++;
}

