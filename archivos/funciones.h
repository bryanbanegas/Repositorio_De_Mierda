#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

void guardarIDs(int idEmpleados,int idClientes,int idPedidos,int idVentas,int idInventario);
int leerArchivoID(int pos);
bool esint(const string& entrada);
bool esdouble(const string& entrada);

#endif