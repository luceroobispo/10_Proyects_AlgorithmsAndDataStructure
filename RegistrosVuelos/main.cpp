#include <iostream>
#include<functional>
#include <string>
#include<vector>
#include<stdlib.h>
#include<time.h>

using namespace std;

template <class T>
class Tree {
	template <class T>
	class Node {//inner class
	public:
		Node<T>* l; //izquierda
		Node<T>* r; //derecha
		T e;
		Node(T e) { r = l = nullptr; this->e = e; }
	};
	Node<T>* root;
	bool (*compare) (T,T);
	function<void(T)> fprint;
public:
	Tree() {}
	Tree(function<void(T)> fprint, bool (*compare)(T,T)) {
		this->fprint = fprint;
		root = nullptr;
		this->compare = compare;
	}
	~Tree() {}

	void add(T e, Node<T>*& tmp) {
		if (tmp == nullptr) tmp = new Node<T>(e);
		else if (compare(e, root->e)) { add(e, tmp->r); }
		else add(e, tmp->l);
	}

	void _postOrden(Node<T>* nodo) {
		if (nodo == nullptr) return;
		_postOrden(nodo->l);
		_postOrden(nodo->r);
		fprint(nodo->e);
	}

	void add(T e) {
		add(e, root);
	}

	void postOrden() {
		_postOrden(root);
	}
};

class Registro {
private:
	int nr, ida, idv;
	string ma;
public:
	Registro(int nr = 0,int ida=0,int idv=0,string ma="") :nr(nr),ida(ida),idv(idv),ma(ma) {}
	~Registro() {}

	string toString() { return "\n Nro. "+to_string(nr) + " | ID A: " + to_string(ida) + " | ID V: " + to_string(idv) + " | Matric Avion: " + ma; }
	int getidv() { return idv; }
};

class Vuelos {
private:
	vector<Registro> v;
	Tree<Registro>* t;
	int n;
public:
	Vuelos() { 
		srand(time(NULL));
		n = 100 + rand() % (5001 - 100); 
		auto imprime = [](Registro r) {cout << r.toString() << endl; };
		t = new Tree<Registro>(imprime, [](Registro r, Registro r2) -> bool {return r.getidv()>=r2.getidv(); });
	}
	~Vuelos() {}

	void generarData() {
		srand(time(NULL));
		int nr=0, ida=0, idv=0;
		string ma="AB00";
		int first = 'A';
		for (int i = 0; i < n;i++) {
			nr = i+1;
			ida= 1000 + rand() % (9999 - 1000);
			idv= 10000 + rand() % (99999 - 10000);
			ma[0] = (char)(first + rand() % (90 - first + 1));
			ma[1] = (char)(first + rand() % (90 - first + 1));
			int a = 1 + rand() % (10 - 1);
			ma[2] = a + '0';
			ma[3] = a + '0';
			v.push_back(Registro(nr,ida,idv, ma));
		}
	}

	void listarVector() {
		for (int i = 0; i<v.size(); i++) { cout << v[i].toString(); }
	}

	void addArbol() {
		for (int i = 0; i < 100; i++) {
			t->add(v[i]);
		}
	}

	void listarArbol() {
		t->postOrden();
	}

};

void menu()	{
	cout <<" MENU --------------------"<< endl;
	cout <<" 1. Generar datos"<< endl;
	cout <<" 2. Indexar en arbol binario de busqueda"<< endl;
	cout <<" 3. Salir"<< endl;
}

int main() {
	Vuelos* v = new Vuelos();
	int opc;
	do {
		menu();
		cout << "Ingrese una opcion: ";
		cin >> opc;
		switch (opc) {
		case 1:
			cout << "\n VECTOR: " << endl;
			v->generarData();
			v->listarVector();
			break;
		case 2:
			cout << "\n ARBOL: " << endl;
			v->addArbol();
			v->listarArbol();
			break;
		case 3: exit(0);
			break;
		default:
			break;
		}
		system("pause");
		system("CLS");
	} while (1);
	return 0;
}
