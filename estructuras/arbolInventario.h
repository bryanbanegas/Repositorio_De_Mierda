#ifndef ARBOLINVENTARIO_H
#define ARBOLINVENTARIO_H

#include "/home/bryan/Documents/VSCode/Gestion_Empresarial/clases/inventario.h"
#include <fstream>

class ArbolInventario{
public:
    Inventario *root;
    int num;
    datosInventario dato;

    ArbolInventario(int num);

    datosInventario* buscar(int clave);
    void insertar(int clave, string nombre, string categoria,int cantidad, double precio, bool estado);
    void imprimir();
    void guardarEnArchivoBinario();
    void leerEnArchivoBinario();
private:
    datosInventario* search(int clave,Inventario nodoArbol);
    void split(Inventario *nodo1,int i, Inventario *nodo2);
    void nonfullInsert(Inventario *nodo,int clave);
    void print(Inventario nodoArbol);
    void save(ofstream &archivo,Inventario *nodo);
    Inventario* read(ifstream &archivo);
};

#endif