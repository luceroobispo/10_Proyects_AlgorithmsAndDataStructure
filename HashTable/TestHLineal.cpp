#include "HashEntidad.h"
#include <iostream>
#include "HashTabla.h"
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int string_sumatoria(string s) {
	int result = 0;
	for (int i = 0; i < s.length(); i++) {
		result += int(s[i]);
	}
	return result%10;
}

int string_potencia(string s) { 
	int result = 0;
	char letras[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int potencia = s.length()-1;
	int i, j;
	for (i = 0; i < s.length();i++) {
		for (j = 0; j < 27;j++) {
			if (letras[j]==s[i]) {
				result += ((j+1) * pow(27,potencia));
				potencia--;
				break;
			}
		}
	}
	return result%10;
}

void criba(int n) {
	vector<bool> esPrimo;
	vector<int> primos;
	esPrimo = vector<bool>(50, true);
	primos = vector<int>();
	bool band = false;

	esPrimo[0] = esPrimo[1] = false;
	for (int i = 2; i < 50; ++i) {
		if (esPrimo[i]) {
			primos.push_back(i);
			for (int j = 2; j * i < 50; ++j) esPrimo[i * j] = 0;
		}
	}

	//Imprimir el numero primo mas cercano a n
	for (int i = 2; i < 50; ++i) {
		if (esPrimo[i] && i>n && band==false) {
			band = true;
			cout << "\nNumero de elementos: " << n;
			cout << "\nPrimo cercano: " << i;
		}
	}
}

void imprimirTablaHashSumatoria(HashTabla* ht, string* keys) {
	cout << "\n\nSIZE TABLA: " << ht->size() << endl;
	cout << "SIZE ACTUAL: " << ht->sizeactual() << endl;
	for (int i = 0; i < ht->sizeactual(); ++i) {
		cout << keys[i] << " \t| Key: " << ht->buscar(string_sumatoria(keys[i])) << endl;
	}
	cout << "\nHashTable ordenado: " << endl;
	for (int i = 0; i < ht->size(); ++i) {
		cout << " "<< i << " : " << ht->getValue(i) << endl;
	}
}

void imprimirTablaHashPotencia(HashTabla* ht, string* keys) {
	cout << "\n\nSIZE TABLA: " << ht->size() << endl;
	cout << "SIZE ACTUAL: " << ht->sizeactual() << endl;
	for (int i = 0; i < ht->sizeactual(); ++i) {
		cout << keys[i] << " \t| Key: " << ht->buscar(string_potencia(keys[i])) << endl;
	}

	cout << "\nHashTable ordenado: " << endl;
	for (int i = 0; i < ht->size(); ++i) {
		cout << " " << i << " : " << ht->getValue(i) << endl;
	}
}


class Estudiante {
private:
	string nombre;
	string apellido;
	int dni;
	int celular;
public:
	Estudiante(string nombre = "", string apellido = "", int dni = 0, int celular = 0) : nombre(nombre), apellido(apellido), dni(dni), celular(celular) {}
	~Estudiante() {}
	string ToString() { return nombre + " " + apellido + " " + std::to_string(dni) + " " + std::to_string(celular); }
};



int main() {
	unsigned t1, t2, t3, t4;
	Estudiante* e = new Estudiante("eric","cuevas",7771,9999991);
	Estudiante* e2 = new Estudiante("lucero","obispo",7772,9999992);
	Estudiante* e3 = new Estudiante("hiro","rodriguez",7773,9999993);
	Estudiante* e4 = new Estudiante("josue","rodriguez",7774,9999994);
	Estudiante* e5 = new Estudiante("jair","coraje",7775,9999995);
	Estudiante* e6 = new Estudiante("ismael","coraje",7776,9999996);
	Estudiante* e7 = new Estudiante("ana","coraje",7777,9999997);

	HashTabla* hte = new HashTabla(10);
	HashTabla* hte2 = new HashTabla(10);
	string keyse[] = { "eric","lucero","hiro","josue","jair","ismael","ana"};

	hte->insertar(string_sumatoria("eric"), e->ToString());
	hte->insertar(string_sumatoria("lucero"), e2->ToString());
	hte->insertar(string_sumatoria("hiro"), e3->ToString());
	hte->insertar(string_sumatoria("josue"), e4->ToString());
	hte->insertar(string_sumatoria("jair"), e5->ToString());
	hte->insertar(string_sumatoria("ismael"), e6->ToString());
	hte->insertar(string_sumatoria("ana"), e7->ToString());

	cout << "\nCriba Eratostenes: ";
	criba(hte->sizeactual());

	t1 = clock();
	imprimirTablaHashSumatoria(hte, keyse);
	t2 = clock();
	double tiempo = (double(t2 - t1) / CLOCKS_PER_SEC);
	cout << "\nColisiones: " << hte->getcont_colisiones();
	cout << "\nEl tiempo de ejecucion de busqueda de sumatoria: " << tiempo;
	cout << "\n-----------------------------------------------------";

	hte2->insertar(string_potencia("eric"), e->ToString());
	hte2->insertar(string_potencia("lucero"), e2->ToString());
	hte2->insertar(string_potencia("hiro"), e3->ToString());
	hte2->insertar(string_potencia("josue"), e4->ToString());
	hte2->insertar(string_potencia("jair"), e5->ToString());
	hte2->insertar(string_potencia("ismael"), e6->ToString());
	hte2->insertar(string_potencia("ana"), e7->ToString());

	t3 = clock();
	imprimirTablaHashPotencia(hte2, keyse);
	t4 = clock();
	double tiempo2 = (double(t4 - t3) / CLOCKS_PER_SEC);
	cout << "\nColisiones: " << hte2->getcont_colisiones();
	cout << "\nEl tiempo de ejecucion de busqueda de potencia: " << tiempo2;
	cout << "\nana: " << "304 % 10: "<<304 % 10 << ", 1108 % 10: " << 1108 % 10;
	cin.get();
	return 0;
}

/*
//OUTPUT:

Criba Eratostenes:
Numero de elementos: 7
Primo cercano: 11

SIZE TABLA: 10
SIZE ACTUAL: 7
eric    | Key: 9
lucero  | Key: 0
hiro    | Key: 4
josue   | Key: 0
jair    | Key: 2
ismael  | Key: 5
ana     | Key: 4

HashTable ordenado:
 0 : lucero obispo 7772 9999992
 1 : josue rodriguez 7774 9999994
 2 : jair coraje 7775 9999995
 3 : -
 4 : hiro rodriguez 7773 9999993
 5 : ismael coraje 7776 9999996
 6 : ana coraje 7777 9999997
 7 : -
 8 : -
 9 : eric cuevas 7771 9999991

Colisiones: 5
El tiempo de ejecucion de busqueda de sumatoria: 0.015
-----------------------------------------------------

SIZE TABLA: 10
SIZE ACTUAL: 7
eric    | Key: 3
lucero  | Key: 0
hiro    | Key: 6
josue   | Key: 8
jair    | Key: 0
ismael  | Key: 7
ana     | Key: 8

HashTable ordenado:
 0 : lucero obispo 7772 9999992
 1 : jair coraje 7775 9999995
 2 : -
 3 : eric cuevas 7771 9999991
 4 : -
 5 : -
 6 : hiro rodriguez 7773 9999993
 7 : ismael coraje 7776 9999996
 8 : josue rodriguez 7774 9999994
 9 : ana coraje 7777 9999997

Colisiones: 4
El tiempo de ejecucion de busqueda de potencia: 0.048
ana: 304 % 10: 4, 1108 % 10: 8
*/