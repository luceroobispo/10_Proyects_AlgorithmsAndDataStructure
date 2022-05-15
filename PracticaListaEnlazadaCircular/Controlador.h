#pragma once
#include "Punto.h"
class Controlador {
private:
	ListaPuntos* puntos;
public:
	Controlador() {
		puntos = new ListaPuntos();
	}
	~Controlador() {}

	void menu() {
		cout << "1. Insertar al final" << endl;
		cout << "2. Insertar al inicio" << endl;
		cout << "3. Eliminar en posicion" << endl;
		cout << "4. Buscar todos los valores de x menor a y,z" << endl;
		cout << "5. Mostrar" << endl;
		cout << "6. Mostrar con iterador" << endl;
		cout << "7. Salir " << endl;
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
				puntos->insertarAlFinal();
				break;
			case 2:
				puntos->insertarAlInicio();
				break;
			case 3:
				puntos->eliminarEnPosicion();
				break;
			case 4:
				puntos->mostrarSiXesMenor();
				break;
			case 5:
				puntos->mostrar();
				break;
			case 6: 
				puntos->iterador();
				break;
			case 7: exit(0);
				break;
			default:
				break;
			}
			system("pause");
			system("CLS");
		} while (1);
	}
};