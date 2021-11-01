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
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 El ejercicio consiste en conseguir averiguar que persona le toca en cada
 momento una vez registrada con un identificador y un periodo que esta misma 
 ha solicitado. Para ello se creará una estructura o una clase según convenga
 con el identificador de esta nueva persona, el momento en el que quiere que se
 le avise y el periodo entre un momento y otro. Como se realizará una cola de prioridad 
 se sobreecargará el operador < para que compruebe el momento o en caso peor el id.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct registro {
   int momento; 
   int id;  
   int periodo; 
   bool operator<(registro const& other) const {
      return other.momento < this->momento || (other.momento == this->momento && other.id < this->id);
   }
};

/*bool operator<(const registro& a, const registro& b) {
   return a.momento > b.momento || (a.momento == b.momento && a.id > b.id);
}*/

bool resuelveCaso() {
   
   // leer los datos de la entrada
   int lengthCases;
   cin >> lengthCases;
   if (lengthCases == 0)
      return false;
   
   // resolver el caso posiblemente llamando a otras funciones
   priority_queue<registro> cola;

   for (int i = 0; i < lengthCases; i++) {
       int id;
       int periodo;
       cin >> id >> periodo;
       cola.push({periodo, id, periodo});
   }

   int periocity;
   cin >> periocity;
   while (periocity--) {
       registro a = cola.top();
       cola.pop();
       cout << a.id << "\n";
       a.momento += a.periodo;
       cola.push(a);
   }

   cout << "---" << "\n";
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
