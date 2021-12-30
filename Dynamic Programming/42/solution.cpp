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

 f(i, j) = numero de caminos de coste minimo que no pasan por pasadizos que llegan a i, j desde 0,0 
 f(0, 0) = 0 si en el mapa en la posicion 0,0 hay un pasadizo 
 f(0, 0) = 1 en caso contrario
 f(i, j) = 0 si M[i][j] = Pasadizo
 f(i, j) = f(i - 1, j) + f(i, j - 1)
 f(0, j) = f(0, j - 1)
 f(i, 0) = f(i - 1, 0)

 Se necesita una tabla de M * N
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

void print(vector<int> const& formas) {
   for (auto elem : formas)
      cout << elem << " ";
   cout << endl;
}


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

   cout << mapa;
   vector<int> formas(M);

   for (int j =  1; j < M; j++)
      formas[j] = mapa[0][j] == 'P' ? 0 : formas[j - 1];
   
   print(formas);

   for (int i = 1; i < N; i++) {
      formas[0] = mapa[i][0] == 'P' ? 0 : formas[0];
      for (int j = 1; j < M; j++)
         formas[j] = (mapa[i][j] == 'P') ? 0 : formas[j] + formas[j - 1];
   }

   cout << formas[M - 1] << "\n";

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
