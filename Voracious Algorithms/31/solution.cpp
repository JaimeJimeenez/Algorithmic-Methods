/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

/*@ <answer>

 Supongamos los enemigos ordenados de la forma que i <= j => E[i] <= E[j]
 
 El algoritmo voraz V toma la defensa más pequeña de las que quedan que pueden
 ganar. Las derrotas da igual cómo se asignen. Por tanto, el aspecto de la solución 
 voraz es una secuencia creciente de índices de defensas (que permiten ganar) y luego 
 el resto son derrotas que en realidad da igual cómo se asignen. 

 Ejemplo:
   E 4 7 9 11 13
   D 3 4 6 8 15
 
 La solución voraz: 1 3 4 (son victorias) y luego 0 2 son derrotas (siendo estos los indices)

 Sea O una solución óptima y sea i la primera posición donde O y V difieren: O[i] != V[i].
 Entonces la defensa de V[i] ha sido asignada más adelante en O. Sea k la posición que cumple que
 V[i] == O[k].

 E:   E[0] <= E[1] ... 
 V:   V[0]  V[1] ... | V[i]
         =     = ... | !=
 O:   O[0] O[1] ... | O[i] ... O[k] == V[k]
 
 Caso 1: D[V[i]] >= E[i] (hay victoria en la voraz)

 Caso 1.1: Si hubiese derrota en la óptima en la ciudad i, D[O[i]] < E[i] podemos intercambiar i y k
 sin perder victorias, ya que la i va a convertirse en victorias porque D[V[i]] >= E[i] (tampoco van a ganar
 ambas porque es óptima).

 Caso 1.2: Si hay victoria en i en la óptima, D[O[i]] >= E[i], entonces D[O[i]] >= D[V[i]] 
 porque de las defensas que quedan por asignar D[V[i]] es la menor que permite ganar
 (y las defensas que quedan por asignar son las mismas) por la estrategia voraz. 
 Tanto si hay victoria en la ciudad k como si no, intercambiar la posición i con la k
 en O no reduce el número de victorias: en la ciudad i seguimos ganando y a la
 ciudad k estamos enviando al menos el mismo número de defensas. 
 
 Caso 2:  D[V[i]] < E[i] (hay derrota en la voraz)

 Si hay derrota en la voraz no puede existir ninguna defensa no asignada que permita ganar en i
 y por tanto D[O[i]] < E[i] (porque las defensas no asignadas son las mismas) ya que en caso 
 contrario la solución voraz la hubiese asignado.
 
 Tampoco hay victoria en k porque E[i] <= E[k] así que simplemente intercambiamos dos derrotas
 para que se parezca más a la voraz.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso() {

   int N;
   cin >> N;
   if (!cin)
      return false;
   
   vector<int> enemigos(N);
   for (int i = 0; i < N; i++)
      cin >> enemigos[i];
   
   vector<int> defensas(N);
   for (int i = 0; i < N; i++)
      cin >> defensas[i];
   
   sort(enemigos.begin(), enemigos.end());
   sort(defensas.begin(), defensas.end());

   int victorias = 0; int defensa = 0; int enemigo = 0;
   while (enemigo < enemigos.size() && defensa < defensas.size()) {
      if(enemigos[enemigo] <= defensas[defensa]) {
         victorias++;
         defensa++;
         enemigo++;
      }
      else
         defensa++;
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
