/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <limits>
#include <vector> 

#include <iostream>
#include <fstream>
#include "DigrafoValorado.h"
//#include "IndexPQ.h"
using namespace std;

/*@ <answer>
  
 Utiliza Dijkstra con el grafo inverso (todos los caminos llegan a la salida)
 Para calcular cuanto tarda cada ratón en llegar a la salida. Se cuenta cuantos 
 ratones hay que no tarden más que T
 O(V + E log V)
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class Dijkstra {

public:


};

bool resuelveCaso() {
   
   int N, S, T, P;
   cin >> N >> S >> T >> P;
   if (!std::cin) 
    return false;
         
   DigrafoValorado <int> laberinto(N + 1); //La celda 0 no se tiene en cuenta
   while (P--) {
       int A, B, seg;
       cin >> A >> B >> seg;
       laberinto.ponArista({A, B, seg});
    }

   Dijkstra <int> caminos(laberinto, S - 1);
   int salen = 0;
   for (int r = 0; r < N; r++) {
      if (caminos.hayCamino(r) && caminos.valor(r) <= T)
         ++salen;
   }
   cout << salen - 1 << "\n";
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
