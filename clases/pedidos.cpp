#include "pedidos.h"

Pedidos::Pedidos(int num){
    numeroClaves=0;
    hoja=true;
    claves=new datosPedidos[(2*num)];
    hijos=new Pedidos*[(2*num)];
}

void Pedidos::imprimir(){
    string producto;
    int contar=0;
    cout<<"-----Nodo------"<<endl;
    for(int i=0;i<numeroClaves;i++){
        if(claves[i].estado){
            cout<<"ID: "<<claves[i].id<<" Cliente: "<<claves[i].cliente<<" Fecha: "<<claves[i].fecha<<" Cliente: "<<claves[i].cliente<<" Se a entregado el pedido."<<endl;
        }else{
            cout<<"ID: "<<claves[i].id<<" Cliente: "<<claves[i].cliente<<" Fecha: "<<claves[i].fecha<<" Cliente: "<<claves[i].cliente<<" No se a entregado el pedido."<<endl;
        }
        cout<<"Pedidos: ";
        for(int i=0;i<claves[i].productosSolicitados.size();i++){
            if(producto!=claves[i].productosSolicitados.at(i)){
                if(i!=0){
                    cout<<", Cantidad: "<<contar<<" ";
                }
                cout<<claves[i].productosSolicitados.at(i);
                producto=claves[i].productosSolicitados.at(i);
                contar=0;
            }else if(i==claves[i].productosSolicitados.size()-1){
                cout<<", Cantidad: "<<contar<<endl;
            }else{
                contar++;
            }
        }
    }
}

datosPedidos Pedidos::buscar(int id){
    datosPedidos datos;
    for(int i=0;i<numeroClaves;i++){
        if(claves[i].id==id){
            datos=claves[i];
            break;
        }
    }
    return datos;
}

bool Pedidos::confirmar(int id){
    datosPedidos datos;
    for(int i=0;i<numeroClaves;i++){
        if(claves[i].id==id){
            claves[id].estado=true;
            return true;
        }
    }
    return false;
}

bool Pedidos::eliminar(int id){
    return true;
}

