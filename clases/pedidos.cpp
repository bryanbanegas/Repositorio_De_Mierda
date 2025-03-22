#include "pedidos.h"

Pedidos::Pedidos(int num){
    numeroClaves=0;
    hoja=true;
    claves=new datosPedidos[(2*num)];
    hijos=new Pedidos*[(2*num)];
}

void imprimirPedidos(vector<string> pedidos){
    if(pedidos.empty()){
        return;
    }
    string productoActual=pedidos.at(0);
    int contar=0;
    cout<<"Pedidos: ";
    for(int i=0;i<pedidos.size();i++){
        if(productoActual==pedidos.at(i)){
            contar++;
        }else{
            cout<<productoActual<<", Cantidad:"<<contar<<" ";
            productoActual=pedidos.at(i);
            contar=1;
        }
    }
    cout<<productoActual<<", Cantidad:"<<contar;
    cout<<endl;
}

void Pedidos::imprimir(){
    string productoActual;
    int contar=0;
    for(int i=0;i<numeroClaves;i++){
        if(claves[i].estado){
            cout<<"ID: "<<claves[i].id<<", Cliente: "<<claves[i].cliente<<", Fecha: "<<claves[i].fecha<<", Cliente: "<<claves[i].cliente<<", Se a entregado el pedido."<<endl;
        }else{
            cout<<"ID: "<<claves[i].id<<", Cliente: "<<claves[i].cliente<<", Fecha: "<<claves[i].fecha<<", Cliente: "<<claves[i].cliente<<", No se a entregado el pedido."<<endl;
        }
        imprimirPedidos(claves[i].productosSolicitados);
    }
}

datosPedidos* Pedidos::buscar(int id){
    for(int i=0;i<numeroClaves;i++){
        if(claves[i].id==id){
            return &claves[i];
        }
    }
    return nullptr;
}

bool Pedidos::confirmar(int id){
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


