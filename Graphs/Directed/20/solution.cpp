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
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

const int MAX = 10000000;
const int INF = 10000000000;

int bfs(int N, int K, vector<int> const& saltos) {
    int destino = N * N;
    vector<int> distancia(MAX, INF);
    int origen = K;
    distancia[origen] = 0;
    queue<int> cola; cola.push(origen);
}

bool resuelveCaso() {
   
   int N, K, S, E;
   cin >> N >> K >> S >> E;
   
   if (N == 0)
      return false;
   
   vector<int> saltos;
   for (int i = 0; i <= N * N; ++i) {
       saltos[i] = i;
   }
   for (int i =  0; i < S + E; i++) {
       int O, D;
       cin >> O >> D;
       saltos[O] = D;
   }
   
   //Se realiza un recorrido en anchura
   cout << bfs(N, K, saltos);
   
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
