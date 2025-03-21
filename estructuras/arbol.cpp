#include "arbol.h"

Arbol::Arbol(int num){
    this->num=num;
    root=new Nodo(num);
}

void Arbol::buscar(int clave){

}

void Arbol::insertar(int clave) {
    if (root->numeroClaves == (2 * num) - 1) {  // Si la raíz está llena, hacer split
        Nodo* nuevaRoot = new Nodo(num);
        nuevaRoot->hoja = false;
        nuevaRoot->numeroClaves = 0;
        nuevaRoot->hijos[0] = root;

        split(nuevaRoot, 0, root); // Dividir la raíz
        root = nuevaRoot;  // Nueva raíz después del split
    }

    nonfullInsert(root, clave);
}

void Arbol::split(Nodo* nodoPadre, int index, Nodo* nodoLleno) {
    Nodo* nuevoNodo = new Nodo(num);
    nuevoNodo->hoja = nodoLleno->hoja;
    nuevoNodo->numeroClaves = num - 1;

    // Mover las claves superiores al nuevo nodo
    for (int i = 0; i < num - 1; i++) {
        nuevoNodo->claves[i] = nodoLleno->claves[i + num];
    }

    // Mover los hijos si no es hoja
    if (!nodoLleno->hoja) {
        for (int i = 0; i < num; i++) {
            nuevoNodo->hijos[i] = nodoLleno->hijos[i + num];
        }
    }

    // Reducir el número de claves en el nodo lleno
    nodoLleno->numeroClaves = num - 1;

    // Mover los hijos del nodo padre
    for (int i = nodoPadre->numeroClaves; i > index; i--) {
        nodoPadre->hijos[i + 1] = nodoPadre->hijos[i];
    }
    nodoPadre->hijos[index + 1] = nuevoNodo;

    // Mover las claves del nodo padre
    for (int i = nodoPadre->numeroClaves - 1; i >= index; i--) {
        nodoPadre->claves[i + 1] = nodoPadre->claves[i];
    }
    nodoPadre->claves[index] = nodoLleno->claves[num - 1];  // Subir la clave media al padre
    nodoPadre->numeroClaves++;
}

void Arbol::nonfullInsert(Nodo* nodo, int clave) {
    if (nodo->hoja) {
        int i = nodo->numeroClaves - 1;
        while (i >= 0 && clave < nodo->claves[i]) {
            nodo->claves[i + 1] = nodo->claves[i];  // Mover claves hacia la derecha
            i--;
        }
        nodo->claves[i + 1] = clave;
        nodo->numeroClaves++;
    } else {
        int i = nodo->numeroClaves - 1;
        while (i >= 0 && clave < nodo->claves[i]) {
            i--;
        }
        i++;

        if (nodo->hijos[i]->numeroClaves == (2 * num) - 1) {
            split(nodo, i, nodo->hijos[i]);
            if (clave > nodo->claves[i]) {
                i++;
            }
        }

        nonfullInsert(nodo->hijos[i], clave);
    }
}


void Arbol::print(Nodo nodoArbol){
    nodoArbol.imprimir();

    if(!nodoArbol.hoja){
        for(int i=0;i<=nodoArbol.numeroClaves;i++){
            if(nodoArbol.hijos[i]!=nullptr){
                cout<<endl;
                print(*nodoArbol.hijos[i]);
            }
        }
    }
}

void Arbol::imprimir(){
    print(*root);
}