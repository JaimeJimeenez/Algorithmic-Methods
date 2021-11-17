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
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 Se crea un struct con los atributos para detectar si una tarea se repite
 o no y se guarda en una cola de prioridad la cual está ordenada según el tiempo
 en el que empieza cada tarea.
 Una vez recogidas todas las tareas se comprueba para cada tarea hasta que haya un
 conflicto, se acaben todas las tareas o se sobrepase el periodo de querer
 comprobar si hay un conflicto.
 Habrá un conflicto si se está ocupado cuando se quiera iniciar otra tarea.
 Coste de la operación en el caso peor: O(T) siendo T el número de tareas a realizar, suponiendo que
 todas las tareas no crean conflictos y entren todas en el margen que se quiere conmprobar.
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Task {
   bool repeat;
   int begin, end, frequency;
   bool operator<(const Task& other) const {
      return other.begin < begin;
   }
};

void print(Task const& t) {
   cout << t.begin << " " << t.end << endl;
}

bool resuelveCaso() {
   
   int N, M, T; //N: Tareas unicas, M: Tareas repetitivas, T: Tiempo de ver si hay conflicto.

   cin >> N >> M >> T;
   if (!std::cin) 
      return false;
   
   int begin, end;
   priority_queue<Task> cola;
   while (N--) {
      cin >> begin >> end;
      cola.push({false, begin, end, 0});
   }

   int frequency;
   while (M--) {
      cin >> begin >> end >> frequency;
      cola.push({true, begin, end, frequency});
   }

   bool conflict = false;
   int busy = 0;

   while (!conflict && !cola.empty() && cola.top().begin < T) {
      Task t = cola.top();
      cola.pop(); 
      conflict = busy > t.begin;
      busy = t.end;
      if (t.repeat) 
         cola.push({true, t.begin + t.frequency, t.end + t.frequency, t.frequency});
      
   }

   if (conflict) 
      cout << "SI\n";
   else
      cout << "NO\n";

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
