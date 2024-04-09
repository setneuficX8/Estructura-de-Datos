/*
	Tengo un parqueadero de callejon con ocupacion para Motos y Carros. 
    Los cuales se parquean en sistema LIFO.
	Los carros tiene un valor de parqueo de 1.000 y motos 500, pero 
    al retirarlos cada movimiento adicional
	de vehiculos cuesta 100 para carro y 50 para moto.
    Calcular el valor devegando en x momento del dia.
*/

#include <iostream>
#include <malloc.h>
#include <locale.h>

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

void parquearCarro(){
    auxc= ((struct carro *) malloc (sizeof(struct carro)));
    int cuotac=1000;

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
    int cuotam=500;

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

    if(tempCarro!=NULL){
        cout<<"\nCARROS PARQUEADOS: \n"<<endl;
        cout<<"CARRO "<<posCarro<<endl;

        cout<<"ID: "<<tempCarro->idc<<endl;
        cout<<"PLACA: "<<tempCarro->plaCarro<<endl;
        cout<<"MARCA: "<<tempCarro->marca<<endl;
        cout<<"MODELO: "<<tempCarro->modelo<<endl;

        tempCarro= tempCarro->sigc; posCarro++;

    } else{
        cout<<"\nNO HAY CARROS PARQUEADOS\n"<<endl;
    }
        
        if(tempMoto!=NULL){
            cout<<"\nMOTOS PARQUEADAS: \n"<<endl;

            cout<<"MOTO "<<posMoto<<endl;

            cout<<"ID: "<<tempMoto->idm<<endl;
            cout<<"PLACA: "<<tempMoto->placaMoto<<endl;
            cout<<"MARCA: "<<tempMoto->marcam<<endl;
            cout<<"MODELO: "<<tempMoto->modelom<<endl;

            tempMoto= tempMoto->sigm; posMoto++;
        
        } else{
            cout<<"\nNO HAY MOTOS PARQUEADAS\n"<<endl;
        }
}

void desparquear(){

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