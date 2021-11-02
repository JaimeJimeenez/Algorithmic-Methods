/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*@ <answer>
 
  Se recorrerá los diferentes puntos de la manguera de izquierda a derecha y se pondrá un parche en cada punto
  donde exista un agujero que no se encuentre tapado por un parche.
  La demostración se realizará por reducción de diferencias teniendo en cuenta dos soluciones: la solución planteada (X)
  y la solución óptima (Y).
   (Y) podría introducir un parche en una posición anterior que en la solución X. Para ello se quita el parche de la posición 
   en la que se encontraba en la solución óptima para igualar la posición de X. A continuación se asegura que sigue siendo solución 
   y que sigue siendo óptima.
  Coste O(N) siendo N el número de agujeros que hay en la manguera.
  
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso() {
   
   int N, L;
   cin >> N >> L;
   if (!std::cin) return false;
   
   int cubiertoHasta = 0;
   int parches = 0;
   int agujero;
   
   for (int i = 0; i < N; i++) {
      cin >> agujero;
      if (agujero > cubiertoHasta) {
         parches++;
         cubiertoHasta = agujero + L;
      }
   }
   
   cout << parches << "\n";
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
