/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include "Grafo.h"
#include <iostream>
#include <fstream>
#include <queue> 
#include <vector>
using namespace std;

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 Se representa la red de comunicaciones mediante una grafo no dirigido
 en la que los nodos o estaciones son los vertices y las conexiones de estas
 las aristas existentes.
 Se quiere ver las conexiones más rápidas y cortas para llegar de una estación a otra
 por lo que se realizará un recorrido en profundidad.
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class NodosMaximos {
public:
    NodosMaximos(Grafo const& G) : visit(G.V(), false), componente(G.V()), distComponente(G.V()) {
        for (int v = 0; v <= G.V(); v++) {
            if (!visit[v]) {
                int tam = dfs(G, v);
                distComponente[v].push_back(tam);
            }
        }
    }

private:
    vector<bool> visit;
    vector<int> componente;
    vector<vector<int>> distComponente;

    int dfs(Grafo const& G, int v) {
        int tam = 1;
        visit[v] = true;
        componente[v] = distComponente.size();
        for (int w : G.ady(v)) {
            if (!visit[w]) {
                tam += dfs(G, w);
            }
        }

        return tam;
    }

};

bool resuelveCaso() {
   
   // leer los datos de la entrada
   int N;
   cin >> N;
   if (!std::cin)  // fin de la entrada
      return false;
   Grafo G(N);

   int C;
   cin >> C;
   while (C--) {
       int v, w;
       cin >> v >> w;

       G.ponArista(v - 1, w - 1);
   }

   int numConsultas;
   cin >> numConsultas;
   G.print();
   while (numConsultas--) {
       int nodo, TTL;
       
       cin >> nodo >> TTL;

       cout << nodo - 1 << " " << TTL << endl;
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
