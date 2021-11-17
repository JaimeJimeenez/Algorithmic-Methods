/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 Para comprobar si el grafo es libre se tendrá que comprobar si para cada 
 par de vertices del grafo está conectado por un camino. Para ello, se creará
 un patrón de resolución de problema que tendrá un método recursivo llamado dfs cuyo funcionamiento
 consistirá en comprobar si el vértice está visitado, si no lo está se marcará como visitado y se sumará
 + 1 al atributo visitados. Para comprobar que el grafo es acíclico se deberá cumplir que la propiedad V - 1 = A.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

#include "Grafo.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <fstream>
#include <stdexcept>

#ifndef CAMINODFS_H_
#define CAMINODFS_H_

using namespace std;
using Camino = deque<int>; // Representacion de caminos

class CaminoDFS {
private:
   vector<bool> visit; // visit[v], vector para comprobar si existe un camino entre vertices
   int V, A;
   int visitados;

   void dfs(Grafo const& g, int v) { //O(V + A)
      visitados++;
      visit[v] = true;
      for (int w : g.ady(v)) {
         if (!visit[w]) {
            dfs(g, w);
         }
      }
   }

public:

   CaminoDFS(Grafo const& g) : visit(g.V(), false), V(g.V()), A(g.A()), visitados(0) {
      dfs(g, 0);
   }

   bool hayCamino(int v) const {
      return visit[v];
   }

   bool esArbolLibre() const {
      return (visitados == V) && (V - 1 == A);
   }

};

#endif 

bool resuelveCaso() {
   
   // leer los datos de la entrada
   int v;
   cin >> v;

   if (!std::cin)  // fin de la entrada
      return false;

   Grafo g(v);
   int a;
   cin >> a;

   while (a--) {
       int x, y;
       
       cin >> x >> y;
       g.ponArista(x, y);
   }

   CaminoDFS c(g);

   if (c.esArbolLibre())
      cout << "SI\n";
   else 
      cout << "NO\n";

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
