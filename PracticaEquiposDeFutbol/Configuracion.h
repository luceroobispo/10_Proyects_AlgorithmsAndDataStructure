#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

class Configuracion {
private:
	ofstream EscribirArchivo;
	ifstream LeerArchivo;
	string texto;
	string nombre, posicion, nombreE;
	int numero;
	bool creado;
public:
	Configuracion() {
		numero = 0;
		creado = false;
	}
	~Configuracion() {}

	void leerInformacion() {
		LeerArchivo.open("configuracion.txt", ios::in);

		if (LeerArchivo.fail()) {
			LeerArchivo.close();

			EscribirArchivo.open("configuracion.txt", ios::out); //Creates the new txt
			EscribirArchivo << "Panteras" << endl; //Nombre de Equipo
			EscribirArchivo << "Paolo" << endl; //Nombre de jugador
			EscribirArchivo << "10" << endl;  //Numero
			EscribirArchivo << "Delantero" << endl;   //Posicion
			EscribirArchivo.close();
			LeerArchivo.open("configuracion.txt", ios::in);
			creado = true;
		}

		getline(LeerArchivo, nombreE); 
		getline(LeerArchivo, nombre); 
		getline(LeerArchivo, texto); numero = atoi(texto.c_str());
		getline(LeerArchivo, posicion);
		LeerArchivo.close();
	}

	string getnombreE() { return nombreE; }
	string getnombre() { return nombre; }
	int getnumero() { return numero; }
	string getposicion() { return posicion; }

	bool configuracionCreada() { return creado; }
};