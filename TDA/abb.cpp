/**
*Se importan todas la librerias a utilizar para el funcionamiento del programa.
*/

#include "tda_abb.cpp"
#include <iostream>
using namespace std; 
/*
  Mediante un recorrido en postorden, se eliminan todos los nodos
  a partir de uno. Es usado por el destructor de la clase para
  eliminar el árbol que sea creado.
  *
*/
template<class TDA>
void ABB<TDA>::Podar(Nodo<TDA>* &nodo) {
	// Algoritmo recursivo, recorrido en postorden
	if(nodo) {
		Podar(nodo->izquierdo); // Podar izquierdo
		Podar(nodo->derecho);   // Podar derecho
		delete nodo;            // Eliminar nodo
		nodo = NULL;
	}
}
//**********************************************************************************************************************************//
/* Función para insertar datos en el árbol binario
   Es declarada como template para poder guardar cualquier tipo dato
   Entrada		: el dato a insertar.
   Salida		: el elemento en el árbol binario.
   Restriccion	: solo inserta un tipo de dato en el árbol. Éste dato es declarado al crear la 
                  instancia de la clase ABB.           
*/
template<class TDA>
void ABB<TDA>::Insertar(const TDA dat) {
	Nodo<TDA> *padre = NULL;

	actual = raiz;
	// Buscar el dato en el árbol, manteniendo un puntero al nodo padre
	while(!Vacio(actual)){ 
		padre = actual;
		if(dat >= actual->dato) actual = actual->derecho;
		else if(dat < actual->dato) actual = actual->izquierdo;
	}
	// Si se ha encontrado el elemento, regresar sin insertar
	if(!Vacio(actual)) return;
	// Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será el nodo raiz
	if(Vacio(padre)) raiz = new Nodo<TDA>(dat);
	// Si el dato es menor que el que contiene el nodo padre, lo insertamos en la rama izquierda
	else if(dat < padre->dato) padre->izquierdo = new Nodo<TDA>(dat);
	// Si el dato es mayor que el que contiene el nodo padre, lo insertamos en la rama derecha
	else if(dat >= padre->dato) padre->derecho = new Nodo<TDA>(dat);
}

//**********************************************************************************************************************************//
/* Función para buscar dato en el árbol binario
   Es declarada como template para poder guardar cualquier tipo dato
   Entrada		: el dato a buscar.
   Salida		: el elemento en el árbol binario.
   Restriccion	: solo inserta un tipo de dato en el árbol. Éste dato es declarado al crear la 
                  instancia de la clase ABB.           
*/
template<class TDA>
bool ABB<TDA>::Buscar(const TDA dat) {
	Nodo<TDA> *padre = NULL;

	actual = raiz;
	// Buscar el dato en el árbol, manteniendo un puntero al nodo padre
	while(!Vacio(actual)){ 
		// Si se ha encontrado el elemento
		if (actual->dato == dat) {
			return true;
		}
		if(dat >= actual->dato) actual = actual->derecho;
		else if(dat < actual->dato) actual = actual->izquierdo;
	}
	// No esta el valor.
	return false;
}

//**********************************************************************************************************************************//
/* 
  Se recorre el árbol en PreOrden
  Durante el recorrido, se muestra el valor de cada nodo 
*/
template<class TDA>
void ABB<TDA>::PreOrden(void (*func)(TDA&), Nodo<TDA> *nodo, bool r) {
	if(r) nodo = raiz;
	func(nodo->dato);
	if(nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
	if(nodo->derecho)   PreOrden(func, nodo->derecho, false);
}

//**********************************************************************************************************************************//
/*  
 Recorrido de árbol en postorden.
 Durante el recorrido se muestra el valor de cada nodo
*/
template<class TDA>
void ABB<TDA>::PostOrden(void (*func)(TDA&), Nodo<TDA> *nodo, bool r) {
	if(r) nodo = raiz; 											// Si r es true, el nodo es la raiz
	if(nodo->izquierdo) PostOrden(func, nodo->izquierdo, false);// Se recorre la izquierda del nodo padre
	if(nodo->derecho)   PostOrden(func, nodo->derecho, false);	// Se recorre la derecha del nodo padre
	func(nodo->dato);											// Se muestra el valor del nodo
}

//**********************************************************************************************************************************//
/*
  Se recorre el árbol en InOrden
  Durante el recorrido, se muestra el valor de cada nodo
*/
template<class TDA>
void ABB<TDA>::InOrden(void (*func)(TDA&) , Nodo<TDA> *nodo, bool r) {
	if(r) nodo = raiz; 											// Si r es true, el nodo es la raiz
	if(nodo->izquierdo) InOrden(func, nodo->izquierdo, false); 	// Se recorre la izquierda del nodo padre
	func(nodo->dato); 											// Se muestra el valor del nodo
	if(nodo->derecho)   InOrden(func, nodo->derecho, false); 		// Se recorre la derecha del nodo padre
}

//**********************************************************************************************************************************//
/*  
  Se recorre el árbol en preorden, la funcion func se encarga de mostrar el
  dato que contiene el nodo.
  Durante el recorrido se pregunta si el nodo es hoja.
  Si es hoja se muestra en la pantalla y se continua recorriendo el árbol
*/
template<class TDA>
void ABB<TDA>::MostrarHojas(void (*func)(TDA&), Nodo<TDA> *nodo, bool r) {
	if(r) nodo = raiz; 												// Si r es true, el nodo es la raíz 
	if (EsHoja(nodo)) {func(nodo->dato);} 							// Si el nodo es hoja, se muestra su valor
	if(nodo->izquierdo) MostrarHojas(func, nodo->izquierdo, false);	// Se recorre a la izquierda del nodo padre
	if(nodo->derecho) MostrarHojas(func, nodo->derecho, false); 	// Se recorre a la derecha del nodo padre
}

//**********************************************************************************************************************************//
/*
   Se recorre el árbol en preorden, la funcion func se encarga de mostrar el 
   dato que contiene el nodo.
   Durante el recorrido se pregunta si el nodo NO es hoja.
   De no ser hoja, se muestra en pantalla y se continua recorriendo el árbol 
*/
template<class TDA>
void ABB<TDA>::MostrarInternos(void (*func)(TDA&), Nodo<TDA> *nodo, bool r) {
	if(r) nodo = raiz; 													// Si r es true, el nodo es la raíz
	if(!EsHoja(nodo)) {  func(nodo->dato);} 							// Si el nodo NO es hoja, se muestra su valor
	if(nodo->izquierdo) MostrarInternos(func, nodo->izquierdo, false);	// Se recorre a la izquierda del nodo padre
	if(nodo->derecho) MostrarInternos(func, nodo->derecho, false); 		// Se recorre a la derecha del nodos padre
}

//**********************************************************************************************************************************//
/*  
   Función para  Contar el número de nodos
   Es declarada como template para poder guardar cualquier tipo dato
   Entrada: no tiene entradas
   Salida: la cantidad de nodos que contiene el árbol.  
*/

template<class TDA>
const int ABB<TDA>::NumeroNodos() {
	contador = 0;
	if (raiz != NULL) { 	// Si se ha creado un árbol retorna la cantidad de nodos que contiene
		auxContador(raiz); 	// Función auxiliar de contador para realizar el conteo de los nodos
		return contador;  	// retorna la cantidad de nodos que tiene el árbol
	} 
	else { 					// Si no se ha creado ningún árbol retorna que la cantidad de nodos es cero
		return 0;
	}  
}

//**********************************************************************************************************************************//
/* 
   Función auxiliar para contar nodos. Función recursiva de recorrido en
   preorden, el proceso es aumentar el contador
   Es declarada como template para poder guardar cualquier tipo dato
   Entrada: recibe como entrada el nodo 
   Salida: genera a la función NumeroNodos un registro de un nodo mas por cqada nodo que ingrese a esta función.   
*/

template<class TDA>
void ABB<TDA>::auxContador(Nodo<TDA> *nodo) {
	contador++;  // Otro nodo
	// Continuar recorrido
	if(nodo->izquierdo) auxContador(nodo->izquierdo); 	//recorrido por la izquierda
	if(nodo->derecho)   auxContador(nodo->derecho);		//recorrido por la derecha
}

//**********************************************************************************************************************************//
/*
  Función para mostrar el árbol.
*/
template <class TDA>
void Mostrar(const TDA dat) {
	cout << dat << ","; //Imprime el dato y coloca una coma para separar cada dato.
}