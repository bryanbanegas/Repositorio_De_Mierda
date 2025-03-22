#include "arbolPedidos.h"

ArbolPedidos::ArbolPedidos(int num){
    this->num=num;
    root=new Pedidos(num);
}

bool ArbolPedidos::confirmar(int clave){
    return confirmarPedido(clave,*root);
}

bool ArbolPedidos::confirmarPedido(int clave,Pedidos nodo){
    if(nodo.confirmar(clave)){
        return true;
    }

    if(!nodo.hoja){
        for(int i=0;i<=nodo.numeroClaves;i++){
            if(nodo.hijos[i]!=nullptr){
                confirmarPedido(clave,*nodo.hijos[i]);
            }
        }
    }

    return false;
}

datosPedidos* ArbolPedidos::buscar(int clave){
    return search(clave,*root);
}

datosPedidos* ArbolPedidos::search(int clave,Pedidos nodo){
    datosPedidos *datos=nodo.buscar(clave);
    if(!datos->cliente.empty()){
        return datos;
    }

    if(!nodo.hoja){
        for(int i=0;i<=nodo.numeroClaves;i++){
            if(nodo.hijos[i]!=nullptr){
                search(clave,*nodo.hijos[i]);
            }
        }
    }
    return datos;
}

void ArbolPedidos::insertar(int clave, string cliente, string fecha, bool estado){
    dato.id=clave;
    dato.cliente=cliente;
    dato.fecha=fecha;
    dato.estado=estado;
    if(root->numeroClaves==((2*num)-1)){
        Pedidos *nuevaRoot=new Pedidos(num);
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

void ArbolPedidos::split(Pedidos *nodo1, int a, Pedidos *nodo2){
    Pedidos *temp=new Pedidos(num);
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

void ArbolPedidos::nonfullInsert(Pedidos *nodo,int clave){
    if(nodo->hoja){
        int i=nodo->numeroClaves;
        while(i>=1&&clave<nodo->claves[i-1].id){
            nodo->claves[i]=nodo->claves[i-1];
            i--;
        }
        nodo->claves[i].id=dato.id;
        nodo->claves[i].cliente=dato.cliente;
        nodo->claves[i].fecha=dato.fecha;
        nodo->claves[i].estado=dato.estado;
        nodo->numeroClaves++;
    }else{
        int i=0;
        while(i<nodo->numeroClaves&&clave>nodo->claves[i].id){
            i++;
        }
        if(nodo->hijos[i]->numeroClaves==((2*num)-1)){
            
            if(clave>nodo->claves[i].id){
                i++;
            }
        }
        nonfullInsert(nodo->hijos[i],clave);
    }
}

void ArbolPedidos::print(Pedidos nodo){
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

void ArbolPedidos::imprimir(){
    print(*root);
}

void ArbolPedidos::save(ofstream &archivo, Pedidos *nodo){
    archivo.write(reinterpret_cast<const char*>(&nodo->numeroClaves),sizeof(nodo->numeroClaves));
    
    for(int i=0;i<nodo->numeroClaves;i++){
        archivo.write(reinterpret_cast<const char*>(&nodo->claves[i].id),sizeof(nodo->claves[i].id));

        size_t clienteSize=nodo->claves[i].cliente.size();
        archivo.write(reinterpret_cast<const char*>(&clienteSize),sizeof(clienteSize));
        archivo.write(nodo->claves[i].cliente.c_str(),clienteSize);

        size_t fechaSize=nodo->claves[i].fecha.size();
        archivo.write(reinterpret_cast<const char*>(&fechaSize),sizeof(fechaSize));
        archivo.write(nodo->claves[i].fecha.c_str(),fechaSize);

        archivo.write(reinterpret_cast<const char*>(&nodo->claves[i].estado),sizeof(nodo->claves[i].estado));

        int productosSize=nodo->claves[i].productosSolicitados.size();
        archivo.write(reinterpret_cast<const char*>(&productosSize),sizeof(productosSize));
        for(int i=0;i<nodo->claves[i].productosSolicitados.size();i++){
            size_t productoSize=nodo->claves[i].productosSolicitados.at(i).size();
            archivo.write(reinterpret_cast<const char*>(&productoSize),sizeof(productoSize));
            archivo.write(nodo->claves[i].productosSolicitados.at(i).c_str(),productoSize);
        }
    }

    archivo.write(reinterpret_cast<const char*>(&nodo->hoja),sizeof(nodo->hoja));

    if(!nodo->hoja){
        for(int i=0;i<=nodo->numeroClaves;i++){
            save(archivo,nodo->hijos[i]);
        }
    }
}


void ArbolPedidos::guardarEnArchivoBinario(){
    ofstream archivo("archivos/arbolPedidos.dat",ios::binary);
    if(!archivo){
        cout<<"Error"<<endl;
        return;
    }
    archivo.write(reinterpret_cast<const char*>(&num),sizeof(num));
    save(archivo,root);
    archivo.close();
}

Pedidos* ArbolPedidos::read(ifstream &archivo){
    Pedidos* nodo=new Pedidos(num);
    string producto;
    int prodctosSize;

    archivo.read(reinterpret_cast<char*>(&nodo->numeroClaves), sizeof(nodo->numeroClaves));

    for(int i=0;i<nodo->numeroClaves;i++) {
        archivo.read(reinterpret_cast<char*>(&nodo->claves[i].id), sizeof(nodo->claves[i].id));

        size_t clienteSize;
        archivo.read(reinterpret_cast<char*>(&clienteSize), sizeof(clienteSize));
        nodo->claves[i].cliente.resize(clienteSize);
        archivo.read(&nodo->claves[i].cliente[0], clienteSize);

        size_t fechaSize;
        archivo.read(reinterpret_cast<char*>(&fechaSize), sizeof(fechaSize));
        nodo->claves[i].fecha.resize(fechaSize);
        archivo.read(&nodo->claves[i].fecha[0], fechaSize);

        archivo.read(reinterpret_cast<char*>(&nodo->claves[i].estado), sizeof(nodo->claves[i].estado));

        archivo.read(reinterpret_cast<char*>(&prodctosSize),sizeof(prodctosSize));
        for(int i=0;i<prodctosSize;i++){
            size_t productoSize;
            archivo.read(reinterpret_cast<char*>(&productoSize),sizeof(productoSize));
            producto.resize(productoSize);
            archivo.read(&producto[0],productoSize);
            nodo->claves[i].productosSolicitados.push_back(producto);
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

void ArbolPedidos::leerEnArchivoBinario(){
    ifstream archivo("archivos/arbolPedidos.dat",ios::binary);
    if(!archivo){
        cout<<"Error"<<endl;
        return;
    }
    archivo.read(reinterpret_cast<char*>(&num),sizeof(num));
    root=read(archivo);
    archivo.close();
}

