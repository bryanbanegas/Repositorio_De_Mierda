#include "arbolInventario.h"

ArbolInventario::ArbolInventario(int num){
    this->num=num;
    root=new Inventario(num);
}

datosInventario ArbolInventario::buscar(int clave){
    return search(clave,*root);
}

datosInventario ArbolInventario::search(int clave,Inventario nodo){
    datosInventario datos=nodo.buscar(clave);
    if(!datos.nombre.empty()){
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

void ArbolInventario::insertar(int clave, string nombre, string categoria,int cantidad, double precio, bool estado){
    dato.id=clave;
    dato.nombre=nombre;
    dato.categoria=categoria;
    dato.cantidad=cantidad;
    dato.precio=precio;
    dato.estado=estado;
    if(root->numeroClaves==(2*num)-1){
        Inventario *nuevaRoot=new Inventario(num);
        nuevaRoot->hoja=false;
        nuevaRoot->numeroClaves=0;
        nuevaRoot->hijos[0]=root;
        split(nuevaRoot,0,root);
        root=nuevaRoot;
    }
    nonfullInsert(root,clave);
}

void ArbolInventario::split(Inventario *nodo1, int indice, Inventario *nodo2){
    Inventario *temp=new Inventario(num);
    temp->hoja=nodo2->hoja;
    temp->numeroClaves=num-1;

    for(int i=0;i<num-1;i++){
        temp->claves[i]=nodo2->claves[i+num];
    }

    if(!nodo2->hoja){
        for(int i=0;i<num;i++){
            temp->hijos[i]=nodo2->hijos[i+num];
        }
    }
    nodo2->numeroClaves=num-1;
    
    for(int i=nodo1->numeroClaves;i>indice;i--){
        nodo1->hijos[i+1]=nodo1->hijos[i];
    }
    nodo1->hijos[indice+1]=temp;
    
    for(int i=nodo1->numeroClaves-1;i>=indice;i--){
        nodo1->claves[i+1]=nodo1->claves[i];
    }
    nodo1->claves[indice]=nodo2->claves[num-1];
    nodo1->numeroClaves++;
}

void ArbolInventario::nonfullInsert(Inventario *nodo,int clave){
    if(nodo->hoja){
        int i=nodo->numeroClaves-1;
        while(i>=0&&clave<nodo->claves[i].id){
            nodo->claves[i+1]=nodo->claves[i];
            i--;
        }
        nodo->claves[i+1]=dato;
        nodo->numeroClaves++;
    }else{
        int pos=nodo->numeroClaves-1;
        while(pos>=0&&clave<nodo->claves[pos].id){
            pos--;
        }
        pos++;
        if(nodo->hijos[pos]->numeroClaves==(2*num)-1){
            split(nodo,pos,nodo->hijos[pos]);
            if(clave>nodo->claves[pos].id){
                pos++;
            }
        }
        nonfullInsert(nodo->hijos[pos],clave);
    }
}

void ArbolInventario::print(Inventario nodo){
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

void ArbolInventario::imprimir(){
    print(*root);
}

void ArbolInventario::save(ofstream &archivo, Inventario *nodo) {
    archivo.write(reinterpret_cast<const char*>(&nodo->numeroClaves),sizeof(nodo->numeroClaves));

    for(int i=0;i<nodo->numeroClaves;i++){
        archivo.write(reinterpret_cast<const char*>(&nodo->claves[i].id),sizeof(nodo->claves[i].id));

        size_t nombreSize=nodo->claves[i].nombre.size();
        archivo.write(reinterpret_cast<const char*>(&nombreSize),sizeof(nombreSize));
        archivo.write(nodo->claves[i].nombre.c_str(),nombreSize);

        size_t categoriaSize=nodo->claves[i].categoria.size();
        archivo.write(reinterpret_cast<const char*>(&categoriaSize),sizeof(categoriaSize));
        archivo.write(nodo->claves[i].categoria.c_str(),categoriaSize);

        archivo.write(reinterpret_cast<const char*>(&nodo->claves[i].cantidad),sizeof(nodo->claves[i].cantidad));
        archivo.write(reinterpret_cast<const char*>(&nodo->claves[i].precio),sizeof(nodo->claves[i].precio));
        archivo.write(reinterpret_cast<const char*>(&nodo->claves[i].estado),sizeof(nodo->claves[i].estado));
    }

    archivo.write(reinterpret_cast<const char*>(&nodo->hoja),sizeof(nodo->hoja));

    if(!nodo->hoja){
        for(int i=0;i<=nodo->numeroClaves;i++){
            save(archivo,nodo->hijos[i]);
        }
    }
}

void ArbolInventario::guardarEnArchivoBinario(){
    ofstream archivo("archivos/arbolInventario.dat",ios::binary);
    if(!archivo){
        cout<<"Error"<<endl;
        return;
    }
    archivo.write(reinterpret_cast<const char*>(&num),sizeof(num));
    save(archivo,root);
    archivo.close();
}

Inventario* ArbolInventario::read(ifstream &archivo) {
    Inventario* nodo = new Inventario(num);

    archivo.read(reinterpret_cast<char*>(&nodo->numeroClaves), sizeof(nodo->numeroClaves));

    for(int i=0;i<nodo->numeroClaves;i++) {
        archivo.read(reinterpret_cast<char*>(&nodo->claves[i].id), sizeof(nodo->claves[i].id));

        size_t nombreSize;
        archivo.read(reinterpret_cast<char*>(&nombreSize), sizeof(nombreSize));
        nodo->claves[i].nombre.resize(nombreSize);
        archivo.read(&nodo->claves[i].nombre[0], nombreSize);

        size_t categoriaSize;
        archivo.read(reinterpret_cast<char*>(&categoriaSize), sizeof(categoriaSize));
        nodo->claves[i].categoria.resize(categoriaSize);
        archivo.read(&nodo->claves[i].categoria[0], categoriaSize);

        archivo.read(reinterpret_cast<char*>(&nodo->claves[i].cantidad), sizeof(nodo->claves[i].cantidad));
        archivo.read(reinterpret_cast<char*>(&nodo->claves[i].precio), sizeof(nodo->claves[i].precio));
        archivo.read(reinterpret_cast<char*>(&nodo->claves[i].estado), sizeof(nodo->claves[i].estado));
    }

    archivo.read(reinterpret_cast<char*>(&nodo->hoja),sizeof(nodo->hoja));
    
    if(!nodo->hoja){
        for(int i=0;i<=nodo->numeroClaves;i++){
            nodo->hijos[i]=read(archivo);
        }
    }

    return nodo;
}

void ArbolInventario::leerEnArchivoBinario(){
    ifstream archivo("archivos/arbolInventario.dat",ios::binary);
    if(!archivo){
        cout<<"Error"<<endl;
        return;
    }
    archivo.read(reinterpret_cast<char*>(&num),sizeof(num));
    root=read(archivo);
    archivo.close();
}