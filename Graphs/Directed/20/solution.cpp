/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector> 
#include <queue>
using namespace std;

/*@ <answer>
  
 Coste O(K * N^2)
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

const int MAX = 10000000;
const int INF = 10000;

int bfs(int N, int K, vector<int> const& saltos) {
    int destino = N * N;
    queue<int> q;
    vector<int> distancia(destino + 1, INF);

    distancia[1] = 0;
    q.push(1);

    while(!q.empty()) {
       int v = q.front();
       q.pop();
       for (int i = 1; i <= K && v + 1 <= destino; i++) {
          int w = saltos[v + i];
          if (distancia[w] == INF) {
             distancia[w] = distancia[v] + 1;
             if (w == destino)
               return distancia[destino];
            q.push(w);
          }
       }
    }
}

bool resuelveCaso() {
   
   int N, K, S, E;
   cin >> N >> K >> S >> E;
   
   if (N == 0)
      return false;
   
   vector<int> saltos(N * N + 1);
   for (int i = 1; i <= N * N; ++i) {
       saltos[i] = i;
   }

   int O, D;
   for (int i = 0; i < S + E; i++) {
       cin >> O >> D;
       saltos[O] = D;
   }
   
   //Se realiza un recorrido en anchura
   cout << bfs(N, K, saltos) << "\n";
   
   // escribir la solución

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
