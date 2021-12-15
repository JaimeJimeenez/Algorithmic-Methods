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
   int turno;
   bool operator<(Turno const& other) const {
      return other.turno < turno;
   }
};

void mediano(priority_queue<Turno> &turnos) {
   priority_queue<Turno> aux;
   int tam = (turnos.size() + 1) / 2;
   int cont = 1;

   while (!turnos.empty()) {
      if (cont == tam) {
         cout << turnos.top().turno << " ";
         turnos.pop();
         cont++;
      }
      else {
         aux.push(turnos.top());
         turnos.pop();
         cont++;
      }
   }
   
   turnos = aux;
}

bool resuelveCaso() {
   
   int N;
   cin >> N;   
   if (!std::cin)
      return false;

   int turno;
   priority_queue<Turno> turnos;
   vector<int> aux;
   while (N--) {
      cin >> turno;
      if (turno == 0)
         if (turnos.size() == 0)
            cout << "ECSA ";
         else
            cout << aux.at((turnos.size() + 1) / 2);
      else {
         turnos.push({ turno });
         aux.push_back(turnos.top().turno);
      }
   }

   cout << "\n";
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
