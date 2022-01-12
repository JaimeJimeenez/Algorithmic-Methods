/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

/*@ <answer>
  
 Se tiene una estructura llamada turno que almacena el turno de cada usuario 
 el cual se almacena en una cola de prioridad que ordena dichos turnos de manera creciente.
 
 Si llega el momento en que el carnicero espera al mediano se recorre la cola esperando a
 encontrar dicho mediano. Los turnos que no cumplan este requisito se almacenan en una cola auxiliar
 la cual se reemplazará por la actual.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Turno {
   int posicion;
   bool operator<(Turno const& other) const {
      return posicion > other.posicion;
   }
};

void print(priority_queue<Turno> cola) {

   while (!cola.empty()) {
      auto p = cola.top();
      cola.pop();
      cout << p.posicion << " ";
   }
   cout << endl;
}

bool resuelveCaso() {

   int N;
   cin >> N;
   if (!cin)
      return false;

   priority_queue<Turno> carniceria;
   vector<int> orden(N);
   while (N--) {
      int turno;
      cin >> turno;
      if (turno == 0) {
         if (carniceria.empty())
            cout << "ECSA";
         else {
            
         }
      }
      else {
         carniceria.push({ turno });
      }
         
   }

   print(carniceria);
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
