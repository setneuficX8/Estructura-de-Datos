#include <iostream>
#include <stdlib.h>
#include <malloc.h>

using namespace std;

void aggNodo(){

}

void verNodo(){
    
}

int main(){

    int op=0;

    do
    {
        cout<<"\n\tBIENVENIDO, SENIOR, SENIORA O SENIORE\n"<<endl;
        cout<<"1. AGREGAR UN PACIENTE"<<endl;        
        cout<<"2. VER PACIENTES AGREGADOS"<<endl;
        cout<<"3. SALIR DEL HOSPITALITO\n"<<endl;
        cin>>op; system("cls");
    } while (op!=3);
    
    system("pause");
    return 0;
}