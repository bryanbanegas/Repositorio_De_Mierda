#include "arbolClientes.h"

ArbolClientes::ArbolClientes(int num){
    this->num=num;
    root=new Clientes(num);
}

datosClientes* ArbolClientes::buscar(int clave){
    return search(clave,*root);
}

datosClientes* ArbolClientes::search(int clave,Clientes nodo){
    datosClientes* datos=nodo.buscar(clave);
    if(!datos->nombre.empty()){
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

void ArbolClientes::insertar(int clave, string nombre, string correo, string telefono, double saldo){
    dato.id=clave;
    dato.nombre=nombre;
    dato.correo=correo;
    dato.telefono=telefono;
    dato.saldo=saldo;
    if(root->numeroClaves==(2*num)-1){
        Clientes *nuevaRoot=new Clientes(num);
        nuevaRoot->hoja=false;
        nuevaRoot->numeroClaves=0;
        nuevaRoot->hijos[0]=root;
        split(nuevaRoot,0,root);
        root=nuevaRoot;
    }
    nonfullInsert(root,clave);
}

void ArbolClientes::split(Clientes *nodo1, int indice, Clientes *nodo2){
    Clientes *temp=new Clientes(num);
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

void ArbolClientes::nonfullInsert(Clientes *nodo,int clave){
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

void ArbolClientes::print(Clientes nodo){
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

void ArbolClientes::imprimir(){
    print(*root);
}

void ArbolClientes::save(ofstream &archivo,Clientes *nodo){
    archivo.write(reinterpret_cast<const char*>(&nodo->numeroClaves),sizeof(nodo->numeroClaves));

    for(int i=0;i<nodo->numeroClaves;i++){
        archivo.write(reinterpret_cast<const char*>(&nodo->claves[i].id),sizeof(nodo->claves[i].id));
        
        size_t nombreSize=nodo->claves[i].nombre.size();
        archivo.write(reinterpret_cast<const char*>(&nombreSize),sizeof(nombreSize));
        archivo.write(nodo->claves[i].nombre.c_str(),nombreSize);
        
        size_t telefonoSize=nodo->claves[i].telefono.size();
        archivo.write(reinterpret_cast<const char*>(&telefonoSize),sizeof(telefonoSize));
        archivo.write(nodo->claves[i].telefono.c_str(),telefonoSize);
        
        size_t correoSize=nodo->claves[i].correo.size();
        archivo.write(reinterpret_cast<const char*>(&correoSize),sizeof(correoSize));
        archivo.write(nodo->claves[i].correo.c_str(),correoSize);
        
        archivo.write(reinterpret_cast<const char*>(&nodo->claves[i].saldo),sizeof(nodo->claves[i].saldo));
        
        int historialSize=nodo->claves[i].historialCompras.size();
        archivo.write(reinterpret_cast<const char*>(&historialSize),sizeof(historialSize));
        for(int i=0;i<nodo->claves[i].historialCompras.size();i++){
            size_t compraSize=nodo->claves[i].historialCompras.at(i).size();
            archivo.write(reinterpret_cast<const char*>(&compraSize),sizeof(compraSize));
            archivo.write(nodo->claves[i].historialCompras.at(i).c_str(),compraSize);
        }
    }

    archivo.write(reinterpret_cast<const char*>(&nodo->hoja),sizeof(nodo->hoja));

    if(!nodo->hoja){
        for(int i=0;i<=nodo->numeroClaves;i++){
            if(nodo->hijos[i]!=nullptr){
                save(archivo,nodo->hijos[i]);
            }
        }
    }
}

void ArbolClientes::guardarEnArchivoBinario(){
    ofstream archivo("archivos/arbolClientes.dat",ios::binary);
    if(!archivo){
        cout<<"Error"<<endl;
        return;
    }
    archivo.write(reinterpret_cast<const char*>(&num),sizeof(num));
    save(archivo,root);
    archivo.close();
}

Clientes* ArbolClientes::read(ifstream &archivo){
    Clientes* nodo=new Clientes(num);
    string compra;
    int historialSize;

    archivo.read(reinterpret_cast<char*>(&nodo->numeroClaves),sizeof(nodo->numeroClaves));

    for(int i=0;i<nodo->numeroClaves;i++){
        archivo.read(reinterpret_cast<char*>(&nodo->claves[i].id),sizeof(nodo->claves[i].id));
        
        size_t nombreSize;
        archivo.read(reinterpret_cast<char*>(&nombreSize),sizeof(nombreSize));
        nodo->claves[i].nombre.resize(nombreSize);
        archivo.read(&nodo->claves[i].nombre[0],nombreSize);

        size_t telefonoSize;
        archivo.read(reinterpret_cast<char*>(&telefonoSize),sizeof(telefonoSize));
        nodo->claves[i].telefono.resize(telefonoSize);
        archivo.read(&nodo->claves[i].telefono[0],telefonoSize);

        size_t correoSize;
        archivo.read(reinterpret_cast<char*>(&correoSize),sizeof(correoSize));
        nodo->claves[i].correo.resize(correoSize);
        archivo.read(&nodo->claves[i].correo[0],correoSize);

        archivo.read(reinterpret_cast<char*>(&dato.saldo),sizeof(dato.saldo));

        archivo.read(reinterpret_cast<char*>(&historialSize),sizeof(historialSize));
        for(int i=0;i<historialSize;i++){
            size_t compraSize;
            archivo.read(reinterpret_cast<char*>(&compraSize),sizeof(compraSize));
            compra.resize(compraSize);
            archivo.read(&compra[0],compraSize);
            dato.historialCompras.push_back(compra);
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

void ArbolClientes::leerEnArchivoBinario(){
    ifstream archivo("archivos/arbolClientes.dat",ios::binary);
    if(!archivo){
        cout<<"Error"<<endl;
        return;
    }
    archivo.read(reinterpret_cast<char*>(&num),sizeof(num));
    root=read(archivo);
    archivo.close();
}