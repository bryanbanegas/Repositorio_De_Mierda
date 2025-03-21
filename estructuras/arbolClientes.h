#ifndef ARBOLCLIENTES_H
#define ARBOLCLIENTES_H

#include "/home/bryan/Documents/VSCode/Gestion_Empresarial/clases/clientes.h"
#include <fstream>

class ArbolClientes{
public:
    Clientes *root;
    int num;
    datosClientes dato;

    ArbolClientes(int num);

    datosClientes buscar(int clave);
    void insertar(int clave, string nombre, string correo, string telefono, double saldo);
    void imprimir();
    void guardarEnArchivoBinario();
    void leerEnArchivoBinario();
private:
    void split(Clientes *nodo1,int i, Clientes *nodo2);
    void nonfullInsert(Clientes *nodo,int clave);
    void print(Clientes nodoArbol);
    datosClientes search(int clave,Clientes nodoArbol);
    void save(ofstream &archivo,Clientes *nodo);
    Clientes* read(ifstream &archivo);
};

#endif