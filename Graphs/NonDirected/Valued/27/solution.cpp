/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <numeric>
#include <queue>
using namespace std;

#include "GrafoValorado.h"
#include "IndexPQ.h"

/*@ <answer>
  
 
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

using Camino = deque<Arista<int>>;

class Dijkstra {
public:
    Dijkstra(GrafoValorado<int> const& g, int orig) : origen(orig), dist(g.V(), INF), ulti(g.V()), pq(g.V()) {
        dist[origen] = 0;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v)) 
                relajar(a);
        }
    }

    bool hayCamino(int v) const { return dist[v] != INF; }

    int distancia(int v) const { return dist[v]; }

    Camino camino(int v) const {
        Camino cam;
        Arista<int> a;
        for (a = ulti[v]; a.uno() != origen; a = ulti[a.otro(ulti[v].valor())])
            cam.push_front(a);
        cam.push_front(a);
        return cam;
    }

private:
    const int INF = std::numeric_limits<int>::max();
    int origen;
    vector<int> dist;
    vector<Arista<int>> ulti;
    IndexPQ<int> pq;

    void relajar(Arista<int> a) {
        int v = a.uno(); int w = a.otro(v);
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor(); ulti[w] = a;
            pq.update(w, dist[w]);
        }
    }
};

bool resuelveCaso() {

    int N, C;
    cin >> N >> C;
    if (!cin)
        return false;

    GrafoValorado <int> g (N + 1);
    while (C--) {
        int v, w, p;
        cin >> v >> w >> p;
        g.ponArista({v, w, p});
    }
    
    cout << g;
    Dijkstra d (g, 1);
    if (d.hayCamino(N)) {
        Camino cam = d.camino(N);
        for (auto it = cam.begin(); it != cam.end(); ++it) {
            cout << *it << " ";
        }
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
