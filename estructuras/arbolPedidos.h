#ifndef ARBOLPEDIDOS_H
#define ARBOLPEDIDOS_H

#include "/home/bryan/Documents/VSCode/Gestion_Empresarial/clases/pedidos.h"
#include <fstream>

class ArbolPedidos{
public:
    Pedidos *root;
    int num;
    datosPedidos dato;

    ArbolPedidos(int num);

    datosPedidos buscar(int clave);
    bool confirmar(int clave);
    void insertar(int clave, string cliente, string fecha, bool estado);
    void imprimir();
    void guardarEnArchivoBinario();
    void leerEnArchivoBinario();
private:
    bool confirmarPedido(int clave,Pedidos nodo);
    datosPedidos search(int clave,Pedidos nodo);
    void split(Pedidos *nodo1,int i, Pedidos *nodo2);
    void nonfullInsert(Pedidos *nodo,int clave);
    void print(Pedidos nodoArbol);
    void save(ofstream &archivo,Pedidos *nodo);
    Pedidos* read(ifstream &archivo);
};

#endif