#include "clientes.h"

Clientes::Clientes(int num){
    numeroClaves=0;
    hoja=true;
    claves=new datosClientes[(2*num)];
    hijos=new Clientes*[(2*num)];
}

void Clientes::imprimir(){
    string producto="";
    int contar;
    for(int i=0;i<numeroClaves;i++){
        cout<<"ID: "<<claves[i].id<<" Nombre: "<<claves[i].nombre<<" Correo: "<<claves[i].correo<<" Telefono: "<<claves[i].telefono<<" Saldo: "<<claves[i].saldo<<endl;
        cout<<"Compras: ";
        for(int i=0;i<claves[i].historialCompras.size();i++){
            if(producto!=claves[i].historialCompras.at(i)){
                if(i!=0){
                    cout<<", Cantidad: "<<contar<<" ";
                }
                cout<<claves[i].historialCompras.at(i);
                producto=claves[i].historialCompras.at(i);
                contar=0;
            }else if(i==claves[i].historialCompras.size()-1){
                cout<<", Cantidad: "<<contar<<endl;
            }else{
                contar++;
            }
        }
    }
}

datosClientes Clientes::buscar(int id){
    datosClientes datos;
    for(int i=0;i<numeroClaves;i++){
        if(claves[i].id==id){
            datos=claves[i];
            break;
        }
    }
    return datos;
}