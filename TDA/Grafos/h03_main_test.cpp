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

int * saturados( Graphl * G, int& nsat ){
	int *Sat = new int[G->n() ];    // Arreglo para determinar si salidas – entradas < 0
	int *R   = new int[G->n() ];    // Arreglo para entrega respuestas
	int v, w;
	for ( v = 0; v < G->n(); v++ ){ // Inicializar arreglo con 0
		Sat [v] = 0;
	}
	for ( v = 0; v < G->n(); v++ ){ // Para cada vértice
		for ( w = G->first(v); w < G->n(); w = G->next(v,w) ){ // Recorrer sus vecinos
			cout << "v =" << v << " - w =" << w << "\n";
			Sat[v]++; // Por cada vecino suma 1 al vértice
			Sat[w]--; // Para cada vértice vecino resta 1
		}
	}
	nsat = 0;
	for ( v = 0; v < G->n(); v++ ){
		if( Sat[v] < 0 ){  // Recuperar solo los vértices que salidas – entradas < 0
			R[ nsat ] = v;
			nsat ++;
		}
	}
	delete [] Sat ;
	return R;
}

int componentesDesconectadasDFS(Graphl *G) {
	int i, nComp;
	nComp = 0; // Cuenta la cantidad de componentes conexas del grafo
	for (i = 0; i < G->n(); i++) {
		if (G->getMark(i) == UNVISITED) {
			nComp++;   // Vertice i esta en una componente conexa no considerada hasta ahora
			DFS(G, i); // Inicia recorrido en profundidad desde vertice i
			           // Recordar que DFS marca todos los vertices de la componente
			           // conexa de i como VISITADOs, también sirve un DFS
		}
	}
	return nComp;
}

int componentesDesconectadasDijkstra(Graphl *G) {
	int i, nComp = 0; // Cuenta la cantidad de componentes conexas del grafo
	int * D = new int[G->n()];

	for (i = 0; i < G->n(); i++) {
		if (G->getMark(i) == UNVISITED) {
			nComp++;   // Vertice i esta en una componente conexa no considerada hasta ahora
			Dijkstra(G, D, i);
		}
	}
	return nComp;
}

int componentesDesconectadasPrim(Graphl *G) {
	int i, nComp = 0; // Cuenta la cantidad de componentes conexas del grafo
	int * D = new int[G->n()];

	for (i = 0; i < G->n(); i++) {
		if (G->getMark(i) == UNVISITED) {
			nComp++;   // Vertice i esta en una componente conexa no considerada hasta ahora
			Prim(G, D, i);
		}
	}
	return nComp;
}

int detectarIslas( Graphl * G ){
	int v, w;
	int nsat = 0;

	for ( v = 0; v < G->n(); v++ ){ // Para cada vértice
		for ( w = G->first(v); w < G->n(); w = G->next(v,w) ){ // Recorrer sus vecinos
			if (v == w) nsat++;
		}
	}
	return nsat;
}
	
int centralidad (Graphl * G, int nodo){
	int suma = 0;
	int * D = new int [G->n() ];
	
	for ( int i=0;i<G->n();i ++) {
		G->setMark(i, UNVISITED);
		//D[i]=0;
		//if(i== nodo ) D[i]=0;
		//else D[i]= INFINITY ;
	}
	
	Dijkstra (G, D, nodo);
	for (int i =0; i<G->n(); i++)  {
	cout << "nodo = " << nodo << " - D[" << i << "] = " << D[i] << "\n";
		suma +=D[i];
	}
	return suma ;
}

int el_centro(Graphl * G){
	int c, elcentro = -1, menor = INFINITY ;
	for ( int nodo =0; nodo <G->n(); nodo ++) {
		c = centralidad(G, nodo);
		if(c < menor ){
			menor =c;
			elcentro = nodo ;
		}
	}
	return elcentro ;
}

int main() {
	cout << "Hola mundo ..." << "\n";
	int cantidad = 0;
	int *arreglo;
	
	/* Datos para funcion saturados(), grafo dirigido */
	/*
	Graphl *grf = new Graphl(6);
	grf->setEdge(0, 1, 10);
	grf->setEdge(0, 3, 20);
	grf->setEdge(0, 2, 3);
	grf->setEdge(1, 3, 5);
	grf->setEdge(2, 1, 2);
	grf->setEdge(2, 4, 15);
	grf->setEdge(3, 4, 11);

	arreglo = saturados( grf, cantidad );
	for (int i=0; i<cantidad; i++) 
		cout << "arreglo[" << i << "] = " << arreglo[i] << "\n";
	*/
	
	/* Datos para funcion componentesDesconectadas() grafo no dirigido */
	/*
	Graphl *grf = new Graphl(8);
	grf->setEdge(0, 1, 1);
	grf->setEdge(1, 0, 1);
	grf->setEdge(0, 2, 2);
	grf->setEdge(2, 0, 2);
	grf->setEdge(1, 3, 3);
	grf->setEdge(3, 1, 3);
	grf->setEdge(4, 5, 5);
	grf->setEdge(5, 4, 5);
	grf->setEdge(6, 7, 7);
	grf->setEdge(7, 6, 7);
	
	cantidad = componentesDesconectadasDFS( grf );
	cout << "Componentes desconectadas (DFS) = " << cantidad << "\n";

	cantidad = componentesDesconectadasDijkstra( grf );
	cout << "Componentes desconectadas (Dijkstra) = " << cantidad << "\n";	

	cantidad = componentesDesconectadasPrim( grf );
	cout << "Componentes desconectadas (Prim) = " << cantidad << "\n";	
	*/

	/* Datos para funcion detectarIslas() grafo dirigido */
	/*
	Graphl *grf = new Graphl(8);
	grf->setEdge(0, 1, 1);
	grf->setEdge(0, 3, 3);
	grf->setEdge(1, 2, 2);
	grf->setEdge(2, 3, 3);
	
	grf->setEdge(4, 4, 4);
	grf->setEdge(5, 6, 6);
	grf->setEdge(7, 7, 7);
	
	cantidad = detectarIslas( grf );
	cout << "cantidad = " << cantidad << "\n";
	*/

	/* Datos para funcion centralidad() grafo no dirigido */
	
	Graphl *grf = new Graphl(5);
	grf->setEdge(0, 1, 5);
	grf->setEdge(1, 0, 5);
	grf->setEdge(0, 4, 3);
	grf->setEdge(4, 0, 3);
	grf->setEdge(1, 3, 1);
	grf->setEdge(3, 1, 1);
	grf->setEdge(1, 2, 7);
	grf->setEdge(2, 1, 7);
	
	grf->setEdge(2, 3, 3);
	grf->setEdge(3, 2, 3);
	grf->setEdge(2, 4, 1);
	grf->setEdge(4, 2, 1);

	
	cantidad = el_centro( grf );
	cout << "nodo = " << cantidad << "\n";
		
	/* Consultas al grafo */
	cout << "Numero de vertices: " << grf->n() << "\n";
	cout << "Numero de arcos: " << grf->e() << "\n";
	cout << "\n";

}