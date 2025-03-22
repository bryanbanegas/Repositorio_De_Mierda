#ifndef ARBOLEMPLEADOS_H
#define ARBOLEMPLEADOS_H

#include "/home/bryan/Documents/VSCode/Gestion_Empresarial/clases/empleados.h"
#include <fstream>
#include <iterator>

class ArbolEmpleados{
public:
    Empleados *root;
    int num;
    datosEmpleados dato;

    ArbolEmpleados(int num);

    datosEmpleados buscar(int clave);
    bool cambiar(int clave);
    void insertar(int clave, string nombre, string departamento, string puesto, double salario, bool estado);
    void imprimir();
    void guardarEnArchivoBinario();
    void leerEnArchivoBinario();
private:
    void split(Empleados *nodo1,int i, Empleados *nodo2);
    void nonfullInsert(Empleados *nodo,int clave);
    void print(Empleados nodoArbol);
    datosEmpleados search(int clave,Empleados nodoArbol);
    bool cambiarEstado(int clave,Empleados nodo);
    void save(ofstream &archivo,Empleados *nodo);
    Empleados* read(ifstream &archivo);
};

#endif