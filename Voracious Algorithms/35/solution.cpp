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

 Se ordenan los edificios de menor a mayor dependiendo del comienzo de
 cada edificio. Se empieza marcando donde acaba el primer edificio y se 
 coloca un tunel en esta posición. Se van recorriendo todos los edificios
 en este orden comprobando si el comienzo de cada edificio empieza en un tramo
 mayor o igual a la posición de el útlimo tunel construido.

 Coste O(NlogN) siendo N el número de edificios que se plantean.



 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Edificio {
    int inicio;
    int fin;
};

class ComparadorEdificios {
public:
    bool operator()(Edificio const& a, Edificio const& b) const {
        return a.fin < b.fin || (a.fin == b.fin && a.inicio < b.inicio);
    }
};

bool resuelveCaso() {
   
   int N;
   cin >> N;
   if (N == 0) 
      return false;
   
   vector<Edificio> edificios;
   int ini, fin;
   for (int i = 0; i < N; i++) {
       cin >> ini >> fin;
       edificios.push_back({ini, fin});
   }
   sort(edificios.begin(), edificios.end(), ComparadorEdificios());

   int ultimoTunel = edificios[0].fin;
   int tuneles = 1;
   for (int i = 1; i < edificios.size(); i++) {
       if (edificios[i].inicio >= ultimoTunel) {
           tuneles++;
           ultimoTunel = edificios[i].fin;
       }
   }

   cout << tuneles << "\n";
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
