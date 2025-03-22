#include "inventario.h"

Inventario::Inventario(int num){
    numeroClaves=0;
    hoja=true;
    numero=num;
    claves=new datosInventario[(2*num)];
    hijos=new Inventario*[(2*num)];
}

void Inventario::imprimir(){
    for(int i=0;i<numeroClaves;i++){
        if(claves[i].estado){
            cout<<"ID: "<<claves[i].id<<" Nombre: "<<claves[i].nombre<<" Cantidad: "<<claves[i].cantidad<<" Categoria: "<<claves[i].categoria<<" Precio: "<<claves[i].precio<<endl;
        }
    }
}

datosInventario* Inventario::buscar(int id){
    for(int i=0;i<numeroClaves;i++){
        if(claves[i].id==id&&claves[i].estado){
            return &claves[i];
        }
    }
    return nullptr;
}