/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include "Grafo.h"
#include <iostream>
#include <fstream>

using namespace std;

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class ComponentesConexas { //O(V + A)
public:
   ComponentesConexas(Grafo const& G) : visit(G.V(), false), componente(G.V()) {
      for (auto v = 0; v < G.V(); ++v) {
         if (!visit[v]){
            int tam = dfs(G, v);
            tamComp.push_back(tam);
         }
      }
   }
   int tamCompV(int v) {
      return tamComp[componente[v]];
   }

private:
   vector<bool> visit;
   vector<int> componente;
   vector<int> tamComp;

   int dfs(Grafo const& G, int v) {
      visit[v] = true;
      componente[v] = tamComp.size();
      int tam = 1;
      for (int w : G.ady(v)) {
         if (!visit[w])
            tam += dfs(G, w);
      }

      return tam;
   }
};

bool resuelveCaso() {
   
   int N, M;
   cin >> N >> M;
   if (!std::cin) 
      return false;
   
   Grafo g(N);
   while (M--) {
      int v, aux;
      cin >> v;
      aux = v;
      while (v--) {
         int w;
         cin >> w;
         g.ponArista(aux, w);
         cout << "Arista puesta: " << aux << " " << w << endl;
      }
   }
   // escribir la solución

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
