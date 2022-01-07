/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Matriz.h"
#include "EnterosInf.h"
using namespace std;

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Festival {
    int entrada;
    int grupos;
};

class CompararFestival {
public:
    bool operator()(Festival const& a, Festival const& b) const {
        return (a.grupos > b.grupos) || (a.grupos == b.grupos && a.entrada < b.entrada);
    }
};



bool resuelveCaso() {

    int P, N;
    cin >> P >> N;
    if (!cin)
        return false;

    vector<Festival> festivales(N);
    for (int i = 0; i < N; i++) {
        int grupo, entrada;
        cin >> grupo >> entrada;
        festivales.at(i) = {grupo, entrada};
    }
    sort(festivales.begin(), festivales.end(), CompararFestival());

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
