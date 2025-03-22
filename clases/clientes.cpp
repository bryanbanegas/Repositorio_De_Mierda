#include "clientes.h"

Clientes::Clientes(int num){
    numeroClaves=0;
    hoja=true;
    claves=new datosClientes[(2*num)];
    hijos=new Clientes*[(2*num)];
}

void imprimirCompras(vector<string> compras){
    if(compras.empty()){
        return;
    }
    string productoActual=compras.at(0);
    int contar=0;
    cout<<"Compras: ";
    for(int i=0;i<compras.size();i++){
        if(productoActual==compras.at(i)){
            contar++;
        }else{
            cout<<productoActual<<", Cantidad:"<<contar<<" ";
            productoActual=compras.at(i);
            contar=1;
        }
    }
    cout<<productoActual<<", Cantidad:"<<contar;
    cout<<endl;
}

void Clientes::imprimir(){
    string producto="";
    int contar;
    for(int i=0;i<numeroClaves;i++){
        cout<<"ID: "<<claves[i].id<<" Nombre: "<<claves[i].nombre<<" Correo: "<<claves[i].correo<<" Telefono: "<<claves[i].telefono<<" Saldo: "<<claves[i].saldo<<endl;
        imprimirCompras(claves[i].historialCompras);
    }
}

datosClientes* Clientes::buscar(int id){
    for(int i=0;i<numeroClaves;i++){
        if(claves[i].id==id){
            return &claves[i];
        }
    }
    return nullptr;
}