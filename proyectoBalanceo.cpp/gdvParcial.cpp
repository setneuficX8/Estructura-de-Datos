/*
REALIZADO POR:
    CARLOS ANDRES CIFUENTES MONTAÑO: 12200106
    JOSE MANUEL SALAS VALENCIA: 12200369
*/

#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

struct pasajero {
    char nomPasa[999];
    int doc=0;
    pasajero *izqp, *derp;
}; pasajero *raizp, *auxp, *auxp2;

struct viaje
{
    char nomEmbarc[999], destino[999], matricula[999], ideViaje[999];
    int precio=0, capacidad=0, dia=0, mes=0, anio=0, altura;
    viaje *izqv, *derv;
}; viaje *raizv, *auxv;

    /* ESTO SE PONE POR SI ACASO AL FINAL DE REGISTRAR
                auxv->izqv= auxv->derv = NULL;
                if(raizv==NULL){
                    raizv= auxv;
                    auxv= NULL;
                free(auxv); 
                }else {
                    auxv2= raizv;
                }
                */

int obtenerAltura(struct viaje *n) {
    if (n == NULL) {
        return 0;
    }
    return n->altura;
}

int mayor(int a, int b) {
    return (a > b) ? a : b;
}

struct viaje* rotarDerecha(struct viaje *y) {
    struct viaje *x = y->izqv;
    struct viaje *T2 = x->derv;

    x->derv = y;
    y->izqv = T2;

    y->altura = mayor(obtenerAltura(y->izqv), obtenerAltura(y->derv)) + 1;
    x->altura = mayor(obtenerAltura(x->izqv), obtenerAltura(x->derv)) + 1;

    return x;
}

struct viaje* rotarIzquierda(struct viaje *x) {
    struct viaje *y = x->derv;
    struct viaje *T2 = y->izqv;

    y->izqv = x;
    x->derv = T2;

    x->altura = mayor(obtenerAltura(x->izqv), obtenerAltura(x->derv)) + 1;
    y->altura = mayor(obtenerAltura(y->izqv), obtenerAltura(y->derv)) + 1;

    return y;
}

int obtenerBalance(struct viaje *n) {
    if (n == NULL) {
        return 0;
    }
    return obtenerAltura(n->izqv) - obtenerAltura(n->derv);
}

struct viaje* insertar(struct viaje* nodo, struct viaje* auxv) {
    if (nodo == NULL) {
        return auxv;
    }

    if (strcmp(auxv->ideViaje, nodo->ideViaje) < 0) {
        nodo->izqv = insertar(nodo->izqv, auxv);
    } else if (strcmp(auxv->ideViaje, nodo->ideViaje) > 0) {
        nodo->derv = insertar(nodo->derv, auxv);
    } else {
        return nodo;
    }

    nodo->altura = 1 + mayor(obtenerAltura(nodo->izqv), obtenerAltura(nodo->derv));

    int balance = obtenerBalance(nodo);

    if (balance > 1 && strcmp(auxv->ideViaje, nodo->izqv->ideViaje) < 0) {
        return rotarDerecha(nodo);
    }

    if (balance < -1 && strcmp(auxv->ideViaje, nodo->derv->ideViaje) > 0) {
        return rotarIzquierda(nodo);
    }

    if (balance > 1 && strcmp(auxv->ideViaje, nodo->izqv->ideViaje) > 0) {
        nodo->izqv = rotarIzquierda(nodo->izqv);
        return rotarDerecha(nodo);
    }

    if (balance < -1 && strcmp(auxv->ideViaje, nodo->derv->ideViaje) < 0) {
        nodo->derv = rotarDerecha(nodo->derv);
        return rotarIzquierda(nodo);
    }

    return nodo;
}

int regViaje(){ int opc=0;
    struct viaje* auxv= (struct viaje*) malloc (sizeof(struct viaje));

        cout<<"NOMBRE DEL VIAJE: "; cin>>auxv->nomEmbarc;
        cout<<"PRECIO: "; cin>>auxv->precio;
        cout<<"DESTINO: "; cin>>auxv->destino;
        cout<<"CAPACIDAD: "; cin>>auxv->capacidad;
        cout<<"MATRICULA: "; cin>>auxv->matricula;
        cout<<"DIA: "; cin>>auxv->dia;
        cout<<"MES: "; cin>>auxv->mes;
        cout<<"ANIO: "; cin>>auxv->anio;
        auxv->izqv=NULL; auxv->derv=NULL; auxv->altura=1;
        raizv= insertar(raizv, auxv);

        cout<<"REGISTRO REALIZADO"<<endl;
        
        cout<<"\nQUIERES HACER OTRO REGISTRO?: (1.SI/2.NO)\n"; cin>>opc; cout<<"\n"<<endl;
        if(opc==1){
            regViaje();
        } else{
            cout<<"OK"<<endl;
        } return 0;
    }
    
    void inordenViaje(struct viaje *v) {
    if (v != NULL) {
        inordenViaje(v->izqv);
        cout << v->ideViaje << " ";
        inordenViaje(v->derv);
    }
}
    
int regPasajero(){

    return 0;
}

int buscarViaje(){ char idevBusc[999]; int opv=0;
    cout<<"INGRESA EL IDENTIFICADOR DEL VIAJE QUE BUSCAS: "<<endl; cin>>idevBusc;

    if(idevBusc==auxv->ideViaje){
        cout<<"VIAJE ENCONTRADO, LOS DATOS SON: \n"<<endl;

        cout<<"NOMBRE DEL VIAJE: "<<auxv->nomEmbarc<<endl;
        cout<<"PRECIO: "<<auxv->precio<<endl;
        cout<<"DESTINO: "<<auxv->destino<<endl;
        cout<<"CAPACIDAD: "<<auxv->capacidad<<endl;
        cout<<"MATRICULA: "<<auxv->matricula<<endl;
        cout<<"IDENTIFICADOR: "<<auxv->ideViaje<<endl;
        cout<<"DIA: "<<auxv->dia<<endl;
        cout<<"MES: "<<auxv->mes<<endl;
        cout<<"ANIO: "<<auxv->anio<<endl;

    } else{
        cout<<"EL VIAJE NO SE ENCUENTRA, QUIERE BUSCAR OTRO? (1. SI/2.NO)\n"<<endl; cin>>opv;
        if(opv==1){
            buscarViaje();
        } else{
            cout<<"OK, ADIOS"<<endl;
        }
    } return 0;
}

int listarViaje(){

    return 0;
}

int listarPasajero(){

    return 0;
}

int quitarVaije(){

    return 0;
}

int main(){
    int opc=0;
do
    {
        cout<<"\nBIENVENIDO AL SISTEMA DE TRANSPORTE FLUVIAL DEL PACIFICO\n"<<endl;
        cout<<"1. REGISTRAR VIAJE"<<endl;
        cout<<"2. BUSCAR VIAJE"<<endl;
        cout<<"3. LISTAR VIAJES"<<endl;
        cout<<"4. ELIMINAR VIAJE"<<endl;
        cout<<"5. REGISTRAR PASAJERO A UN VIAJE"<<endl;
        cout<<"6. LISTAR PASAJEROS DEL VIAJE"<<endl;
        cout<<"7. SALIR"<<endl;

        cout<<"\nELIGE: "<<endl; cin>>opc; system("cls");

        switch (opc)
        {    case 1: regViaje(); break;
             case 2: ; break;
             case 3: ; break;
             case 4: ; break;
             case 5: ; break;
             case 6: ; break;
             case 7: cout<<"GRACIAS POR USAR EL SERVICIO, ADIOS"<<endl; break;
            
            default: cout<<"OPCION NO EXISTENTE, ELIJA LO MOSTRADO POR EL MENU"<<endl; break;
        }
    } while (opc!=7); system ("pause");
    return 0;
}