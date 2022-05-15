#pragma once
#include "ListaEnlazadaCircular.h"
using namespace std;

class Punto {
private:
	int x, y,z;
public:
	Punto(int x = 0, int y = 0, int z = 0) :x(x), y(y), z(z) {}
	~Punto() {}

	string toString() {
		return "p("+ std::to_string(x)+", "+ std::to_string(y)+", "+ std::to_string(z)+")";
	}
	int getx() { return x; }
	int gety() { return y; }
	int getz() { return z; }
};

class ListaPuntos {
private:
	ListaCircular<Punto> puntos;
public:
	ListaPuntos() {}
	~ListaPuntos() {}
	void insertarAlFinal() {
		int x, y, z;
		cout << "Ingrese x: "; cin >> x;
		cout << "Ingrese y: "; cin >> y;
		cout << "Ingrese z: "; cin >> z;
		puntos.push_back(Punto(x,y,z));
	}

	void insertarAlInicio() {
		int x, y, z;
		cout << "Ingrese x: "; cin >> x;
		cout << "Ingrese y: "; cin >> y;
		cout << "Ingrese z: "; cin >> z;
		puntos.push_front(Punto(x, y, z));
	}

	void mostrar() {
		function<void(Punto)> imprime = [](Punto p) { cout << p.toString() << endl; };
		puntos.print(imprime);
	}

	void mostrarSiXesMenor() {
		function<void(Punto)> imprime = [](Punto p) { cout << p.toString() << endl; };
		function<bool(Nodo<Punto>*)>  condicion = [](Nodo<Punto>* p) { return (p->gete().getx() < p->gete().gety()) &&(p->gete().getx() < p->gete().getz()); };
		puntos.searchElementByCondition(imprime, condicion);
	}

	void eliminarEnPosicion() {
		long pos;
		cout << "Ingrese posicion: "; cin >> pos;
		puntos.eraseByPos(pos);
	}

	void iterador() {
		for (ListaCircular<Punto>::Iterador it = puntos.getinicio(); it != puntos.getfin(); ++it) {
			Punto p = *it;
			cout << p.toString()<<endl;
		}
		Nodo<Punto>* aux = puntos.getFin();
		cout << aux->gete().toString() << endl;
	}
};
