/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;

/*@ <answer>
  e: ciudad
 Defensas ordenados de menor a mayor y cada defensa se envia a la menor ciudad a la que se gana.
 Si puede ganar a la menor defensa se envia a la primera ciudad y sino se envia a la ultima.
 Demostracion:
   Reduccion por diferencia:
      X: x1, x2, ... xi
      Y: y1, y2, ... yi
   Los ciertos (victorias) estarán a la izquierda y los falsos (Derrotas) estarán a la derecha.

   Puede ser que la solucion y la solucion optima coincida 
    xi <= ej
    yi <= ej 
    Esto implica que: xi < yi
    Puede ser?: xj >= ej yi < ej. Si, siempre que se cumplan que el numero de victorias anterior sea igual al numero de victorias que se tiene ahora
    Puede ser: xj < ej yj >= ej. 
   Se modifican las posiciones de yj e xj
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Ejercito {
   int numero;
};

class ComparadorEjercitos {
public:
   bool operator()(Ejercito const& a, Ejercito const& b) const {
      return a.numero < b.numero;
   }
};

void print(vector<Ejercito> const& a) {
   for (auto elem : a) {
      cout << elem.numero << " ";
   }
   cout << endl;
}

bool resuelveCaso() {
   
   int N;
   cin >> N;
   if (!std::cin)  
      return false;
   
   int efectivos;
   vector<Ejercito> atacantes;
   vector<Ejercito> defensores;

   for (int i = 0; i < N; i++) {
      cin >> efectivos;
      atacantes.push_back({efectivos});
   }
   sort(atacantes.begin(), atacantes.end(), ComparadorEjercitos());
   print(atacantes);

   for (int i = 0; i < N; i++) {
      cin >> efectivos;
      defensores.push_back({ efectivos });
   }
   sort(defensores.begin(), defensores.end(), ComparadorEjercitos());
   print(defensores);
   
   int victorias = 0;
   int aux = N - 1;
   for (int i = 0; i < N; i++) {
      if (defensores[i].numero < atacantes[i].numero) {
         
      }
   }
   for (int i = 0; i < N; i++) {
      if (defensores[i].numero < atacantes[i].numero) {
         auto inicio = defensores.begin();
         auto fin = atacantes.end();
         defensores.erase(defensores.begin());
         atacantes.erase(atacantes.end());
         print(atacantes);
         print(defensores); 
      }
      else {
         victorias++;
      }
   }

   cout << victorias << "\n";
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
