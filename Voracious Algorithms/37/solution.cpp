/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

/*@ <answer>

 

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Coche {
   int pila1, pila2;
};

void resuelveCaso() {

   int N, V;
   cin >> N >> V;

   vector<int> pilas(N);
   for (int i = 0; i < N; i++) 
      cin >> pilas[i];
   sort(pilas.begin(), pilas.end(), less<int>());

   int menor = 0;
   int mayor = N - 1;
   int numCoches = 0;
   vector<Coche> coches;

   while (N-- && mayor > menor) {
      if (pilas[menor] + pilas[mayor] >= V) {
         numCoches++;
         menor++;
         mayor--;
         coches.push_back( {pilas[menor], pilas[mayor]} );
      }
      else 
         menor++;
   }
   cout << coches.size() << endl;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   std::cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
      resuelveCaso();
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
