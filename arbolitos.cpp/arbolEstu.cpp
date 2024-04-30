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

void posicionarMCodigo(){
    if(aux->codigo < aux2->codigo){
        if(aux2->izq!=NULL){
            aux2= aux2->izq;
            posicionarMCodigo();
        } else {
            aux2->izq= aux;
        } else if(aux->codigo > aux2->val){
            if(aux2->der!= NULL){
                aux2 = aux2->der;
                posicionarMCodigo();
            } else {
                aux2->der = aux;
            }
        }
    }
}

void recorrido (){
    
}

void agregar(){
    aux= (struct estudiante*) malloc (sizeof(estudiante));

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
        posicionarMCodigo();
    }
        cout<<"REGISTRO REALIZADO"<<endl;
}

void preorden(estudiante *recur){
    if(recur==NULL){
        return;
    } else {
        cout<<"CODIGO: "<<recur->codigo<<endl;
        cout<<"DIA: "<<recur->dia<<" |MES: "<<recur->mes<<" |ANIO: "<<recur->anio<<endl;
        cout<<"----"<<endl;
        preorden(recur->izq); preorden(recur->dere);
    }
}

void inorden(estudiante *recur){
    if(recur==NULL){
        return;
    } else {
        inorden(recur->izq);
        cout<<"CODIGO: "<<recur->codigo<<endl;
        cout<<"DIA: "<<recur->dia<<" |MES: "<<recur->mes<<" |ANIO: "<<recur->anio<<endl;
        cout<<"----"<<endl;
        inorden(recur->dere);
    }
}

void postorden(estudiante *recur){
    if(recur==NULL){
        return;
    } else {
        postorden(recur->izq); postorden(recur->dere);
        cout<<"CODIGO: "<<recur->codigo<<endl;
        cout<<"DIA: "<<recur->dia<<" |MES: "<<recur->mes<<" |ANIO: "<<recur->anio<<endl;
        cout<<"-----"<<endl;
    }
}

void mostrar(estudiante *recur, int conta){
    if(recur==NULL){
        return;
    } else {
        mostrar(recur->izq, conta+1);
        for(int i=0; i<conta; i++){
            cout<<"     ";
        } cout<<recur->codigo<<endl;
        mostrar(recur->dere, conta+1);
    }
}

void eliminar(){


}

int main(){ 

    int op=0;
    do
    {
        cout<<"\nWELCOME TO THE CENTRO ADMINISTRATIVO DE ESTUDIANTES\n"<<endl;
        cout<<"1. REGISTRAR"<<endl;
        cout<<"2. POSICIONAR MEDIANTE PRE-ORDEN"<<endl;
        cout<<"3. POSICIONAR MEDIANTE IN-ORDEN"<<endl;
        cout<<"4. POSICIONAR MEDIANTE POST-ORDEN"<<endl;
        cout<<"5. MOSTRAR EL ARBOL BINARIO"<<endl;
        cout<<"6. ELIMINAR UN ESTUDIANTE DEL SISTEMA"<<endl;
        cout<<"7. SALIR"<<endl;

        cout<<"ELIGE: "<<endl; cin>>op; system("cls");

        switch (op)
        {
            case 1: agregar(); break;
            case 2: preorden(raiz); break;
            case 3: inorden(raiz); break;
            case 4: postorden(raiz); break;
            case 5: eliminar(); break;
            case 6: mostrar(raiz, 0); break;
            case 7: cout<<"GRACIAS POR USAR EL SERVICIO"<<endl; break;
            default: cout<<"ESA OPCION NO EXISTE, ELIJA LO DEL MENU"<<endl; break;
        }
    } while (op!=7); system ("pause");

    return 0;
}