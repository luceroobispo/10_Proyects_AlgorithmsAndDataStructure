#pragma once
#include <iostream>
#include <functional>
using namespace std;

template<class G>
class MyVector {
private:
	G* arr;
	int pos;
	int size;
public:

	MyVector(int size = 8) : size(size), pos(-1) { 
		arr = new G[size]; 
	
	}
	~MyVector() {}

	unsigned int getsize() { return size; }
	int getpos() { return pos; }
	void setpos(int pos) { this->pos = pos; }
	G* getarr() { return arr; }
	void setarr(G* arr) { this->arr = arr; }

	G* deleteByPos(int posicion, G* arreglo) { //2
		G* Aux = new G[size]; //2
		for (int i = 0; i < size; i++) { //1 +    1 + 2
			if (i < posicion) {  //1
				Aux[i] = arreglo[i]; //1
			}
			else {
				Aux[i] = arreglo[i + 1]; //2
			}
		}
		return Aux;//1
		//Detallada: 2+ 2+1+ 8(1+2+1+1+2) +1  
		//Asintotica: 6+ 8(7)
		//O(1) constante
	}

	void push_back(G e) {//1
		if(pos<size) //1
			arr[++pos] = e;//3
		//Detallada: 1+1+3
		//Asintotica: 5
		//O(1) constante
	}

	void print(function<void(G)> mostrar) { //1
		for (int i = 0; i <= pos; i++) //1     + 2 + 2
			mostrar(arr[i]);// logn
		//Detallada: 1+ 1+ n(2+2+logn)
		//Asintotica: 2 + 4n + logn*n
		//O(n*logn) 
	}

	void modificar(G obj, int pos) {
		arr[pos] = obj;
	}

};