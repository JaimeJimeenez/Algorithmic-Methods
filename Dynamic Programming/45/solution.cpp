/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include "Matriz.h"
using namespace std;

/*@ <answer>
 
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

string palindromoMayor(string palabra) {
   int n = palabra.length();
   Matriz<int> palindromos(n, n, 0);

   for (int i = 0; i < n; i++) 
      palindromos[i][i] = 1;
   
   for (size_t i = 1; i < n; i++) {
      for (size_t j = 0; j < n - i; j++) {
         size_t k = i + j;
         if (palabra[j] == palabra[i]) 
            palindromos[j][i] = palindromos[j + 1][i - 1] + 2;
         else
            palindromos[j][i] = max(palindromos[j + 1][i], palindromos[j][i + 1]);
      }
   }

   int max = palindromos[n][n - 1];
   string result(max, "\0");

   int j = n - 1;
   int i = 0;
   int pos = 0;
   while (pos * 2 < max) {
      if () {

      }
   }
}

bool resuelveCaso() {

   string palabra;
   cin >> palabra;
   if (!cin)
      return false;
   
   cout << palindromoMayor(palabra) << "\n";
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
