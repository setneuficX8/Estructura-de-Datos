/*
CARLOS ANDRES CIFUENTES MONTAÑO -> 12200106
JOSE MANUEL SALAS VALENCIA -> 12200369
*/

#include <iostream>
#include <malloc.h>
#include <stdlib.h>

using namespace std;

struct estudiante
{
    char nombre [1000], apellido[1000];
    int codigo=0, dia=0, mes=0, anio=0;
    estudiante *izq, *dere;    
}; estudiante *raiz, *aux, *aux2;

void posXCodigo(){
    if(aux->codigo < aux2->codigo){
        if(aux2->izq!=NULL){
            aux2= aux2->izq;
            posXCodigo();
        } else {
            aux2->izq= aux;
        }
    }   else if(aux->codigo > aux2->codigo){
            if(aux2->dere!=NULL){
                aux2= aux2->dere;
                posXCodigo();
            } else{
                aux2->dere= aux;
            }
    }
}

void posXFecha(){
    if(aux->anio < aux2->anio || (aux->anio == aux2->anio && aux->mes < aux2->mes) || (aux->anio == aux2->anio && aux->mes == aux2->mes && aux->dia < aux2->dia)){
        if(aux2->izq!=NULL){
            aux2= aux2->izq;
            posXFecha();
        } else {
            aux2->izq= aux;
        } 
    } else if(aux->anio < aux2->anio || (aux->anio == aux2->anio && aux->mes < aux2->mes) || (aux->anio == aux2->anio && aux->mes == aux2->mes && aux->dia < aux2->dia)){
        if(aux2->dere!= NULL){
                aux2 = aux2->dere;
                posXFecha();
            } else {
                aux2->dere = aux;
         }
    }   
}

void agregar(){int opc;
    do {
        aux= (struct estudiante*) malloc (sizeof(struct estudiante));

        cout<<"NOMBRE: "; cin>>aux->nombre;
        cout<<"APELLIDO: ", cin>>aux->apellido;
        cout<<"CODIGO: "; cin>>aux->codigo;
        cout<<"DIA DE NACIMIENTO: "; cin>>aux->dia;
        cout<<"MES DE NACIMIENTO: ", cin>>aux->mes;
        cout<<"ANIO DE NACIMIENTO: "; cin>>aux->anio;

        aux->izq= aux->dere = NULL;
        if(raiz==NULL){
            raiz= aux;
            aux= NULL;
           free(aux); 
        }else {
            aux2= raiz;
            posXCodigo(); //posXFecha();
        }
        cout<<"REGISTRO REALIZADO"<<endl;
        
        cout<<"\nQUIERES HACER OTRO REGISTRO?: (1.SI/2.NO)\n"; cin>>opc; cout<<"\n"<<endl;
    } while (opc!=2);
    
    return;
}

void preorden(estudiante *recur){
        cout<<recur->codigo<<endl;cout<<"----"<<endl;
        if(recur->izq!=NULL){
            preorden(recur->izq);
        } if(recur->dere!=NULL){
            preorden(recur->dere);
        }
}

void inorden(estudiante *recur){
        if(recur->izq!=NULL){
            inorden(recur->izq);
        }
            cout<<recur->codigo<<endl; cout<<"------"<<endl;
        if(recur->dere!=NULL){
            inorden(recur->dere);
        }
}

void postorden(estudiante *recur){
        if(recur->izq!=NULL){
            postorden(recur->izq);
        } if(recur->dere!=NULL){
            postorden(recur->dere);
        }
            cout<<recur->codigo<<endl;cout<<"------"<<endl;
}

void eliminar(){


}

int main(){ 

    int op=0;
    do
    {
        cout<<"\nWELCOME TO THE CENTRO ADMINISTRATIVO DE ESTUDIANTES\n"<<endl;
        cout<<"1. REGISTRAR"<<endl;
        cout<<"2. USAR RECORRIDO PRE-ORDEN"<<endl;
        cout<<"3. USAR RECORRIDO IN-ORDEN"<<endl;
        cout<<"4. USAR RECORRIDO POST-ORDEN"<<endl;
        cout<<"5. ELIMINAR UN ESTUDIANTE DEL SISTEMA"<<endl;
        cout<<"6. SALIR"<<endl;

        cout<<"\nELIGE: "<<endl; cin>>op; system("cls");

        switch (op)
        {
            case 1: agregar(); break;
            case 2: preorden(raiz); break;
            case 3: inorden(raiz); break;
            case 4: postorden(raiz); break;
            case 5: eliminar(); break;
            case 6: cout<<"GRACIAS POR USAR EL SERVICIO"<<endl; break;
            default: cout<<"ESA OPCION NO EXISTE, ELIJA LO DEL MENU"<<endl; break;
        }
    } while (op!=6); system ("pause");

    return 0;
}

/*void recorrido (){
    aux= raiz;
    if(raiz!=NULL){
        preorden(raiz);
    }

    if(raiz!=NULL){
        inorden(raiz);
    }

    if(raiz!=NULL){
        postorden(raiz);
    }
}
*/