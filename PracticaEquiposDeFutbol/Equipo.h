#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "MyVector.h"
#include <functional>
#include <stdlib.h>

using namespace std;

class Jugador {
private:
	string nombre;
	int numero;
	string posicion;

public:
	Jugador(string nombre = "", int numero = 0, string posicion = "") : nombre(nombre), numero(numero), posicion(posicion) {}
	~Jugador() {}

	string getnombreJ() { return nombre; }
	int getnumero() { return numero; }
	string getposicion() { return posicion; }

	void setnombreJ(string nombre) { this->nombre = nombre; }
	void setnumero(int numero) { this->numero = numero; }
	string setposicion(string posicion) { this->posicion = posicion; }

	string to_String() {
		return "\nNombre: "+ nombre + " | Numero: " + std::to_string(numero)+ " | Posicion: " + posicion;
	}

};

class Equipo {
private:
	MyVector<Jugador> equipo;
	string nombreE;
public:
	Equipo(string nombreE = "") : nombreE(nombreE) {}

	Equipo(string nombreE, string nombre, int numero, string posicion) {
		this->nombreE = nombreE;
		equipo.push_back(Jugador(nombre,numero, posicion));
	}

	~Equipo() {}

	string getnombreE() { return nombreE; }
	void setnombreE(string nombreE) { this->nombreE = nombreE; }
	MyVector<Jugador> getequipo() { return equipo; }
	int getSizeEquipo() { return equipo.getpos(); }

	void insertarJugador() {
		string nombre, posicion;
		int numero;
		cin.ignore();
		cout << "Ingrese el nombre del jugador: ";
		getline(cin, nombre);
		cout << "Ingrese su numero: "; cin >> numero;
		cin.ignore();
		cout << "Ingrese su posicion: "; 
		getline(cin, posicion);
		equipo.push_back(Jugador(nombre, numero, posicion));
	}

	void crearjugador(string nombre, int numero, string posicion) {
		equipo.push_back(Jugador(nombre, numero, posicion));
	}

	void mostrarEquipo() { 
		cout << "\nNombre del equipo: " << nombreE;
		cout << "\nJugadores: ";
		equipo.print([](Jugador j) { cout<< j.to_String(); });
		cout << "\n-----------------------------------------------" << endl;
	}

	void modificarJugadorPorNombre() {
		string nombre, posicion;
		int numero;
		cin.ignore();
		cout << "Ingrese el nombre del jugador: ";
		getline(cin, nombre);
		cout << "Ingrese su numero: "; cin >> numero;
		cout << "Ingrese su posicion: "; cin >> posicion;

		for (int i = 0; i <= equipo.getpos(); ++i) {
			if (equipo.getarr()[i].getnombreJ().compare(nombre) == 0) {
				equipo.modificar(Jugador(nombre,numero,posicion), i);
			}
		}
	}

};

class ListaEquipos {
private:
	MyVector<Equipo> vequipos;
public:
	ListaEquipos() {}

	ListaEquipos(string nombreE, string nombre, int numero, string posicion) {
		vequipos.push_back(Equipo(nombreE,nombre,numero,posicion));
	}
	~ListaEquipos() {}

	MyVector<Equipo> getvequipos() { return vequipos; }
	int getSizeEquipos() { return vequipos.getpos(); }

	void agregarEquipo() {
		string nombreE="";
		cout << "Ingrese nombre del equipo: "; cin >> nombreE;
		vequipos.push_back(Equipo(nombreE));
	}

	void crearEquipo(string nombreE) {
		vequipos.push_back(Equipo(nombreE));
	}

	void agregarJugadorPorNombreEquipo() {
		string nombreE="";
		cin.ignore();
		cout << "Ingrese nombre del equipo: "; 
		getline(cin, nombreE);
		for (int i = 0; i <= vequipos.getpos(); ++i) {
			if (vequipos.getarr()[i].getnombreE().compare(nombreE)==0) {
				vequipos.getarr()[i].insertarJugador();
			}
		}
	}

	void modificarJugadorPorNombreEquipo() {
		string nombreE;
		cout << "Ingrese nombre del equipo: "; cin >> nombreE;
		for (int i = 0; i <= vequipos.getpos(); ++i) {
			if (vequipos.getarr()[i].getnombreE().compare(nombreE) == 0) {
				vequipos.getarr()[i].modificarJugadorPorNombre();
			}
		}
	}

	void eliminarEquipo() {
		string nombreE;
		cin.ignore();
		cout << "Ingrese el nombre del equipo completo a eliminar: ";
		getline(cin, nombreE);
		for (int i = 0; i <= vequipos.getpos(); ++i) {
			if (vequipos.getarr()[i].getnombreE().compare(nombreE) == 0) {
				vequipos.setarr(vequipos.deleteByPos(i, vequipos.getarr()));
				vequipos.setpos(vequipos.getpos()-1);
			}
		}
	}
	
	void mostrarEquipos() {
		function<void(Equipo)> imprime = [](Equipo e) { e.mostrarEquipo(); };
		vequipos.print(imprime);
	}
	
};

