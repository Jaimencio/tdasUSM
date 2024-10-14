/**
Descripción: En este archivo se declaran las dos clases a utilizarce Nodo y ABB(Arbol Binario)
*/

/**
*Se importa la libreria a utilizar para el funcionamiento del programa.
*/
#include <iostream>

using namespace std;

template <class TDA> class ABB;
// Clase declarada como template con las declaraciones necesarias para la creación de nodos
// El template nos permite usar cualquier tipo de dato.
template<class TDA>

class Nodo {
	public:
		// Constructor de la clase nodo:
		Nodo(const TDA dat, Nodo<TDA> *izq=NULL, Nodo<TDA> *der=NULL) : dato(dat), izquierdo(izq), derecho(der) {}
		// Miembros de la clase nodo:
		TDA dato; 				// El dato a almacenar
		Nodo<TDA> *izquierdo; 	// El puntero a la izquierda del árbol
		Nodo<TDA> *derecho; 	// El puntero a la derecha del árbol
      
		friend class ABB<TDA>; 	// Debe ser amiga de la clase lista para poder usar los nodos como parametros de las funciones
};

// Clase declarada como template para crear árboles.
// El template nos permite usar cualquier tipo de dato.
template<class TDA>
class ABB {
	private:   
		Nodo<TDA> *raiz; 	// Declaración la raíz del árbol
		Nodo<TDA> *actual; 	// Declaracion del nodo actual del arbol
		int contador; 		// Variable de tipo entero para contar la cantidad de nodos del árbol

	public:
	   // Constructor de la clase
	   ABB() : raiz(NULL), actual(NULL) {}
	   // Destructor de la clase
	   ~ABB() { Podar(raiz); }
	   // Inserción en un árbol ordenado:
	   // *******************************
	   // void insert(tipoElem item)
	   // *******************************
	   void Insertar(const TDA dat);
	   // Busqueda en un árbol ordenado:
	   // ******************************
	   // bool find(tipoElem item)
	   // ******************************
	   bool Buscar(const TDA dat);	   
	   // Retorna true si el árbol está vacío, false en caso contrario:
	   bool Vacio(Nodo<TDA> *r) { return r == NULL; }
	   // Retorna true si el nodo es hoja, false en caso contrario:
	   bool EsHoja(Nodo<TDA> *r) { return !r->derecho && !r->izquierdo; }
	   // Cuenta el número de nodos del árbol y retorna dicho número:
	   // ***********************************************************
	   // int size()
	   // ***********************************************************
	   const int NumeroNodos();
	   // Retorna el valor que contiene el nodo actual
	   // ********************************************
	   // tipoElem getValue()
       // ********************************************
	   TDA &ValorActual() { return actual->dato; }
	   // Mueve actual a la raíz:
	   void Raiz() { actual = raiz; }
	   // Recorre el árbol en InOrden
	   // ***************************
	   // void inOrden()
       // ***************************
	   void InOrden(void (*func)(TDA&) , Nodo<TDA> *nodo=NULL, bool r=true);
	   // Recorre el árbol en PreOrden
	   // ****************************
	   // void preOrden()
	   // ****************************
	   void PreOrden(void (*func)(TDA&) , Nodo<TDA> *nodo=NULL, bool r=true);
	   // Recorre el árbol en PostOrden
	   // *****************************
	   // void postOrden()
	   // *****************************
	   void PostOrden(void (*func)(TDA&) , Nodo<TDA> *nodo=NULL, bool r=true);
	   // Muestra las hojas del árbol
	   void MostrarHojas(void (*func)(TDA&) , Nodo<TDA> *nodo=NULL, bool r=true);
	   // Muestra los nodos internos del árbol
	   void MostrarInternos(void (*func)(TDA&) , Nodo<TDA> *nodo=NULL, bool r=true);
   
	private:
		// Función auxiliar para eliminar todos los nodos del árbol a partir de uno
		// ************************************************************************
		// void clear()
		void Podar(Nodo<TDA>* &); 
		//Función auxiliar para contar la cantidad de nodos del árbol
		void auxContador(Nodo<TDA>*);
};