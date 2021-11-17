/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include "DigrafoValorado.h"
#include <iostream>
#include <fstream>
#include <indexsrv.h>
#include <algorithm>
using namespace std;

/*@ <answer>

 Para este problema se representan las páginas con sus respectivos enlaces
 mediante un digrafo valorado en el que el vertice origen es la pagina origen
 y el vértice destino es la página a la que se quiere llegar. El coste de este enlace
 viene dado por milisegundos y se anotará también.
 
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class EnlacesPaginas {
   //const int INF = numeric_limits<int>::max();
   vector<int> dist;
   //IndexPQ<int> pq;
   int coste;
   
   void dfs(DigrafoValorado<int> const& G, vector<int> const& tiempoPag, int v) {
      coste += tiempoPag[v];

   }

public:
   EnlacesPaginas(DigrafoValorado<int> const& G, vector<int> const& tiempoPag) : visit(G.V(), false), coste(0), dist(G.V(), INF) {
      dfs(G, tiempoPag, 1);
   }

   
   int getCoste() const {
      return coste;
   }
};

bool resuelveCaso() {
   
   int N;
   cin >> N;
   if (N == 0)
      return false;
   
   DigrafoValorado<int> enlaces(N + 1); //El vertice 0 no se usa
   vector<int> paginas(N + 1);
   int M;

   for (int i = 1; i <= N; i++) {
      int tiempo ;
      cin >> tiempo;
      paginas[i] = tiempo;
   }

   cin >> M;
   while (M--) {
       int v, w, valor;

       cin >> v >> w >> valor;
       AristaDirigida<int> arista (v, w, valor);
       if (enlaces.hayArista(v, w)) {
          for (auto elem : enlaces.ady(v)) {
             if (elem.desde() == v && elem.hasta() == w) 
                if (elem > arista) 
                   enlaces.ponArista(arista);
          }
       }
       else
         enlaces.ponArista(arista); 

   }

   EnlacesPaginas e(enlaces, paginas);

   enlaces.print();

   cout << e.getCoste() << endl;
   return true;
}

//@ </answer>

int main() {
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   while (resuelveCaso());
   
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
