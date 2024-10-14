#include <iostream>
#include "tree.h"

tABB::tABB(){
    raiz = nullptr;
    nElems = 0;
};

// // elimina todos los elementos de un ABB T, dejándolo vacío
// void tABB::clear() {
//     clearHelp(raiz); // función auxiliar para eliminar los nodos
//     raiz = nullptr;
//     nElems = 0;
// }
//
// // función auxiliar recursiva para eliminar los nodos del árbol
// void tABB::clearHelp(tNodoArbolBin *nodo) {
//     if (nodo == nullptr) // árbol vacío, se detiene
//         return;
//     clearHelp(nodo->izq); // visita subárbol izquierdo recursivamente
//     clearHelp(nodo->der); // visita subárbol derecho recursivamente
//     delete nodo; // después de borrar subárboles, se borra a sí mismo
// }

// recorrido in-orden de un ABB T
void tABB::inOrden () {
    inOrdenHelp (raiz);
    std::cout << std::endl;
}

void tABB::inOrdenHelp (tNodoArbolBin *nodo) {
    if (nodo == nullptr) return;
    inOrdenHelp (nodo->izq); // visita hijo izquierdo en in-orden
    std::cout << nodo->info << " "; // procesa nodo actual
    inOrdenHelp (nodo->der); // visita hijo derecho en in-orden
}

// busca un "item" en un ABB T, retorna 0 en caso de no encontrarlo
int tABB::find(tipoElem item) {
    return findHelp(raiz, item);
}

int tABB::findHelp(tNodoArbolBin *nodo, tipoElem item) {
    if (nodo == nullptr)
        return 0; // item no está en el ABB

    if (nodo->info == item)
        return 1; // item encontrado
    if (item < nodo->info)
        return findHelp(nodo->izq, item);
    else
        return findHelp(nodo->der, item);
}


void tABB::insert(tipoElem item){
    if (!find(item)){
        insertHelp(raiz, item);
    }
    return;
}

void tABB::insertHelp(tNodoArbolBin *&nodo, tipoElem item){
    if (nodo == nullptr){
        nodo = new tNodoArbolBin;
        nodo->info = item;
        nodo->izq = nullptr;
        nodo->der = nullptr;
        nElems++;
    }
    else{
        if (item < nodo->info){
            insertHelp(nodo->izq, item);
        }
        else
            insertHelp(nodo->der, item);
    }
    return;
}
