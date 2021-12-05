/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include "Matriz.h"
using namespace std;

/*@ <answer>

 Se necesitará inicializar una matriz para saber cual es el coste minimo
 para una cometa con L centimetros. Después se recorrerá un vector para
 saber que centimetros hacen falta para conseguir dicho coste
 

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Cuerda {
   int longitud;
   int coste;
};

void print(vector<Cuerda> cuerdas) {
   for (auto elem : cuerdas)
      cout << elem.longitud << " " << elem.coste << " ";
   cout << endl;
}

vector<Cuerda> formarCometa(vector<Cuerda> const& cuerdas, int L, int& costeMin) {
   int n = cuerdas.size() - 1;
   Matriz<int> costeCometa(n + 1, L + 1, INT_MAX - 1);

   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= L; j++) {
         if (cuerdas[i].longitud > L)
            costeCometa[i][j] = costeCometa[i - 1][j];
         else 
            costeCometa[i][j] = min(costeCometa[i - 1][j], costeCometa[i - 1][j - (cuerdas[i].longitud + cuerdas[i].coste)]);
      }
   }

   costeMin = costeCometa[n][L];
   cout << costeMin << endl;

   return { };
} 

bool resuelveCaso() {
   
   int N, L;
   cin >> N >> L;
   if(!cin) 
      return false;
   
   vector<Cuerda> cuerdas(N + 1);
   for (int i = 1; i <= N; i++) 
      cin >> cuerdas[i].longitud >> cuerdas[i].coste;
   
   int costeMin = 0;
   formarCometa(cuerdas, L, costeMin);

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
