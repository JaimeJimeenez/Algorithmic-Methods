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

struct Tarea {
   bool repite;
   int inicio, fin, frecuencia;
   bool operator<(Tarea const& other) const {
      return other.inicio < inicio;
   }
};

bool resuelveCaso() {

   int N, M, T;
   cin >> N >> M >> T;
   if (!cin)
      return false;

   priority_queue<Tarea> tareas;
   int inicio, fin, frecuencia;

   //Se leen las tareas que no se repiten 
   while (N--) {
      cin >> inicio >> fin;
      tareas.push({ false, inicio, fin, 0 });
   }

   //Se leen las tareas que se repiten
   while (M--) {
      cin >> inicio >> fin >> frecuencia;
      tareas.push({ true, inicio, fin, frecuencia });
   }

   bool conflicto = false;
   int ocupado = 0;

   while (!conflicto && !tareas.empty() && tareas.top().inicio < T) {
      auto t = tareas.top();
      tareas.pop();
      conflicto = ocupado > t.inicio;
      ocupado = t.fin;
      if (t.repite) 
         tareas.push( {true, t.inicio + t.frecuencia, t.fin + t.frecuencia, t.frecuencia }); 
   }

   if (conflicto)
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
