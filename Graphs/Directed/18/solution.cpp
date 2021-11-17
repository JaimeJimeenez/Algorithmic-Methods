/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include "Digrafo.h"
#include <iostream>
#include <fstream>
#include <stack>
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

using Camino = stack<int>;

class CicloDirigido {
private:
   vector<bool> visit;
   vector<bool> apilado;
   vector<int> ant;
   Camino _camino;
   bool hayCiclo;
   int precedente;

   void dfs(Digrafo const& D, int v) {

      apilado[v] = true;
      visit[v] = true;
      for (int w : D.ady(v)) {
         if (hayCiclo)
            return;
         if (!visit[w]) {
            ant[w] = v;
            dfs(D, w);
         }
         else if (apilado[w]) {
            hayCiclo = true;
            for (int x = v; x != w; x = ant[x]){}
            //   _camino.push_front(x);
            //_camino.push_front(w); _camino.push_front(v);
         }
      }
      apilado[v] = false;
   }


public:
   CicloDirigido(Digrafo const& D, int v, int w) : visit(D.V(), false), apilado(D.V(), false), ant(D.V()), camino(), hayCiclo(false), precedente(w){
      for (int x : D.ady(v)) {
         if (!visit[x])
            dfs(D, x);
      }
   }

   Camino const& getCamino() { return _camino; }

   bool const& hayCiclo() { return hayCiclo; }

};

bool resuelveCaso() {
   
   int N;

   cin >> N;
   if (!std::cin)  // fin de la entrada
      return false;
   
   int M, v, w;
   Digrafo d(N);

   cin >> M;
   while (M--) {
       cin >> v >> w;
       d.ponArista(v, w);
   }
   d.print();
   int A, B;

   cin >> M;
   while (M--) {
       cin >> A >> B;
       CicloDirigido c(d, A, B);
       if (c.hayCiclo())
         Camino ciclo = c.getCamino();
       else
         cout << "Imposible";
   }
   // resolver el caso posiblemente llamando a otras funciones
   
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
