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
        return b.inicio > a.inicio;
    }
};

bool resuelveCaso() {
   
   int N;
   cin >> N;
   if (N == 0) return false;

   vector<Edificio> playa;
   int occidental, oriental;
   while (N--) {
       cin >> occidental >> oriental;
       playa.push_back({occidental, oriental});
   }

   sort(playa.begin(), playa.end(), ComparadorEdificios());

   int tuneles = 1;
   int hasta = playa[0].fin + 1;
   cout << hasta << endl;

   for (int i = 1; i < N; i++) {
       if (playa[i].inicio > hasta) {
           tuneles++;
           hasta = playa[i].fin + 1;
       }
   }

   cout << tuneles << "\n";
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
