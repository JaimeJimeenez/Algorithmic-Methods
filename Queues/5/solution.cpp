/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

/*@ <answer>
 
 Se crea una estructura Pacient para almacenar el nombre, la gravedad y
 el tiempo de espera de cada paciente que llega a emergencias. Para cada 
 operación se clasificará mediante un switch. En el caso de que se quiera
 atender a un paciente se sacará de la cola de prioridad el primero y se
 eliminará de esta dando por entendido que ya ha sido atendido. 
 En el caso de querer introducir un nuevo paciente, se meterán los datos de
 dicho paciente junto con su tiempo de llegada.
 La cola de prioridad viene determinada por la gravedad de cada paciente y 
 en caso de igualdad de este factor, por el tiempo de espera de cada uno.

 Coste de la solución: O(NlogN) siendo N el numero de elementos de la cola 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Pacient {
    string name;
    int gravity, waiting;
    bool operator<(const Pacient &other) const {
        return (other.gravity > gravity) || (other.gravity == gravity
         && other.waiting > waiting);
    }
};

bool resuelveCaso() {
   
   int n;
   cin >> n;
   if (n == 0)
      return false;
   
   priority_queue<Pacient> emergencies;
   Pacient next;
   string name;
   char option;
   int gravity;
   int waiting = 0;

   while (n--) {
       cin >> option;

       switch (option) {
           case ('A'):
           next = emergencies.top();
           emergencies.pop();
           cout << next.name << '\n';
           break;
           
           case ('I'):
           cin >> name >> gravity;
           emergencies.push({ name, gravity, waiting });
           break;
           
           default:
           break;
       }

       waiting--;
   }

   cout << "---\n";
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
