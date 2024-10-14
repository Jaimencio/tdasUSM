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
	int D[6];
	
	/* Creación de grafo */
	Graphl *grf = new Graphl(defaultSize);
	
	/* Clase de hoy 1 
	grf->setEdge(0, 1, 6);
	grf->setEdge(0, 2, 1);
	grf->setEdge(0, 3, 5);

	grf->setEdge(1, 2, 5);
	grf->setEdge(1, 4, 3);

	grf->setEdge(3, 2, 5);
	grf->setEdge(3, 5, 2);
	
	grf->setEdge(4, 2, 6);
	grf->setEdge(4, 5, 6);
	
	grf->setEdge(5, 2, 4);
	*/
	
	/* Clase de hoy 2 */
	grf->setEdge(0, 1, 6);
	grf->setEdge(1, 0, 6);
	grf->setEdge(0, 2, 1);
	grf->setEdge(2, 0, 1);
	grf->setEdge(0, 3, 5);
	grf->setEdge(3, 0, 5);

	grf->setEdge(2, 1, 5);
	grf->setEdge(1, 2, 5);
	grf->setEdge(2, 3, 5);
	grf->setEdge(3, 2, 5);
	grf->setEdge(2, 4, 6);
	grf->setEdge(4, 2, 6);
	grf->setEdge(2, 5, 4);
	grf->setEdge(5, 2, 4);
	
	grf->setEdge(1, 4, 3);
	grf->setEdge(4, 1, 3);
	grf->setEdge(3, 5, 2);
	grf->setEdge(5, 3, 2);
	
	grf->setEdge(4, 5, 6);
	grf->setEdge(5, 4, 6);
	
	/* Consultas al grafo */
	cout << "Numero de vertices: " << grf->n() << "\n";
	cout << "Numero de arcos: " << grf->e() << "\n";
	cout << "\n";
	
	Prim(grf, D, 0);
	
	for (int i=0; i<defaultSize; i++) // Initialize
		cout << "D[" << i << "] = " << D[i] << "\n";

}