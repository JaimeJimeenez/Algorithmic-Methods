/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

#include "DigrafoValorado.h"
#include "IndexPQ.h"
using namespace std;

/*@ <answer>
  
 Se quiere conocer si es posible, el esfuerzo minimo que hay que realizar en un día repartiendo paquetes.
 Para ello representamos la ciudad como un grafo en el que las carreteras corresponden con las aristas y las
 casas los respectivos vértices. Se utilizará el algoritmo de Dijkstra para conocer el coste minimo de ir de un vertice
 origen a un vértice destino. Como se consta que solo puede llevar un paquete a la vez se realiza el recorrido de Dijkstra 
 una segunda vez para ir al origen inicial a por otro paquete pero esta vez utilizando el grafo inverso del actual.

 En cuanto al coste:
 - En función del tiempo: O(A + VlogA) siendo V el número de vértices y A el número de aristas
 - En función del espacio: O(A) siendo A el número de aristas.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class Dijkstra {
public:
   Dijkstra(DigrafoValorado<int> const& g, int s) : s(s), ulti(g.V()), dist(g.V(), INF), pq(g.V()) {
      dist[s] = 0;
      pq.push(s, 0);
      while (!pq.empty()) {
         int v = pq.top().elem;
         pq.pop();
         for (auto a : g.ady(v)) 
            relajar(a);
      }
   }

   bool hayCamino(int v) const { return dist[v] != INF; }

   int coste(int v) const { return dist[v]; }

private:
   const int INF = 1000000000;
   vector<AristaDirigida<int>> ulti;
   vector<int> dist;
   IndexPQ<int> pq;
   int s;

   void relajar(AristaDirigida<int> a) {
      int v = a.desde();
      int w = a.hasta();

      if (dist[w] > dist[v] + a.valor()) {
         dist[w] = dist[v] + a.valor();
         ulti[w] = a;
         pq.update(w, dist[w]);
      }
   }

};

bool resuelveCaso() {
   
   int N, M;
   cin >> N >> M;
   if (!cin)
      return false;
   
   DigrafoValorado<int> grafo(N);
   while (M--) {
      int v, w, coste;
      cin >> v >> w >> coste;
      grafo.ponArista({v - 1, w - 1, coste});
   }

   int O, P;
   cin >> O >> P;
   Dijkstra recorridoIda(grafo, O - 1);
   Dijkstra recorridoVuelta(grafo.inverso(), O - 1);
   int esfuerzo = 0;
   bool posible = true;
   while (P--) {
      int destino;
      cin >> destino;
      if (recorridoIda.hayCamino(destino - 1) && recorridoVuelta.hayCamino(destino - 1)) 
         esfuerzo += (recorridoIda.coste(destino - 1) + recorridoVuelta.coste(destino - 1));
      else 
         posible = false;
   }

   if (!posible)
      cout << "Imposible\n";
   else
      cout << esfuerzo << endl;

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
