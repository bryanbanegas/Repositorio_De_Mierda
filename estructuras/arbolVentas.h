#ifndef ARBOLVENTAS_H
#define ARBOLVENTAS_H

#include "/home/bryan/Documents/VSCode/Gestion_Empresarial/clases/ventas.h"
#include <fstream>

class ArbolVentas{
public:
    Ventas *root;
    int num;
    datosVentas dato;

    ArbolVentas(int num);

    datosVentas* buscar(int clave);
    void insertar(int clave, int idcliente, string fecha, int cantidad, double total);
    void imprimir();
    void guardarEnArchivoBinario();
    void leerEnArchivoBinario();
private:
    datosVentas* search(int clave,Ventas nodo);
    void split(Ventas *nodo1,int i, Ventas *nodo2);
    void nonfullInsert(Ventas *nodo,int clave);
    void print(Ventas nodoArbol);
    void save(ofstream &archivo,Ventas *nodo);
    Ventas* read(ifstream &archivo);
};

#endif