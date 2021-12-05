/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*@ <answer>
  
 cubos(i, j) = comida maxima que le va a tocar comer la protagonista si los cubos restantes son los cubos de i a j.
 cubos(i, j) = 0 si i > j 
 cubos(i, i) = C[i]
 cubos(i, i + 1) = max(C[i], C[i + 1])
 cubos(i, j) = max(C[i] + (cubos(i + 2, j) si C[i + 1] > C[j]) + (cubos[i + 1, j - 1] en caso contrario),
  C[j] + (cubos[i + 1, j - 1] si C[i] > j - 1) cubos[i, j - 2] en caso contrario) si j - i + 1 > 2
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

    vector<int> cubos(N);
    for (int cubo : cubos)
        cin >> cubo;
    
    //Primero se calcula por donde se tiene que empezar
    int index = (cubos[1] > cubos[N - 2]) ? N - 2 : 1;
    int fin = (index == N - 2) ? 0 : N;
    while (index != fin) {

    }

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
