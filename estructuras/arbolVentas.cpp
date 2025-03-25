#include "arbolVentas.h"

ArbolVentas::ArbolVentas(int num){
    this->num=num;
    root=new Ventas(num);
}

datosVentas* ArbolVentas::buscar(int clave){
    return search(clave,*root);
}

datosVentas* ArbolVentas::search(int clave,Ventas nodo){
    datosVentas* datos=nodo.buscar(clave);
    if(datos!=nullptr){
        return datos;
    }

    if(!nodo.hoja){
        for(int i=0;i<=nodo.numeroClaves;i++){
            if(nodo.hijos[i]!=nullptr){
                search(clave,*nodo.hijos[i]);
            }
        }
    }
    return nullptr;
}

void ArbolVentas::insertar(int clave, int idcliente, string fecha, int cantidad, double total){
    dato.idVenta=clave;
    dato.idCliente=idcliente;
    dato.fecha=fecha;
    dato.cantidad=cantidad;
    dato.total=total;
    if(root->numeroClaves==((2*num)-1)){
        Ventas *nuevaRoot=new Ventas(num);
        root=nuevaRoot;
        nuevaRoot->hoja=false;
        nuevaRoot->numeroClaves=0;
        nuevaRoot->hijos[0]=root;
        split(nuevaRoot,0,root);
        nonfullInsert(nuevaRoot,clave);
    }else{
        nonfullInsert(root,clave);
    }
}

void ArbolVentas::split(Ventas *nodo1, int a, Ventas *nodo2){
    Ventas *temp=new Ventas(num);
    temp->hoja=nodo2->hoja;
    temp->numeroClaves=num-1;
    for(int i=0;i<(num-1);i++){
        temp->claves[i]=nodo2->claves[i+num];
    }
    if(!nodo2->hoja){
        for(int i=0;i<num;i++){
            temp->hijos[i]=nodo2->hijos[i+num];
        }
    }
    nodo2->numeroClaves=num-1;
    for(int i=nodo1->numeroClaves;i>a;i--){
        nodo1->hijos[i+1]=nodo1->hijos[i];
    }
    nodo1->hijos[a+1]=temp;
    for(int i=nodo1->numeroClaves;i>a;i--){
        nodo1->claves[i+1]=nodo1->claves[i];
    }
    nodo1->claves[a]=nodo2->claves[num-1];
    nodo1->numeroClaves++;
}

void ArbolVentas::nonfullInsert(Ventas *nodo,int clave){
    if(nodo->hoja){
        int i=nodo->numeroClaves;
        while(i>=1&&clave<nodo->claves[i-1].idVenta){
            nodo->claves[i]=nodo->claves[i-1];
            i--;
        }
        nodo->claves[i].idVenta=dato.idVenta;
        nodo->claves[i].idCliente=dato.idCliente;
        nodo->claves[i].fecha=dato.fecha;
        nodo->claves[i].cantidad=dato.cantidad;
        nodo->claves[i].total=dato.total;
        nodo->numeroClaves++;
    }else{
        int i=0;
        while(i<nodo->numeroClaves&&clave>nodo->claves[i].idVenta){
            i++;
        }
        if(nodo->hijos[i]->numeroClaves==((2*num)-1)){
            
            if(clave>nodo->claves[i].idVenta){
                i++;
            }
        }
        nonfullInsert(nodo->hijos[i],clave);
    }
}

void ArbolVentas::print(Ventas nodo){
    nodo.imprimir();

    if(!nodo.hoja){
        for(int i=0;i<=nodo.numeroClaves;i++){
            if(nodo.hijos[i]!=nullptr){
                cout<<endl;
                print(*nodo.hijos[i]);
            }
        }
    }
}

void ArbolVentas::imprimir(){
    print(*root);
}

void ArbolVentas::save(ofstream &archivo, Ventas *nodo){
    archivo.write(reinterpret_cast<const char*>(&nodo->numeroClaves),sizeof(nodo->numeroClaves));

    for(int i=0;i<nodo->numeroClaves;i++){
        archivo.write(reinterpret_cast<const char*>(&nodo->claves[i].idVenta),sizeof(nodo->claves[i].idVenta));
        archivo.write(reinterpret_cast<const char*>(&nodo->claves[i].idCliente),sizeof(nodo->claves[i].idCliente));

        size_t fechaSize=nodo->claves[i].fecha.size();
        archivo.write(reinterpret_cast<const char*>(&fechaSize),sizeof(fechaSize));
        archivo.write(nodo->claves[i].fecha.c_str(),fechaSize);

        archivo.write(reinterpret_cast<const char*>(&nodo->claves[i].cantidad),sizeof(nodo->claves[i].cantidad));
        archivo.write(reinterpret_cast<const char*>(&nodo->claves[i].total),sizeof(nodo->claves[i].total));

        int productosSize=nodo->claves[i].productosVendidos.size();
        archivo.write(reinterpret_cast<const char*>(&productosSize),sizeof(productosSize));
        for(int i=0;i<nodo->claves[i].productosVendidos.size();i++){
            size_t productoSize=nodo->claves[i].productosVendidos.at(i).size();
            archivo.write(reinterpret_cast<const char*>(&productoSize),sizeof(productoSize));
            archivo.write(nodo->claves[i].productosVendidos.at(i).c_str(),productoSize);
        }
    }

    archivo.write(reinterpret_cast<const char*>(&nodo->hoja),sizeof(nodo->hoja));

    if(!nodo->hoja){
        for(int i=0;i<=nodo->numeroClaves;i++){
            save(archivo,nodo->hijos[i]);
        }
    }
}

void ArbolVentas::guardarEnArchivoBinario(){
    ofstream archivo("archivos/arbolVentas.dat",ios::binary);
    if(!archivo){
        cout<<"Error"<<endl;
        return;
    }
    archivo.write(reinterpret_cast<const char*>(&num),sizeof(num));
    save(archivo,root);
    archivo.close();
}

Ventas* ArbolVentas::read(ifstream &archivo){
    Ventas* nodo=new Ventas(num);
    string producto;
    int prodctosSize;
    
    archivo.read(reinterpret_cast<char*>(&nodo->numeroClaves), sizeof(nodo->numeroClaves));

    for(int i=0;i<nodo->numeroClaves;i++) {
        archivo.read(reinterpret_cast<char*>(&nodo->claves[i].idVenta),sizeof(nodo->claves[i].idVenta));
        archivo.read(reinterpret_cast<char*>(&nodo->claves[i].idCliente),sizeof(nodo->claves[i].idCliente));

        size_t fechaSize;
        archivo.read(reinterpret_cast<char*>(&fechaSize),sizeof(fechaSize));
        nodo->claves[i].fecha.resize(fechaSize);
        archivo.read(&nodo->claves[i].fecha[0],fechaSize);

        archivo.read(reinterpret_cast<char*>(&nodo->claves[i].cantidad),sizeof(nodo->claves[i].cantidad));
        archivo.read(reinterpret_cast<char*>(&nodo->claves[i].total),sizeof(nodo->claves[i].total));

        archivo.read(reinterpret_cast<char*>(&prodctosSize),sizeof(prodctosSize));
        for(int i=0;i<prodctosSize;i++){
            size_t productoSize;
            archivo.read(reinterpret_cast<char*>(&productoSize),sizeof(productoSize));
            producto.resize(productoSize);
            archivo.read(&producto[0],productoSize);
            nodo->claves[i].productosVendidos.push_back(producto);
        }
    }

    archivo.read(reinterpret_cast<char*>(&nodo->hoja),sizeof(nodo->hoja));
    
    if(!nodo->hoja){
        for(int i=0;i<=nodo->numeroClaves;i++){
            nodo->hijos[i]=read(archivo);
        }
    }

    return nodo;
}

void ArbolVentas::leerEnArchivoBinario(){
    ifstream archivo("archivos/arbolVentas.dat",ios::binary);
    if(!archivo){
        cout<<"Error"<<endl;
        return;
    }
    archivo.read(reinterpret_cast<char*>(&num),sizeof(num));
    root=read(archivo);
    archivo.close();
}

