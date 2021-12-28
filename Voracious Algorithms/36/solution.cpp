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
};

class ComparadorIntervalos {
public:
    bool operator()(Intervalo const& primero, Intervalo const& segundo) const {
        return primero.inicio < segundo.inicio;
    }
};

void trabajos(vector<Intervalo> const& intervalos, int& numTrabajos, int C, int F, int N, bool& imposible){

    int cubiertoHasta = C; 
    int siguiente = 0;
    while (!imposible && cubiertoHasta < F) {
        int max = cubiertoHasta;
        while (siguiente < N && intervalos[siguiente].inicio <= cubiertoHasta) {
            if (intervalos[siguiente].fin > max)
                max = intervalos[siguiente].fin;
            siguiente++;
        }
        
        if (max > cubiertoHasta) {
            numTrabajos++;
            cubiertoHasta = max;
        }
        else 
            imposible = true;
    }
}

bool resuelveCaso() {
    
    int C, F, N;
    cin >> C >> F >> N;
    if (F == 0)
        return false;

    vector <Intervalo> intervalos;
    int ci, fi;
    for (int i = 0; i < N; i++) {
        cin >> ci >> fi;
        intervalos.push_back({ci, fi});
    }
    sort(intervalos.begin(), intervalos.end(), ComparadorIntervalos()); //NlogN

    int numTrabajos = 0;
    bool imposible = false;
    trabajos(intervalos, numTrabajos, C, F, N, imposible);

    if (imposible)
        cout << "Imposible\n";
    else
        cout << numTrabajos << "\n";
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
