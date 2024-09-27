#include <iostream>
#include <string.h>
#include <locale.h>
#include <conio.h>

using namespace std;

struct Habitacion{
	int numHabitacion;
	int tipoHabitacion;
	float precioBase;
	int vistaAlMar;
	int numCamas;
};
struct Cliente{
	string nombres;
	string cedula;
	string telefono;
	string email;
	Cliente *sgt;
	Cliente *ant;
};
struct Reserva{
	Habitacion datosHabitacion;
	Cliente datosClientes;
	string fecha_in;
	string fecha_out;
	string temporada;
	int n_dias;
	float precioFinal;
};
struct Factura{
	Reserva totalDatos;
	float gastosBar;
	float valorTotal;
	
};
//Funciones de menus
int menuHabitacion();
int menuBar();
int menuCliente();
int menuPrincipal();
int menuReservas();
//Funciones de operaciones
void opcionesHabitacion(int op);
void opcionesCliente(int op, Cliente *&pcabC, Cliente *&pfinC);
void opcionesPrincipal(int op, Cliente  *&pcabC, Cliente *&pfinC);
void opcionesReservas(int op);
void opcionesBar(int op);
//Funciones de Habitaciones

//Funciones de Clientes
void InsertarCliente(Cliente *&pcabC, Cliente *&pfinC);
Cliente *BuscarCliente(Cliente *&pcabC, string cedulabuscar);
void PresentarCliente(Cliente *dirNodoCliente);
void ModificarCliente(Cliente *dirNodoCliente);
void EliminarCliente(Cliente *dirNodoCliente, Cliente *&pcabC, Cliente *&pfinC);
void listarClientes(Cliente *&pcabC, Cliente *&pfinC);
//Funciones de Reservas

//Funciones de Bar
int main(){
	setlocale(LC_CTYPE, "Spanish");
	int op;
	Cliente *pcabC = NULL, *pfinC = NULL;
	do {
		op = menuPrincipal();
		opcionesPrincipal(op, pcabC, pfinC);
	} while (op != 5);
	
	getch();
	return 0;
}
int menuPrincipal(){
	int op;
	do{
		system("cls");
		cout << "***** MENU PRINCIPAL *****" << endl;
		cout << " 1: Gestionar Habitaciones" << endl;
		cout << " 2: Gestionar Clientes" << endl;
		cout << " 3: Gestionar Reservas" << endl;
		cout << " 4: Gestionar Bar" << endl;
		cout << " 5: Salir del programa" << endl;
		cout << "Elija la opcion: ";
		cin >> op;
	} while (op < 1 || op > 5);
	return op;
}
int menuCliente(){
	int op;
	do {
		system("cls");
		cout << "***** MENU CLIENTES *****" << endl;
		cout << " 1: Insertar Cliente" << endl;
		cout << " 2: Modificar un cliente" << endl;
		cout << " 3: Eliminar un cliente" << endl;
		cout << " 4: Listar clientes" << endl;
		cout << " 5: Volver al menú principal" << endl;
		cout << "Elija la opción: ";
		cin >> op;
	} while (op < 1 || op > 5); // Verificación de opción válida
	return op;
}
int menuReservas(){
	int op;
	do {
		system("cls");
		cout << "***** MENU DE RESERVAS *****" << endl;
		cout << " 1: Reservar" << endl;
		cout << " 2: Buscar reserva" << endl;
		cout << " 3: Finalizar reserva y entregar factura" << endl;
		cout << " 4: Volver al menú principal" << endl;
		cout << "Elija la opción: ";
		cin >> op;
	} while (op < 1 || op > 4); // Verificación de opción válida
	return op;
}
int menuHabitacion(){
	int op;
	do {
		system("cls");
		cout << "***** MENU DE HABITACIONES *****" << endl;
		cout << " 1: Insertar habitación" << endl;
		cout << " 2: Modificar habitación" << endl;
		cout << " 3: Eliminar habitación" << endl;
		cout << " 4: Listar habitaciones" << endl;
		cout << " 5: Volver al menú principal" << endl;
		cout << "Elija la opción: ";
		cin >> op;
	} while (op < 1 || op > 5); // Verificación de opción válida
	return op;
}
int menuBar(){
	int op;
	do {
		system("cls");
		cout << "***** MENU DE BAR *****" << endl;
		cout << " 1: Ingresar el valor de consumo a cliente" << endl;
		cout << " 2: Volver al menú principal" << endl;
		cout << "Elija la opción: ";
		cin >> op;
	} while (op < 1 || op > 2); // Verificación de opción válida
	return op;
}

void opcionesHabitacion(int op){
	switch(op){
		case 1: 
			// Insertar habitación
			break;
		case 2: 
			// Modificar habitación
			break;
		case 3: 
			// Eliminar habitación
			break;
		case 4: 
			// Listar habitaciones
			break;
		case 5: 
			// Volver al menú principal
			break;
	}
}
void opcionesCliente(int op, Cliente *&pcabC, Cliente *&pfinC){
	Cliente *dirNodoCliente;
	string cedulabuscar;
	switch(op){
		case 1: // Insertar Cliente
			InsertarCliente(pcabC, pfinC);
			break;
		case 2: // Modificar un cliente
			cout << "Ingrese el numero de cedula del cliente: ";
			cin >> cedulabuscar;
			dirNodoCliente = BuscarCliente(pcabC, cedulabuscar);
			if (dirNodoCliente == NULL){
				cout << "El cliente no existe :c " << endl; 
			}else {
				ModificarCliente(dirNodoCliente);
			}
			break;
		case 3: // Eliminar un cliente
			cout << "Ingrese el numero de cedula del cliente: ";
			cin >> cedulabuscar;
			dirNodoCliente = BuscarCliente(pcabC, cedulabuscar);
			if (dirNodoCliente == NULL){
				cout << "El cliente no existe :c " << endl; 
			}else {
				EliminarCliente(dirNodoCliente, pcabC, pfinC);
			}
			break;
		case 4: // Listar clientes
			listarClientes(pcabC, pfinC);
			break;
		case 5: 
			// Volver al menú principal
			break;
	}
}
void opcionesPrincipal(int op, Cliente  *&pcabC, Cliente *&pfinC){
	int resp = 1;
	switch(op){
		case 1: 
			do {
				op = menuHabitacion();
				opcionesHabitacion(op);
				cout << "Dese Realizar otro proceso SI(1), No(0): ";
				cin >> resp;
			} while (resp == 1);
			break;
		case 2: 
			do{
				op = menuCliente();
				opcionesCliente(op, pcabC, pfinC);
				cout << "Desea Realizar otro proceso Si(1), No(0): ";
				cin >> resp;				
			} while (resp == 1);
			break;
		case 3: 
			do{
				op = menuReservas();
				opcionesReservas(op);
				cout << "Desea realizar otro proceso Si(1), No(0): ";
				cin >> resp;				
			} while (resp == 1);
			break;
		case 4: 
			do{
				op = menuBar();
				opcionesBar(op);
				cout << "Desea realizar otro proceso Si(1), No(0)";
				cin >> resp;
			} while (resp == 1);
			break;
		case 5: 
			cout << "Saliendo del programa..." << endl;
			break;
	}
}
void opcionesReservas(int op){
	switch(op){
		case 1: 
			// Reservar
			break;
		case 2: 
			// Buscar reserva
			break;
		case 3: 
			// Finalizar reserva y entregar factura
			break;
		case 4: 
			// Volver al menú principal
			break;
	}
}
void opcionesBar(int op){
	switch(op){
		case 1: 
			// Ingresar consumo a cliente
			break;
		case 2: 
			// Volver al menú principal
			break;
	}
}

void InsertarCliente(Cliente *&pcabC, Cliente *&pfinC){
	Cliente *nodoCliente =new Cliente();
	fflush(stdin);
	cout << "Ingrese los nombres del cliente: ";
	getline(cin, nodoCliente->nombres);
	cout << "Ingrese el numero de Cedula del cliente: ";
	cin >> nodoCliente->cedula;
	cout << "Ingrese el email del cliente: ";
	cin >> nodoCliente->email;
	cout << "Ingrese el telefono del cliente: ";
	cin >> nodoCliente->telefono;
	nodoCliente->sgt = NULL;
	nodoCliente->ant = NULL;
	
	if(pcabC == NULL){
		pcabC = nodoCliente;
		pfinC = nodoCliente;
	}else{
		pfinC->sgt = nodoCliente;
		nodoCliente->ant = pfinC;
		pfinC = nodoCliente;
	}
}
Cliente *BuscarCliente(Cliente *&pcabC, string cedulabuscar){
	Cliente *actual=pcabC;
	while(actual != NULL){
		if(actual->cedula == cedulabuscar){
			return actual;
		}
		actual = actual->sgt;
	}
	return NULL;
}
void PresentarCliente(Cliente *dirNodoCliente){
	cout << "Nombres: " << dirNodoCliente->nombres << endl;
	cout << "Cedula: " << dirNodoCliente->cedula << endl;
	cout << "Email: " << dirNodoCliente->email << endl;
	cout << "Telefono: " << dirNodoCliente->telefono << endl;
	cout << endl;
}
void ModificarCliente(Cliente *dirNodoCliente){
	int op, resp;
	do{
		PresentarCliente(dirNodoCliente);
		cout << "Que campo desea modificar: " << endl;
		cout << " 1: Nombres" << endl;
		cout << " 2: Cedula" << endl;
		cout << " 3: Email" << endl;
		cout << " 4: Telefono" << endl;
		cout << "Elija la opcion: " ;
		cin >> op;
		switch (op){
			case 1:
				fflush(stdin);
				cout << "Ingrese los nuevos nombres: ";
				getline(cin,dirNodoCliente->nombres);
				break;
			case 2:
				cout << "Ingrese la nueva cedula: ";
				cin >> dirNodoCliente->cedula;
				break;
			case 3:
				cout << "Ingrese el nuevo email: ";
				cin >> dirNodoCliente->email;
				break;
			case 4:
				cout << "Ingrese el nuevo Telefono: ";
				cin >> dirNodoCliente->telefono;
				break;
		}
		cout << "Desea modificar otro campo Si(1), No(0): ";
		cin >> resp;
	} while (resp == 1);
}
void EliminarCliente(Cliente *dirNodoCliente, Cliente *&pcabC, Cliente *&pfinC){
	if(pcabC == pfinC){
		pcabC = NULL;
		pfinC = NULL;
		delete(dirNodoCliente);
	}else{
		if(pcabC == dirNodoCliente){//caso 1: Eliminar el primer nodo
		    pcabC=dirNodoCliente->sgt;
			pcabC->ant=NULL;
			delete(dirNodoCliente);
		}else{
			 if(dirNodoCliente->sgt!=NULL){//caso 2: eliminar en la mitad
			 	dirNodoCliente->ant->sgt = dirNodoCliente->sgt;
			 	dirNodoCliente->sgt->ant=dirNodoCliente->ant;
			 	delete(dirNodoCliente);
			}else{//caso 3: al final de la lista
				pfinC=dirNodoCliente->ant;
				pfinC->sgt=NULL;
				delete(dirNodoCliente);
			}
		}
	}
	cout << "Se ha eliminado con exito." << endl;
}
void listarClientes(Cliente *&pcabC, Cliente *&pfinC){
	Cliente *actual = pcabC;
	if (pcabC == NULL) {
        cout<<"La lista está vacía."<<endl;
    }else{
    	cout<<"Lista de clientes:"<<endl;
		while(actual!=NULL){
			cout<<"Nombre: " << actual->nombres<<endl;
			cout<<"Cédula: " << actual->cedula<<endl;
			cout<<"Telefono: " << actual->telefono<<endl;
			cout<<"Mail: " << actual->email<<endl<<endl;
			actual = actual->sgt;
		}
	}	
}
