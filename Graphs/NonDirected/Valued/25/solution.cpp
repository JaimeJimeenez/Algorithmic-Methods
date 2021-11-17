/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include "GrafoValorado.h"
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

/*@ <answer>
 
 Se parte de un grafo valorado en el que las ciudades son los vértices que componen dicho grafo
 y sus aristas las carreteras cuyo valor es el precio por construir estas.
 Con respecto a los aeropuertos se necesitará construir n numeros de aeropuertos para n números de componentes
 conexas que se obtengan.
 
 Coste O(V) siendo V el número de vértices del grafo construido.
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class Construccion {
    vector<bool> visit;
    int aeropuerto, coste;

    void dfs(GrafoValorado<int> const& G, int v) {
        visit[v] = true;

        for (auto w : G.ady(v)) {
            if(!visit[w.otro(v)]) {
                int minimo;
                if (v == w.uno()) 
                    minimo = getCosteMinimo(G, w.uno(), w.otro(v));
                else
                    minimo = getCosteMinimo(G, w.uno(), v);
                coste += minimo;
                dfs(G, w.otro(v));
            }
        }

    }

    int getCosteMinimo(GrafoValorado<int> const& G, int v, int w) {
        int minimo = 1000000;

        for (auto z : G.ady(v)) {
            if (z.otro(v) == w) 
                minimo = min(minimo, z.valor());
        }

        return minimo;
    }

public:
    Construccion(GrafoValorado<int> const& G, int costeA) : visit(G.V(), false), aeropuerto(0), coste(0) {
        for (int v = 1; v < G.V(); v++) {
            if (!visit[v]) {
                dfs(G, v);
                aeropuerto++;
            }
        }
        coste += costeA * aeropuerto;
    }

    int getAeropuertos() const {
        return aeropuerto;
    }

    int getCoste() const {
        return coste;
    }
};

bool resuelveCaso() {
    
    int N, M, A;
    cin >> N >> M >> A;
    if (!std::cin) 
      return false;
    
    GrafoValorado <int> aeropuerto(N + 1); //No se cogerá el vértice 0
    int X, Y, C;
    while (M--) {
        cin >> X >> Y >> C;
        aeropuerto.ponArista({X, Y, C});
   }

   Construccion c(aeropuerto, A);
   cout << c.getCoste() << " " << c.getAeropuertos() << "\n";

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
