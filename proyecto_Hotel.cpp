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
	int numCamas = 1;
	int estado = 0;
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
	float subtotal;
	float total;
	int estado = 0;
	string numeroR;
	Reserva *sgt;
	Reserva *ant;
	float iva=0.15;
};
struct Factura{
	Reserva *reservacion;
	float gastosBar;
	string estado;
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
void opcionesPrincipal(int op, Habitacion *&pcabHab, Habitacion *&pfinHab, Cliente  *&pcabC, Cliente *&pfinC, Reserva *&pcabRes, Reserva *&pfinRes, Factura *&cabFac,Factura *&finFac);
void opcionesReservas(int op, Reserva *&pcabRes, Reserva *&pfinRes, Cliente *&pcabC, Cliente *&pfinC, Habitacion *&pcabHab, Habitacion *&pfinHab,Factura *&cabFac,Factura *&finFac);
void opcionesBar(int op,Factura *&cabFac,Reserva *&pcabRes);
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
void ReservarHabitacion(Reserva *&pcabRes, Reserva *&pfinRes, Cliente *&pcabC, Cliente *&pfinC, Habitacion *&pcabHab, Habitacion *&pfinHab, Factura *&cabFac, Factura *&finFac) ;
Cliente *Fun_InsertarCliente(Cliente *&pcabC, Cliente *&pfinC, string cedula);
void RecuperarCliente(Cliente *dirNodoCliente);
void RecuperarHabitacion(Habitacion *dirNodoHabitacion);
Reserva *BuscarReserva(Reserva *&pcabRes, string numeroR);
void PresentarReserva(Factura *dirNodo);
Factura *Fun_BuscarReserva(Factura *&pcabFac, string cedula);
void finalizarReserva(Factura *&dirNodo,Factura *&cabFac,Factura *&finFac);
void PresentarComprobante(Factura *dirNodo);
void finalizarReserva(Factura *&dirNodo, Factura *&cabFac, Factura *&finFac);
//Funciones de Bar
void IngresarConsumoBar(Reserva *&pcabRes, Factura *&cabFac);
//Funcion principal
int main(){
	setlocale(LC_CTYPE, "Spanish");
	int op;
	Cliente *pcabC = NULL, *pfinC = NULL;
	Habitacion *pcabHab = NULL, *pfinHab = NULL;
	Reserva *pcabRes =NULL , *pfinRes = NULL;
	Factura *cabFac=NULL, *finFac=NULL;
	do {
		op = menuPrincipal();
		opcionesPrincipal(op, pcabHab, pfinHab, pcabC, pfinC, pcabRes, pfinRes,cabFac,finFac);
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
		cout << " 2: Comprobar reserva" << endl;
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
void opcionesPrincipal(int op, Habitacion *&pcabHab, Habitacion *&pfinHab, Cliente  *&pcabC, Cliente *&pfinC, Reserva *&pcabRes, Reserva *&pfinRes,Factura *&cabFac,Factura *&finFac){
	int resp = 1;
	switch(op){
		case 1: 
			do {
				op = menuHabitacion();
				opcionesHabitacion(op, pcabHab, pfinHab);
				cout << "\nDese Realizar otro proceso SI(1), No(0): ";
				cin >> resp;
			} while (resp == 1);
			break;
		case 2: 
			do{
				op = menuCliente();
				opcionesCliente(op, pcabC, pfinC);
				cout << "\nDesea Realizar otro proceso Si(1), No(0): ";
				cin >> resp;				
			} while (resp == 1);
			break;
		case 3: 
			do{
				op = menuReservas();
				opcionesReservas(op, pcabRes, pfinRes, pcabC, pfinC, pcabHab, pfinHab,cabFac,finFac);
				cout << "\nDesea realizar otro proceso Si(1), No(0): ";
				cin >> resp;				
			} while (resp == 1);
			break;
		case 4: 
			do{
				op = menuBar();
				opcionesBar(op,cabFac,pcabRes);
				cout << "\nDesea realizar otro proceso Si(1), No(0)";
				cin >> resp;
			} while (resp == 1);
			break;
		case 5: 
			cout << "Saliendo del programa..." << endl;
			break;
	}
}
void opcionesReservas(int op, Reserva *&pcabRes, Reserva *&pfinRes, Cliente *&pcabC, Cliente *&pfinC, Habitacion *&pcabHab, Habitacion *&pfinHab,Factura *&cabFac,Factura *&finFac){
	string numeroR, cedula;
	Cliente *dirNodoCliente;
	Factura *dirNodo;
	switch(op){
		case 1: // Reservar
			ReservarHabitacion(pcabRes, pfinRes, pcabC, pfinC, pcabHab, pfinHab, cabFac, finFac);
			break;
		case 2: // Comprobar reserva
		    cout << "Ingrese la cédula del cliente: ";
		    cin >> cedula;
		    dirNodoCliente = BuscarCliente(pcabC, cedula);
		    if (dirNodoCliente == NULL) {
		        cout << "El cliente no existe" << endl;
		    } else {
		        dirNodo = Fun_BuscarReserva(cabFac, cedula);
		        if (dirNodo == NULL) {
		            cout << "No existe la reserva" << endl;
		        } else {
		            PresentarComprobante(dirNodo);
		        }
		    }
		    break;
		case 3: 
				// Finalizar  reserva
				cout << "Ingrese la cedula del cliente: ";
			cin >> cedula;
			dirNodoCliente = BuscarCliente(pcabC, cedula);
			if(dirNodoCliente == NULL){
				cout << "El cliente no existe" << endl;
			}else{			
				dirNodo = Fun_BuscarReserva(cabFac, cedula);
				if (dirNodo == NULL){
					cout << "No existe la reserva" << endl;
				}else{
					if (dirNodo->reservacion->estado == 1){
						finalizarReserva(dirNodo, cabFac, finFac);
					}else{
						cout <<  "La reserva no esta activa" << endl;
					}
				}
			}
			break;
		case 4: 
			// Volver al menú principal
			break;
	}
}

void opcionesBar(int op,Factura *&cabFac,Reserva *&pcabRes){
	switch(op){
		case 1: 
			IngresarConsumoBar(pcabRes, cabFac);
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
Cliente *Fun_InsertarCliente(Cliente *&pcabC, Cliente *&pfinC, string cedula){
	Cliente *nodoCliente = new Cliente();
	nodoCliente->cedula = cedula;
	fflush(stdin);
	gotoxy(5,5); cout << "Nombres: ";		gotoxy(15, 5); getline(cin, nodoCliente->nombres);
	gotoxy(5,6); cout << "Telefono: ";		gotoxy(15, 6); cin >> nodoCliente->telefono;
	gotoxy(5,7); cout << "Email: ";			gotoxy(15, 7); cin >> nodoCliente->email;
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
	return nodoCliente;
}
void RecuperarCliente(Cliente *dirNodoCliente){
	gotoxy(5,5); cout << "Nombres: ";		gotoxy(15, 5); cout << dirNodoCliente->nombres;
	gotoxy(5,6); cout << "Telefono: ";		gotoxy(15, 6); cout << dirNodoCliente->telefono;
	gotoxy(5,7); cout << "Email: ";			gotoxy(15, 7); cout << dirNodoCliente->email;
}
void RecuperarHabitacion(Habitacion *dirNodoHabitacion){
	
	gotoxy(40, 5); cout << "Tipo: "; gotoxy(60, 5); cout << dirNodoHabitacion->tipoHabitacion;
	gotoxy(40, 6); cout << "Camas: "; gotoxy(60,6); cout << dirNodoHabitacion->numCamas;
	gotoxy(40, 7); cout << "Vista al mar: "; if (dirNodoHabitacion->vistaAlMar == 0 ){
		gotoxy(60,7); cout << "No";
	}else{
		gotoxy(60,7); cout << "Si";
	}
	gotoxy(40, 8); cout << "Precio"; gotoxy(60, 8); cout << dirNodoHabitacion->precioBase;
}
// Función para finalizar la reserva
void finalizarReserva(Factura *&dirNodo, Factura *&cabFac, Factura *&finFac) {
    PresentarReserva(dirNodo);

    dirNodo->reservacion->estado = 0; 
	dirNodo->reservacion->datosHabitacion->estado = 0;
}

// Función para reservar una nueva habitación
void ReservarHabitacion(Reserva *&pcabRes, Reserva *&pfinRes, Cliente *&pcabC, Cliente *&pfinC, Habitacion *&pcabHab, Habitacion *&pfinHab, Factura *&cabFac, Factura *&finFac) {
    system("cls");
    Reserva *nodoReserva = new Reserva(); 
    Factura *nodoFac = new Factura();
    Cliente *dirNodoCliente;
    Habitacion *dirNodoHabitacion;
    string cedula, numeroH;
    float incremento = 0.0, subtotal = 0.0, total = 0.0;

    nodoFac->gastosBar = 0; 
    gotoxy(4, 1); cout << "HOTEL TU DESCANSO";    
    gotoxy(4, 2); cout << "# Reserva: "; gotoxy(15, 2); cin >> nodoReserva->numeroR;     
    gotoxy(5, 4); cout << "Cedula: "; gotoxy(15, 4); cin >> cedula;

    dirNodoCliente = BuscarCliente(pcabC, cedula);
    if (dirNodoCliente == NULL) {
        dirNodoCliente = Fun_InsertarCliente(pcabC, pfinC, cedula);
    } else {
        RecuperarCliente(dirNodoCliente);
    }

    gotoxy(40, 2); cout << "Fecha de entrada: "; gotoxy(60, 2); cin >> nodoReserva->fecha_in;
    gotoxy(90, 2); cout << "Fecha de salida: "; gotoxy(110, 2); cin >> nodoReserva->fecha_out; 
    gotoxy(40, 4); cout << "# Habitacion: "; gotoxy(60, 4); cin >> numeroH;

    dirNodoHabitacion = buscarHabitacion(numeroH, pcabHab);
    if (dirNodoHabitacion == NULL) {
        cout << "La habitación no existe." << endl;
        delete nodoReserva;
        delete nodoFac;
        return;
    }

    if (dirNodoHabitacion->estado == 0) {
        RecuperarHabitacion(dirNodoHabitacion);
        dirNodoHabitacion->estado = 1; 
    } else {
        cout << "La habitación no está disponible." << endl;
        delete nodoReserva;
        delete nodoFac;
        return;
    }

    nodoReserva->datosClientes = dirNodoCliente;
    nodoReserva->datosHabitacion = dirNodoHabitacion;

    gotoxy(5, 9); cout << "Temporada: "; gotoxy(15, 9); cin >> nodoReserva->temporada;
    gotoxy(40, 9); cout << "# Días: "; gotoxy(60, 9); cin >> nodoReserva->n_dias;

    if (nodoReserva->temporada == "Alta") {
        incremento = 0.15;
    } else if (nodoReserva->temporada == "Media") {
        incremento = 0.1;
    }

    subtotal = nodoReserva->n_dias * nodoReserva->datosHabitacion->precioBase * (1 + incremento);
    nodoReserva->subtotal = subtotal;
    nodoReserva->iva = 0.15; 
    total = subtotal + (subtotal * nodoReserva->iva);
    nodoReserva->total = total;

    gotoxy(5, 11); cout << "Consumo de bar: 0";
    gotoxy(5, 12); cout << "Subtotal: " << subtotal;
    gotoxy(5, 13); cout << "IVA: " << nodoReserva->iva * 100 << "%: " << subtotal * nodoReserva->iva;
    gotoxy(5, 14); cout << "Total: " << total;

    nodoReserva->estado = 1;
    if (pcabRes == NULL) {
        pcabRes = nodoReserva;
        pfinRes = nodoReserva;
    } else {
        pfinRes->sgt = nodoReserva;
        nodoReserva->ant = pfinRes;
        pfinRes = nodoReserva;
    }

    nodoFac->reservacion = nodoReserva;
    if (cabFac == NULL) {
        cabFac = nodoFac;
        finFac = nodoFac;
    } else {
        finFac->sgt = nodoFac;
        nodoFac->ant = finFac;
        finFac = nodoFac;
    }
}

// Función para presentar el comprobante
void PresentarComprobante(Factura *dirNodo) {
    system("cls");
    gotoxy(4, 1); cout << "HOTEL TU DESCANSO";    
    gotoxy(4, 2); cout << "# Reserva: "; gotoxy(15, 2); cout << dirNodo->reservacion->numeroR;     
    gotoxy(5, 4); cout << "Cedula: "; gotoxy(15, 4); cout << dirNodo->reservacion->datosClientes->cedula;
    gotoxy(5, 5); cout << "Nombres: "; gotoxy(15, 5); cout << dirNodo->reservacion->datosClientes->nombres;
    gotoxy(5, 6); cout << "Telefono: "; gotoxy(15, 6); cout << dirNodo->reservacion->datosClientes->telefono;
    gotoxy(5, 7); cout << "Email: "; gotoxy(15, 7); cout << dirNodo->reservacion->datosClientes->email;
    gotoxy(40, 2); cout << "Fecha de entrada: "; gotoxy(60, 2); cout << dirNodo->reservacion->fecha_in;
    gotoxy(90, 2); cout << "Fecha de salida: "; gotoxy(110, 2); cout << dirNodo->reservacion->fecha_out;
    gotoxy(90, 3); cout << "Estado de la reserva: "; gotoxy(120, 3); cout << (dirNodo->reservacion->estado == 1 ? "Activa" : "Finalizada");
    gotoxy(40, 4); cout << "# Habitacion: "; gotoxy(60, 4); cout << dirNodo->reservacion->datosHabitacion->numHabitacion;
    gotoxy(40, 5); cout << "Tipo: "; gotoxy(60, 5); cout << dirNodo->reservacion->datosHabitacion->tipoHabitacion;
    gotoxy(40, 6); cout << "Camas: "; gotoxy(60, 6); cout << dirNodo->reservacion->datosHabitacion->numCamas;
    gotoxy(40, 7); cout << "Vista al mar: "; gotoxy(60, 7); cout << (dirNodo->reservacion->datosHabitacion->vistaAlMar == 0 ? "No" : "Si");

    float subtotal = dirNodo->reservacion->subtotal;
    float iva = subtotal * dirNodo->reservacion->iva;
    float gastosBar = dirNodo->gastosBar;
    float total = subtotal + iva + gastosBar;

    gotoxy(40, 8); cout << "Precio base: "; gotoxy(60, 8); cout << dirNodo->reservacion->datosHabitacion->precioBase;
    gotoxy(5, 9); cout << "Temporada: "; gotoxy(15, 9); cout << dirNodo->reservacion->temporada;
    gotoxy(40, 9); cout << "# Días: "; gotoxy(60, 9); cout << dirNodo->reservacion->n_dias;
    gotoxy(5, 11); cout << "Gastos de bar: "; gotoxy(20, 11); cout << gastosBar;
    gotoxy(5, 12); cout << "Subtotal: "; gotoxy(20, 12); cout << subtotal;
    gotoxy(5, 13); cout << "IVA (" << dirNodo->reservacion->iva * 100 << "%): "; gotoxy(20, 13); cout << iva;
    gotoxy(5, 16); cout << "Total a pagar: "; gotoxy(20, 16); cout << total;
}

// Función para presentar la reserva
void PresentarReserva(Factura *dirNodo) {
    system("cls");
    gotoxy(4, 1); cout << "HOTEL TU DESCANSO";    
    gotoxy(4, 2); cout << "# Reserva: "; gotoxy(15, 2); cout << dirNodo->reservacion->numeroR;     
    gotoxy(5, 4); cout << "Cedula: "; gotoxy(15, 4); cout << dirNodo->reservacion->datosClientes->cedula;
    gotoxy(5, 5); cout << "Nombres: "; gotoxy(15, 5); cout << dirNodo->reservacion->datosClientes->nombres;
    gotoxy(5, 6); cout << "Telefono: "; gotoxy(15, 6); cout << dirNodo->reservacion->datosClientes->telefono;
    gotoxy(5, 7); cout << "Email: "; gotoxy(15, 7); cout << dirNodo->reservacion->datosClientes->email;
    gotoxy(40, 2); cout << "Fecha de entrada: "; gotoxy(60, 2); cout << dirNodo->reservacion->fecha_in;
    gotoxy(90, 2); cout << "Fecha de salida: "; gotoxy(110, 2); cout << dirNodo->reservacion->fecha_out;
    gotoxy(90, 3); cout << "Estado de la reserva: "; gotoxy(120, 3); cout << (dirNodo->reservacion->estado == 1 ? "Activa" : "Finalizada");
    gotoxy(40, 4); cout << "# Habitacion: "; gotoxy(60, 4); cout << dirNodo->reservacion->datosHabitacion->numHabitacion;
    gotoxy(40, 5); cout << "Tipo: "; gotoxy(60, 5); cout << dirNodo->reservacion->datosHabitacion->tipoHabitacion;
    gotoxy(40, 6); cout << "Camas: "; gotoxy(60, 6); cout << dirNodo->reservacion->datosHabitacion->numCamas;
    gotoxy(40, 7); cout << "Vista al mar: "; gotoxy(60, 7); cout << (dirNodo->reservacion->datosHabitacion->vistaAlMar == 0 ? "No" : "Si");

    float subtotal = dirNodo->reservacion->subtotal;
    float iva = subtotal * dirNodo->reservacion->iva;
    float gastosBar = dirNodo->gastosBar;
    float total = subtotal + iva + gastosBar;

    gotoxy(40, 8); cout << "Precio base: "; gotoxy(60, 8); cout << dirNodo->reservacion->datosHabitacion->precioBase;
    gotoxy(5, 9); cout << "Temporada: "; gotoxy(15, 9); cout << dirNodo->reservacion->temporada;
    gotoxy(40, 9); cout << "# Días: "; gotoxy(60, 9); cout << dirNodo->reservacion->n_dias;
    gotoxy(5, 11); cout << "Gastos de bar: "; gotoxy(20, 11); cout << gastosBar;
    gotoxy(5, 12); cout << "Subtotal: "; gotoxy(20, 12); cout << subtotal;
    gotoxy(5, 13); cout << "IVA (" << dirNodo->reservacion->iva * 100 << "%): "; gotoxy(20, 13); cout << iva;
    gotoxy(5, 16); cout << "Total a pagar: "; gotoxy(20, 16); cout << total;
}
Factura *Fun_BuscarReserva(Factura *&cabFac, string cedula) {
    Factura *actualFac = cabFac;
    while (actualFac != NULL) {
        if (actualFac->reservacion->datosClientes->cedula == cedula) {
            return actualFac;
        }
        actualFac = actualFac->sgt;
    } 
    return NULL; 
}

void IngresarConsumoBar(Reserva *&pcabRes, Factura *&cabFac) {
    string cedulabuscar;
    float consumoBar;
    Factura *actual = cabFac;

    cout << "Ingrese el número de cédula del cliente: ";
    cin >> cedulabuscar;
    
    actual = Fun_BuscarReserva(cabFac, cedulabuscar);
    if (actual == NULL) {
        cout << "No existe la reserva asociada al cliente con esa cédula." << endl;
        return;
    }

    if (actual->reservacion->estado == 0) {
        cout << "La reserva del cliente ya ha sido finalizada." << endl;
        return;
    }

    cout << "Ingrese el valor del consumo en el bar: ";
    cin >> consumoBar;

    actual->gastosBar += consumoBar;

    actual->reservacion->total += consumoBar;

    cout << "Consumo del bar añadido con éxito. Nuevo total: " << actual->reservacion->total << endl;
}
