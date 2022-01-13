/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <climits>

#include "GrafoValorado.h"
#include "IndexPQ.h"
using namespace std;

/*@ <answer>
  
 Se quiere conocer el número de caminos que se pueden tener de coste minimo desde un vértice inicial 
 a un vértie destino. Para ello se realizará el algoritmo de Dijkstra para recorrer el grafo representando a una ciudad 
 con sus respectivas calles e intersecciones.

 Coste: O(A) siendo A el número de aristas que se tienen
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class Dijkstra {
public:
    Dijkstra(GrafoValorado<int> const& g, int s, int d) : origen(s), destino(d), dist(g.V(), INF), caminos(g.V(), 0), ulti(g.V()), pq(g.V()) {
        dist[origen] = 0;
        caminos[origen] = 1;
        pq.push(origen, 0);
        while (!pq.empty() && pq.top().elem != destino) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a, v);
        }
    }

    int numCaminos() const { return caminos[destino]; }

private:
    const int INF = 1000000000;
    vector<int> dist;
    vector<Arista<int>> ulti;
    vector<int> caminos;
    IndexPQ<int> pq;
    int origen;
    int destino;

    void relajar(Arista<int> a, int v) {
        int w = a.otro(v);

        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor();
            caminos[w] = caminos[v];
            ulti[w] = a;
            pq.update(w, dist[w]);
        }
        else if (dist[w] == dist[v] + a.valor()) {
            caminos[w] += caminos[v];
        }
    }
};


bool resuelveCaso() {
    int N, C;
    cin >> N >> C; 
    if (!cin) 
        return false;

    GrafoValorado<int> grafo(N);
    while (C--) {
        int v, w, coste;
        cin >> v >> w >> coste;
        grafo.ponArista({v - 1, w - 1, coste});
    }
    Dijkstra recorrido(grafo, 0, N - 1);
    cout << recorrido.numCaminos() << endl;

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
