#include "ventas.h"

Ventas::Ventas(int num){
    numeroClaves=0;
    hoja=true;
    claves=new datosVentas[(2*num)];
    hijos=new Ventas*[(2*num)];
}

void Ventas::imprimir(){
    string producto="";
    int contar;
    cout<<"-----Nodo------"<<endl;
    for(int i=0;i<numeroClaves;i++){
        cout<<"ID de Venta: "<<claves[i].idVenta<<" ID de CLiente: "<<claves[i].idCliente<<" Fecha: "<<claves[i].fecha<<" Cantidad: "<<claves[i].cantidad
        <<" Total: "<<claves[i].total<<endl;
        cout<<"Productos Vendidos: ";
        for(int i=0;i<claves[i].productosVendidos.size();i++){
            if(producto!=claves[i].productosVendidos.at(i)){
                if(i!=0){
                    cout<<", Cantidad: "<<contar<<" ";
                }
                cout<<claves[i].productosVendidos.at(i);
                producto=claves[i].productosVendidos.at(i);
                contar=0;
            }else if(i==claves[i].productosVendidos.size()-1){
                cout<<", Cantidad: "<<contar<<endl;
            }else{
                contar++;
            }
        }
    }
}

datosVentas Ventas::buscar(int id){
    datosVentas datos;
    for(int i=0;i<numeroClaves;i++){
        if(claves[i].idVenta==id){
            datos=claves[i];
            break;
        }
    }
    return datos;
}

bool Ventas::eliminar(int id){
    return true;
}