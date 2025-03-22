#include "arbolEmpleados.h"

ArbolEmpleados::ArbolEmpleados(int num){
    this->num=num;
    root=new Empleados(num);
}

datosEmpleados ArbolEmpleados::buscar(int clave){
    return search(clave,*root);
}

datosEmpleados ArbolEmpleados::search(int clave,Empleados nodo){
    datosEmpleados datos=nodo.buscar(clave);
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

bool ArbolEmpleados::cambiar(int clave){
    return cambiarEstado(clave,*root);
}

bool ArbolEmpleados::cambiarEstado(int clave,Empleados nodo){
    if(nodo.cambiar(clave)){
        return true;
    }

    if(!nodo.hoja){
        for(int i=0;i<=nodo.numeroClaves;i++){
            if(nodo.hijos[i]!=nullptr){
                cambiarEstado(clave,*nodo.hijos[i]);
            }
        }
    }

    return false;
}

void ArbolEmpleados::insertar(int clave, string nombre, string departamento, string puesto, double salario, bool estado){
    dato.id=clave;
    dato.nombre=nombre;
    dato.departamento=departamento;
    dato.puesto=puesto;
    dato.salario=salario;
    dato.estado=estado;
    if(root->numeroClaves==(2*num)-1){
        Empleados *nuevaRoot=new Empleados(num);
        nuevaRoot->hoja=false;
        nuevaRoot->numeroClaves=0;
        nuevaRoot->hijos[0]=root;
        split(nuevaRoot,0,root);
        root=nuevaRoot;
    }
    nonfullInsert(root,clave);
}

void ArbolEmpleados::split(Empleados *nodo1, int indice, Empleados *nodo2){
    Empleados *temp=new Empleados(num);
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

void ArbolEmpleados::nonfullInsert(Empleados *nodo,int clave){
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

void ArbolEmpleados::print(Empleados nodo){
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

void ArbolEmpleados::imprimir(){
    print(*root);
}

void ArbolEmpleados::save(ofstream &archivo, Empleados *nodo){
    archivo.write(reinterpret_cast<const char*>(&nodo->numeroClaves),sizeof(nodo->numeroClaves));

    for(int i=0;i<nodo->numeroClaves;i++){
        archivo.write(reinterpret_cast<const char*>(&nodo->claves[i].id),sizeof(nodo->claves[i].id));

        size_t nombreSize=nodo->claves[i].nombre.size();
        archivo.write(reinterpret_cast<const char*>(&nombreSize),sizeof(nombreSize));
        archivo.write(nodo->claves[i].nombre.c_str(),nombreSize);

        size_t departamentoSize=nodo->claves[i].departamento.size();
        archivo.write(reinterpret_cast<const char*>(&departamentoSize),sizeof(departamentoSize));
        archivo.write(nodo->claves[i].departamento.c_str(),departamentoSize);

        size_t puestoSize=nodo->claves[i].puesto.size();
        archivo.write(reinterpret_cast<const char*>(&puestoSize),sizeof(puestoSize));
        archivo.write(nodo->claves[i].puesto.c_str(),puestoSize);

        archivo.write(reinterpret_cast<const char*>(&nodo->claves[i].salario),sizeof(nodo->claves[i].salario));
        archivo.write(reinterpret_cast<const char*>(&nodo->claves[i].estado),sizeof(nodo->claves[i].estado));
    }

    archivo.write(reinterpret_cast<const char*>(&nodo->hoja),sizeof(nodo->hoja));

    if(!nodo->hoja){
        for(int i=0;i<=nodo->numeroClaves;i++){
            save(archivo,nodo->hijos[i]);
        }
    }
}


void ArbolEmpleados::guardarEnArchivoBinario(){
    ofstream archivo("archivos/arbolEmpleados.dat",ios::binary);
    if(!archivo){
        cout<<"Error"<<endl;
        return;
    }
    archivo.write(reinterpret_cast<const char*>(&num),sizeof(num));
    save(archivo,root);
    archivo.close();
}

Empleados* ArbolEmpleados::read(ifstream &archivo){
    Empleados* nodo=new Empleados(num);

    archivo.read(reinterpret_cast<char*>(&nodo->numeroClaves), sizeof(nodo->numeroClaves));

    for(int i=0;i<nodo->numeroClaves;i++) {
        archivo.read(reinterpret_cast<char*>(&nodo->claves[i].id), sizeof(nodo->claves[i].id));

        size_t nombreSize;
        archivo.read(reinterpret_cast<char*>(&nombreSize), sizeof(nombreSize));
        nodo->claves[i].nombre.resize(nombreSize);
        archivo.read(&nodo->claves[i].nombre[0], nombreSize);

        size_t departamentoSize;
        archivo.read(reinterpret_cast<char*>(&departamentoSize), sizeof(departamentoSize));
        nodo->claves[i].departamento.resize(departamentoSize);
        archivo.read(&nodo->claves[i].departamento[0], departamentoSize);

        size_t puestoSize;
        archivo.read(reinterpret_cast<char*>(&puestoSize), sizeof(puestoSize));
        nodo->claves[i].puesto.resize(puestoSize);
        archivo.read(&nodo->claves[i].puesto[0], puestoSize);

        archivo.read(reinterpret_cast<char*>(&nodo->claves[i].salario), sizeof(nodo->claves[i].salario));
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

void ArbolEmpleados::leerEnArchivoBinario(){
    ifstream archivo("archivos/arbolEmpleados.dat",ios::binary);
    if(!archivo){
        cout<<"Error"<<endl;
        return;
    }
    archivo.read(reinterpret_cast<char*>(&num),sizeof(num));
    root=read(archivo);
    archivo.close();
}

