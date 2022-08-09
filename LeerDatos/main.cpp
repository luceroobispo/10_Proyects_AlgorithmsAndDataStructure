#pragma once
#include <iostream>
#include <fstream>
#include <functional>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

void calcular(vector<int> potencia) { //1
	int arr[] = { 1,2,3,4,5,6,7,8,9 }; //2
	int N = sizeof(arr) / sizeof(arr[0]); //3
	cout << endl; //1
	for (int i = 0; i < potencia.size(); i++) { // 2 + n(2 + 2 + INTERNA)  -> n = tamaño del vector de potencia
		for (int j = 0; j < N; j++) { //2 + 9(1 + 2 + INTERNA) -> 9 es N que es el tamaño del arreglo
			cout << arr[j] << ":" << (long long)pow(arr[j], potencia[i]) << ", "; //3
		}
		cout << endl; //1
	}
	//Tiempo detallado: 1 + 2 + 3 + 1 + 2 + n(2 + 2 + 2 + 9(1 + 2 + 3)+ 1)
	//Tiempo asintótico: 9 + 61n
	//Big O(n)
	cout << "\nBigO(n)\n";
}

void leerdatos() {
	ifstream arch("input.txt");
	string line;
	vector<int> potencia;
	while (getline(arch, line, ' ')) {
		string aux;
		int p = 0;
		stringstream s(line);
		getline(s, aux, ' ');
		p = std::stoi(aux);
		potencia.push_back(p);
	}
	arch.close();
	calcular(potencia);
}

int main() {
	leerdatos();
	system("pause");
	return 0;
}
