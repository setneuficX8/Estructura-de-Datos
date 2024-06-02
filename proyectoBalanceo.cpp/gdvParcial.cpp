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
    pasajero* sig;
}; pasajero *auxp;

struct viaje
{
    char nomEmbarc[999], destino[999], matricula[999], ideViaje[999];
    int precio=0, capacidad=0, dia=0, mes=0, anio=0, altura, nPasajeros=0;
    viaje *izqv, *derv; pasajero* kbza, *k2;
}; viaje *raizv, *auxv; 

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

//FUNCION PARA GENERAR EL IDENTIFICADOR PARA EL VIAJE HECHO
void genIdev(viaje* v) {
    snprintf(v->ideViaje, sizeof(v->ideViaje), "%c%c%04d%02d%02d",
             v->matricula[0], v->matricula[1],
             v->anio, v->mes, v->dia);
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
        genIdev(auxv); raizv= insertar(raizv, auxv);

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

int listarViaje(viaje* nodo){
    if (nodo != NULL) {
        listarViaje(nodo->izqv);
        cout<<"\n\tVIAJES REGISTRADOS\t\n"<<endl;
        cout << "IDENTIFICADOR DEL VIAJE: " << nodo->ideViaje << endl;
        cout << "NOMBRE DEL VIAJE: " << nodo->nomEmbarc << endl;
        cout << "PRECIO: " << nodo->precio << endl;
        cout << "DESTINO: " << nodo->destino << endl;
        cout << "CAPACIDAD: " << nodo->capacidad << endl;
        cout << "MATRICULA: " << nodo->matricula << endl;
        cout << "DIA: " << nodo->dia << endl;
        cout << "MES: " << nodo->mes << endl;
        cout << "ANIO: " << nodo->anio << endl;
        listarViaje(nodo->derv);
    }

    return 0;
}

int buscarViaje(){ char idevBusc[999]; int opv=0; viaje *actual= raizv;
    cout<<"INGRESA EL IDENTIFICADOR DEL VIAJE QUE BUSCAS: "<<endl; cin>>idevBusc;

    if(actual!= NULL){
        if(strcmp(idevBusc, actual->ideViaje)==0){
        cout<<"VIAJE ENCONTRADO, LOS DATOS SON: \n"<<endl;

        cout<<"NOMBRE DEL VIAJE: "<<actual->nomEmbarc<<endl;
        cout<<"PRECIO: "<<actual->precio<<endl;
        cout<<"DESTINO: "<<actual->destino<<endl;
        cout<<"CAPACIDAD: "<<actual->capacidad<<endl;
        cout<<"MATRICULA: "<<actual->matricula<<endl;
        cout<<"IDENTIFICADOR: "<<actual->ideViaje<<endl;
        cout<<"DIA: "<<actual->dia<<endl;
        cout<<"MES: "<<actual->mes<<endl;
        cout<<"ANIO: "<<actual->anio<<endl;

        } else if(strcmp(idevBusc, actual->ideViaje)<0){
                actual= actual->izqv;
            } else{
                actual= actual->derv;
            }
    } cout<<"QUIERE BUSCAR OTRO VIAJE? (1. SI/2.NO)\n"<<endl; cin>>opv;
        if(opv==1){
            buscarViaje();
        } else{
            cout<<"OK, ADIOS"<<endl;
        } return 0;
    } 

// FUNCION PARA EL NODO MENOR, SIRVE PARA EL BALANCEO
viaje* menor(viaje* nodo) {
    viaje* actual = nodo;
    while (actual->izqv != NULL) {
        actual = actual->izqv;
    }
    return actual;
}

// FUNCION PARA ELIMINAR UN VIAJE, EN SI ES LA LOGICA APENAS
viaje* borrar(viaje* raiz, char ideViaje[999]) {
    if (raiz == NULL) {
        return raiz;
    }

    if (strcmp(ideViaje, raiz->ideViaje) < 0) {
        raiz->izqv = borrar(raiz->izqv, ideViaje);
    } else if (strcmp(ideViaje, raiz->ideViaje) > 0) {
        raiz->derv = borrar(raiz->derv, ideViaje);
    } else {
        if ((raiz->izqv == NULL) || (raiz->derv == NULL)) {
            viaje* btempo = raiz->izqv ? raiz->izqv : raiz->derv;
            if (btempo == NULL) {
                btempo = raiz;
                raiz = NULL;
            } else {
                *raiz = *btempo;
            }
            free(btempo);
        } else {
            viaje* btempo = menor(raiz->derv);
            strcpy(raiz->ideViaje, btempo->ideViaje);
            raiz->derv = borrar(raiz->derv, btempo->ideViaje);
        }
    } return 0;
}

int quitarVaije(){ viaje* verif= raizv;
    char idevBorrar[999];

    if(verif!= NULL){
        cout<<"INGRESE EL IDENTIFICADOR DEL VIAJE QUE DESEA QUITAR: "<<endl; cin>>idevBorrar;
        if(strcmp(idevBorrar, verif->ideViaje)==0){
            cout<<"EL VIAJE "<<verif->ideViaje<<" HA SIDO ENCONTRADO PARA BORRARSE"<<endl;
            raizv= borrar(raizv, idevBorrar); cout<<"VIAJE ELIMINADO"<<endl;
            
            if(strcmp(idevBorrar, verif->ideViaje)<0){
                verif= verif->izqv;
            } else{
                verif= verif->derv;
            }
        }
    } return 0;
}

viaje* buscId(viaje *vnodo, char idv[999]){
    if(vnodo==NULL || strcmp(vnodo->ideViaje, idv)==0){
        return vnodo;
    } if(strcmp(idv, vnodo->ideViaje)<0){
        return buscId(vnodo->izqv, idv);
    } else{
        return buscId(vnodo->derv, idv);
    }
}

int regPasajero(){ //viaje* //tviaje=raizv;
    char idReg[999];
    
    cout<<"\nINGRESA EL ID DEL VIAJE PARA AGREGAR UN PASAJERO: "<<endl; cin>>idReg;

    viaje *tviaje= buscId(raizv, idReg);
    if(tviaje==NULL){
        cout<<"\nVIAJE NO EXISTENTE\n"<<endl; return 0;
    } if(tviaje->nPasajeros>= tviaje->capacidad){
        cout<<"\nVIAJE LLENO, EL TOPE HA SIDO ALCANZADO"<<endl; return 0;
    }

    auxp= (struct pasajero*) malloc(sizeof(struct pasajero));
    cout<<"\nINGRESA TU NOMBRE: "<<endl; cin>>auxp->nomPasa;
    cout<<"INGRESA TU NUMERO DE ID: "<<endl; cin>>auxp->doc;
    auxp->sig=NULL;

    if(tviaje->kbza==NULL){
        tviaje->kbza= auxp; tviaje->k2= auxp;
    } else{
        tviaje->kbza->sig= auxp; tviaje->k2= auxp;
    } tviaje->nPasajeros++;

    return 0;
}

int listarPasajero(){ char idVb[999]; int opci=0;
    cout<<"INGRESE EL ID DEL VIAJE QUE BUSCAS PARA VER SU LISTADO: "<<endl; cin>>idVb;

    viaje *busv= buscId(raizv, idVb); if(busv==NULL){
        cout<<"NO SE ENCUENTRA EL VIAJE SOLICITADO"<<endl;
        cout<<"QUIERES BUSCAR OTRO?: 1.SI/2.NO"<<endl; cin>>opci;

        if(opci==1){
            listarPasajero();
        } else{
            cout<<"DE NADA, VUELVA PRONTO"<<endl;
        }
    } cout<<"\nPASAJEROS DEL VIAJE "<<busv->ideViaje<<" HACIA "<<busv->destino<<endl; cout<<"\n"<<endl;
    pasajero * verp= busv->kbza;
    if(verp!= NULL){
        cout<<"NOMBRE: "<<verp->nomPasa<<", NUMERO DE ID: "<<verp->doc<<endl;
    }

    return 0;
}

int main(){
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
             case 4: quitarVaije(); break;
             case 5: regPasajero(); break;
             case 6: listarPasajero(); break;
             case 7: cout<<"GRACIAS POR USAR EL SERVICIO, ADIOS"<<endl; break;
            
            default: cout<<"OPCION NO EXISTENTE, ELIJA LO MOSTRADO POR EL MENU"<<endl; break;
        }
    } while (opc!=7); system ("pause");
    return 0;
}