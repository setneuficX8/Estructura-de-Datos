/*	By: Carlos Andres Cifuentes Montaño ->12200106

	Tengo un parqueadero de callejon con ocupacion para Motos y Carros. 
    Los cuales se parquean en sistema LIFO.
	Los carros tiene un valor de parqueo de 1.000 y motos 500, pero 
    al retirarlos cada movimiento adicional
	de vehiculos cuesta 100 para carro y 50 para moto.
    Calcular el valor devegando en x momento del dia.
*/

#include <iostream>
#include <malloc.h>
#include <stdlib.h>

using namespace std;

struct carro{
    int idc=0;
    char plaCarro[1000], marca[1000], modelo[1000];
    carro* sigc;
};carro *topc, *auxc;

struct moto
{
    int idm=0;
    char placaMoto[1000], marcam[1000], modelom[1000];
    moto* sigm;
};moto *topm, *auxm;

int cuotac=1000;
int cuotam=500;

void parquearCarro(){
    auxc= ((struct carro *) malloc (sizeof(struct carro)));

    cout<<"\nINGRESA EL ID DE TU CARRO: "; cin>>auxc->idc;
    cout<<"INGRESA LA PLACA DE TU CARRO: "; cin>>auxc->plaCarro; cin.ignore(1000, '\n');
    cout<<"INGRESA LA MARCA DE TU CARRO: "; cin>>auxc->marca; cin.ignore(1000, '\n');
    cout<<"INGRESA EL MODELO DE TU CARRO: "; cin>>auxc->modelo; cin.ignore(1000, '\n');

    cout<<"\nPARQUEO EXITOSO, LA CUOTA ES DE "<<cuotac<<" PESOS"<<endl;

    if(topc==NULL){
        topc= auxc;
        topc->sigc=NULL;
    } else{
        auxc->sigc= topc;
        topc= auxc;
    } auxc= NULL;

    free(auxc);
}

void parquearMoto(){
    auxm= ((struct moto *) malloc (sizeof(struct moto)));

    cout<<"\nINGRESA EL ID DE TU MOTO: "; cin>>auxm->idm;
    cout<<"INGRESA LA PLACA DE TU MOTO: "; cin>>auxm->placaMoto; cin.ignore(1000, '\n');
    cout<<"INGRESA LA MARCA DE TU MOTO: "; cin>>auxm->marcam; cin.ignore(1000, '\n');
    cout<<"INGRESA EL MODELO DE TU MOTO: "; cin>>auxm->modelom; cin.ignore(1000, '\n');

    cout<<"\nPARQUEO EXITOSO, LA CUOTA ES DE "<<cuotam<<" PESOS"<<endl;

    if(topm==NULL){
        topm= auxm;
        topm->sigm=NULL;
    } else{
        auxm->sigm= topm;
        topm= auxm;
    } auxm= NULL;

    free(auxm);
}

void verParking(){
    carro* tempCarro= topc; moto* tempMoto= topm;
    int posCarro= 1, posMoto=1;

    while (tempCarro!=NULL){
        cout<<"\nCARROS PARQUEADOS: \n"<<endl;
        cout<<"---------------------------------------------"<<endl;
        cout<<"CARRO "<<posCarro<<endl;
        cout<<"ID: "<<tempCarro->idc<<endl;
        cout<<"PLACA: "<<tempCarro->plaCarro<<endl;
        cout<<"MARCA: "<<tempCarro->marca<<endl;
        cout<<"MODELO: "<<tempCarro->modelo<<endl;
        cout<<"---------------------------------------------"<<endl;

        tempCarro= tempCarro->sigc; posCarro++;
    } cout<<"NO HAY CARROS"<<endl;
        
        while (tempMoto!=NULL){
            cout<<"\nMOTOS PARQUEADAS: \n"<<endl;
            cout<<"---------------------------------------------"<<endl;
            cout<<"MOTO "<<posMoto<<endl;
            cout<<"ID: "<<tempMoto->idm<<endl;
            cout<<"PLACA: "<<tempMoto->placaMoto<<endl;
            cout<<"MARCA: "<<tempMoto->marcam<<endl;
            cout<<"MODELO: "<<tempMoto->modelom<<endl;
            cout<<"---------------------------------------------"<<endl;

            tempMoto= tempMoto->sigm; posMoto++;
        } cout<<"NO HAY MOTOS"<<endl;
}

void desparquear(){    
    int impCarro= 100, impMoto= 50;
    int sumaCarro=0, sumaMoto= 0;

    carro* tempc1= topc; moto* tempm1= topm;
    carro* abajoc= NULL; moto* abajom= NULL;

    int idVehi=0;

    cout<<"INGRESE EL ID DEL VEHICULO QUE QUIERE SACAR DEL PARQUEADERO: "<<endl; cin>>idVehi;

    while(tempc1!= NULL){
        if(tempc1->idc== idVehi){
            cout<<"CARRO ENCONTRADO, SUS DATOS SON: \n"<<endl;

            cout<<"ID: "<<tempc1->idc<<endl;
            cout<<"PLACA: "<<tempc1->plaCarro<<endl;
            cout<<"MARCA: "<<tempc1->marca<<endl;
            cout<<"MODELO: "<<tempc1->modelo<<endl;

            carro* movCarro= topc;
            while(movCarro!= tempc1){
                sumaCarro += impCarro;
                movCarro= movCarro->sigc;
            } cout<<"SE PAGA "<<sumaCarro<<" PESOS ADICIONALMENTE"<<endl;

            if(abajoc!= NULL){
                abajoc->sigc= tempc1->sigc; free(tempc1);
            } else{
                topc= tempc1->sigc; free(tempc1);
            }
        } abajoc= tempc1;
        tempc1= tempc1->sigc;
    }

    while(tempm1!= NULL){
        if(tempm1->idm== idVehi){
            cout<<"CARRO ENCONTRADO, SUS DATOS SON: \n"<<endl;

            cout<<"ID: "<<tempm1->idm<<endl;
            cout<<"PLACA: "<<tempm1->placaMoto<<endl;
            cout<<"MARCA: "<<tempm1->marcam<<endl;
            cout<<"MODELO: "<<tempm1->modelom<<endl;

            moto* movMoto= topm;
            while(movMoto!= tempm1){
                sumaMoto+= impMoto;
                movMoto= movMoto->sigm;
            } cout<<"SE PAGA "<<sumaMoto<<" PESOS ADICIONALMENTE"<<endl;

            if(abajom!= NULL){
                abajom->sigm= tempm1->sigm; free(tempm1);
            } else{
                topm= tempm1->sigm; free(tempm1);
            }
        } abajom= tempm1;
        tempm1= tempm1->sigm;
    } cout<<"VEHICULO NO ENCONTRADO"<<endl;
}

int main(){
    int op=0;
    
    do
    {
    cout<<"\nBIENVENIDO AL PARQUEADERO\n"<<endl;
    cout<<"1. PARQUEAR CARRO"<<endl;
    cout<<"2. PARQUEAR MOTO"<<endl;
    cout<<"3. VER PARQUEADERO"<<endl;
    cout<<"4. DESPACHAR VEHICULO"<<endl;
    cout<<"5. NO ME GUSTA SU PARQUEADERO, CHAO"<<endl;

    cout<<"\nELIJA: "<<endl; cin>>op; system("cls");

    switch (op)
    {
    case 1:parquearCarro(); break;
    case 2:parquearMoto(); break;
    case 3:verParking(); break;
    case 4:desparquear(); break;
    case 5:cout<<"\nSAYONARA\n"<<endl; break;
    default:cout<<"\nESCOJA UNA OPCION DISPONIBLE"; break;
    } 
} while (op!=5);
    system("pause");
    return 0;
}
