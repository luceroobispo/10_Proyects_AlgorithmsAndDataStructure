#pragma once
#include "Usuario.h"
class Controlador {
private:
	ListaUsuarios* usuarios;
public:
	Controlador() {
		usuarios = new ListaUsuarios();
	}
	~Controlador() {}

	void menu() {
		cout << "MENU------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "1. Insertar usuario por teclado a la cola, crea el objeto usuario dinamicamente" << endl;
		cout << "2. Atender por orden de llegada y por tipo usuario, eligiendose tipo de usuario que se desea atender en el orden que llegan" << endl;
		cout << "3. Atender solamente por orden de llegada" << endl;
		cout << "4. Mostrar el numero de atenciones por cada tipo de usuario" << endl;
		cout << "5. Mostrar los nombres de usuarios y tipo en cada cola" << endl;
		cout << "6. Salir" << endl;
	}

	void run() {
		int opc;
		do {
			menu();
			cout << "Ingrese una opcion: ";
			cin >> opc;
			system("CLS");
			switch (opc) {
			case 1: 
				usuarios->insertarAlFinal();
				break;
			case 2:
				usuarios->atenderPorTipoUsuario();
				break;
			case 3:
				usuarios->atender();
				break;
			case 4:
				usuarios->obtenerNroAtenciones();
				break;
			case 5:
				usuarios->mostrar();
				break;
			case 6: exit(0);
				break;
			default:
				break;
			}
			system("pause");
			system("CLS");
		} while (1);
	}
};