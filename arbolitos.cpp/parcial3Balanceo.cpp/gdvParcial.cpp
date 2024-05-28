/*
REALIZADO POR:
    CARLOS ANDRES CIFUENTES MONTAÑO: 12200106
    JOSE MANUEL SALAS VALENCIA: 12200369
*/

#include <iostream>
#include <malloc.h>
#include <stdlib.h>

using namespace std;

struct viaje {
    char nombre[999];
    int doc=0;
    pasajero *izqv, *derv;
}; viaje *auxv, *auxv2, *raizv;

struct pasajero
{
    char nomEmbarc[999];
    int precio=0, matricula=0, dia=0, mes=0, anio=0, capacidad=0;
}; pasajero *auxp, *auxp2, *raizp;

void regViaje(){

}

void regPasajero(){

}

void buscarViaje(){

}

void listarViaje(){

}

void listarPasajero(){
    
}

void quitarVaije(){

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
        {    case 1: ; break;
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