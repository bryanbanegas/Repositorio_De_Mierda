#include <iostream>
#include <string>
#include <fstream>
#include "/home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolEmpleados.h"
#include "/home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolClientes.h"
#include "/home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolVentas.h"
#include "/home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolInventario.h"
#include "/home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolPedidos.h"
#include "/home/bryan/Documents/VSCode/Gestion_Empresarial/archivos/funciones.h"
using namespace std;

ArbolEmpleados *arbolEmpleados=new ArbolEmpleados(3);
ArbolClientes *arbolClientes=new ArbolClientes(3);
ArbolVentas *arbolVentas=new ArbolVentas(3);
ArbolInventario *arbolInvetario=new ArbolInventario(3);
ArbolPedidos *arbolPedidos=new ArbolPedidos(3);
int idEmpleados=0,idClientes=0,idPedidos=0,idVentas=0,idInventario=0,cantidadInventario=0;

void agregarEmpleados(){
    string nombre, departamento, puesto, opcion="d"; 
    double salario;
    cout << "---------------------------------" << endl;
    //hay que ver que tipo de restriccion pondremos para el id o si la funcion ya tendra las validaciones
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
    cout << "Ingresar salario: ";
    cin >> salario;
    cin.ignore();
    arbolEmpleados->insertar(idEmpleados,nombre,departamento,puesto,salario,true);
    cout << "---------------------------------" << endl;
    cout << "¡Empleado agregado con éxito!" << endl;
    cout << "ID: " << idEmpleados << endl;
    cout << "---------------------------------" << endl;
}

void agregarCliente(){
    string nombre, correo, telefono, opcion="d"; 
    double saldo;
    cout << "---------------------------------" << endl;
    cout << "Ingresar nombre del cliente: ";
    getline(cin,nombre);
    cout << "Ingresar correo del cliente: ";
    getline(cin,correo);
    cout << "Ingresar telefono del cliente: ";
    getline(cin,telefono);
    cout << "Ingresar saldo del cliente: ";
    cin>>saldo;
    cin.ignore();
    arbolClientes->insertar(idClientes,nombre,correo,telefono,saldo);
    cout << "---------------------------------" << endl;
    cout << "¡Cliente agregado con éxito!" << endl;
    cout << "---------------------------------" << endl;
}

void administracion(string puesto){
    string opcion="er",opcionVentas,opcionPedidos;
    while(opcion!="3"){
        cout << "---------------------------------" << endl;
        cout << "---- MENÚ ADMINISTRACION ----" << endl;
        cout << "1. Gestion de Ventas" << endl
        << "2. Gestion de Pedidos" << endl
        << "3. Salir" << endl
        << "Ingresar una opcion: ";
        cin >> opcion;
        cin.ignore();
        cout << "---------------------------------" << endl;
        if(opcion == "1" && puesto=="Ventas"){
            opcionVentas="h";
            while(opcionVentas!="2"){
                cout << "---- MENÚ VENTAS ----" << endl;
                cout << "1. Ver Ventas" << endl
                << "2. Salir" << endl    
                << "Ingresar una opcion: ";
                cin >> opcionVentas;
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
                cin >> opcionPedidos;
                cout << "---------------------------------" << endl;
                if(opcionPedidos == "1"){
                    arbolPedidos->imprimir();
                }else if(opcionPedidos == "2"){
                    int id;
                    cout << "Ingresar id de pedido: ";
                    cin >> id;
                    if(arbolPedidos->confirmar(id)){
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
    string opcion,opcionCategoria,nombre,categoria;
    int cantidad;
    double precio;
    bool estado;
    while(opcion!="3"){
        cout << "---------------------------------" << endl;
        cout << "---- MENÚ INVENTARIO ----" << endl;
        cout << "1. Agregar Producto" << endl
        << "2. Ver Productos" << endl
        << "3. Salir" << endl
        << "Ingresar una opcion: ";
        cin >> opcion;
        cout << "---------------------------------" << endl;
        if(opcion == "1"){
            cout<<"Ingresar nombre de producto:";
            cin>>nombre;
            opcionCategoria="j";
            while(opcionCategoria != "1" && opcionCategoria != "2"){
                cout << "Seleccionar Categoria:" << endl
                << "1. Comestible" << endl
                << "2. No Comestible" << endl
                << "Ingresar departamento: ";
                cin >> opcionCategoria;
                if(opcionCategoria == "1"){
                    categoria = "Comestible";
                } else {
                    categoria = "No Comestible";
                }    
            }
            cout<<"Ingresar cantidad de producto:";
            cin>>cantidad;
            cout<<"Ingresar precio de producto:";
            cin>>precio;
            idInventario=leerArchivoID(4);
            idInventario++;
            guardarIDs(idEmpleados,idClientes,idPedidos,idVentas,idInventario);
            arbolInvetario->insertar(idInventario,nombre,categoria,cantidad,precio,true);
            cout << "---------------------------------" << endl;
            cout << "¡Producto agregado con éxito!" << endl;
            cout << "ID de pedido: " << idInventario << endl;
            cout << "---------------------------------" << endl;
            cout<<endl;
        } else if(opcion == "2"){
            arbolInvetario->imprimir();
        }
    }
}

void agregarPedido(string cliente,int idCliente){
    idPedidos=leerArchivoID(2);
    idPedidos++;
    guardarIDs(idEmpleados,idClientes,idPedidos,idVentas,idInventario);
    string cantidad,fecha,id="";
    int cantidadProductos=0;
    double total=0;
    cout << "---------------------------------" << endl;
    fecha="3/25/2025";
    arbolPedidos->insertar(idPedidos,cliente,fecha,false);
    datosPedidos datos1;
    arbolInvetario->imprimir();
    while(id!="0"){
        cout << "Para salir ingrese 0: "<<endl;
        cout << "Ingresar ID de producto: ";
        getline(cin,id);
        if(id!="0"){
            cout << "Ingresar cantidad que quiere de producto: ";
            getline(cin,cantidad);
            datosInventario datos2=arbolInvetario->buscar(stoi(id));
            if(datos2.nombre.empty()){
                cout<<"Este producto no existe."<<endl;
            }else{
                if(stoi(cantidad)<=datos2.cantidad&&stoi(cantidad)>1){
                    cantidadProductos+=stoi(cantidad);
                    for(int i=0;i<stoi(cantidad);i++){
                        datos1.productosSolicitados.push_back(datos2.nombre);
                        total+=stoi(cantidad)*datos2.precio;
                    }
                }else{
                    cout<<"La cantidad ingresada excede la cantidad del producto o es menor que 1."<<endl;
                }
            }
        }
    }
    arbolPedidos->buscar(idPedidos).productosSolicitados=datos1.productosSolicitados;
    cout << "---------------------------------" << endl;
    cout << "¡Pedido hecho con éxito!" << endl;
    cout << "Total de pedido: " << total << endl;
    cout << "ID de pedido: " << idPedidos << endl;
    cout << "---------------------------------" << endl;
    idVentas=leerArchivoID(3);
    idVentas++;
    guardarIDs(idEmpleados,idClientes,idPedidos,idVentas,idInventario);
    arbolVentas->insertar(idVentas,idCliente,fecha,cantidadProductos,total);
}

int main(){
    string opcion="g", opcionEmpleados="g", opcionClientes="g", id;

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
            << "3. Desactivar empleado" << endl;
            cout << "Ingresar una opcion: ";
            getline(cin,opcionEmpleados);
            cout << "---------------------------------" << endl;
            if(opcionEmpleados == "1"){
                idEmpleados=leerArchivoID(0);
                idEmpleados++;
                guardarIDs(idEmpleados,idClientes,idPedidos,idVentas,idInventario);
                agregarEmpleados();
            } else if(opcionEmpleados == "2"){
                cout << "Ingresar ID: ";
                getline(cin,id);
                datosEmpleados datos=arbolEmpleados->buscar(stoi(id));
                if(datos.nombre.empty()){
                    cout << "Ingreso un ID incorrecto";
                }else{
                    if(datos.departamento=="Administracion"){
                        administracion(datos.puesto);
                    } else if (datos.departamento=="Personal Laboral") {
                        inventario();
                    }
                }
            } else if(opcionEmpleados == "3"){

            }else{
                cout << "Opción Incorrecta" << endl;
            }

        } else if(opcion == "2"){
            cout << "---- MENÚ CLIENTES ----" << endl;
            cout << "1. Agregar cliente" << endl
                 << "2. Hacer un pedido como cliente" << endl;
            cout << "Ingresar una opcion: ";
            getline(cin,opcionClientes);
            cout << "---------------------------------" << endl;
            if(opcionClientes == "1"){
                idClientes=leerArchivoID(1);
                idClientes++;
                guardarIDs(idEmpleados,idClientes,idPedidos,idVentas,idInventario);
                agregarCliente();
            } else if(opcionClientes == "2" && cantidadInventario>0){
                cout << "Ingresar ID: ";
                getline(cin,id);
                datosClientes datos=arbolClientes->buscar(stoi(id));
                if(datos.nombre.empty()){
                    cout << "Ingreso un ID incorrecto";
                }else{
                    agregarPedido(datos.nombre,datos.id);
                }
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