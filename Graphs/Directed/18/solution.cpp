/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include "Digrafo.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 Se realizará un ciclo dirigido del grafo
 Cuando se llegue al vertice B se comprobará si el vertice A ha sido ya visitado
 y por tanto realizado. Si esto es negativo se propondrá un error notificando Es Imposisble
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class OrdenTopologico {
public:
   OrdenTopologico(Digrafo const& g) : visit(g.V(), false) {
      for (int v = 1; v < g.V(); v++) {
         if (!visit[v])
            dfs(g, v);
      }
   }

   deque<int> const& orden() const {
      return _orden;
   }

private:
   vector<bool> visit;
   deque<int> _orden;

   void dfs(Digrafo const& g, int v) {
      visit[v] = true;
      for (int w : g.ady(v)) {
         if (!visit[w])
            dfs(g, w);
         _orden.push_front(v);
      }
   }
};

bool resuelveCaso() {
   int N, M;
   cin >> N >> M;
   if (!cin)
      return false;
   
   Digrafo G(N + 1);
   while (M--) {
      int v, w;
      cin >> v >> w;
      G.ponArista(v, w);
   }

   OrdenTopologico tareas(G);
   cout << tareas.orden().size() << "\n";
   if (tareas.orden().size() != N + 1)
      cout << "Imposible";
   else {
      deque<int> ordenTareas = tareas.orden();
      for (int i = N; i >= 0; i--) {
         cout << ordenTareas.at(i) << " ";
      }
   }
   cout << "\n";
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
