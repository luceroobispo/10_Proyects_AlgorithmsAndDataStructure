#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
/*
EJERCICIO 1: 
Leer n numeros enteros mayor a 150 desde archivo y duplicarlos usando enmascaramiento de bits.
*/

void lectura() {
	vector<int> enteros;
	ifstream i("input.txt");
	ofstream o("output.txt");
	short x;
	while (i >> x) {
		if (x >= 150 && !(x & 1)) enteros.push_back(x << 1);
	}

	for (unsigned int i = 0; i < enteros.size(); i++) {
		o << enteros[i] << " ";
	}
	o.close();
}

void ordenar() {
	vector<int> enteros;
	ifstream i("input.txt");
	ofstream o("output.txt");
	short x;
	while (i>>x) {
		if (x>=150 && !(x & 1)) enteros.push_back(x);
	}

	sort(enteros.begin(), enteros.end(), [](int a, int b) {return a < b; });

	for (unsigned int i = 0; i < enteros.size();i++) {
		o << enteros[i] <<  " ";
	}
	o.close();
}

int main() {
	//lectura();
	ordenar();
	int a = 10;
	int b = 6;
	int x = 180;
	int z = a & b; //AND LOGIGO (PAR O IMPAR)
	int z2 = a | b; //OR LOGICO
	int z3 = a ^ b;//XOR LOGICO (iguales = 0)
	int z4 = ~x; //NEGACION
	int z5 = a << 1; //duplica el valor de bits, mueve un bit a la izquierda
	cout << z<< " "<<z2 << " " << z3 <<" "<<z4<< " "<< z5 <<endl;
	if ((a&1) == 0) cout << 10 << " es par" << endl; // &1 obtiene el ultimo valor para saber si es par o impar
	else cout << 10 << " es impar" << endl;
	return 0;
}
