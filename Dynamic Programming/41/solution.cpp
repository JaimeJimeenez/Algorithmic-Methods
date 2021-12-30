/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#include "Matriz.h"

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

void calculoIndice(Matriz<int> tablero, int N) {

   for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
         tablero[i][j] += max(tablero[i - 1][j], max(tablero[i - 1][j - 1], tablero[i - 1][j + 1]));
      }
   }

   int sumaTotal = 0;
   int indice;
   for (int i = 1; i <= N; i++) {
      if (sumaTotal < tablero[N][i]) {
         sumaTotal = tablero[N][i];
         indice = i;
      }
   }

   cout << sumaTotal << " " << indice << "\n";
}

bool resuelveCaso() {

   int N;
   cin >> N;
   if (!cin)
      return false;

   Matriz<int> tablero(N + 1, N + 2, 0);
   for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) 
         cin >> tablero[i][j];
   }

   calculoIndice(tablero, N);
   
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
