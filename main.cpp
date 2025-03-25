#include "funcionesAgregar.h"

void administracion(string puesto){
    string opcion="er",opcionVentas,opcionPedidos,id;
    while(opcion!="3"){
        cout << "---------------------------------" << endl;
        cout << "---- MENÚ ADMINISTRACION ----" << endl;
        cout << "1. Gestion de Ventas" << endl
        << "2. Gestion de Pedidos" << endl
        << "3. Salir" << endl
        << "Ingresar una opcion: ";
        getline(cin,opcion);
        cout << "---------------------------------" << endl;
        if(opcion == "1" && puesto=="Ventas"){
            opcionVentas="h";
            while(opcionVentas!="2"){
                cout << "---- MENÚ VENTAS ----" << endl;
                cout << "1. Ver Ventas" << endl
                << "2. Salir" << endl    
                << "Ingresar una opcion: ";
                getline(cin,opcionVentas);
                cout << "---------------------------------" << endl;
                if(opcionVentas == "1"){
                    arbolVentas->imprimir();
                }
            }
        } else if(opcion == "2" && puesto=="Pedidos"){
            opcionPedidos="j";
            while(opcionPedidos!="3"){
                cout << "---- MENÚ PEDIDOS ----" << endl;
                cout << "1. Ver Pedidos" << endl
                << "2. Confirmar Pedido." << endl
                << "3. Salir" << endl    
                << "Ingresar una opcion: ";
                getline(cin,opcionPedidos);
                cout << "---------------------------------" << endl;
                if(opcionPedidos == "1"){
                    arbolPedidos->imprimir();
                }else if(opcionPedidos == "2"){
                    do{
                        cout << "Ingresar ID de pedido: ";
                        getline(cin,id);
                    }while(esint(id));
                    if(arbolPedidos->confirmar(stoi(id))){
                        cout << "Pedido confirmado con exito." << endl;
                    }else{
                        cout << "El pedido no existe." << endl;
                    }
                }
            }
        }
    }
}

void inventario(){
    string opcion;
    while(opcion!="3"){
        cout << "---------------------------------" << endl;
        cout << "---- MENÚ INVENTARIO ----" << endl;
        cout << "1. Agregar Producto" << endl
        << "2. Ver Productos" << endl
        << "3. Salir" << endl
        << "Ingresar una opcion: ";
        getline(cin,opcion);
        cout << "---------------------------------" << endl;
        if(opcion == "1"){
            thread t3(agregarProducto);
            t3.join();
        } else if(opcion == "2"){
            arbolInvetario->imprimir();
        }
    }
}

int main(){
    string opcion="g", opcionEmpleados="g", opcionClientes="g", id, saldo;

    arbolEmpleados->leerEnArchivoBinario();
    arbolClientes->leerEnArchivoBinario();
    arbolInvetario->leerEnArchivoBinario();
    arbolPedidos->leerEnArchivoBinario();
    arbolVentas->leerEnArchivoBinario();

    while(opcion != "4"){
        cout << "---------------------------------" << endl;
        cout << "---- MENÚ PRINCIPAL ----" << endl;
        cout << "1. Gestion de Empleados" << endl
        << "2. Gestion de Clientes" << endl
        << "3. Limpiar pantalla" << endl
        << "4. Salir" << endl;
        cout << "Ingresar una opcion: ";
        getline(cin,opcion);
        cout << "---------------------------------" << endl;
        if(opcion == "1"){
            cout << "---- MENÚ EMPLEADOS ----" << endl;
            cout << "1. Agregar empleado" << endl
            << "2. Ingresar ID de empleado" << endl
            << "3. Cambiar estado de empleado" << endl
            << "4. Ver empleados" << endl;
            cout << "Ingresar una opcion: ";
            getline(cin,opcionEmpleados);
            cout << "---------------------------------" << endl;
            if(opcionEmpleados == "1"){
                idEmpleados=leerArchivoID(0);
                idEmpleados++;
                guardarIDs(idEmpleados,idClientes,idPedidos,idVentas,idInventario);
                thread t1(agregarEmpleados);
                t1.join();
            } else if(opcionEmpleados == "2"){
                do{
                    cout << "Ingresar ID: ";
                    getline(cin,id);
                }while(!esint(id));
                datosEmpleados datos=arbolEmpleados->buscar(stoi(id));
                if(datos.nombre.empty()&&!datos.estado){
                    cout << "Ingreso un ID incorrecto o el empleado no esta disponible.";
                }else{
                    if(datos.departamento=="Administracion"){
                        administracion(datos.puesto);
                    } else if (datos.departamento=="Personal Laboral") {
                        inventario();
                    }
                }
            } else if(opcionEmpleados == "3"){
                do{
                    cout << "Ingresar ID: ";
                    getline(cin,id);
                }while(!esint(id));
                arbolEmpleados->cambiar(stoi(id));
            }else if(opcionEmpleados == "4"){
                arbolEmpleados->imprimir();
            } else {
                cout << "Opción Incorrecta" << endl;
            }

        } else if(opcion == "2"){
            cout << "---- MENÚ CLIENTES ----" << endl;
            cout << "1. Agregar cliente" << endl
            << "2. Hacer un pedido como cliente" << endl
            << "3. Añadir saldo a cliente."<<endl
            << "4. Ver clientes."<<endl
            << "Ingresar una opcion: ";
            getline(cin,opcionClientes);
            cout << "---------------------------------" << endl;
            if(opcionClientes == "1"){
                idClientes=leerArchivoID(1);
                idClientes++;
                guardarIDs(idEmpleados,idClientes,idPedidos,idVentas,idInventario);
                thread t2(agregarCliente);
                t2.join();
            } else if (opcionClientes == "2" && arbolInvetario->root){
                do{
                    cout << "Ingresar ID: ";
                    getline(cin,id);
                }while(!esint(id));
                datosClientes* datos=arbolClientes->buscar(stoi(id));
                if(datos==nullptr){
                    cout << "Ingreso un ID incorrecto";
                }else{
                    thread t4(agregarPedido,datos->nombre,datos->id,datos->saldo);
                    t4.join();
                }
            } else if (opcionClientes == "3"){
                do{
                    cout << "Ingresar ID: ";
                    getline(cin,id);
                }while(!esint(id));
                datosClientes* datos=arbolClientes->buscar(stoi(id));
                if(datos==nullptr){
                    cout << "Ingreso un ID incorrecto";
                }else{
                    do{
                        cout << "Ingresar saldo: ";
                        getline(cin,saldo);
                    }while(!esdouble(saldo));
                    datos->saldo=stod(saldo);
                }
            } else if (opcionClientes == "4"){
                arbolClientes->imprimir();
            } else {
                cout << "Opción Incorrecta" << endl;
            }

        } else if(opcion == "3"){
            system("clear");
        } else if(opcion == "4"){
            cout << "Saliendo del sistema..." << endl;
        } else {
            cout << "Opción Incorrecta." << endl;
        }

        cout << endl;
    }

    arbolEmpleados->guardarEnArchivoBinario();
    arbolClientes->guardarEnArchivoBinario();
    arbolVentas->guardarEnArchivoBinario();
    arbolPedidos->guardarEnArchivoBinario();
    arbolInvetario->guardarEnArchivoBinario();

    return 0;
}