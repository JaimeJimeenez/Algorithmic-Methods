/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */
/*@ <answer>
  
 
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
#include <iostream>
#include <fstream>
#include "Grafo.h"

class ComponenteConexa {
private:
    vector<bool> visit;
    int maxim;
    
    int dfs(Grafo const& G, int v) {
        visit[v] = true;
        int tam = 1;
        for (int w : G.ady(v)) {
            if (!visit[w]) {
                tam += dfs(G, w);
            }
        }

        return tam;
    }

public:
    ComponenteConexa(Grafo const& G) : visit(G.V(), false), maxim(0) {
        for (int v = 0; v < G.V(); v++) {
            if (!visit[v]){
                int tam = dfs(G, v);
                maxim = max(maxim, tam);
            }
                
        }
    }

    int maximun() const {
        return maxim;
    }
};

void resuelveCaso() {

   int N, M;
   cin >> N >> M;

   Grafo G(N + 1);
   while (M--) {
       int v, w;
       cin >> v >> w;
       G.ponArista(v, w);
   }

   ComponenteConexa comp (G);
   cout << comp.maximun() << endl;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   std::cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
      resuelveCaso();
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
