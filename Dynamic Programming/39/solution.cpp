/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

/*@ <answer>

 Se pide calcular el número minimo de cometas que se pueden formar a partir de ciertos cordeles 
 junto con el coste minimo y sus respectiva longitud.
 Se utilizará programació dinámica para resolver el problema atendiendo a la función recursiva:

 - cometas(i, j) = mínimo número de cometas que se pueden formar de una longitud j a partir de unos cordeles
 de longitudes 1 a la i.

 Como se tiene una función recursiva, se parten de diversos casos básicos los cuales son:
 - cometas (i, 0) = 0 si la cometa que se quiere formar tien una longitud nula (0)
 - cometas (0, j) = Infinito si no se tienen cordeles para formar una cometa de longitud j
 Por contrapartida se tienen diversos casos recursivos los cuales son:
 - cometas (i, j) = cometas(i - 1, j) si la longitud del cordel i es mayor a la longitud que se quiere formar.
 - cometas (i, j) = min(cometas(i - 1, j), cometas(i, j - longitud[i]) + costes[i]) en caso contrario
 La solución buscada es la que cumple con la siguiente función recursiva: cometas(1, N).

 Se utiliza una matriz con la posiblidad de utilizar un vector para mejorar el espacio utilizado. La dimensión de dicha
 matriz es N * L siendo N el número de cordeles que se pueden utilizar y L la longitud de la cometa que se quiere formar.
 La matriz se rellenará siguiendo la función recursiva explicada anteriormente por lo que para conocer el elemento de la posición
 [i][j] se ha de conocer el elemento en la posición [i - 1][j] y el valor de la posición [i][j - longitud[i]]

 Como se ha mencionado, se puede mejorar el coste espacial sustituyendo la matriz por un vector que se irá recorriendo de izquierda a derecha
 y su valor corresponderá a cada uno de los valores de las filas de la matriz.

 Así pues se tienen los coste:
 - En función del tiempo: O(N * L) siendo N el número de cordeles que se tienen y L la longitud que se quiere tener en la cometa
 - En función del espacio: O(L) en el caso en que se use un vector.


 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

vector<int> minimoCordeles(vector<int> longitudes, vector<int> costes, int L, int& numCordeles) {
   int n = longitudes.size() - 1;
   vector<int> cometas(L + 1, INT_MAX - 1);
   cometas[0] = 0;
   for (int i = 1; i <= n; i++)
      for (int j = longitudes[i]; j <= L; j++)
         cometas[j] = min(cometas[j], cometas[j - longitudes[i]] + 1);

   numCordeles = cometas[L];

   if (numCordeles >= longitudes.size()) {
      numCordeles = -1;
      return { };
   }
   else {
      vector<int> cuantas(n + 1, 0);
      int i = n, j = L;
      while (j > 0) {
         if (longitudes[i] <= j && cometas[j] == cometas[j - longitudes[i]] + 1) {
            cuantas[i]++;
            j = j - longitudes[i];
         }
         else
            i--;
      }
      return cuantas;
   }

}

bool resuelveCaso() {

   int N, L;
   cin >> N >> L;
   if (!cin)
      return false;

   vector<int> longitudes(N);
   vector<int> costes(N);
   for (int i = 0; i < N; i++) {
      cin >> longitudes[i];
      cin >> costes[i];
   }

   int cordeles = 0;
   
   vector<int> numCometas = minimoCordeles(longitudes, costes, L, cordeles);
   if (cordeles == -1)
      cout << "NO\n";
   else {
      int precio = 0;
      for (int i = 0; i < numCometas.size(); i++) 
         if (numCometas[i] != 0)
            precio += (costes[i] * numCometas[i]);
      cout << "SI " << cordeles << " " << precio << "\n";
   }
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
