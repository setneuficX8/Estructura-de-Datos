#include <iostream>
#include <malloc.h>

/*
CODIFICACION ACREDITADA A:
    CARLOS ANDRES CIFUENTES MONTAÑO -> CODIGO: 12200106
    JOSE MANUEL SALAS VALENCIA -> CODIGO: 12200369
*/

using namespace std;

struct pacientes
{
    char nombre[500];
    int doc=0;
    pacientes *sig;
}; pacientes *cabeza, *aux, *aux2; //declaracion de apuntadores en la cola


void aggPaciente(){
    if(cabeza==NULL){
            cabeza= (struct pacientes *) malloc (sizeof(struct pacientes));

            cout<<"\nINGRESE SU NOMBRE: "<<endl; cin>>cabeza->nombre; cin.ignore(1000, '\n');
            cout<<"\nINGRESE SU NUMERO DE DOCUMENTO: "<<endl; cin>>cabeza->doc;
        cabeza->sig= NULL;
    } else{
        aux= (struct pacientes *) malloc (sizeof(struct pacientes));
            cout<<"\nINGRESE SU NOMBRE: "<<endl; cin>>aux->nombre; cin.ignore(1000, '\n');
            cout<<"\nINGRESE SU NUMERO DE DOCUMENTO: "<<endl; cin>>aux->doc;
        aux->sig= NULL;
        aux2= cabeza;

        while (aux2->sig!=NULL)
        {
            aux2= aux2->sig; // se apunta hace siguiente siempre y cuando este no sea nulo
        }
        
        aux2->sig= aux;
        aux2= aux= NULL;

            free(aux);
            free(aux2); // libera la memoria que utilizan
    }
}

void verPaciente(){
    int posi=1; pacientes *actual= cabeza;

    while (actual!= NULL)
    {
        cout<<"\nPACIENTE "<<posi<<endl;
        cout<<"\nNOMBRE: "<<actual->nombre<<endl<<"NUMERO DE DOCUMENTO: "<<actual->doc<<"\n";
        cout<<"-----------------------------------";
        posi++;
        actual= actual->sig;
    }
    
}

int main(){

    int op=0;

    do
    {
        cout<<"\n\tBIENVENIDO, SENIOR, SENIORA O SENIORE\n"<<endl;
        cout<<"1. AGREGAR UN PACIENTE"<<endl;        
        cout<<"2. VER PACIENTES AGREGADOS"<<endl;
        cout<<"3. SALIR DEL HOSPITALITO\n"<<endl;
        cin>>op;

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