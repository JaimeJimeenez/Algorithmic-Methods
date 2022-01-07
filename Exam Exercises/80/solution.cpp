/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
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

bool resuelveCaso() {

    int N;
    cin >> N;
    if (N == 0)
        return false;
    
    vector<int> personas(N);
    for (auto &x : personas)
        cin >> x;
    sort(personas.begin(), personas.end(), greater<int>());

    vector<int> esquis(N);
    for (auto &x : esquis)
        cin >> x;
    sort(esquis.begin(), esquis.end(), greater<int>());

    int diferencia = 0;
    for (int i = 0; i < N; i++) 
        diferencia += abs(personas.at(i) - esquis.at(i));

    cout << diferencia << "\n";
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
