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

 Se recorren de menor a mayor los jugadores. A cada jugador 
 se le da una camiseta de su tamaño, si hay. Si no, una de un tamaño
 1 más, si hay. Si no, se compra una camiseta.
 Por eficencia, conviene tener también ordenadas de menor a mayor las camisetas

 Coste: O(NlogN + MlogM) siendo N el número de jugadores y M el número de equipaciones.

 Demostración de la optimalidad de la estrategia:

 Se representa las soluciones como N-tuplas, donde x_i es qué se han hecho con el jugador i.
 Si x_i = e_r, es que se le han asignado la equipación e_r. Si x_i = nueva, es que se le ha comprado
 una nueva.
 Suponiendo las tallas de los jugadores ordenadas de menor a mayor:
   j_1 <= j_2 <= ... <= j_N

 Se comparan la solución X del algoritmo voraz con una solución óptima Y. Suponiendo que ambas son iguales
 hasta la posición i, donde difieren:
   Sol X: x_1, x_2 .... | x_i      ...
                           !=
   Sol Y: y_1, y_2 .... | y_i ...   y_k
   -x_i = nueva => no hay camiseta libre de la talla del jugador i, ni de una talla más => y_i tiene que ser
   también nueva (esto no es una diferencia)
   - x_i = e_r && e_r = j_i (talla del jugador i)
      Si Y no usa e_r en ningún jugador, el cambio es hacer y_i = e_r. Y no puede empeorar.
      En otro caso, habrá un y_k = e_r.
   Se puede intercambiar y_i con y_k ya que y_k le vale al jugador i (por la solución voraz)
      si y_i = nueva => se le compra nueva ahora al jugador k.
      si y_i = j_i + 1 => y_i le vale al jugador k, porque le valía a j_i.
      En cualquier caso Y no empeora.
   - x_i = e_k & e_k = j_i + 1 (se le da una talla l mayor)
      Por como funciona el algoritmo voraz, eso supone que no quedan tallas j_i libre
      x_i != y_i => y_i = nueva y la camiseta e_k se está usando en otro jugador y_k (si no Y sería mejorable) =>
      se intercambia y_i y y_k sin empeorar la solución óptima.
      
 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso() {
   int N, M;
   cin >> N >> M;
   if (!std::cin)
      return false;

   int talla;
   vector<int> jugadores;
   vector<int> equipaciones;

   while (N--) {
      cin >> talla;
      jugadores.push_back({talla});
   }
   sort(jugadores.begin(), jugadores.end(), less<int>());

   while (M--) {
      cin >> talla;
      equipaciones.push_back({talla});
   }
   sort(equipaciones.begin(), equipaciones.end(), less<int>());

   if (M == 0) {
      cout << N << "\n";
      return true;
   }

   if (N == 0) {
      cout << "0\n";
      return true;
   }

   int nuevas = 0;
   for (int i = 0; i < jugadores.size(); i++) {
      if (jugadores[i] != equipaciones[i]) {
         if (jugadores[i] + 1 != equipaciones[i])
            nuevas++;
      }
   }
   cout << nuevas << "\n";
   return true;
}

//@ </answer>

int main() {
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   while (resuelveCaso());
   
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
