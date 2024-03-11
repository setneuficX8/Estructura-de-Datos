#include <iostream>
#include <malloc.h>

using namespace std;

struct pacientes
{
    char nombre=' ';
    int doc=0;
    pacientes *sig;
}; pacientes *cabeza, *aux, *aux2;


void aggPaciente(){
    if(cabeza==NULL){
            cabeza= (struct pacientes *) malloc (sizeof(struct pacientes));

            cout<<"\nINGRESE SU NOMBRE: "<<endl; cin>>cabeza->nombre;
            cout<<"\nINGRESE SU NUMERO DE DOCUMENTO: "<<endl; cin>>cabeza->doc;
        cabeza->sig= NULL;
    } else{
        aux= (struct pacientes *) malloc (sizeof(struct pacientes));
            cout<<"\nINGRESE SU NOMBRE: "<<endl; cin>>aux->nombre;
            cout<<"\nINGRESE SU NOMBRE: "<<endl; cin>>aux->doc;
        aux->sig= NULL; aux2= cabeza;

        while (aux2->sig!=NULL)
        {
            aux2= aux2->sig;
            aux2->sig= aux;
            aux2= aux= NULL;

            free(aux);
            free(aux2);
        }
        
    }
}

void verPaciente(){
    
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

        switch (op)
        {
        case 1: aggPaciente();
            break;
        case 2: verPaciente();
            break;

        case 3: cout<<"FIN DE LA JORNADA :)\n"<<endl;
            break;
        default: cout<<"\nLA OPCION ELEGIDA NO EXISTE, ELIJA UNA DISPONIBLE\n"<<endl;
            break;
        }
    } while (op!=3);
    
    return 0;
}