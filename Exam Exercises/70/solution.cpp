/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>

#include "GrafoValorado.h"
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"
using namespace std;

/*@ <answer>
  
 Se pide conocer el camino con coste minimo dado un grafo predefinido.
 Para ello se representará el grafo como un árbol de recubrimiento mínimo
 y se utilizará el algoritmo de Kruskal para ello.
 Como se pide que todo vértice este conectado por el resto mediante una o varias
 aristas se deberá comprobar que el árbol es conexo (aunque ya es una condición para que 
 un grafo sea un árbol de recubrimiento). Por ello si el número de aristas que componen el árbol es igual 
 al número de vértices del grafo - 2 (dado que anteriormente se ha sumado 1 para que coincidiese los vértices con los datos de entrada)
 será conexo.

 El coste de la operación es:
    - En función del espacio: O(A) siendo A el número de aristas del grafo
    - En función del tiemopo: O(A log A) siendo A el número de aristas del grafo.
 
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

        if (_ARM.size() != g.V() - 2)
            hayCamino = false;
        else
            hayCamino = true;
    }
};

bool resuelveCaso(){

    int N, M;
    cin >> N >> M;
    if (!cin)
        return false;
    
    GrafoValorado<int> grafo(N + 1);
    while (M--) {
        int v, w, coste;
        cin >> v >> w >> coste;
        grafo.ponArista({v, w, coste});
    }

    
    ARM_Kruskal kruskal(grafo);
    if (kruskal.getCamino())
        cout << kruskal.costeARM() << "\n";
    else 
        cout << "Imposible\n";
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
