#include <iostream>
#include <string.h>
#include <locale.h>
#include <conio.h>

using namespace std;

struct Habitacion{
	
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

int main(){
	setlocale(LC_CTYPE, "Spanish");
	int op, resp=1;
	do{
		system("cls");
		op=menuPrincipal();
		switch(op){
			case 1:
				//gestionar Habitaciones
				break;
			case 2:
				//Gestionar Clientes
				break;
			case 3:
				//Gestionar Reservas
				break;
			case 4:
				//Salir
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
		cout << " 4: Sair " << endl;
		cout << "Elija la opcion";
		cin >> op;
	} while (op < 1 || op > 4);
	return op;
}
int menuCliente(){
	int op;
	do{
		cout << "***** MENU CLIENTES *****" << endl;
		cout << " 1: insertar Cliente" << endl;
		cout << " 2: ";
		cout << " 3: ";
		cout << " 4: ";
		cout << " 5: ";
		cout << " Elija la opcion ";
		
		cin >> op;
	} while (op < 1 || op > 5);
	return op;
}
int menuReservas(){
	int op;
	do{
		cout << "***** MENU DE RESERVAS *****" << endl;
		cout << " 1: " << endl;
		cout << " 2: " << endl;
		cout << " 3: " << endl;
		cout << " 4: " << endl;
		cout << " 5: " << endl;
		cout << "Elija la opcion: ";
		cin >> op;
	} while (op < 1 || op > 5);
	return op;
}
int menuHabitacion(){
	int op;
	return op;
}
