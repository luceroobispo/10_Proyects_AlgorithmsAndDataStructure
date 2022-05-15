#pragma once
#include <iostream>
#include <string>
#include "Cola.h"
#include <fstream>
//#include <stdlib.h>
using namespace std;

class Usuario {
private:
	string nombre, apellido, codigo;
	char tipo;
	int nro_ticket;
public:
	Usuario(string nombre="", string apellido ="", string codigo="", char tipo=' ', int nro_ticket = 0):nombre(nombre),apellido(apellido),codigo(codigo),tipo(tipo),nro_ticket(nro_ticket) {}
	~Usuario() {}

	string toString() { return "Nombre y Apellido: " + nombre + " " + apellido +
		                       "\nCodigo: " + codigo + 
							   "\nTipo:" + tipo + 
							   "\nNumero de Ticket: " + std::to_string(nro_ticket) + 
		                       "\n----------------------------------------"; }
	char gettipo() { return tipo; }
};

class ListaUsuarios {
private:
	Cola<Usuario> usuarios;
	int ticket;
	ofstream archivo;
	ofstream archivo2;
	ofstream archivo3;
public:
	ListaUsuarios() {
		ticket = 1;
		usuarios.setcapacidad(100);
		archivo.open("Padres.txt", ios::out);
		archivo2.open("Docentes.txt", ios::out);
		archivo3.open("Alumnos.txt", ios::out);
	}
	~ListaUsuarios() {}

	void insertarAlFinal() {
		string nombre, apellido, codigo;
		char tipo;
		cout << "Nombre: "; cin >> nombre;
		cout << "Apellido: "; cin >> apellido;
		cout << "Codigo: "; cin >> codigo;
		cout << "Tipo -> Padres(P),Docentes(D) y Alumno(A): "; cin >> tipo;
		usuarios.enqueue(Usuario(nombre, apellido, codigo, tipo, ticket));

		if (archivo.is_open() == true && tipo=='P') {
			archivo << "\nNombre y Apellido: " << nombre << " " << apellido <<
				       "\nCodigo: " << codigo <<
				       "\nTipo:" << tipo <<
				       "\nNumero de Ticket: " << std::to_string(ticket) <<
				       "\n----------------------------------------";
		}

		if (archivo2.is_open()==true && tipo == 'D') {
			archivo2 << "\nNombre y Apellido: " << nombre << " " << apellido <<
				        "\nCodigo: " << codigo <<
				        "\nTipo:" << tipo <<
				        "\nNumero de Ticket: " << std::to_string(ticket) <<
				        "\n----------------------------------------";
		}

		if (archivo3.is_open() == true && tipo == 'A') {
			archivo3 << "\nNombre y Apellido: " << nombre << " " << apellido <<
				        "\nCodigo: " << codigo <<
				        "\nTipo:" << tipo <<
				        "\nNumero de Ticket: " << std::to_string(ticket) <<
				        "\n----------------------------------------";
		}

		if (usuarios.isFull()) {
			archivo.close();
			archivo2.close();
			archivo3.close();
		}
		ticket++;
	}

	void atenderPorTipoUsuario() {
		char tipo;
		cout << "Ingrese el tipo de usuario -> Padres(P),Docentes(D) y Alumno(A): "; cin >> tipo;
		Nodo<Usuario>* aux = usuarios.getinicio();
		bool band = false;
		while (aux != nullptr && band==false) {
			if (aux->getdato().gettipo() == tipo && band==false) {
				cout << "\nSe atendera el siguiente usuario: \n" << aux->getdato().toString()<<endl;
				usuarios.deleteByNodo(aux);
				band = true;
			}
			aux = aux->getsiguiente();
		}
	}

	void atender() {
		usuarios.dequeue();
	}

	void obtenerNroAtenciones() {
		function<bool(Nodo<Usuario>*)>  condicionA = [](Nodo<Usuario>* u) { return u->getdato().gettipo() == 'A'; };
		function<bool(Nodo<Usuario>*)>  condicionP = [](Nodo<Usuario>* u) { return u->getdato().gettipo() == 'P'; };
		function<bool(Nodo<Usuario>*)>  condicionD = [](Nodo<Usuario>* u) { return u->getdato().gettipo() == 'D'; };
		cout<<"Cantidad de (A)lumnos: "<<usuarios.printContCondicion(condicionA)<<endl;
		cout<<"Cantidad de (P)adres: "<<usuarios.printContCondicion(condicionP)<<endl;
		cout<<"Cantidad de (D)ocentes: "<<usuarios.printContCondicion(condicionD)<<endl;
	}
	
	void mostrar() {
		function<void(Usuario)> imprime = [](Usuario u) { cout << u.toString() << endl; };
		usuarios.print(imprime, usuarios.getinicio());
	}
	
	
};