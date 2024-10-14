#include "tda_linkedlist.cpp"
#include <cstdio>

tLista::tLista() {
    head = tail = curr = new tNodo;
    listSize = 0;
    pos = 0;
}

tLista::~tLista() {
    tNodo *aux;
    curr = head;
    do {
        aux = curr->sig;
        delete curr;
        curr = aux;
    } while (curr != NULL);
}

void tLista::clear() {
    //TODO completar, ejercicio
    //...
}

// inserta un elemento en la posición actual de la lista
int tLista::insert(tElemLista item) {
    tNodo *aux = curr->sig;
    curr->sig = new tNodo;
    curr->sig->info = item;
    curr->sig->sig = aux;
    if (curr == tail) tail = curr->sig;
    listSize++;
    return pos;
}

int tLista::append(tElemLista item) {
    tail->sig = new tNodo;
    tail->sig->info = item;
    tail->sig->sig = NULL;
    tail = tail->sig;
    listSize++;
    return 1;  //inserción exitosa
}

tElemLista tLista::erase() {
	if (curr == tail) {
		prev();
	}
	tElemLista item = curr->info;
	tNodo* aux = curr->sig;
	if (tail == curr->sig) tail = curr;
	curr->sig = curr->sig->sig;
	delete aux;
	listSize--;
	return item;
}

void tLista::moveToStart() { curr = head; pos = 0; }

void tLista::moveToEnd() { curr = tail; pos = listSize-1; }

void tLista::prev() {
    tNodo *temp;
    if (curr == head) return;
    temp = head;
    while (temp->sig != curr) temp = temp->sig;
    curr = temp;
    pos--;
}

void tLista::next() { if (curr != tail) { curr = curr->sig; pos++; } }

int tLista::length() {
    return listSize;
}

int tLista::currPos() {
    return pos;
}

void tLista::moveToPos(unsigned int posicion) {
    unsigned int i;
    if (posicion < 0 || posicion > listSize) return;
    curr = head;
    pos = 0;
    for (i = 0; i < posicion; i++) {
        curr = curr->sig;
        pos++;
    }
}

tElemLista tLista::getValue() {
    return curr != tail ? curr->sig->info : curr->info;
}
