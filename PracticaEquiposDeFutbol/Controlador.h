#pragma once
#include "Equipo.h"
#include "Configuracion.h"
class Controlador {
private:
	ListaEquipos* equipos;
	Configuracion* file;
	ofstream EscribirArchivo;
public:
	Controlador() {
		file = new Configuracion();
		file->leerInformacion();

		if (file->configuracionCreada()) {
			equipos = new ListaEquipos();
		}
		else {
			equipos = new ListaEquipos(file->getnombreE(), file->getnombre(), file->getnumero(), file->getposicion());
		}
		cargar();
	}
	~Controlador() {}

	void menu() {
		cout << "1. Agregar equipo "<<endl;
		cout << "2. Agregar jugador por nombre de equipo"<<endl;
		cout << "3. Modificar jugador por nombre de equipo y nombre de jugador"<<endl;
		cout << "4. Eliminar jugador por nombre de equipo y nombre de jugador"<<endl;
		cout << "5. Mostrar Equipos" << endl;
		cout << "6. Salir" << endl;
	}

	void guardar() {
		EscribirArchivo.open("equipos.txt", ios::out);
		EscribirArchivo << std::to_string(equipos->getvequipos().getpos()) << endl; //cantidad de equipos
		for (int i = 0; i <= equipos->getvequipos().getpos(); ++i) {
			EscribirArchivo << equipos->getvequipos().getarr()[i].getnombreE() << endl;
			EscribirArchivo << std::to_string(equipos->getvequipos().getarr()[i].getequipo().getpos()) << endl; //cantidad de jugadores de ese equipo
			for (int j = 0; j <= equipos->getvequipos().getarr()[i].getequipo().getpos(); ++j) { 
				EscribirArchivo << equipos->getvequipos().getarr()[i].getequipo().getarr()[j].getnombreJ() << endl;
				EscribirArchivo << std::to_string(equipos->getvequipos().getarr()[i].getequipo().getarr()[j].getnumero()) << endl;
				EscribirArchivo << equipos->getvequipos().getarr()[i].getequipo().getarr()[j].getposicion() << endl;
			}
			cout << endl;
		}
		EscribirArchivo.close();
	}

	void cargar() {
		ifstream LeerArchivo;
		LeerArchivo.open("equipos.txt", ios::in);
		string nombreE, nombre, posicion, texto;
		int numero, cantequipos, cantjugadores;
		if (LeerArchivo.is_open() == true) {
			getline(LeerArchivo, texto); cantequipos = atoi(texto.c_str());
			for (int i = 0; i <= cantequipos; i++) {
				getline(LeerArchivo, nombreE);
				equipos->crearEquipo(nombreE);

				getline(LeerArchivo, texto); cantjugadores = atoi(texto.c_str());
				for (int j = 0; j <= cantjugadores; j++) {
					getline(LeerArchivo, nombre);
					getline(LeerArchivo, texto); numero = atoi(texto.c_str());
					getline(LeerArchivo, posicion);
					equipos->getvequipos().getarr()[i].crearjugador(nombre, numero, posicion);
				}
			}
			LeerArchivo.close();
		}
	}

	void run() {
		int opc;
		do {
			menu();
			cout << "Ingrese una opcion: "; cin >> opc;
			cout << endl;
			switch (opc) {
			case 1:
				equipos->agregarEquipo();
				break;
			case 2:
				equipos->agregarJugadorPorNombreEquipo();
				break;
			case 3:
				equipos->modificarJugadorPorNombreEquipo();
				break;
			case 4:
				equipos->eliminarEquipo();
				break;
			case 5:
				equipos->mostrarEquipos();
				break;
			case 6:
				guardar();
				exit(0);
				break;
			default:
				break;
			}

			system("pause");
			system("CLS");

		} while (1);
	}
};