/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#include "Matriz.h"

/*@ <answer>
  
 Se quiere saber el número de veces que pueden comer dos niños la misma fruta de un bizcocho.
 Como los trozos que se pueden comer son los de sus extremos, el bizcocho resultante es uno derivado del original.
 Se tienen tres opciones: 
    1. Las dos personas elijan un trozo por el extremo de la derecha
    2. Las dos personas elijan un trozo por el extremo izquierdo.
    3. Cada persona coja un trozo por uno de los extremos.
 Se utiliza programación dinámica para resolver este ejercicio, utilizando la siguiente función recursiva:

    - partir(i, j) = máximo número de veces que pueden comer igual dos personas con un bizcocho de tamaño (i, j).

 Como toda función recursiva se tienen los siguientes casos básicos:
    - partir(i, j) = 0 si i > j es decir, no queda bizcocho.
 Por contrapartida se tienen los siguientes casos recursivos:
    - partir(i, j) = (bizcocho[i] == bizcocho[j] && B[i] != 0) si i = j - 1 (quedan dos trozos)
    - partir(i, j) = max(partir[i + 2][j], max(partir[i][j + 2], partir[i + ][j - 1] + (bizcocho[i] == bizcocho[j] && bizcocho[i] != 0)))
 
 El coste del ejercicio es O(N^2) (tanto en función del espacio como del tiempo) siendo N el número de trozos del bizcocho
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

    vector<int> bizcocho(N);
    for (int i = 0; i < N; i++) 
        cin >> bizcocho[i];
    
    Matriz<int> partir(N, N, 0);
    for (int i = 0; i < N - 1; i++) 
        partir[i][i + 1] = (bizcocho[i] == bizcocho[i + 1] && bizcocho[i] != 0);
    
    for (int d = 3; d < N; d += 2) {
        for (int i = 0; i < N - d; i++) {
            int j = i + d;
            partir[i][j] = max(partir[i + 2][j], max(partir[i][j - 2], partir[i + 1][j - 1] + (bizcocho[i] == bizcocho[j] && bizcocho[i] != 0)));
        }
    }
    
    cout << partir[0][N - 1] << "\n";
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
