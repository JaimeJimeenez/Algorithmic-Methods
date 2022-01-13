/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <climits>

#include "ConjuntosDisjuntos.h"
#include "GrafoValorado.h"
#include "IndexPQ.h"
using namespace std;

/*@ <answer>
  
 Se quiere saber si el camino más corto desde un punto a otro coincide con el coste minimo para llegar desde el mismo origen al mismo 
 destino. Para ello se realizará el recorrido en anchura del grafo representado por calles (aristas) e intersecciones (vértices) para conocer
 cuantas aristas (distancia) son necesarias para ir de un punto a otro. 
 Del mismo modo se utilizará el algoritmo de Dijkstra para conocer el camino mínimo para ir del mismo punto de origen al mismo punto destino.
 A la hora de usar el método relajar se actualizará el recorrido de las aristas y se actualizará en un vector la cantidad necesaria de aristas que se ha 
 de pasar para llegar a un vértice cualquiera partiendo del vértice origen.

 En cuanto al coste: O(V + A) siendo V el número de vértices y A el número de aristas a recorrer del grafo.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class RecorridoBFS {
private:
    vector<bool> visit;
    int s;
    vector<int> ant;
    vector<int> dist;

    void bfs(GrafoValorado<int> const& g) {
        queue<int> q;
        dist[s] = 0;
        visit[s] = true;
        q.push(s);
        while(!q.empty()) {
            int v = q.front(); q.pop();
            for (auto w : g.ady(v)) {
                if (!visit[w.otro(v)]) {
                    ant[w.otro(v)] = v;
                    dist[w.otro(v)] = dist[v] + 1;
                    visit[w.otro(v)] = true;
                    q.push(w.otro(v));
                }
            }
        }
    }

public:
    RecorridoBFS(GrafoValorado<int> const& g, int s) : visit(g.V(), false), s(s), ant(g.V()), dist(g.V()) {
        bfs(g);
    }

    int distancia(int v) const { return dist[v]; }

    bool hayCamino(int v) const { return visit[v]; }
};

class Dijkstra {
private:
    const int INF = 1000000000;
    vector<Arista<int>> ulti;
    vector<int> dist;
    vector<int> aristas; //Vector que guarda el número de aristas necesarias desde su indice al origen
    IndexPQ<int> pq;
    int s;
    int destino;

    void relajar(Arista<int> a, int v) {
        int w = a.otro(v);
        if (dist[w] > dist[v] + a.valor()) { //Se tiene un nuevo camino minimo
            dist[w] = dist[v] + a.valor(); ulti[w] = a;
            aristas[w] = aristas[v] + 1; //Ahora la distancia que hay desde el origen a w es la distancia que había hasta v + 1
            pq.update(w, dist[w]);
        }
        else if (dist[w] == dist[v] + a.valor() && aristas[w] > aristas[v] + 1) {//El coste del nuevo camino mínimo es el mismo pero el número de aristas no
            aristas[w] = aristas[v] + 1;
            ulti[w] = a;
        }
    }


public:
    Dijkstra(GrafoValorado<int> const& g, int s, int v) : ulti(g.V()), aristas(g.V(), 0), dist(g.V(), INF), s(s), destino(v), pq(g.V()) {
        dist[s] = 0;
        pq.push(s, 0);
        while (!pq.empty() && pq.top().elem != v) {
            int w = pq.top().elem; pq.pop();
            for (auto a : g.ady(w)) {
                relajar(a, w);
            }
        }
    }

    int coste() { return dist[destino]; }

    int callesMinimas() { return aristas[destino]; } 

};

bool resuelveCaso() {

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

    int K;
    cin >> K;
    while (K--) {
        int s, v;
        cin >> s >> v;
        RecorridoBFS recorrido(grafo, s);

        if (recorrido.hayCamino(v)) {
            Dijkstra recorridoDijkstra(grafo, s, v);
            cout << recorridoDijkstra.coste() << " ";

            if (recorrido.distancia(v) == recorridoDijkstra.callesMinimas()) 
                cout << "SI\n";
            else 
                cout << "NO\n";
        }
        else 
            cout << "SIN CAMINO\n";
    }

    cout << "---\n";
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
