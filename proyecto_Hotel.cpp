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
};
struct Reserva{
	
};
int menuHabitacion();
void opcionesHabitacion();
int menuCliente();
void opcionesCliente();
int menuPrincipal();
void opcionesPrincipal(int op);
int menuReservas();
void opcionesReservas();
int menuBar();
void opcionesBar();

int main(){
	setlocale(LC_CTYPE, "Spanish");
	int op, resp=1;
	do{
		system("cls");
		op = menuPrincipal();
		opcionesPrincipal(op);
		
		cout << "Presiona una tecla para continuar: ";
		getch();
	} while (op < 1 || op > 5);
	getch();
	return 0;
}
int menuPrincipal(){
	int op;

		cout << "***** MENU PRINCIPAL *****" << endl;
		cout << " 1: Gestionar Habitaciones" << endl;
		cout << " 2: Gestionar Clientes" << endl;
		cout << " 3: Gestionar Reservas" << endl;
		cout << " 4: Gestionar Bar" << endl;
		cout << " 5: Salir del programa" << endl;
		cout << "Elija la opcion"<<endl;
		cin >> op;

	return op;
}
int menuCliente(){
	int op;
	do{
		cout << "***** MENU CLIENTES *****" << endl;
		cout << " 1: Insertar Cliente" << endl;
		cout << " 2: Modificar un cliente"<<endl;
		cout << " 3: Eliminar un cliente"<<endl;
		cout << " 4: Listar clientes"<<endl;
		cout << " 5: Volver al menú principal"<<endl;
		cout << " Elija la opcion "<<endl;
		cin >> op;
	} while (op < 1 || op > 5);
	return op;
}
int menuReservas(){
	int op;
	do{
		cout << "***** MENU DE RESERVAS *****" << endl;
		cout << " 1: Reservar" << endl;
		cout << " 2: Buscar reserva" << endl;
		cout << " 3: Finalizar reserva y entregar factura" << endl;
		cout << " 4: Volver al menú principal" << endl;
		cout << "Elija la opcion: "<<endl;
		cin >> op;
	} while (op < 1 || op > 5);
	return op;
}
int menuHabitacion(){
	int op;
	do {
		cout << "***** MENU DE HABITACIONES *****" << endl;
		cout << " 1: Insertar habitación" << endl;
		cout << " 2: Modificar habitación" << endl;
		cout << " 3: Eliminar habitación" << endl;
		cout << " 4: Listar habitaciones" << endl;
		cout << " 5: Volver al menú principal" << endl;
		cout << "Elija la opcion: "<<endl;
		cin >> op;
	} while (op < 1 || op > 5);
	return op;
}
int menuBar(){
	int op;
	do {
		cout << "***** MENU DE BAR *****" << endl;
		cout << " 1: Ingresar el valor de consumo a cliente" << endl;
		cout << " 2: Volver al menú principal" << endl;
		cout << "Elija la opcion: "<<endl;
		cin >> op;
	} while (op < 1 || op > 2);
	return op;
}
void opcionesHabitacion(){
	switch(op){
			case 1: 
				//Insertar habitación
				break;
			case 2: 
				//Modificar habitación
				break;
			case 3: 
				//Eliminar habitación
				break;
			case 4: 
				//Listar habitaciones
				break;
			case 5: //Salir
				cout << "Saliendo del programa ... " << endl;
				break;
		}
}
void opcionesCliente(){
	switch(op){
			case 1: //Insertar Cliente
				
				break;
			case 2: //Modificar un cliente
				
				break;
			case 3: //Eliminar un cliente
				
				break;
			case 4: //Listar clientes
				
				break;
			case 5: //Salir
				cout << "Saliendo del programa ... " << endl;
				break;
		}
}
void opcionesPrincipal(int op){
	switch(op){
			case 1: //gestionar Habitaciones
				menuHabitacion();
				break;
			case 2: //Gestionar Clientes
				menuCliente();
				break;
			case 3: //Gestionar Reservas
				menuReservas();
				break;
			case 4: //Gestionar Bar
				menuBar();
				break;
			case 5: //Salir
				cout << "Saliendo del programa ... " << endl;
				break;
		}
}
void opcionesReservas(){
	switch(op){
			case 1: //Reservar
				
				break;
			case 2: //Buscar reserva
				
				break;
			case 3: //finalizar reserva y entregar factura
				
				break;
		
			case 4: //Salir
				cout << "Saliendo del programa ... " << endl;
				break;
		}
}
void opcionesBar(){
	switch(op){
			case 1: //gestionar Habitaciones
				
				break;
		
			case 2: //Salir
				cout << "Saliendo del programa ... " << endl;
				break;
		}
}
