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
        cout << elem.inicio << " " << elem.fin << " ";
    }
    cout << endl;
}

bool resuelveCaso() {
    int C, F, N;
    cin >> C >> F >> N;
    if (F == 0) 
        return false;
    
    vector<Trabajo> radio;
    int ci, fi;
    while (N--) {
        cin >> ci >> fi;
        radio.push_back({ci, fi, fi - ci});
    }

    sort(radio.begin(), radio.end(), ComparadorTrabajos());
    print(radio);

    if (radio[0].inicio > C) {
        cout << "Imposible\n";
        return true;
    }

    int trabajos = 1;
    
    auto [inicioI, finalI, duracionI] = radio[0];
    vector<Trabajo> finTrabajos;
    for (int i = 1; i < radio.size(); i++) {
        cout << radio[i].inicio << " " << radio[i].fin << " " << radio[i].duracion << endl;
        if (inicioI < radio[i].inicio) {
            auto [nuevoinicio, nuevofin, nuevaDur] = radio[i];
            finTrabajos.push_back(radio[i]);
        }
        else if (inicioI == radio[i].inicio) {
            if (duracionI < radio[i].duracion) {
                auto [nuevoInicio, nuevoFin, nuevaDur] = radio[i];
                finTrabajos.push_back(radio[i]);
            }
        }
        else { //Los intervalos de los trabajos no coinciden.
            cout << "Imposible\n";
            return true;
        }
    }
    print(finTrabajos);
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
   // ajustes para que cin extraiga directamente de un fichero
/*#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif*/
   
   while (resuelveCaso());
   
   // para dejar todo como estaba al principio
/*ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif*/
   return 0;
}
