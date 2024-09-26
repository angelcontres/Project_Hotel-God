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
int menuCliente();
int menuPrincipal();
int menuReservas();
int menuBar();

int main(){
	setlocale(LC_CTYPE, "Spanish");
	int op, resp=1;
	do{
		system("cls");
		op = menuPrincipal();
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
			case 4: //Salir
				resp = 0;
				cout << "Saliendo del programa ... " << endl;
				break;
		}
		cout << "Presiona una tecla para continuar: ";
		getch();
	} while (resp == 1);
	getch();
	return 0;
}
int menuPrincipal(){
	int op;
	do{
		cout << "***** MENU PRINCIPAL *****" << endl;
		cout << " 1: Gestionar Habitaciones" << endl;
		cout << " 2: Gestionar Clientes" << endl;
		cout << " 3: Gestionar Reservas" << endl;
		cout << " 4: Salir del programa" << endl;
		cout << "Elija la opcion"<<endl;
		cin >> op;
	} while (op < 1 || op > 4);
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
		cout << " 2: Modificar Reserva" << endl;
		cout << " 3: Eliminar Reserva" << endl;
		cout << " 4: Listar Reservas" << endl;
		cout << " 5: Volver al menú principal" << endl;
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
}
