typedef int tipoElem;

struct tNodoArbolBin {
    tipoElem info;
    tNodoArbolBin* izq;
    tNodoArbolBin* der;
};


class tABB {
    tNodoArbolBin* raiz;
    int nElems;
public:
    tABB();
    // elimina todos los elementos de un ABB, dejándolo vacío
    //void clear();
    //void clearHelp(tNodoArbolBin *nodo);

    // inserta un elemento “item” en el ABB
    void insert(tipoElem item);
    void insertHelp(tNodoArbolBin *&nodo, tipoElem item);

    // elimina un elemento “item” de un ABB
    //void remove(tipoElem item);

    // busca un “item” en un ABB, retorna 0 en caso de no encontrarlo
    int find(tipoElem item);
    int findHelp(tNodoArbolBin *nodo, tipoElem item);

    // cantidad de elementos en el árbol
    //int size();

    // recorrido in-orden de un ABB
    void inOrden();
    void inOrdenHelp(tNodoArbolBin *nodo);

    // recorrido pre-orden de un ABB
    //void preOrden();
    // recorrido post-orden de un ABB
    //void postOrden();

};

