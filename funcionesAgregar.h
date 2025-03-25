#ifndef FUNCIONESAGREGAR_H
#define FUNCIONESAGREGAR_H
#include "/home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolEmpleados.h"
#include "/home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolClientes.h"
#include "/home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolVentas.h"
#include "/home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolInventario.h"
#include "/home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolPedidos.h"
#include "/home/bryan/Documents/VSCode/Gestion_Empresarial/archivos/funciones.h"
#include <thread>

ArbolEmpleados *arbolEmpleados=new ArbolEmpleados(3);
ArbolClientes *arbolClientes=new ArbolClientes(3);
ArbolVentas *arbolVentas=new ArbolVentas(3);
ArbolInventario *arbolInvetario=new ArbolInventario(3);
ArbolPedidos *arbolPedidos=new ArbolPedidos(3);
int idEmpleados=0,idClientes=0,idPedidos=0,idVentas=0,idInventario=0,cantidadInventario=0;

void agregarEmpleados(){
    string nombre, departamento, puesto, opcion="d",salario;
    cout << "---------------------------------" << endl;
    cout << "Ingresar nombre: ";
    getline(cin,nombre);
    while(opcion != "1" && opcion != "2"){
        cout << "Seleccionar Departamento:" << endl
        << "1. Administracion" << endl
        << "2. Personal Laboral" << endl
        << "Ingresar departamento: ";
        getline(cin,opcion);
        if(opcion == "1"){
            departamento = "Administracion";
        } else if(opcion == "2"){
            departamento = "Personal Laboral";
        }  
    }
    if(departamento == "Administracion"){
        opcion="g";
        while(opcion != "1" && opcion != "2"){
            cout << "Seleccionar puesto:" << endl
            << "1. Ventas" << endl
            << "2. Pedidos" << endl
            << "Ingresar puesto: ";
            getline(cin,opcion);
            if(opcion == "1"){
                puesto = "Ventas";
            } else if(opcion == "2"){
                puesto = "Pedidos";
            }  
        }
    }else{
        puesto = "Laboral";
    }
    do{
        cout << "Ingresar salario: ";
        getline(cin,salario);
    }while(!esdouble(salario));
    for(int i=0;i<4;i++){
        if(i==0){
            cout<<"Cargando."<<flush;
        }else if(i==1){
            cout<<"."<<flush;
        }else if(i==2){
            cout<<"."<<flush;
        }else{
            cout<<"."<<flush;
        }
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout<<endl;
    arbolEmpleados->insertar(idEmpleados,nombre,departamento,puesto,stod(salario),true);
    cout << "---------------------------------" << endl;
    cout << "¡Empleado agregado con éxito!" << endl;
    cout << "ID: " << idEmpleados << endl;
    cout << "---------------------------------" << endl;
}

void agregarCliente(){
    string nombre, correo, telefono, opcion="d",saldo;
    cout << "---------------------------------" << endl;
    cout << "Ingresar nombre del cliente: ";
    getline(cin,nombre);
    cout << "Ingresar correo del cliente: ";
    getline(cin,correo);
    do{
        cout << "Ingresar telefono del cliente: ";
        getline(cin,telefono);
    }while(!esint(telefono)||telefono.length()!=8);
    cout << "Ingresar saldo del cliente: ";
    do{
        cout << "Ingresar saldo del cliente: ";
        getline(cin,saldo);
    }while(!esdouble(saldo));
    for(int i=0;i<4;i++){
        if(i==0){
            cout<<"Cargando."<<flush;
        }else if(i==1){
            cout<<"."<<flush;
        }else if(i==2){
            cout<<"."<<flush;
        }else{
            cout<<"."<<flush;
        }
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout<<endl;
    arbolClientes->insertar(idClientes,nombre,correo,telefono,stod(saldo));
    cout << "---------------------------------" << endl;
    cout << "¡Cliente agregado con éxito!" << endl;
    cout << "---------------------------------" << endl;
}

void agregarProducto(){
    string opcionCategoria,nombre,categoria,cantidad, precio;
    cout<<"Ingresar nombre de producto:";
    getline(cin,nombre);
    opcionCategoria="j";
    while(opcionCategoria != "1" && opcionCategoria != "2"){
        cout << "Seleccionar Categoria:" << endl
        << "1. Comestible" << endl
        << "2. No Comestible" << endl
        << "Ingresar departamento: ";
        getline(cin,opcionCategoria);
        if(opcionCategoria == "1"){
            categoria = "Comestible";
        } else if(opcionCategoria == "2"){
            categoria = "No Comestible";
        }    
    }
    do{
        cout<<"Ingresar cantidad de producto:";
        getline(cin,cantidad);
    }while(!esint(cantidad));
    do{
        cout<<"Ingresar precio de producto:";
        getline(cin,precio);
    }while(!esdouble(precio));
    idInventario=leerArchivoID(4);
    idInventario++;
    guardarIDs(idEmpleados,idClientes,idPedidos,idVentas,idInventario);
    for(int i=0;i<4;i++){
        if(i==0){
            cout<<"Cargando."<<flush;
        }else if(i==1){
            cout<<"."<<flush;
        }else if(i==2){
            cout<<"."<<flush;
        }else{
            cout<<"."<<flush;
        }
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout<<endl;
    arbolInvetario->insertar(idInventario,nombre,categoria,stoi(cantidad),stod(precio),true);
    cout << "---------------------------------" << endl;
    cout << "¡Producto agregado con éxito!" << endl;
    cout << "ID de producto: " << idInventario << endl;
    cout << "---------------------------------" << endl;
    cout<<endl;
}

void agregarPedido(string cliente,int idCliente,double saldo){
    string cantidad,fecha,id="";
    int cantidadProductos=0;
    double total=0;
    bool pedido=false;
    cout << "---------------------------------" << endl;
    fecha="3/25/2025";
    datosPedidos datos1;
    datosInventario *datos2;
    while(id!="0"){
        arbolInvetario->imprimir();
        cout << "Para salir ingrese 0: "<<endl;
        do{
            cout << "Ingresar ID de producto: ";
            getline(cin,id);
        }while(!esint(id));
        if(id!="0"){
            do{
                cout << "Ingresar cantidad que quiere de producto: ";
                getline(cin,cantidad);
            }while(!esint(cantidad));
            datos2=arbolInvetario->buscar(stoi(id));
            if(datos2==nullptr){
                cout<<"Este producto no existe."<<endl;
            }else{
                if(stoi(cantidad)<=datos2->cantidad&&stoi(cantidad)>1){
                    total+=stoi(cantidad)*datos2->precio;
                    cout<<total<<endl;
                    cout<<saldo<<endl;
                    if(saldo>=total){
                        pedido=true;
                        cantidadProductos+=stoi(cantidad);
                        saldo-=total;
                        for(int i=0;i<stoi(cantidad);i++){
                            datos1.productosSolicitados.push_back(datos2->nombre);
                        }
                        datos2->cantidad=datos2->cantidad-stoi(cantidad);
                        if(datos2->cantidad==0){
                            datos2->estado=false;
                        }
                    }else{
                        total-=stoi(cantidad)*datos2->precio;
                        cout<<"No tiene suficiente saldo para esta compra."<<endl;
                    }
                }else{
                    cout<<"La cantidad ingresada excede la cantidad del producto o es menor que 1."<<endl;
                }
            }
        }
        cout<<endl;
    }
    if(pedido){
        idPedidos=leerArchivoID(2);
        idPedidos++;
        guardarIDs(idEmpleados,idClientes,idPedidos,idVentas,idInventario);
        arbolPedidos->insertar(idPedidos,cliente,fecha,false);
        arbolPedidos->buscar(idPedidos)->productosSolicitados=datos1.productosSolicitados;
        for(int i=0;i<4;i++){
            if(i==0){
                cout<<"Cargando."<<flush;
            }else if(i==1){
                cout<<"."<<flush;
            }else if(i==2){
                cout<<"."<<flush;
            }else{
                cout<<"."<<flush;
            }
            this_thread::sleep_for(chrono::seconds(1));
        }
        cout<<endl;
        cout << "---------------------------------" << endl;
        cout << "¡Pedido hecho con éxito!" << endl;
        cout << "Total de pedido: " << total << endl;
        cout << "ID de pedido: " << idPedidos << endl;
        cout << "---------------------------------" << endl;
        idVentas=leerArchivoID(3);
        idVentas++;
        guardarIDs(idEmpleados,idClientes,idPedidos,idVentas,idInventario);
        arbolVentas->insertar(idVentas,idCliente,fecha,cantidadProductos,total);
        arbolVentas->buscar(idVentas)->productosVendidos=datos1.productosSolicitados;
        arbolClientes->buscar(idCliente)->saldo=saldo;
    }else{
        cout << "---------------------------------" << endl;
        cout << "No realizo ningun pedido." << endl;
        cout << "---------------------------------" << endl;
    }
}

#endif