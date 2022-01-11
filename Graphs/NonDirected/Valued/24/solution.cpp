/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <climits>
#include <algorithm>
#include <queue>

#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"
#include "GrafoValorado.h"
using namespace std;

/*@ <answer>
  
 Se pide conocer el minimo coste de un grafo siendo dicho coste como la suma de los minimos costes de las aristas 
 que componen dicho grafo. Para ello se utilizará el algoritmo de Kruskal para conseguir un arbol de recubrimiento minimo.
 Se dispone de la plantilla ConjuntosDisjuntos que indicará a que conjunto pertenece cada vértice (el vértice 0 pertenece a un conjunto exclusivo y no se tiene en cuenta).
 Si el número de conjuntos disjuntos es 1 se llegará a la conclusión que el grafo es conexo y se sacará el coste minimo obtenido en el algoritmo.

 El coste del ejercicio es:
 - En función del tiempo: O(A log A)
 - En función del espacio: O(A) 
 
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

public:
    int costeARM() const { return coste; }

    bool getCamino() const { return hayCamino; }

    vector<Arista<int>> const& ARM() const { return _ARM; }

    ARM_Kruskal(GrafoValorado<int> const& g) : coste(0) {
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
        if (cjtos.num_cjtos() - 1 == 1) 
            hayCamino = true;
        else 
            hayCamino = false;
    }
};

bool resuelveCaso() {

    int I, P;
    cin >> I >> P;
    if (!cin)
        return false;

    GrafoValorado<int> grafo(I + 1);
    while (P--) {
        int v, w, coste;
        cin >> v >> w >> coste; 
        grafo.ponArista({v, w, coste});
    }

    ARM_Kruskal kruskal(grafo);
    if (kruskal.getCamino())
        cout << kruskal.costeARM() << "\n";
    else
        cout << "No hay puentes suficientes\n";

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
