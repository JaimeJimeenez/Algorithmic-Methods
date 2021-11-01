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

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

const int MAX = 10000;
const int INF = 100000000;

int adyacente(int v, int i) {
   switch(i) {
      case 0: return (v + 1) % MAX;
      case 1: return (v * 2) % MAX;
      case 2: return (v / 3);
   }
}

int bfs(int origen, int destino) { //O(V + A) siendo V = 10000 y A = 30000
   if (origen == destino) return 0;
   vector<int> distancia(MAX, INF);
   distancia[origen] = 0;
   queue<int> cola; cola.push(origen);
   while (!cola.empty()) {
      int v = cola.front(); cola.pop();
      for (int i = 0; i < 3; i++) {
         int w = adyacente(v, i);
         if (distancia[w] == INF) {
            distancia[w] = distancia[v] + 1;
            if (w == destino) return distancia[w];
            else cola.push(w);
         }
      }
   }
}

bool resuelveCaso() {
   
   int origen, destino;
   cin >> origen >> destino;
   
   if (!std::cin)
      return false;
   
   cout << bfs(origen, destino) << "\n";

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
