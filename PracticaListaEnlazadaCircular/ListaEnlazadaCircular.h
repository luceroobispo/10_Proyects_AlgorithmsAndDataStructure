#pragma once
#include <iostream>
#include <string>
#include <functional>
using namespace std;

template<class Generico>
class Nodo {
private:
	Generico elemento;
	Nodo<Generico>* sig;
public:
	Nodo(Generico e) {
		elemento = e;
		sig = nullptr;
	}
	~Nodo() {}
	Nodo<Generico>* getsig() { return sig; }
	void setsig(Nodo<Generico>* sig) { this->sig = sig; }
	Generico gete() { return elemento; }
};

template<class Generico>
class ListaCircular {
	Nodo<Generico>* inicio;
	Nodo<Generico>* fin;
	Nodo<Generico>* temp;
	size_t cantidad;
public:
	//-----------------------Iterador---------------
	class Iterador {
	private:
		Nodo<Generico>* aux;

	public:
		Iterador(Nodo<Generico>* aux = nullptr) : aux(aux) {}
		void operator ++ () { aux = aux->getsig(); }
		bool operator != (Iterador it) { return this->aux != it.aux; }
		Generico operator* () { return aux->gete(); }
		Nodo<Generico>* getaux() { return aux; }
	};
	//-----------------------Iterador---------------
	ListaCircular() {
		inicio = fin = temp = nullptr;
		cantidad = 0;
	}
	~ListaCircular() {}

	Iterador getinicio() { return Iterador(inicio); };
	Iterador getfin() { return Iterador(fin); };
	Nodo<Generico>* getFin() { return fin; }

	void push_back(Generico e) { //De orden O(1)
		Nodo<Generico>* nuevo = new Nodo<Generico>(e);
		if (inicio == nullptr) {
			inicio = fin = nuevo;
			inicio->setsig(inicio);
		}
		else {
			fin->setsig(nuevo);
			nuevo->setsig(inicio); //circular
			fin = nuevo;
		}
		cantidad++;
	}
	Nodo<Generico>* getNodeByPos(long pos) {
		temp = inicio;
		for (size_t i = 0; i < pos; ++i) {
			temp = temp->getsig();
		}
		return temp;
	}

	void push_front(Generico e) {
		Nodo<Generico>* nuevo = new Nodo<Generico>(e);
		if (inicio == nullptr) {
			inicio = fin = nuevo;
		}
		else {
			temp = inicio;
			fin->setsig(nuevo);
			inicio = nuevo;
		}
		nuevo->setsig(temp);
		cantidad++;
	}

	bool eraseByPos(long pos) {
		Nodo<Generico>* aux;
		if (pos >= 0 && pos < cantidad) {
			if (pos == 0) { //inicio
				temp = inicio;
				inicio = inicio->getsig();
				fin->setsig(inicio);
			}
			else { //otra posicion
				aux = getNodeByPos(pos - 1);
				temp = aux->getsig();
				aux->setsig(temp->getsig());
				if (pos == cantidad - 1) {
					fin = aux;
					fin->setsig(inicio);
				}
			}
			delete temp;
			temp = nullptr;
			cantidad--;
			return true;
		}
		else return false;
	}

	void searchElementByCondition(function<void(Generico)> imprime, function<bool(Nodo<Generico>*)> condicion) {
		temp = inicio;
		for (size_t i = 0; i < cantidad; ++i) {
			if (condicion(temp)) imprime(temp->gete());
			temp = temp->getsig();
		}
		temp = nullptr;
	}

	void print(function<void(Generico)> imprime) {
		Nodo<Generico>* aux=inicio;
		for (size_t i = 0; i < cantidad; ++i) {
			imprime(aux->gete());
			aux = aux->getsig();
		}
		cout << endl;
	}
};