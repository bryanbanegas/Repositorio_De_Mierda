#include "empleados.h"

Empleados::Empleados(int num){
    numeroClaves=0;
    hoja=true;
    claves=new datosEmpleados[(2*num)];
    hijos=new Empleados*[(2*num)];
}

void Empleados::imprimir(){
    for(int i=0;i<numeroClaves;i++){
        if(claves[i].estado){
            cout<<"ID: "<<claves[i].id<<", Nombre: "<<claves[i].nombre<<", Departamento: "<<claves[i].departamento<<", Puesto: "<<claves[i].puesto<<", Salario: "<<
            claves[i].salario<<", Esta Disponible."<<endl;
        }else{
            cout<<"ID: "<<claves[i].id<<", Nombre: "<<claves[i].nombre<<", Departamento: "<<claves[i].departamento<<", Puesto: "<<claves[i].puesto<<", Salario: "<<
            claves[i].salario<<", No esta Disponible."<<endl;
        }
    }
}

datosEmpleados Empleados::buscar(int id){
    datosEmpleados datos;
    for(int i=0;i<numeroClaves;i++){
        if(claves[i].id==id){
            datos=claves[i];
            break;
        }
    }
    return datos;
}

bool Empleados::cambiar(int id){
    for(int i=0;i<numeroClaves;i++){
        if(claves[i].id==id){
            if(claves[id].estado){
                claves[id].estado=false;
            }else{
                claves[id].estado=true;
            }
            return true;
        }
    }
    return false;
}