#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

//Ejercicio: implementar el método buscar por el tipo de dato string manteniendo una estructura generica.

template <class T>
class Ejemplo {
    T e;
    vector<T> v;
    function<int(T, vector<T>)> f;//funcion como atributo de clase
public:
    Ejemplo(T e, vector<T> v, function<int(T, vector<T>)> f) : e(e), v(v), f(f) {}
    ~Ejemplo() {}
    T gete() { return e; }
    int funcion() {
        return f(e, v);
    }

    void print() {
        for (const auto& elemento : v) {
            cout << elemento << "  ";
        }
        cout << endl;
    }

};

template<typename T>
int searchRec(T v, int s, int e, vector<T> vector) {
    if (s <= e) {
        int m = s + (e - s) / 2;
        if (v == vector[m])return m;//encuentra
        else if (v > vector[m])return searchRec(v, m + 1, e, vector);//derecha
        else return searchRec(v, s, m - 1, vector);//izquierda
    }return -1;//no lo encuentra
}


template<typename T>
int searchIt(T x, vector<T> vector) {
    int inicio = 0, fin = vector.size();
    while (inicio <= fin) {
        int mitad = (inicio + fin) / 2;
        if (vector[mitad] < x)
            inicio = mitad + 1;
        else if (vector[mitad] > x)
            fin = mitad - 1;
        else if (vector[mitad] == x)
            return mitad;
    }
    return -1;
}

int toInt(string key) {
    int result = 0;
    for (int i = 0; i < key.length(); i++) {
        result += int(key[i]);
    }
    return result;
}

vector<int> vectorInt(vector<string> v) {
    vector<int> nv;
    for (int i = 0; i < v.size(); i++) {
        nv.push_back(toInt(v[i]));
    }
    return nv;
}

int main() {
    vector<int> v = { 10,20,30,40,50 };
    Ejemplo<int> ejmEnteros(20, v, [](int e, vector<int> vt) {
        return searchRec(e, 0, vt.size(), vt); });

    ejmEnteros.print();
    cout << " -> "<< ejmEnteros.gete() << " esta en la posicion " << ejmEnteros.funcion() << endl;


    vector<string> vs = { "Ana", "Cecilia", "Juan", "Fidel", "Gertrudes" };
    sort(vs.begin(), vs.end());
    Ejemplo<string> ejmCadenas("Fidel", vs, [](string e, vector<string> vt) {
        return searchIt(toInt(e), vectorInt(vt)); });

    cout << endl;
    ejmCadenas.print();
    cout << " -> " << ejmCadenas.gete() << " esta en la posicion " << ejmCadenas.funcion() << endl;
    
    cin.get();
    return 0;
}
