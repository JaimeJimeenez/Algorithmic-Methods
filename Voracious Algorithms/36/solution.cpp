/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

/*@ <answer>

 
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Trabajo {
    int inicio;
    int fin;
    int duracion;
};

class ComparadorTrabajos {
public:
    bool operator()(Trabajo const& a, Trabajo const& b) const {
        return a.inicio < b.inicio;
    }
};

void print(vector<Trabajo> const& radio) {
    for (auto elem : radio) {
        cout << elem.inicio << " " << elem.fin << " - ";
    }
    cout << endl;
}

bool resuelveCaso() {
    
    int C, F, N;
    cin >> C >> F >> N;
    if (F == 0)
        return false;

    vector <Trabajo> radio;
    int ci, fi;
    while (N--) {
        cin >> ci >> fi;
        radio.push_back({ci, fi, fi - ci});
    }
    sort(radio.begin(), radio.end(), ComparadorTrabajos());
    print(radio);

    if (radio[0].inicio > C) { //Caso en que se inicie con un tiempo de inicio mayor que el intervalo Ci
        cout << "Imposible\n";
        return true;
    }

    int finT = radio[0].fin;
    int durT = 0;
    int trabajos = 0;
    for (int i = 1; i < radio.size() && radio[i].fin >= F; i++) {
        if (finT < radio[i].inicio) {
            cout << "Imposible\n";
            return true;
        }
        else if (durT < radio[i].duracion){
            finT = radio[i].fin;
            durT = radio[i].duracion;
            trabajos++;
        }
    }
    if (finT < F) { //Caso en el que se acaben los trabajos y se llegue a que no pasa de Fi
        cout << "Imposible\n";
        return true;
    }

    cout << trabajos << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   while (resuelveCaso());
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
