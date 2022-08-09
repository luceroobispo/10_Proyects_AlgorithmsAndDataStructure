#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <ctime> 
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <cmath>
using namespace std;
namespace DS {
	template<class G>
	class Tree {
		template<class T>
		class Node {//inner class(composicion)
		public:
			Node<T>* l, * r, *cl, *cr;
			T data;
			int altura = 0;
			Node(T d) :data(d) { l = r = cl = cr = nullptr; altura = 0; }
		};
		Node<G>* root;
		int(*cmp)(G);
		void (*imp)(G);
	public:
		Tree(int(*cmp)(G), void (*imp)(G)) :cmp(cmp), imp(imp) { root = nullptr; }
		
		int _altura(Node<G>* nodo) {
			if (nodo == nullptr) return 0;
			return nodo->altura;
		}

		void insert(G e, Node<G>*& tmp) {
			if (tmp == nullptr) tmp = new Node<G>(e);
			else {
				int opc = cmp(e);
				switch (opc) {
				case 0: insert(e, tmp->l); break;
				case 1: insert(e, tmp->cl); break;
				case 2: insert(e, tmp->cr); break;
				case 3: insert(e, tmp->r); break;
				};
			}
		}

		void insert(G e) {
			insert(e, root);
		}

		void insert_v(G e, Node<G>*& tmp, function<int(G, G)> condicion) {
			if (tmp == nullptr)
				tmp = new Node<G>(e);
			else if (condicion(e, tmp->data))
				insert_v(e, tmp->r, condicion);// a la izquierda
			else insert_v(e, tmp->l, condicion); // a la derecha
			_balanceo(tmp);
		}

		void insert_v(G e, function<int(G, G)> condicion) {
			insert_v(e, root, condicion);
		}

		bool Eliminar(G e, function<int(G, G)> condicion) {
			return _eliminar(root, e, condicion);
		}

		void print() { enOrden(root); }

		void enOrden(Node<G>* tmp) {//enOrden
			if (tmp == nullptr)return;
			enOrden(tmp->l);
			enOrden(tmp->cl);
			imp(tmp->data);
			enOrden(tmp->cr);
			enOrden(tmp->r);
		}
		void preOrden(Node<G>* tmp) {//preOrden
			if (tmp == nullptr)return;
			cout << tmp->data << " ";
			preOrden(tmp->l);
			enOrden(tmp->cl);
			enOrden(tmp->cr);
			preOrden(tmp->r);
		}
		void postOrden(Node<G>* tmp) {//postOrden
			if (tmp == nullptr)return;
			postOrden(tmp->l);
			postOrden(tmp->cl);
			postOrden(tmp->cr);
			postOrden(tmp->r);
			cout << tmp->data << " ";
		}

		bool Buscar(G e, function<int(G, G)> condicion) {
			return _buscar(root, e, condicion);
		}

		bool _buscar(Node<G>* nodo, G e, function<int(G, G)> condicion) {
			if (nodo == nullptr) return false;
			else {
				int r = condicion(nodo->data, e);
				if (r == 0) return true;
				else if (r < 0) {
					return _buscar(nodo->r, e, condicion);
				}
				else {
					return _buscar(nodo->l, e, condicion);
				}
			}
		}
	
		bool _eliminar(Node<G>*& nodo, G e, function<int(G, G)> condicion) { // para el de dos hijos
			if (nodo == nullptr) return false;
			int r = condicion(nodo->data, e);// 0 1 2 3 // 2
			
			if (r == 0) { // if r == 0 //
				if (nodo->r == nullptr && nodo->l == nullptr) {//caso 1
					nodo = nullptr;
					delete nodo;
					return true;
				}
				else if (nodo->l == nullptr) { //caso 2
					nodo = nodo->r;
					return true;
				}
				else if (nodo->r == nullptr) { //caso 3
					nodo = nodo->l;
					return true;
				}
				else { //caso 4
					Node<G>* aux = nodo->r; //Se establece buscar el menor elemento por la derecha
					while (aux->l != nullptr)
					{
						aux = aux->l; //Se obtiene la hoja menor
					}
					nodo->data = aux->data; //Se actualiza el elemento en el nodo raiz y
					return _eliminar(nodo->r, aux->data, condicion); //se envía a eliminar el elemento en el arbol por la derecha
				}
			}
			else if (r < 0) { // 2 // a
				return _eliminar(nodo->r, e, condicion);
			}
			else if (r > 0) {
				return _eliminar(nodo->l, e, condicion);
			}
		}

		void _rotarDerecha(Node<G>*& nodo) {
			Node<G>* p = nodo->l;
			nodo->l = p->r;
			p->r = nodo;
			//Actualizamos la altura
			nodo = p;
		}

		void _rotarIzquierda(Node<G>*& nodo) {
			Node<G>* p = nodo->r;
			nodo->r = p->l;
			p->l = nodo;
			//Actualizamos la altura
			nodo = p;
		}

		void _balanceo(Node<G>*& nodo) {
			int hizq = _altura(nodo->l);
			int hder = _altura(nodo->r);
			int fb = hder - hizq;

			if (fb > 1) { //rotar a la izq
				int hhizq = _altura(nodo->r->l);
				int hhder = _altura(nodo->r->r);
				if (hhizq > hhder) { //verificar si aplica doble rotación
					_rotarDerecha(nodo->r);
				}
				_rotarIzquierda(nodo);
			}
			if (fb < -1) { //rotar a la der
				int hhizq = _altura(nodo->l->l);
				int hhder = _altura(nodo->l->r);
				if (hhizq < hhder) {//verificar si aplica doble rotación 
					_rotarIzquierda(nodo->l);
				}
				_rotarDerecha(nodo);
			}
			//Actualizar la altura del nodo raiz
			hizq = _altura(nodo->l);
			hder = _altura(nodo->r);
			nodo->altura = 1 + ((hizq > hder) ? hizq : hder);
		}
	};
};

namespace Ejemplo1 {
	using namespace DS;
	class Poliza {
		int importe;
		string nro;
		string nombreB;
		friend class Coleccion;
	public:
		Poliza(int importe, string nro, string nombreB) :importe(importe), nro(nro), nombreB(nombreB) {}
		string toString() { return "(" + nro + " " + to_string(importe) + " " + nombreB + ")"; }
	};
	class Coleccion {
		Tree<Poliza>* arbol;
		Tree<Poliza>* arbolV;
		vector<Poliza> vecR;//list, queue, stack
	public:
		Coleccion() {
			auto l = [](Poliza x) {cout << x.toString() << endl; };

			arbol = new Tree<Poliza>([](Poliza r) {
				switch (r.nro[0]) {
				case 'a':return 0; break;
				case 'b':return 1; break;
				case 'c':return 2; break;
				case 'd':return 3; break;
				};
				}, l);

			arbolV = new Tree<Poliza>([](Poliza r) {
				switch (r.nro[0]) {
				case 'a':return 0; break;
				case 'b':return 1; break;
				case 'c':return 2; break;
				case 'd':return 3; break;
				};
				}, l);

		}
		void datos() {
			string nombre = "ABCD";
			string apellido = "ABCD";
			string fn = "";
			int first = 'a';
			char letra = ' ';
			srand(time(NULL));
			for (size_t i = 0; i < 20; ++i) {
				nombre[0] = (char)(first + rand() % (122 - first + 1));
				nombre[1] = (char)(first + rand() % (122 - first + 1));
				nombre[2] = (char)(first + rand() % (122 - first + 1));
				nombre[3] = (char)(first + rand() % (122 - first + 1));
				apellido[0] = (char)(first + rand() % (122 - first + 1));
				apellido[1] = (char)(first + rand() % (122 - first + 1));
				apellido[2] = (char)(first + rand() % (122 - first + 1));
				apellido[3] = (char)(first + rand() % (122 - first + 1));
				fn = nombre + " " + apellido;
				letra = (char)(first + rand() % (100 - first + 1));
				vecR.push_back(Poliza(rand() % 1000, letra + to_string(rand() % 1000), fn));
				fn = " ";
			}
		}

		void leerdatos() {
			ifstream arch("polizas.txt");
			string line;
			while (getline(arch, line, '\n')) {
				string aux;
				int importe=0;
				string nro;
				string nombreB;
				string apellidoB;
				string nombreCompleto;

				stringstream s(line);
				getline(s, aux, ' ');
				importe = std::stoi(aux);
				getline(s, aux, ' ');
				nro = aux;
				getline(s, aux, ' ');
				nombreB = aux;
				getline(s, aux, ' ');
				apellidoB = aux;
				nombreCompleto = nombreB + ' ' + apellidoB;
				vecR.push_back(Poliza(importe,nro,nombreCompleto));
			}
			arch.close();
		}

		void indexar() {
			for (size_t i = 0; i < vecR.size(); ++i) {
				arbol->insert(vecR[i]);// indexa para el campo X
			}
		}
		void imprimir() {
			cout << "\nArbol de 4 hijos: " << endl;
			arbol->print();
		}

		void imprimir_v() {
			cout << "\nArbol de 2 hijos: " << endl;
			arbolV->print();
		}
		void indexar_v() {
			auto condicion = [](Poliza a, Poliza b) { return  a.nro.compare(b.nro) >= 0; };
			for (size_t i = 0; i < vecR.size(); ++i) {
				arbolV->insert_v(vecR[i], condicion);
			}
		}
		void eliminar() {
			cout << "\n Eliminar datos del arbol binario: " << endl;
			auto condicion = [](Poliza a, Poliza b) {
				if (a.nro.compare(b.nro) == 0) return 0;
				else if (a.nro.compare(b.nro) > 0) return 1;
				else return -1;
			};
			arbolV->Eliminar(vecR[2], condicion);
			cout << "\n Se elimino: " << vecR[2].toString()<< endl;
			arbolV->print();
		}

		void buscar() {
			auto condicion = [](Poliza a, Poliza b) {
				if (a.nro.compare(b.nro) == 0) return 0;
				else if (a.nro.compare(b.nro) > 0) return 1;
				else return -1;
			};
			cout << endl<<endl;
			if(arbolV->Buscar(vecR[2], condicion)) cout<<"Se encontro"<<endl;
			else cout << "No se encontro" << endl;
		}
	};

	void test() {
		Coleccion c;
		c.leerdatos();
		c.indexar();
		c.indexar_v();
		c.imprimir();
		c.imprimir_v();
		c.eliminar();
		c.buscar();
	}
}
	int main() {
		Ejemplo1::test();
		return 0;
	}
