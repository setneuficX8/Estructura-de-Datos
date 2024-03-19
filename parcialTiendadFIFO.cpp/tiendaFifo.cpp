/*
DESARROLLADO POR:
CARLOS ANDRES CIFUENTES MONTAÑO: 12200106
JOSE MANUEL SALAS VALENCIA: 12200369
*/

#include <iostream>
#include <malloc.h>
#include <stdlib.h>
/*malloc.h se usa para asignar memoria de forma
dinamica*/
using namespace std;

struct producto
{
    char nombre[999];
    int idp=0, precio=0, cantidad=0;

    producto* sig;
}; producto *kbza, *aux, *aux2;

void regisProducto(){
    if(kbza==NULL){
		kbza= (struct producto *) malloc (sizeof(struct producto)); // Gestion de memoria
			
			cout<<"\nINGRESE EL NOMBRE DEL PRODUCTO A REGISTRAR: "<<endl;
			cin>>kbza->nombre; cin.ignore(1000, '\n'); // Para que no haya alguna irregularidad al momento de ingresar el dato
			cout<<"\nINGRESE EL ID DEL PRODUCTO A REGISTRAR: "<<endl;
			cin>>kbza->idp;
			cout<<"\nINGRESE EL PRECIO DEL PRODUCTO A REGISTRAR: "<<endl;
			cin>>kbza->precio;
			cout<<"\nINGRESE LA CANTIDAD DE PRODUCTOS A REGISTRAR: "<<endl;
			cin>>kbza->cantidad;
			
			cout<<"\nSU PRODUCTO HA SIDO REGISTRADO"<<endl;
		kbza->sig= NULL;
		} else{
		aux= (struct producto *) malloc (sizeof(struct producto)); 
			cout<<"\nINGRESE EL NOMBRE DEL PRODUCTO A REGISTRAR: "<<endl;
			cin>>aux->nombre; cin.ignore(1000, '\n');
			cout<<"\nINGRESE EL ID DEL PRODUCTO A REGISTRAR: "<<endl;
			cin>>aux->idp;
			cout<<"\nINGRESE EL PRECIO DEL PRODUCTO A REGISTRAR: "<<endl;
			cin>>aux->precio;
			cout<<"\nINGRESE LA CANTIDAD DE PRODUCTOS A REGISTRAR: "<<endl;
			cin>>aux->cantidad;
			
			cout<<"\nSU PRODUCTO HA SIDO REGISTRADO"<<endl;
		aux->sig= NULL;
		aux2= kbza;
		while(aux2->sig!=NULL)
			aux2= aux2->sig;
		aux2->sig= aux;
		aux2= aux= NULL;
		free(aux);
		free(aux2);
	}
}

void verInventario(){
    int lugar=1;
	producto *actuali= kbza; // Apunte hacia la dirección y asigna valores
	
	cout<<"\n\tESTOS SON LOS PRODUCTOS REGISTRADOS EN EL INVENTARIO\n\n"<<endl;
	if (actuali!= NULL) {
	
	cout<<"\nPRODUCTO "<<lugar<<"\n"<<endl;
    cout<<"NOMBRE DEL PRODUCTO: "<<actuali->nombre<<endl;
    cout<<"ID DEL PRODUCTO: "<<actuali->idp<<endl;
	cout<<"PRECIO DEL PRODUCTO: "<<actuali->precio<<endl;
	cout<<"CANTIDAD DE PRODUCTOS: "<<actuali->cantidad<<endl;
    
    lugar++;
    actuali = actuali->sig;
	}	else{
		cout<<"\nEL INVENTARIO ESTA VACIO, HAY QUE SURTIRLO\n"<<endl;
	}
}

void buscarProducto(){
	int auxId=0; // Sirve como comparador
	
	if(kbza==NULL){
		cout<<"\nJOVEN, NO HAY PRODUCTOS REGISTRADOS"<<endl;
	}
	producto *tempo= kbza;
	while(tempo!=NULL){
	cout<<"\nINGRESE EL ID DEL PRODUCTO QUE DESEA BUSCAR: "<<endl; cin>>auxId;
		if(tempo->idp== auxId){ // Comparacion
			cout << "\nSU PRODUCTO HA SIDO ENCONTRADO, SUS DATOS SON:\n" << endl;
            cout << "ID: " << tempo->idp << endl;
            cout << "NOMBRE: " << tempo->nombre << endl;
            cout << "PRECIO: " << tempo->precio << endl;
            cout << "CANTIDAD: " << tempo->cantidad << endl;
			} else{
				cout<<"\nEL PRODUCTO QUE BUSCAS NO SE ENCUENTRA\n"<<endl;
			}	
		tempo= tempo->sig;
	}
}

void quitarProducto(){
if (kbza == NULL) {
        cout << "\nAQUI NO HAY NADA\n"<< endl;
        return;
    }

    int idBuscar;
    cout << "\nINGRESE EL ID DEL PRODUCTO QUE QUIERE BQUITAR DEL INVENTARIO: ";
    cin >> idBuscar;

    producto *temp = kbza;
    producto *anterior = NULL;

    while (temp != NULL) {
        if (temp->idp == idBuscar) { // Otra comparacion
            if (anterior == NULL) { // Si es el primer nodo
                kbza = temp->sig;
            } else {
                anterior->sig = temp->sig;
            }
            cout << "\nPRODUCTO ELIMINADO\n"<< endl;
            free(temp); // Libera memoria porque se saca un producto
            return;
        }
        anterior = temp;
        temp = temp->sig;
    }

    cout << "\nPRODUCTO NO ENCONTRADO\n"<<idBuscar<<endl;
}

void sumaPrecios(){
	producto *tempo2= kbza; int sumaPrecios=0;

	while (kbza && tempo2!= NULL)
	{
		sumaPrecios+= tempo2->precio*tempo2->cantidad;
		tempo2= tempo2->sig;
	} cout<<"\nLA SUMA TOTAL DEL INVENTARIO ES DE: "<<sumaPrecios<<" PESOS"<<endl;

	if (kbza==NULL)
	{
		cout<<"\nNO HAY NADA EN EL INVENTARIO\n"<<endl;
	}
}

void promedioPrecios(){
	producto* tempo3= kbza; int sumaPre=0, sumaCantidad=0; float prom=0;
	while (kbza && tempo3!= NULL)
	{
		sumaPre+= tempo3->precio*tempo3->cantidad;
		sumaCantidad+= tempo3->cantidad;

		prom= sumaPre/sumaCantidad;

		tempo3= tempo3->sig;

	} cout<<"\nEL PROMEDIO DE PRECIOS DEL INVENTARIO ES DE: "<<prom<<" PESOS"<<endl;

	if (kbza==NULL)
	{
		cout<<"\nNO HAY NADA EN EL INVENTARIO\n"<<endl;
	}
}

void venderProducto(){
	int idBusc=0, cantiVenta=0, pagoFact=0;

	if(kbza== NULL){
		cout<<"NO HAY PRODUCTOS EN INVENTARIO"<<endl;
	}else{
		cout<<"\nINGRESE EL ID DEL PRODUCTO QUE DESEA VENDER: "<<endl; cin>>idBusc;
	producto* tempo4= kbza; producto *anterior= NULL;

		if(tempo4->idp== idBusc){
			cout << "\nSU PRODUCTO HA SIDO ENCONTRADO, SUS DATOS SON:\n" << endl;
            cout << "ID: " << tempo4->idp<<endl;
            cout << "NOMBRE: " << tempo4->nombre<<endl;
            cout << "PRECIO: " << tempo4->precio<<endl;
            cout << "CANTIDAD: " << tempo4->cantidad<<endl;

			cout<<"\nCUANTAS UNIDADES QUIERE VENDER?: "<<endl; cin>>cantiVenta;

			if(cantiVenta<= tempo4->cantidad){
				pagoFact= cantiVenta * tempo4->precio;
				cout<<"\nPREPARE LOS VERDES, DEBE PAGAR: "<<pagoFact<<" PESOS\n"<<endl;

				tempo4->cantidad -= cantiVenta;
			if (tempo4->cantidad==0){
				if (anterior==NULL){
					kbza= tempo4->sig;
				} else{
					anterior->sig= tempo4->sig;
			} free(tempo4);
		} 
	}else{
		cout<<"\nNO HAY PARA TANTO, SURTA EL NEGOCIO\n"<<endl;
	} 
				
		}else{
				cout<<"\nEL PRODUCTO QUE BUSCAS NO SE ENCUENTRA, AQUI NO VENDEMOS ESO\n"<<endl;
			} anterior= tempo4; tempo4= tempo4->sig; 
	}
}


int main (){
    int op=0;
	
	do{
		cout<<"\n\n\tHOLA JOVEN, QUE QUIERE HACER?\n"<<endl;
		cout<<"1. REGISTRAR UN PRODUCTO"<<endl;
		cout<<"2. VER INVENTARIO DE PRODUCTOS"<<endl;
		cout<<"3. BUSCAR UN PRODUCTO EN EL INVENTARIO"<<endl;
		cout<<"4. QUITAR UN PRODUCTO DEL INVENTARIO"<<endl;
		cout<<"5. VER EL PRECIO ACUMULADO DE LOS PRODUCTOS REGISTRADOS"<<endl;
		cout<<"6. VER EL PROMEDIO DE LOS PRODUCTOS REGISTRADOS"<<endl;
		cout<<"7. VENDER PRODUCTOS"<<endl;
		cout<<"8. ABANDONAR LOCAL\n"<<endl;
		cin>>op; system("cls");
		
		switch (op){
			case 1: regisProducto(); break;
			case 2: verInventario(); break;
			case 3: buscarProducto(); break;
			case 4: quitarProducto(); break;
			case 5: sumaPrecios(); break;
			case 6: promedioPrecios(); break;
			case 7: venderProducto(); break;
			case 8: cout<<"\n\nFIN DEL SERVICIO\n"<<endl; break;
			default: cout<<"\n\nJOVEN, ELIJA BIEN, SU OPCION NO EXISTE"<<endl; break;
		}
	}while (op!=8);

	system ("pause");
    return 0;
}
