/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>

#include "GrafoValorado.h"
using namespace std;

/*@ <answer>
  
 Se pide conocer si existe un camino desde un un vértice origen a un vértice destino teniendo en cuenta
 que los pesos o costes de las aristas que unen dicho par de vértices no superen un umbral. Para ello se realiza
 el recorrido en profundidad y se pasará a otro vértice si el umbral es menor que el peso o coste de la arista.

 El coste de la operación es: O(V + A) siendo V el número de vertices y A el número de aristas.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class Recorrido {
public:
    Recorrido(GrafoValorado<int> const& g, int s, int umbral) : visit(g.V(), false) {
        dfs(g, s, umbral);
    }

    bool hayCamino(int v) const { return visit[v]; }

private:
    vector<bool> visit;

    void dfs(GrafoValorado<int> const& g, int v, int umbral) {
        visit[v] = true;
        for (auto a : g.ady(v)) {
            if (a.valor() >= umbral) {
                int w = a.otro(v);
                if (!visit[w]) 
                    dfs(g, w, umbral);
            }
        }
    }
};

bool resuelveCaso() {

    int V, E;
    cin >> V >> E;
    if (!cin)
        return false;

    GrafoValorado<int> grafo(V + 1);
    while (E--) {
        int v, w, coste;
        cin >> v >> w >> coste;
        grafo.ponArista({v, w, coste});
    }

    int K;
    cin >> K;
    while(K--) {
        int s, v, umbral;
        cin >> s >> v >> umbral;
        Recorrido r(grafo, s, umbral);
        if (r.hayCamino(v))
            cout << "SI\n";
        else 
            cout << "NO\n";
    }

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
