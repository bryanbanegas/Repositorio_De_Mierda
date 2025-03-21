#include "/home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolEmpleados.h"
#include "/home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbol.h"
#include "/home/bryan/Documents/VSCode/Gestion_Empresarial/archivos/funciones.h"

int main(){
    ArbolEmpleados *arbolEmpleados=new ArbolEmpleados(3);
    Arbol *arbol=new Arbol(3);
    string nombre="Bryan",departamento="NO se",puesto="Puesto";
    double salario=0.6;
    
    /*arbolEmpleados->insertar(0,nombre,departamento,puesto,salario,true);
    arbolEmpleados->insertar(1,nombre,departamento,puesto,salario,true);
    arbolEmpleados->insertar(2,"jwgewjhbd",departamento,puesto,salario,true);
    arbolEmpleados->insertar(3,"que",departamento,puesto,salario,true);
    arbolEmpleados->insertar(4,"no",departamento,puesto,salario,true);
    arbolEmpleados->insertar(5,nombre,departamento,puesto,salario,true);
    arbolEmpleados->insertar(6,nombre,departamento,puesto,salario,true);*/
    arbolEmpleados->leerEnArchivoBinario();
    arbolEmpleados->imprimir();

    /*arbol->insertar(0);
    arbol->insertar(1);
    arbol->insertar(2);
    arbol->insertar(3);
    arbol->insertar(4);
    arbol->insertar(5);
    arbol->insertar(6);
    arbol->insertar(7);
    arbol->imprimir();*/
}


