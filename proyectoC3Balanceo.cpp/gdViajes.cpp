/*
REALIZADO POR:
    CARLOS ANDRES CIFUENTES MONTAÑO: -> 12200106
    JOSE MANUEL SALAS VALENCIA: -> 12200369
*/

#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <ctime>

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
/*
int generarIDViaje(viaje *v) { //ME GENERA EL ID PARA EL VIAJE
    int digMtri= v->matricula/10000;
    v->idViaje= digMtri * 100000000 + v->anio * 10000 + v->mes * 100 + v->dia;
    //int idViaje = generarIDViaje(); PARA ASIGNAR EL VALOR Y MOSTRAR EN LA FUNCION REGISTRAR
    return 0;//o tambien idViaje
}
*/

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
        cout<<"FECHA: ANIO "<<auxv->anio<<", MES "<<auxv->mes<<", DIA "<<auxv->dia<<endl;
        cout<<"MATRICULA: "<<auxv->matricula<<endl;
        cout<<"ID DEL VIAJE: "<<auxv->idViaje<<endl; cout<<"-----------------------------------"<<endl;
        listarViaje(nv->izqv);
        listarViaje(nv->derv);
    }   return 0;
}

int buscarViaje(){

    return 0;
}

int quitarViaje(){

    return 0;
}

int regPasajero(){

    return 0;
}

int listarPasajeros(){

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
}