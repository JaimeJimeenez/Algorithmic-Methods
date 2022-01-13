/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>

#include "ConjuntosDisjuntos.h"
#include "GrafoValorado.h"
#include "PriorityQueue.h"
using namespace std;

/*@ <answer>
  
 Se quiere saber cuantos aeropuertos son necesarios para conectar varios puntos predefinidos y el coste minimo de construir carreteras que unan dichos puntos.
 Para ello, se representarán dichos puntos como un grafo en el que los sitios de interés serán sus vértices y las carrreteras que conecten dichos sitios sus aristas con su respectivo valor.
 Se utilizará el algoritmo de Kruskal para conseguir el árbol de recubrimiento mínimo y su coste minimo total. Además se consigue el número de conjuntos disjuntos que componen 
 el grafo que indicará el número mínimo de aeropuertos necesarios para conectar todos los puntos.

 El coste del ejercicio es:
    - En función del tiempo: O(A logA) siendo A el número de aristas que componen el grafo
    - En función del espacio: O(A) siendo A el número de aristas que componen el grafo.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class ARM_Kruskal {
private:
    vector<Arista<int>> _ARM;
    int coste;
    bool hayCamino;
    int aeropuertos;

public:
    int costeARM() const { return coste; }

    int getAeropuertos() const { return aeropuertos; }

    bool getCamino() const { return hayCamino; }

    vector<Arista<int>> const& ARM() const { return _ARM; }

    ARM_Kruskal(GrafoValorado<int> const& g) : coste(0), aeropuertos(1) {
        PriorityQueue<Arista<int>> pq(g.aristas());
        ConjuntosDisjuntos cjtos(g.V());
        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(); int w = a.otro(v);
            if (!cjtos.unidos(v, w)) {
                cjtos.unir(v, w);
                _ARM.push_back(a); coste += a.valor();
                if (_ARM.size() == g.V() - 1) break;
            }
        }
        aeropuertos = cjtos.num_cjtos() - 1;
    }
};


bool resuelveCaso() {

    int N, M, A;
    cin >> N >> M >> A;
    if (!cin)
        return false;

    GrafoValorado<int> grafo(N + 1);
    while (M--) {
        int v, w, precio;
        cin >> v >> w >> precio;
        grafo.ponArista({ v, w, precio });
    }

    ARM_Kruskal kruskal(grafo);
    int precioTotal = kruskal.getAeropuertos() * A + kruskal.costeARM();
    cout << precioTotal << " " << kruskal.getAeropuertos() << "\n";

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
