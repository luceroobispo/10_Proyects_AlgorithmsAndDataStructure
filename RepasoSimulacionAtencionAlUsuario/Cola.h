#pragma once
#include <iostream>
#include <functional>
using namespace std;

template<class Generico>
class Nodo {
private:
	Generico dato;
	Nodo<Generico>* siguiente;

public:
	Nodo(Generico v, Nodo<Generico>* sig = nullptr) {
		dato = v;
		siguiente = sig;
	}
	~Nodo() {}
	Generico getdato() { return dato; }
	Nodo<Generico>* getsiguiente() { return siguiente; }

	void setdato(Generico v) { v = dato; }
	void setsiguiente(Nodo<Generico>* sig) { siguiente = sig; }
};

template<class Generico>
class Cola {
private:
	Nodo<Generico>* inicio;
	Nodo<Generico>* fin;
	int cont;
	int capacidad;
public:
	Cola() {
		this->inicio = nullptr;
		this->fin = nullptr;
		cont = 0;
		capacidad = 10; 
	}

	~Cola() {}

	Nodo<Generico>* getinicio() { return inicio; }
	int getcapacidad() { return capacidad; }
	void setcapacidad(int n) { capacidad = n; }

	bool isEmpty() {
		return (inicio == nullptr);
	}

	bool isFull() {
		return (cont == capacidad);
	}

	void print(function<void(Generico)> imprime, Nodo<Generico>* aux) { // aux apunta al inicio de la cola
		if (aux == nullptr) return; 
		imprime(aux->getdato());
		print(imprime, aux->getsiguiente());
	}

	void enqueue(Generico v) { //Agregar -> push_back
		if (!isFull()) {
			Nodo<Generico>* nodo = new Nodo<Generico>(v);
			if (isEmpty()) {
				inicio = nodo;
				fin = inicio;
			}
			else {

				fin->setsiguiente(nodo);
				fin = nodo;
			}
			nodo = nullptr;
			cont++;
		
		}
	}
	Generico dequeue() { //Eliminar -> pop_front
		Generico dato = inicio->getdato();

		if (inicio == fin) {
			inicio = nullptr;
			fin = nullptr;
		}
		else {
			inicio = inicio->getsiguiente();
		}
		cont--;
		return dato;
	}

	int printContCondicion(function<bool(Nodo<Generico>*)> condicion) {
		int cont=0;
		Nodo<Generico>* aux = inicio;
		while (aux != nullptr) {
			if (condicion(aux)) cont++;
			aux = aux->getsiguiente();
		}
		return cont;
	}

	void deleteByNodo(Nodo<Generico>* nodo) {
		Nodo<Generico>* ptr1 = inicio; //nodo actual
		Nodo<Generico>* ptr2 = nullptr; //nodo anterior
		bool band = false;
		
		if (!isEmpty()) {
			while (band!=true && ptr1!=nullptr) {
				if (ptr1 == nodo) {
					if (ptr1 == inicio) { 
						inicio = inicio->getsiguiente(); 
					}
					else if (ptr1 == fin) {
						ptr2->setsiguiente(nullptr);
						fin = ptr2;
					}
					else {
						ptr2->setsiguiente(ptr1->getsiguiente());
					}
					band = true;
				}
				ptr2 = ptr1;
				ptr1 = ptr1->getsiguiente();
			}
		}
	}
};