/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include "Matriz.h"
using namespace std;

/*@ <answer>

 Se pide conocer el número de caminos de coste minimo que no pasan por pasadizos que llegan a una posición (i, j) desde la posición inicial (0, 0)
 Para ello se recurre a la programación dinámica para resolver este problema con la siguiente función recursiva:

 - cuadracity (i, j) = numero de caminos de coste minimo que no pasan por pasadizos que llegan a i, j desde 0, 0

 Como toda función recursiva, se parten de casos básicos los cuales son:
 - cuadracity (0, 0) = 0 si en el mapa en la posición inicial (0, 0) hay un pasadizo
 - cuadracity (0, 0) = 1 en caso contrario
 - cuadracity (i, 0) = cuadracity (i - 1, 0)
 - cuadracity (0, j) = cuadracity (0, j - 1)
 
 Por contrapartida se tienen los siguientes casos recursivos:
 - cuadracity (i, j) = 0 si mapa[i][j] = P (Pasadizo)
 - cuadracity (i, j) = cuadracity(i - 1, j) + cuadracity(i, j - 1)
 
 La solución buscada es la que cumple con la función recursiva cuadracity (i, j)
 
 Para conseguirlo se utiliza una matriz cuya dimensión es N * M siendo N filas y M columnas. Dicha matriz se rellenará siguiendo la función recursiva explicada anteriormente
 por lo que para conocer el elemento de la posición (i, j) es necesario conocer los elementos de las posiciones (i - 1, j), (i, j - 1). Se podrá mejorar el espacio adicional si se sustituye 
 la matriz en cuestión por un vector el cual se va recorriendo de izquierda a derecha.
 
 Por tanto, para este problema se tiene un coste:
 - En función del tiempo: O(N * M) siendo N el número de filas y M el número de columnas de la matriz ya que se rellenará toda la matriz en coste constante.
 - En función del espacio: O(M) en el caso de que se utilice un vector.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso() {
   
   int N, M;
   cin >> N >> M;
   if (!cin)
      return false;
   
   Matriz<char> mapa(N, M, '0');
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) 
         cin >> mapa[i][j];
   }

   vector<int> cuadracity(M, 0);
   cuadracity[0] = (mapa[0][0] == 'P') ? 0 : 1;
   if (cuadracity[0] == 0) {
      cout << "0\n";
      return true;
   }

   for (int i = 1; i < M; i++)
      cuadracity[i] = (mapa[0][i] == 'P') ? 0 : cuadracity[i - 1];

   for (int i = 1; i < N; i++){
      cuadracity[0] = mapa[0][0] == 'P' ? 0 : cuadracity[i - 1];
      for (int j = 1; j < M; j++) 
         cuadracity[j] = (mapa[i][j] == 'P') ? 0 : cuadracity[j - 1] + cuadracity[j];
   }

   cout << cuadracity[M - 1] << "\n";

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
