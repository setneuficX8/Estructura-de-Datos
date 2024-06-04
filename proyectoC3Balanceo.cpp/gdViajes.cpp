/*
REALIZADO POR:
    CARLOS ANDRES CIFUENTES MONTAÑO: -> 12200106
    JOSE MANUEL SALAS VALENCIA: -> 12200369

    LINK PARA VER EL VIDEO DE DEMOSTRACION EN YOUTUBE: https://youtu.be/63fP3JZGi84
*/

#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <ctime>
#include <cstring>

using namespace std;

struct pasajero {
    char nomPasajero[999];
    int doc=0;
    pasajero* sig;
}; pasajero *auxp;

struct viaje
{
    char nomViaje[999], destino[999];
    int precio=0, capacidad=0, dia=0, mes=0, anio=0, altura, nPasajeros=0, matricula=0, idViaje=0;
    viaje *izqv, *derv; pasajero* kbza, *k2;
}; viaje *raizv, *auxv;

int obtenerAltura(viaje *n) {
    if (n == NULL) {
        return 0;
    }
    return n->altura;
}

int mayor(int a, int b) {
    return (a > b) ? a : b;
}

int obtenerBalance(viaje *n) {
    if (n == NULL) {
        return 0;
    }
    return obtenerAltura(n->izqv) - obtenerAltura(n->derv);
}

viaje* rotarDerecha(viaje *y) {
    viaje *x = y->izqv;
    viaje *T2 = x->derv;

    x->derv = y;
    y->izqv = T2;

    y->altura = mayor(obtenerAltura(y->izqv), obtenerAltura(y->derv)) + 1;
    x->altura = mayor(obtenerAltura(x->izqv), obtenerAltura(x->derv)) + 1;

    return x;
}

viaje* rotarIzquierda(viaje *x) {
    viaje *y = x->derv;
    viaje *T2 = y->izqv;

    y->izqv = x;
    x->derv = T2;

    x->altura = mayor(obtenerAltura(x->izqv), obtenerAltura(x->derv)) + 1;
    y->altura = mayor(obtenerAltura(y->izqv), obtenerAltura(y->derv)) + 1;

    return y;
}

viaje* insertar(viaje* nodo) {
    if (nodo == NULL) {
        return auxv;
    }

    if (auxv->idViaje < nodo->idViaje) {
        nodo->izqv = insertar(nodo->izqv);
    } else if (auxv->idViaje > nodo->idViaje) {
        nodo->derv = insertar(nodo->derv);
    } else {
        return nodo;
    }

    nodo->altura = 1 + mayor(obtenerAltura(nodo->izqv), obtenerAltura(nodo->derv));

    int balance = obtenerBalance(nodo);

    if (balance > 1 && auxv->idViaje < nodo->izqv->idViaje) {
        return rotarDerecha(nodo);
    }

    if (balance < -1 && auxv->idViaje > nodo->derv->idViaje) {
        return rotarIzquierda(nodo);
    }

    if (balance > 1 && auxv->idViaje > nodo->izqv->idViaje) {
        nodo->izqv = rotarIzquierda(nodo->izqv);
        return rotarDerecha(nodo);
    }

    if (balance < -1 && auxv->idViaje < nodo->derv->idViaje) {
        nodo->derv = rotarDerecha(nodo->derv);
        return rotarIzquierda(nodo);
    }

    return nodo;
}

void inorden(viaje *nodo) {
    if (nodo != NULL) {
        inorden(nodo->izqv);
        cout << nodo->idViaje << " ";
        inorden(nodo->derv);
    }
}

int regViaje(){
    auxv= ((struct viaje *)malloc(sizeof(struct viaje)));

    time_t now = time(0);
    tm *ltm = localtime(&now);
    int yactual = 1900 + ltm->tm_year, mesact= 1+ ltm->tm_mon, dactual= ltm->tm_mday; //son para manejar el tiempo
    cout<<"\nINGRESE EL NOMBRE DE LA EMBARCACION: "; cin>>auxv->nomViaje; cin.ignore(1000, '\n');
    cout<<"HACIA DONDE VA LA EMBARCACION?: "; cin>>auxv->destino; cin.ignore(1000, '\n');
    cout<<"CUANTOS PASAJEROS VAN?: "; cin>>auxv->capacidad;
    cout<<"CUANTO CUESTA EL BOLETO?: "; cin>>auxv->precio;
    cout<<"INGRESE EL NUMERO DE MATRICULA DEL VIJAE: "; cin>>auxv->matricula;
    cout<<"INGRESE EL ANIO DEL VIAJE: "; cin>>auxv->anio;
    if(auxv->anio<yactual){
        cout<<"\nNO PUEDES VIAJAR EN EL TIEMPO, REGISTRA DE NUEVO EL VIAJE\n"<<endl;
        regViaje();
    }
    cout<<"INGRESE EL MES DEL VIAJE: "; cin>>auxv->mes;
    if(auxv->anio==yactual && auxv->mes<mesact){
        cout<<"\nNO PUEDES PARA EL MESES PASADOS, REGISTRA DE NUEVO EL VIAJE\n"<<endl;
        regViaje();
    }
    cout<<"INGRESE EL DIA DEL VIAJE: "; cin>>auxv->dia;
    if(auxv->anio==yactual && auxv->mes==mesact && auxv->dia<dactual){
        cout<<"\nNO PUEDES RESERVAR PARA DIAS ANTERIORES, REGISTRA DE NUEVO EL VIAJE\n"<<endl;
        regViaje();
    }
    int digMtri= auxv->matricula/10000;
    auxv->idViaje= digMtri * 100000000 + auxv->anio * 10000 + auxv->mes * 100 + auxv->dia;

    cout<<"\nUSTED HA REGISTRADO LO SIGUIENTE: \n"<<endl;
    cout<<"NOMBRE: "<<auxv->nomViaje<<endl;
    cout<<"DESTINO: "<<auxv->destino<<endl;
    cout<<"CAPACIDAD: "<<auxv->capacidad<<endl;
    cout<<"FECHA: ANIO "<<auxv->anio<<", MES "<<auxv->mes<<", DIA "<<auxv->dia<<endl;
    cout<<"MATRICULA: "<<auxv->matricula<<endl;
    cout<<"ID DEL VIAJE: "<<auxv->idViaje<<endl;

    auxv->izqv=NULL; auxv->derv=NULL; auxv->altura=1;
    raizv= insertar(raizv);

    int opci=0;
    cout<<"\nQUIERES HACER OTRA RESERVA?: (1.SI/2.NO)\n"<<endl;cin>>opci;
    if(opci==1){
        regViaje();
    } else{
        cout<<"\nOK\n"<<endl;
    }

    return 0;
}

int listarViaje(viaje* nv){;
    if(nv!=NULL){
        cout<<"NOMBRE: "<<nv->nomViaje<<endl;
        cout<<"DESTINO: "<<nv->destino<<endl;
        cout<<"CAPACIDAD: "<<nv->capacidad<<endl; 
        cout<<"FECHA: ANIO "<<nv->anio<<", MES "<<nv->mes<<", DIA "<<nv->dia<<endl;
        cout<<"MATRICULA: "<<nv->matricula<<endl;
        cout<<"ID DEL VIAJE: "<<nv->idViaje<<endl; cout<<"-----------------------------------"<<endl;
        listarViaje(nv->izqv);
        listarViaje(nv->derv);
    }   return 0;
}

int buscarViaje(){ int idBuscar;
    cout<<"\nINGRESA EL ID DEL VIAJE QUE BUSCAS: "; cin>>idBuscar;
    viaje* baux= raizv;

    while(baux!=NULL){
        if(baux->idViaje==idBuscar){
        cout<<"\nVIAJE ENCONTRADO, LOS DATOS SON: \n"<<endl;
        cout<<"NOMBRE: "<<baux->nomViaje<<endl;
        cout<<"DESTINO: "<<baux->destino<<endl;
        cout<<"CAPACIDAD: "<<baux->capacidad<<endl;
        cout<<"FECHA: ANIO "<<baux->anio<<", MES "<<baux->mes<<", DIA "<<auxv->dia<<endl;
        cout<<"MATRICULA: "<<baux->matricula<<endl;
        cout<<"ID DEL VIAJE: "<<baux->idViaje<<endl; return 1;
        } else if(baux->idViaje<idBuscar){
            baux= baux->izqv;
        } else{
            baux= baux->derv;
        }
    } cout<<"\nVIAJE NO ENCONTRADO, NO COINCIDE\n"<<endl; int opb=0;
    cout<<"QUIERE BUSCAR DE NUEVO? (1.SI/2.NO)\n"<<endl;cin>>opb;
    if(opb==1){
        buscarViaje();
    }else{
        cout<<"OK\n"<<endl;
    }

    return 0;
}

viaje* minimo(viaje* nodo) {
    viaje* actual = nodo;
    while (actual && actual->izqv != NULL)
        actual = actual->izqv;
    return actual;
}

viaje* eliminar(viaje* nodo, int idEliminar) {
    if (nodo == NULL)
        return nodo;

    if (idEliminar < nodo->idViaje)
        nodo->izqv = eliminar(nodo->izqv, idEliminar);
    else if (idEliminar > nodo->idViaje)
        nodo->derv = eliminar(nodo->derv, idEliminar);
    else {
        if (nodo->izqv == NULL || nodo->derv == NULL) {
            viaje* temp = nodo->izqv ? nodo->izqv : nodo->derv;
            if (temp == NULL) {
                temp = nodo;
                nodo = NULL;
            } else
                *nodo = *temp;
            free(temp);
        } else {
            viaje* temp = minimo(nodo->derv);
            nodo->idViaje = temp->idViaje;
            nodo->derv = eliminar(nodo->derv, temp->idViaje);
        }
    }

    if (nodo == NULL)
        return nodo;

    nodo->altura = 1 + mayor(obtenerAltura(nodo->izqv), obtenerAltura(nodo->derv));

    int balance = obtenerBalance(nodo);

    if (balance > 1 && obtenerBalance(nodo->izqv) >= 0)
        return rotarDerecha(nodo);

    if (balance > 1 && obtenerBalance(nodo->izqv) < 0) {
        nodo->izqv = rotarIzquierda(nodo->izqv);
        return rotarDerecha(nodo);
    }

    if (balance < -1 && obtenerBalance(nodo->derv) <= 0)
        return rotarIzquierda(nodo);

    if (balance < -1 && obtenerBalance(nodo->derv) > 0) {
        nodo->derv = rotarDerecha(nodo->derv);
        return rotarIzquierda(nodo);
    }

    return nodo;
}

int quitarViaje(){
    int idElim;
    cout<<"INGRESE EL ID DEL VIAJE QUE QUIERE ELIMINAR: "<<endl;cin>>idElim;

    viaje* nodoActual = raizv;
    viaje* padre = NULL;

    while (nodoActual != NULL) {
        if (idElim == nodoActual->idViaje) {
            if (nodoActual->izqv == NULL || nodoActual->derv == NULL) {
                viaje* temp = nodoActual->izqv ? nodoActual->izqv : nodoActual->derv;
                if (padre == NULL) {
                    raizv = temp;
                } else if (padre->izqv == nodoActual) {
                    padre->izqv = temp;
                } else {
                    padre->derv = temp;
                }
                free(nodoActual);
            } else {
                viaje* temp = minimo(nodoActual->derv);
                nodoActual->idViaje = temp->idViaje;
                nodoActual->derv = eliminar(nodoActual->derv, temp->idViaje);
            }
            cout << "EL VIAJE HA SIDO ELIMINADO EXITOSAMENTE.\n";
            return 0;
        } else if (idElim < nodoActual->idViaje) {
            padre = nodoActual;
            nodoActual = nodoActual->izqv;
        } else {
            padre = nodoActual;
            nodoActual = nodoActual->derv;
        }
    }    return 0;
}

viaje *buscarAux(viaje* raizv, int vbusc){
    if(raizv==NULL){
        return NULL;
    }

    if(vbusc < raizv->idViaje){
        return buscarAux(raizv->izqv, vbusc);
    } else if(vbusc> raizv->idViaje){
        return buscarAux(raizv->derv, vbusc);
    } else{
        return raizv;
    }
}

int regPasajero(){
    int asoViaje; viaje* encont;

    cout<<"INGRESA EL ID DEL VIAJE PARA INGRESAR PASAJEROS: ";cin>>asoViaje;
    encont= buscarAux(raizv, asoViaje);
    
    if(encont==NULL){
        cout<<"\nNO HAY VIAJE CON ESE ID\n"<<endl;
    } if(encont->nPasajeros>encont->capacidad){
        cout<<"\nVIAJE LLENO\n"<<endl;
    } if(encont->nPasajeros <= encont->capacidad){
        pasajero* auxp= ((struct pasajero *)malloc(sizeof(struct pasajero)));
        cout<<"INGRESA TU NOMBRE: "; cin>>auxp->nomPasajero; cin.ignore();
        cout<<"INGRESA TU NUMERO DE ID: "; cin>>auxp->doc;
        cout<<"\nREGISTRO REALIZADO\n"<<endl;
        auxp->sig=NULL;
        encont->nPasajeros++;

        if(encont->kbza==NULL){
            encont->kbza=auxp;
            encont->k2= auxp;
            } else{
                encont->k2->sig= auxp;
                encont->k2= auxp;
            }
        } 
    
    return 0;
}

int listarPasajeros(){
    int idbv;
    cout<<"INGRESA EL ID DEL VIAJE PARA VER EL LISTADO: "; cin>>idbv;

    viaje* enc= buscarAux(raizv, idbv);

    if(enc==NULL){
        cout<<"\nNO VIAJE CON ESE ID\n"<<endl;
    }   pasajero* paux= enc->kbza;
        if(enc!=NULL){
                cout<<"NOMBRE: "<<paux->nomPasajero<<endl;
                cout<<"NUMERO DEL ID: "<<paux->doc<<endl;
                cout<<"----------------------------------------"<<endl;
                paux= auxp->sig;
        }
    
    return 0;
}

int main() {
    int opc=0;
do
    {
        cout<<"\nBIENVENIDO AL SISTEMA DE TRANSPORTE FLUVIAL DEL PACIFICO\n"<<endl;
        cout<<"1. REGISTRAR VIAJE"<<endl;
        cout<<"2. LISTADO DE VIAJES"<<endl;
        cout<<"3. BUSCAR VIAJE"<<endl;
        cout<<"4. ELIMINAR VIAJE"<<endl;
        cout<<"5. REGISTRAR PASAJERO A UN VIAJE"<<endl;
        cout<<"6. LISTADO DE PASAJEROS DEL VIAJE"<<endl;
        cout<<"7. SALIR"<<endl;

        cout<<"\nELIGE: "<<endl; cin>>opc; system("cls");

        switch (opc)
        {    case 1: regViaje(); break;
             case 2: listarViaje(raizv); break;
             case 3: buscarViaje(); break;
             case 4: quitarViaje(); break;
             case 5: regPasajero(); break;
             case 6: listarPasajeros(); break;
             case 7: cout<<"GRACIAS POR USAR EL SERVICIO, ADIOS"<<endl; break;
            
            default: cout<<"OPCION NO EXISTENTE, ELIJA LO MOSTRADO POR EL MENU"<<endl; break;
        }
    } while (opc!=7); system ("pause");
    return 0;
} //VARIOS DIAS SIN DORMIR BIEN PROFE, PERO AQUI ESTA EL TRABAJO