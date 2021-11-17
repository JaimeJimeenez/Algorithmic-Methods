/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include "Digrafo.h"

using namespace std;

/*@ <answer>
  
 Se construye un grafo tal que cada vértice es una instrucción y se presenta 
 un vértice adicional localizado detrás de la última instrucción que indica que
 se ha acabado

 Se conectará cada instrucción con la siguiente siendo: A (siguiente instrucción),
 J (la que diga el salto) y C (la siguiente y la que diga el salto).
 
 Se buscan entonces ciclos desde el vértice correspondiente a la primera instrucción
 para comprobar si se puede alcanzar el final,
 
 El coste la operación es O(I) siendo I el número de instrucciones que tiene el programa.
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class CicloAlcanzable {
   vector<bool> visit;
   vector<bool> apilado;
   bool hayCiclo;

   void dfs(Digrafo const& G, int v) {
      visit[v] = true;
      apilado[v] = true;
      for (int w : G.ady(v)) {
         if (!visit[w]) 
            dfs(G, w);
         else if (apilado[w]) hayCiclo = true;
      }
      apilado[v] = false;
   }

public:
   CicloAlcanzable(Digrafo const& G, int origen) : visit(G.V()), apilado(G.V()), hayCiclo(false) {
      dfs(G, origen);
   }

   bool hayCicloA() const {
      return hayCiclo;
   }

   bool alcanzable(int v) const {
      return visit[v];
   }
};

bool resuelveCaso() {
   
   int L;
   cin >> L;
   if (!std::cin) 
      return false;
   
   Digrafo instrucciones(L + 2);

   char c; int N;
   for (int i = 1; i <= L; i++) {
      cin >> c;
      if (c == 'A')
         instrucciones.ponArista(i, i + 1);
      else {
         cin >> N;
         if (c == 'J')
            instrucciones.ponArista(i, N);
         else {
            instrucciones.ponArista(i, i + 1);
            instrucciones.ponArista(i, N);
         }
      }
   }   
   
   CicloAlcanzable ciclo(instrucciones, 1);
   if (ciclo.alcanzable(L + 1)) {
      if (ciclo.hayCicloA())
         cout << "A VECES\n";
      else 
         cout << "SIEMPRE\n";
   }
   else 
      cout << "NUNCA\n";

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
