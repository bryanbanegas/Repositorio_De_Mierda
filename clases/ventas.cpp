#include "ventas.h"

Ventas::Ventas(int num){
    numeroClaves=0;
    hoja=true;
    claves=new datosVentas[(2*num)];
    hijos=new Ventas*[(2*num)];
}

void imprimirVentas(vector<string> ventas){
    if(ventas.empty()){
        return;
    }
    string productoActual=ventas.at(0);
    int contar=0;
    cout<<"Productos Vendidos: ";
    for(int i=0;i<ventas.size();i++){
        if(productoActual==ventas.at(i)){
            contar++;
        }else{
            cout<<productoActual<<", Cantidad:"<<contar<<" ";
            productoActual=ventas.at(i);
            contar=1;
        }
    }
    cout<<productoActual<<", Cantidad:"<<contar;
    cout<<endl;
}

void Ventas::imprimir(){
    string producto="";
    int contar;
    for(int i=0;i<numeroClaves;i++){
        cout<<"ID de Venta: "<<claves[i].idVenta<<" ID de CLiente: "<<claves[i].idCliente<<" Fecha: "<<claves[i].fecha<<" Cantidad: "<<claves[i].cantidad
        <<" Total: "<<claves[i].total<<endl;
        imprimirVentas(claves[i].productosVendidos);
    }
}

datosVentas* Ventas::buscar(int id){
    for(int i=0;i<numeroClaves;i++){
        if(claves[i].idCliente==id){
            return &claves[i];
        }
    }
    return nullptr;
}

bool Ventas::eliminar(int id){
    return true;
}