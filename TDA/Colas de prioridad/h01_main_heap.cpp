#include "./partes/imp_heap.cpp"
#include <iostream>
using namespace std;
#define defaultSize 14

int main() {
	int *arreglo = new int[defaultSize];

	heap<int>* colaPrioridad = new heap<int>(arreglo,0,defaultSize);

	colaPrioridad->insert(50);
	colaPrioridad->insert(47);
	colaPrioridad->insert(22);
	colaPrioridad->insert(32);
	colaPrioridad->insert(44);
	colaPrioridad->insert(12);
	colaPrioridad->insert(19);
	colaPrioridad->insert(16);
	colaPrioridad->insert(3);
	colaPrioridad->insert(37);
	colaPrioridad->insert(41);
	colaPrioridad->insert(9);

	int largo = colaPrioridad->size();
	cout << "largo =" << largo << "\n";
	
	for (int i = 0; i<largo; i++) {
		cout << "arreglo[" << i << "] = " << arreglo[i] << "\n";
	}
}