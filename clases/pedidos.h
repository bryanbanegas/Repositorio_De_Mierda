#ifndef PEDIDOS_H
#define PEDIDOS_H

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

struct datosPedidos{
    int id;
    string cliente;
    string fecha;
    vector<string> productosSolicitados;
    bool estado;
};

class Pedidos{
public:
    datosPedidos* claves;
    int numeroClaves;
    Pedidos **hijos;
    bool hoja;

    Pedidos(int num);
    void imprimir();
    datosPedidos buscar(int id);
    bool confirmar(int id);
    bool eliminar(int id);
};

#endif