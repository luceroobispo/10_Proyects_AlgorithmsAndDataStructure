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
		cout << "1. Fisher Yates" << endl;
		cout << "2. Bubble Sort" << endl;
		cout << "3. Insertion Sort" << endl;
		cout << "4. Selection Sort" << endl;
		cout << "5. Shell Sort" << endl;
		cout << "6. Merge Sort" << endl;
		cout << "7. Quick Sort" << endl;
		cout << "8. Quick Select" << endl;
		cout << "9. Heap Sort" << endl;
		cout << "10. Salir" << endl;
	}

	template <typename T>
	void bubbleSort(T arr[], int n) {//1+1=2
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
	}

	template <typename T>
	void insertionSort(T arr[], int n) { // 1 + 1 = 2
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
		//Big O() = 2 + 2 + 2 + 1 + n( 1 + 2 + 1 +2 + n(2 + 1 + 1 + 2 + 2) + 2) + 2
		//Big O() = 9 + n(8 + 10n)
		//Big O(9 + 8n + 10 n^2)
		//Big O(n^2)
	}

	template <typename T>
	void selectionSort(T arr[], int n) { //2
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
	}

	template <typename T>
	void shellSort(T arr[], int n) {
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
	}

	template <typename T>
	void Merge(T* A1, T* A2, T* A, int n) {
		int i = 0, j = 0, k = 0;
		int mitad = n / 2;
		while (i < mitad && j < n - mitad) {
			if (A1[i] < A2[j]) {
				A[k] = A1[i];
				i++; k++;
			}
			else {
				A[k] = A2[j];
				j++; k++;
			}
		}
		while (i < mitad) {
			A[k] = A1[i];
			i++; k++;
		}
		while (j < n - mitad) {
			A[k] = A2[j];
			j++; k++;
		}
	}

	template <typename T>
	void mergeSort(T* A, int n) {
		if (n > 1) {
			int mitad = n / 2;
			T* A1 = new int[mitad];
			T* A2 = new int[n - mitad];

			for (int i = 0; i < mitad; i++) {
				A1[i] = A[i];
			}
			for (int i = mitad; i < n; i++) {
				A2[i - mitad] = A[i];
			}
			mergeSort(A1, mitad);
			mergeSort(A2, n - mitad);
			Merge(A1, A2, A, n);
		}
	}

	template <typename T>
	int particion(T* A, int p, int r) {
		int x = A[r]; //el pivote
		int i = p - 1; //indice de los menores
		for (int j = p; j < r; j++) {
			if (A[j] <= x) {
				i++;
				swap(A[i], A[j]);
			}
		}
		swap(A[i + 1], A[r]);
		return i + 1;
	}

	template <typename T>
	void quicksort(T* A, int p, int r) {
		int q; //para almacenar el indice del pivote

		if (p < r) {
			q = particion(A, p, r); //devuelve el indice del pivote
			quicksort(A, p, q - 1);
			quicksort(A, q + 1, r);
		}
	}

	template <typename T>
	int quickselect(T* A, int p, int r, int k) {
		if (p == r) return A[p];
		//indice del pivote con A ordenado Izq(Menores) Der(Mayores) al pivote
		int q = particion(A, p, r);
		int l = q - p + 1; //nro elementos del sub arreglo donde se encuentra el kesimo elemento
		if (k == l)
			return A[q];
		else if (k < l) {
			return quickselect(A, p, q - 1, k);
		}
		else {
			return quickselect(A, q + 1, r, k - l);
		}
	}

	template <typename T>
	void mostrar(T arr[], int n) {
		int j = 0;
		while (j < n) {
			cout << arr[j]<<" ";
			j++;
		}
		cout << endl;
	}

	int parent(int i) {
		return (i - 1) / 2;
	}
	int left(int i) {
		return 2 * i + 1;
	}
	int rigth(int i) {
		return 2 * i + 2;
	}

	template <typename T>
	void maxHeapify(T A[], int n, int i) {
		int l = left(i);
		int r = rigth(i);
		int largest(0);
		if (l <= (n - 1) && A[l] > A[i]) {
			largest = l;
		}
		else
			largest = i;
		if (r <= (n - 1) && A[r] > A[largest]) {
			largest = r;
		}
		if (largest != i) {
			swap(A[i], A[largest]);
			maxHeapify(A, n, largest);
		}
	}

	template <typename T>
	void buildMaxHeap(T A[], int n) {
		for (int i = n / 2 - 1; i >= 0; --i) {
			maxHeapify(A, n, i);
		}
	}

	template <typename T>
	void print(T A[], int n) {
		for (int i = 0; i < n; ++i) {
			cout << A[i] << " ";
			//cout << endl;
		}
	}

	//aplicación de ordenamiento
	template <typename T>
	void heapsort(T A[], int n) {
		buildMaxHeap(A, n);
		for (int i = n - 1; i > 0; --i) {
			swap(A[0], A[i]);
			maxHeapify(A, --n, 0);
		}
	}

	template <typename T>
	void fisher_yates(T arr[], int n) { // 2
		std::srand(std::time(nullptr)); //2
		for (int i = n - 1; i > 0; i--) {// 2 + 1 + 2
			int j = (rand() % (i + 1)); //3
			int aux = arr[j];//1
			arr[j] = arr[i]; //1
			arr[i] = aux;//1
		}
		//Tiempo detalladao = 2+2+2+logn + n(2+1+2+3+1+1+1) + 2 + logn
		//Tiempo asintotico = 8+ logn + 11n + logn
		//Big O(n) -> Se pone el PEOR caso
	}

	void run() {
		int opc;
		//char arr[] = { 's','o','k','y','b' };
		int arr[] = { 5, 6, 9, 1, 2, 4, 7 };
		int N = sizeof(arr) / sizeof(arr[0]);
		do {
			menu();
			cout << "Ingrese una opcion: ";
			cin >> opc;
			switch (opc) {
			case 1:
				cout << "\nAntes: " << endl; 
				mostrar(arr, N);
				fisher_yates(arr, N);
				cout << "\nDespues: " << endl;
				mostrar(arr, N);
				break;
			case 2:
				cout << "\nAntes: " << endl;
				mostrar(arr, N);
				bubbleSort(arr, N);
				cout << "\nDespues: " << endl;
				mostrar(arr, N);
				break;
			case 3:
				cout << "\nAntes: " << endl;
				mostrar(arr, N);
				insertionSort(arr,N);
				cout << "\nDespues: " << endl;
				mostrar(arr, N);
				break;
			case 4:
				cout << "\nAntes: " << endl;
				mostrar(arr, N);
				selectionSort(arr,N);
				cout << "\nDespues: " << endl;
				mostrar(arr, N);
				break;
			case 5:
				cout << "\nAntes: " << endl;
				mostrar(arr, N);
				shellSort(arr,N);
				cout << "\nDespues: " << endl;
				mostrar(arr, N);
				break;
			case 6:
				cout << "\nAntes: " << endl;
				mostrar(arr, N);
				mergeSort(arr,N);
				cout << "\nDespues: " << endl;
				mostrar(arr, N);
				break;
			case 7:
				cout << "\nAntes: " << endl;
				mostrar(arr, N);
				quicksort(arr, 0, N-1);
				cout << "\nDespues: " << endl;
				mostrar(arr, N);
				break;
			case 8:
				cout << "\nAntes: " << endl;
				mostrar(arr, N);
				cout << "\nKesimo elemento es: " << quickselect(arr, 0, N - 1, 6) << endl;
				break;
			case 9:
				cout << "\nAntes: " << endl;
				mostrar(arr, N);
				cout << "\nHEAPSORT: " << endl;
				buildMaxHeap(arr, 7);
				print(arr, 7);
				cout << "\nDespues: " << endl;
				heapsort(arr, 7);
				print(arr, 7);
			case 10: exit(0);
				break;
			default:
				break;
			}
			system("pause");
			system("CLS");
		} while (1);
	}

};