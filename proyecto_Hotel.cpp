#include <iostream>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>

using namespace std;
void gotoxy(int x, int y){
COORD coordinate;
coordinate.X = x;
coordinate.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

struct Habitacion{
	string numHabitacion;
	string tipoHabitacion;
	float precioBase;
	int vistaAlMar;
	int numCamas;
	Habitacion *sgt;
	Habitacion *ant;
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
	Habitacion *datosHabitacion;
	Cliente *datosClientes;
	string fecha_in;
	string fecha_out;
	string temporada;
	int n_dias;
	float precioFinal;
	string estado;
	Reserva *sgt;
	Reserva *ant;
};
struct Factura{
	Reserva reserva;
	Reserva totalDatos;
	float gastosBar;
	float valorTotal;
	Factura *sgt;
	Factura *ant;
};
//Funciones de menus
int menuHabitacion();
int menuBar();
int menuCliente();
int menuPrincipal();
int menuReservas();
//Funciones de operaciones
void opcionesHabitacion(int op, Habitacion *&pcabHab, Habitacion *&pfinHab);
void opcionesCliente(int op, Cliente *&pcabC, Cliente *&pfinC);
void opcionesPrincipal(int op, Habitacion *&pcabHab, Habitacion *&pfinHab, Cliente  *&pcabC, Cliente *&pfinC, Reserva *&pcabRes, Reserva *&pfinRes);
void opcionesReservas(int op, Reserva *&pcabRes, Reserva *&pfinRes, Cliente *&pcabC, Cliente *&pfinC, Habitacion *&pcabHab, Habitacion *&pfinHab);
void opcionesBar(int op);
//Funciones de Habitaciones
void registrarHabitacion(Habitacion *&pcabHab, Habitacion *&pfinHab);
Habitacion *buscarHabitacion(string numHabitacion, Habitacion *pcabHab);
void modificarHabitacion(Habitacion *dirHabitacion);
void eliminarHabitacion(Habitacion *&pcabHab, Habitacion *&pfinHab, Habitacion *&dirHabitacion);
void listarHabitaciones (Habitacion *pcabHab);

//Funciones de Clientes
void InsertarCliente(Cliente *&pcabC, Cliente *&pfinC);
Cliente *BuscarCliente(Cliente *&pcabC, string cedulabuscar);
void PresentarCliente(Cliente *dirNodoCliente);
void ModificarCliente(Cliente *dirNodoCliente);
void EliminarCliente(Cliente *dirNodoCliente, Cliente *&pcabC, Cliente *&pfinC);
void listarClientes(Cliente *&pcabC, Cliente *&pfinC);
//Funciones de Reservas
void ReservarHabitacion(Reserva *&pcabRes, Reserva *&pfinRes, Cliente *&pcabC, Cliente *&pfinC, Habitacion *&pcabHab, Habitacion *&pfinHab);
//Funciones de Bar

//Funcion principal
int main(){
	setlocale(LC_CTYPE, "Spanish");
	int op;
	Cliente *pcabC = NULL, *pfinC = NULL;
	Habitacion *pcabHab = NULL, *pfinHab = NULL;
	Reserva *pcabRes =NULL , *pfinRes = NULL;
	do {
		op = menuPrincipal();
		opcionesPrincipal(op, pcabHab, pfinHab, pcabC, pfinC, pcabRes, pfinRes);
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
		system ("cls");
		cout << "***** MENU DE HABITACIONES *****" << endl;
		cout << " 1: Insertar habitación" << endl;
		cout << " 2: Modificar habitación" << endl;
		cout << " 3: Eliminar habitación" << endl;
		cout << " 4: Listar habitaciones" << endl;
		cout << " 5: Volver al menú principal" << endl;
		cout << "Elija la opción: ";
		cin >> op;
	} while (op < 1 || op > 5);
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

void opcionesHabitacion(int op, Habitacion *&pcabHab, Habitacion *&pfinHab){
	Habitacion *dirHabitacion;
	string numHabitacion;
	switch(op){
		case 1: 
			// Insertar habitación
			registrarHabitacion(pcabHab, pfinHab);
			break;
		case 2: 
			// Modificar habitación
			cout << "Ingrese el número de habitación a MODIFICAR: ";
			cin >> numHabitacion;
			dirHabitacion = buscarHabitacion(numHabitacion, pcabHab);
			if(dirHabitacion == NULL){
				cout << "Aún no ha registrado habitaciones..." << endl;
			} else {
				modificarHabitacion(dirHabitacion);
			}
			break;
		case 3: 
			// Eliminar habitación
			cout << "Ingrese el número de habitación a ELIMINAR: ";
			cin >> numHabitacion;
			dirHabitacion = buscarHabitacion(numHabitacion, pcabHab);
			if(dirHabitacion == NULL){
				cout << "Aún no ha registrado habitaciones..." << endl;
			} else {
				eliminarHabitacion(pcabHab, pfinHab, dirHabitacion);
			}
			break;
		case 4: 
			// Listar habitaciones
			if(pcabHab == NULL){
				cout << "Aún no se ha registrado habitaciones..." << endl;
			} else {
				listarHabitaciones (pcabHab);
			}
			break;
		case 5: 
			// Volver al menú principal
			cout << "Volviendo..." << endl;
			break;
	}
	getch();
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
void opcionesPrincipal(int op, Habitacion *&pcabHab, Habitacion *&pfinHab, Cliente  *&pcabC, Cliente *&pfinC, Reserva *&pcabRes, Reserva *&pfinRes){
	int resp = 1;
	switch(op){
		case 1: 
			do {
				op = menuHabitacion();
				opcionesHabitacion(op, pcabHab, pfinHab);
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
				opcionesReservas(op, pcabRes, pfinRes, pcabC, pfinC, pcabHab, pfinHab);
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
void opcionesReservas(int op, Reserva *&pcabRes, Reserva *&pfinRes, Cliente *&pcabC, Cliente *&pfinC, Habitacion *&pcabHab, Habitacion *&pfinHab){
	switch(op){
		case 1: // Reservar
			ReservarHabitacion(pcabRes, pfinRes, pcabC, pfinC, pcabHab, pfinHab);
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
//Funciones de Habitaciones
void registrarHabitacion(Habitacion *&pcabHab, Habitacion *&pfinHab){
	int tipo;
	Habitacion *nuevaHab = new Habitacion();
	cout << "Ingrese el número de habitación: ";
	cin >> nuevaHab->numHabitacion;
	cout << "Ingrese el tipo de habitación. Sencilla (1), Matrimonial (2), Múltiple (3): ";
	cin >> tipo;
	switch(tipo){
		case 1: nuevaHab->tipoHabitacion = "Sencilla"; break;
		case 2: nuevaHab->tipoHabitacion = "Matrimonial"; break;
		case 3: nuevaHab->tipoHabitacion = "Múltiple"; break;
	}
	if (tipo == 3){
		cout << "Cantidad de camas: ";
		cin >> nuevaHab->numCamas;
	}
	cout << "Ingrese el precio base: ";
	cin >> nuevaHab->precioBase;
	cout << "¿Su habitación tiene vista al mar? Si (1), No (0): ";
	cin >> nuevaHab->vistaAlMar;
	nuevaHab->sgt = NULL;
	
	if (pcabHab == NULL){
		pcabHab = nuevaHab;
		pfinHab = nuevaHab;
	} else {
		pcabHab->sgt = nuevaHab;
		nuevaHab->ant = pcabHab;
		pfinHab = nuevaHab;
	}
}
Habitacion *buscarHabitacion(string numHabitacion, Habitacion *pcabHab){
	while(pcabHab != NULL){
		if(pcabHab->numHabitacion == numHabitacion){
			return pcabHab;
		}
		pcabHab = pcabHab->sgt;
	}
	return NULL;
}
void modificarHabitacion(Habitacion *dirHabitacion){
	int op, resp;
	int tipo;
	
	do{
		system("cls");
		cout << "\n 1: Numero de habitación" << endl;
		cout << " 2: Tipo de habitación " << endl;
		cout << " 3: Precio base" << endl;
		cout << " 4: Vista al mar" << endl;
		cout << " 5: SALIR" << endl;
		cout << "Elija el campo que desea MODIFICAR: ";
		cin >> op;
		
		switch (op){
			case 1:
				cout << "Actualice el número de habitación: ";
				cin >> dirHabitacion->numHabitacion;
				break;
			case 2:
				cout << "Actualice el tipo de habitación. Sencilla (1), Matrimonial (2), Múltiple (3): ";
				cin >> tipo;
				switch(tipo){
					case 1: dirHabitacion->tipoHabitacion = "Sencilla"; break;
					case 2: dirHabitacion->tipoHabitacion = "Matrimonial"; break;
					case 3: dirHabitacion->tipoHabitacion = "Múltiple"; break;
				}
				if(tipo == 3){
					cout << "Cantidad de camas: ";
					cin >> dirHabitacion->numCamas;
				}
				break;
			case 3:
				cout << "Actualice el precio base: ";
				cin >> dirHabitacion->precioBase;
				break;
			case 4:
				cout << "Actualice si tiene vista al mar: ";
				cin >> dirHabitacion->vistaAlMar;
				(dirHabitacion->vistaAlMar == 1 ? "Sí" : "No");
				break;
			case 5:
				cout << "¿Está seguro? Si (1), No (0)";
				cin >> resp;
				cout << "Saliendo...";
				break;
		}
		cout << "¿Desea modificar otro campo? Si (1), No (0): ";
		cin >> resp;
	}while (resp == 1);
}
void eliminarHabitacion(Habitacion *&pcabHab, Habitacion *&pfinHab, Habitacion *&dirHabitacion){
	if (pcabHab == pfinHab){
		pcabHab = NULL;
		pfinHab = NULL;
		delete (dirHabitacion);
	} else {
		if(pcabHab == dirHabitacion){
			pcabHab = dirHabitacion->sgt;
			pcabHab->ant = NULL;
			delete(dirHabitacion);
		}else if(dirHabitacion->sgt != NULL){
			dirHabitacion->ant->sgt = dirHabitacion->sgt;
			dirHabitacion->sgt->ant = dirHabitacion->ant;
			delete(dirHabitacion);
		}else{
			pfinHab = dirHabitacion->ant;
			pfinHab->sgt = NULL;
			delete(dirHabitacion);
		}
	}
}
void listarHabitaciones (Habitacion *pcabHab){
	
	while (pcabHab != NULL){
		cout << "Número de habitación: " << pcabHab->numHabitacion << endl;
		cout << "Tipo de habitación: " << pcabHab->tipoHabitacion << endl;
		if (pcabHab->tipoHabitacion == "Múltiple"){
			cout << "**Cantidad de camas: " << pcabHab->numCamas << endl;
		}
		cout << "Precio base: " << pcabHab->precioBase << endl;
		cout << "Vista al mar: " << (pcabHab->vistaAlMar == 1 ? "Sí" : "No") << endl;
		
		pcabHab = pcabHab->sgt;
	}
}
//Funciones de clientes
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
//Funciones de Reservas
void ReservarHabitacion(Reserva *&pcabRes, Reserva *&pfinRes, Cliente *&pcabC, Cliente *&pfinC, Habitacion *&pcabHab, Habitacion *&pfinHab) {
	system("cls");
    Reserva *nodoReserva = new Reserva();
    Cliente *dirNodoCliente;
    Habitacion *dirNodoHabitacion;
    string cedula, numeroH;

    gotoxy(4, 1);	cout << "HOTEL TU DESCANSO";	
    gotoxy(5, 3);   cout << "Cedula: ";				gotoxy(15,3) cin >> cedula;

    dirNodoCliente = BuscarCliente(pcabC, cedula);
    if (dirNodoCliente == NULL) {
        InsertarCliente(pcabC, pfinC);
        dirNodoCliente = BuscarCliente(pcabC, cedula); // Vuelve a buscar después de insertar
    }
    
    cout << "Ingrese el numero de Habitacion: ";
    cin >> numeroH;
    dirNodoHabitacion = buscarHabitacion(numeroH, pcabHab);
    
    if (dirNodoHabitacion == NULL) {
        cout << "La habitacion no existe :c " << endl;
        delete nodoReserva; // Liberar memoria si no se utiliza
        return; // Salir de la función si no hay habitación
    }

    nodoReserva->datosClientes = dirNodoCliente;
    nodoReserva->datosHabitacion = dirNodoHabitacion;
    
    // Aquí puedes agregar la lógica para enlazar el nodoReserva a la lista de reservas
    // (e.g., InsertarReserva(pcabRes, pfinRes, nodoReserva);)
}
