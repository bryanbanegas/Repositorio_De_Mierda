#include "funciones.h"

void guardarIDs(int idEmpleados,int idClientes,int idPedidos,int idVentas,int idInventario){
    ofstream archivo("archivos/datosID.txt");
    if(!archivo){
        cout<<"Error"<<endl;
        return;
    }
    archivo<<idEmpleados<<endl;
    archivo<<idClientes<<endl;
    archivo<<idPedidos<<endl;
    archivo<<idVentas<<endl;
    archivo<<idInventario<<endl;

    archivo.close();
}

int leerArchivoID(int pos){
    string mensaje;
    int contar=-1,numero;
    ifstream archivo("archivos/datosID.txt");
    if(!archivo){
        cout<<"Error"<<endl;
        return -1;
    }
    while(getline(archivo,mensaje)){
        contar++;
        if(contar==pos){
            numero=stoi(mensaje);
            break;
        }
    }
    archivo.close();
    return numero;
}
