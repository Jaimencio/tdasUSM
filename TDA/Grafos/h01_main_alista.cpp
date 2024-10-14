#include "./partes/imp_alista_grafos.cpp"
#include <iostream>

#define peso 999
using namespace std;

void esArco(Graphl *g, int i, int j) {
	if (g->isEdge(i, j)) 
		cout << "Es un arco(" << i << "," << j << ")" << "\n";
	else
		cout << "NO es un arco(" << i << "," << j << ")" << "\n";
}

void pesoArco(Graphl *g, int i, int j) {
		cout << "Peso del arco(" << i << "," << j << ") es: " << g->weight(i, j) << "\n";
}

void miVecino(Graphl *g, int i, int j) {
		cout << "Vecino del arco(" << i << "," << j << ") es: " << g->next(i, j) << "\n";
}

int main() {
	cout << "Hola mundo ..." << "\n";
	int D[5];
	
	/* Creación de grafo */
	Graphl *grf = new Graphl(defaultSize);
	
	/* Clase de hoy */
	grf->setEdge(0, 1, 10);
	grf->setEdge(0, 2, 3);
	grf->setEdge(0, 3, 20);
	
	grf->setEdge(1, 3, 5);
	
	grf->setEdge(2, 1, 2);
	grf->setEdge(2, 4, 15);
	
	grf->setEdge(3, 4, 11);
	
	/* Consultas al grafo */
	cout << "Numero de vertices: " << grf->n() << "\n";
	cout << "Numero de arcos: " << grf->e() << "\n";
	cout << "\n";
	
	Dijkstra(grf, D, 0);
	
	for (int i=0; i<defaultSize; i++) // Initialize
		cout << "D[" << i << "] = " << D[i] << "\n";
	
	/* Clase de ayer */
	/*
	grf->setEdge(0, 1, peso-1); 
	grf->setEdge(0, 4, peso-2); 
	
	grf->setEdge(1, 0, peso-3);
	grf->setEdge(1, 3, peso-4);
	grf->setEdge(1, 4, peso-5); 
	
	grf->setEdge(2, 3, peso-6); 
	grf->setEdge(2, 4, peso-7);
	
	grf->setEdge(3, 1, peso-8);
	grf->setEdge(3, 2, peso-9);
	
	grf->setEdge(4, 0, peso-10);	
	grf->setEdge(4, 1, peso-11);	
	grf->setEdge(4, 2, peso-12);	
	*/
	
	/* Consultas al grafo */
	/*
	cout << "Numero de vertices: " << grf->n() << "\n";
	cout << "Numero de arcos: " << grf->e() << "\n";
	cout << "\n";
	*/
	
	/*
	esArco(grf,0,1); pesoArco(grf,0,1); miVecino(grf,0,1);
	cout << "\n";
	esArco(grf,0,4); pesoArco(grf,0,4); miVecino(grf,2,3);
	cout << "grf->first(3): " << grf->first(3) << "\n";
	cout << "\n";
	esArco(grf,1,4); pesoArco(grf,1,4); miVecino(grf,1,4);
	cout << "\n";
	esArco(grf,1,6); pesoArco(grf,1,6); miVecino(grf,1,6);
	*/
	
	/* Recorrido del grafo */
	//DFSCustomized(grf, 0, 1);
	//cout << "\n";
	//AQueue<int>* cola = new AQueue<int>(defaultSize);
	//BFS(grf, 0, cola);
}