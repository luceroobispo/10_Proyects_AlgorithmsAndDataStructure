#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <random>
using namespace std;
class Controlador {
public:
	Controlador() {}
	~Controlador() {}
	void menu() {
		cout << "1. Bubble Sort" << endl;
		cout << "2. Insertion Sort" << endl;
		cout << "3. Selection Sort" << endl;
		cout << "4. Shell Sort" << endl;
		cout << "5. " << endl;
		cout << "6. Fisher Yates" << endl;
		cout << "7. Salir" << endl;
	}

	void swap(char a, char b) {
		char aux = a;
		a = b;
		b = aux;
		
	}
	void bubbleSort(char arr[], int n) {//1+1=2
		cout << "Antes: " << endl; //1+1=2
		mostrar(arr,n);
		bool ordenado; //1
		for (int i = 0; i < n - 1; i++) {//1 + 2(n-1) + 2(n-1) = 1 + 4(n-1)
			ordenado = true; //1
			for (int j = 0; j < n - (i + 1); j++) {//n-1 + n - [(n(n+1)/2) + 1] + 2n/(n+1)/2 =
				if (arr[j] > arr[j + 1]) { //1 + 1 = 2
					int aux = arr[j]; //1
					arr[j] = arr[j + 1]; //1 + 1 = 2
					arr[j + 1] = aux; //1 + 1 = 2
					ordenado = false;//1
				}
			}
			if (ordenado) break; //1
		}
		//Big O() = 2 + 1 + n(1 + n(2+1+2+2+1) + 1)

		cout << "\nDespues: " << endl;//1+1=2
		mostrar(arr,n);
	}

	void insertionSort(char arr[], int n) { // 1 + 1 = 2
		cout << "Antes: " << endl; // 1 + 1 = 2
		mostrar(arr, n);
		int key, j; // 2
		for (int i = 1; i < n; i++) { // 1 +    1 + 2
			key = arr[i]; //1
			j = i - 1; //2
			while (j >= 0 && arr[j] > key) { // n(2 + 1 + 1)
				arr[j + 1] = arr[j]; // 2
				j = j - 1; // 2
			}
			arr[j + 1] = key; // 2
		}

		cout << "\nDespues: " << endl; // 2
		mostrar(arr, n);

		//Big O() = 2 + 2 + 2 + 1 + n( 1 + 2 + 1 +2 + n(2 + 1 + 1 + 2 + 2) + 2) + 2
		//Big O() = 9 + n(8 + 10n)
		//Big O(9 + 8n + 10 n^2)
		//Big O(n^2)
	}

	void selectionSort(char arr[], int n) { //2
		cout << "Antes: " << endl;
		mostrar(arr, n);
		int pMenor;
		int menor;
		for (int i = 0; i < n - 1; ++i) {
			menor = arr[i];
			pMenor = i;
			for (int j = i + 1; j < n; ++j) {
				if (arr[j] < menor) {
					menor = arr[j];
					pMenor = j;
				}
			}
			if (pMenor != i) {
				int temp = arr[pMenor];
				arr[pMenor] = arr[i];
				arr[i] = temp;
			}
		}
		cout << "\nDespues: " << endl;
		mostrar(arr, n);
	}

	void shellSort(char arr[], int n) {
		cout << "Antes: " << endl;
		mostrar(arr, n);
		int i, j, k, intervalo = n / 2;
		char temp;
		while (intervalo > 0) {
			for (i = intervalo; i <= n; i++) {
				j = i - intervalo;
				while (j >= 0) {
					k = j + intervalo; //k = i
					if (arr[j] <= arr[k]) { j = -1; } //termina el bucle
					else {
						temp = arr[j];
						arr[j] = arr[k];
						arr[k] = temp;
						j -= intervalo;
					}
				}
				mostrar(arr, n);
			}
			intervalo = intervalo / 2;
			
		}

		cout << "\nDespues: " << endl;
		mostrar(arr, n);
	}

	void shellSort2(char arr[], int n) {
		cout << "Antes: " << endl;
		mostrar(arr, n);
		int intervalo = n / 2;
		while (intervalo > 0) {
			for (int i = intervalo; i < n; i += 1) {
				int temp = arr[i];
				int j;
				for (j = i; j >= intervalo && arr[j - intervalo] > temp; j -= intervalo) {
					arr[j] = arr[j - intervalo];
				}
				arr[j] = temp;
			}
			intervalo = intervalo / 2;
		}
		cout << "\nDespues: " << endl;
		mostrar(arr, n);
	}

	void mostrar(char arr[], int n) {
		int j = 0;
		while (j < n) {
			cout << arr[j]<<" ";
			j++;
		}
		cout << endl;
	}
	void fisher_yates(char arr[], int n) { // 2
		std::srand(std::time(nullptr)); //2
		cout << "Antes: " << endl; // 2
		mostrar(arr, n); //log n
		for (int i = n - 1; i > 0; i--) {// 2 + 1 + 2
			int j = (rand() % (i + 1)); //3
			int aux = arr[j];//1
			arr[j] = arr[i]; //1
			arr[i] = aux;//1
		}
		cout << "\nDespues: " << endl;//2
		mostrar(arr, n);//log n
		//Tiempo detalladao = 2+2+2+logn + n(2+1+2+3+1+1+1) + 2 + logn
		//Tiempo asintotico = 8+ logn + 11n + logn
		//Big O(n) -> Se pone el PEOR caso

	}

	void run() {
		int opc;
		char arr[] = { 's','o','k','y','b' };
		int N = sizeof(arr) / sizeof(arr[0]);
		do {
			menu();
			cout << "Ingrese una opcion: ";
			cin >> opc;
			switch (opc) {
			case 1:
				bubbleSort(arr, N);
				break;
			case 2:
				insertionSort(arr,N);
				break;
			case 3:
				selectionSort(arr,N);
				break;
			case 4:
				shellSort2(arr,N);
				break;
			case 5:
				break;
			case 6:
				fisher_yates(arr,N);
				break;
			case 7: exit(0);
				break;
			default:
				break;
			}
			system("pause");
			system("CLS");
		} while (1);
	}

};