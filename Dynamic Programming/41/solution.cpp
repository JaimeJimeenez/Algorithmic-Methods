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

 Se quiere conocer la columna por la que se tiene que empezar en un tablero 
 para conseguir la mayor suma al recorrer dicho tablero de forma diagonal o vertical.

 Se utilizará la programación dinámica para resolver el problema atendiendo a la función recursiva.
   - tablero(i, j) = máxima suma que se obtiene al tener un tablero de i y j.

 Como se tiene una función recursiva, se parten de casos básicos los cuales son:
   - tablero(i, 0) = 0 si no se tienen columnas.
   - tablero(0, j) = 0 si no se tienen filas.
 Por contrapartida se tiene el caso recursivo:
   - tablero(i, j) += max(tablero[i - 1][j], max(tablero[i - 1][j - 1], tablero[i - 1, j + 1]))
 Se recorre la fila N (siendo N el número de filas) para conocer el elemento más grande y su respectivo índice

 Se utiliza una matriz sin posiblidad de utilizar un vector para mejorar el coste del espacio.
 La matriz tendrá como dimensión (N + 1) * (N + 2) para no tener problemas al realizar la función recursiva.

 Así pues se tienen los costes:
   - En función del tiempo: O(N^2) siendo N el número de elementos que se tiene en el tablero.
   - En función del espacio: O(N^2).
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
