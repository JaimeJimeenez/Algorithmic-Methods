/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include "Grafo.h"
#include <iostream>
#include <fstream>
#include <queue> 
#include <stack>
#include <vector>
using namespace std;

/*@ <answer>

 El ejercicio plantea conocer las distancias de cada nodo en la red propuesta.
 Para ello se representa dicha red como un grafo en el que el número de nodos corresponde
 con el número de estaciones, computadoras... que presenta la red y las aristas las conexiones existentes
 entre ellas.
 Como se quiere conocer la distancia minima que existe entre un nodo origen (s) a los nodos restantes
 se toma el recorrido en anchura para determinarlo. Se deberá comprobar entre que par de nodos existe un camino
 y si la distancia que existe entre estos dos no supera la marcada como TTL.

 En cuanto al coste: se presenta con un O(V + A) siendo V el número de vertices que posee el grafo y A el número de aristas. 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

using Camino = queue<int>;

class CaminoMasCorto {
public:
    CaminoMasCorto(Grafo const& G, int s) : visit(G.V(), false), ant(G.V()), dist(G.V()), s(s){
        bfs(G);
    }

    bool hayCamino(int v) const { return visit[v]; }

    int distancia(int v) const { return dist[v]; }

    Camino camino(int v) const {
        if (!hayCamino(v)) throw domain_error("No hay camino");
        Camino cam;
        for (int x = v; x != s; x = ant[x]) 
            cam.push(x);
        cam.push(s);
        return cam;
    }

private:
    vector<bool> visit;
    vector<int> ant;
    vector<int> dist;
    int s;

    void bfs(Grafo const& G) {
        queue<int> q;
        dist[s] = 0;
        visit[s] = true;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int w : G.ady(v)) {
                if (!visit[w]){
                    ant[w] = v;
                    dist[w] = dist[v] + 1;
                    visit[w] = true;
                    q.push(w);
                }
            }
        }
    }
};


bool resuelveCaso() {

    int N, C;
    cin >> N >> C;
    if (!cin)
        return false;

    Grafo G(N + 1);
    while (C--) {
        int v, w;
        cin >> v >> w;
        G.ponArista(v, w);
    }

    int K;
    cin >> K;
    while (K--) {
        int s, TTL;
        cin >> s >> TTL;
        int nodosLejanos = 0;
        CaminoMasCorto cam(G, s);
        for (int v = 1; v < G.V(); v++){
            if (!cam.hayCamino(v))
                nodosLejanos++;
            else if (cam.distancia(v) > TTL)
                nodosLejanos++;
        }
             
        
        cout << nodosLejanos << "\n";
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
