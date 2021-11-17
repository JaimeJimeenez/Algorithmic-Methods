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

struct Intervalo {
    int inicio;
    int fin;
    bool operator<(Intervalo const& other) const {
        return inicio < other.inicio;
    }
};

struct Trabajo {
    int inicio;
    int fin;
    int longitud;
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
    sort(radio.begin(), radio.end(), ComparadorTrabajos()); //NlogN
    print(radio);

    int cubiertoHasta = C;
    int sig = 0;
    int selecs = 0;
    bool imposible = false;
    while (!imposible && cubiertoHasta < F) {
        int maximo = cubiertoHasta;
        while (siguiente < N && intervalos[siguiente].inicio <= cubiertoHasta) { //Busqueda del intervalo que llega más lejos
            if (intervalos[siguiente].fin > maximo)
                maximo = intervalos[siguiente].fin;
            siguiente++;
        }
        if (maximo > cubiertoHasta) {
            ++selecs;
            cubiertoHasta = maximo;
        }
        else
            imposible = true;
    }

    if (imposible)
        cout << "Imposible\n";

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
