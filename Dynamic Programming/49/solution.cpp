/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include "Matriz.h"
using namespace std;

/*@ <answer>
  
 Se pide conocer el minimo esfuerzo que puede haber al cortar un tablón de longitud L en ciertos puntos.
 Para ello se usará programación dinámica para resolver el ejercicio siendo la función recursiva:
    
    - cortar(i, j) = minimo esfuerzo necesario que se necesita para cortar un tablón de longitud j
    partiendo de los puntos de corte de i a n.

 Como toda función recursiva, se tienen los siguientes casos básicos:
    - cortar(i, 0) = 0 si no se tiene ninguna tabla que cortar.
    - cortar(0, j) = INF si no se tienen ningún punto de corte 
 Por contrapartida se tienen los siguientes casos recursivos:
    -  cortar (i, j) = min(cortar(i, j), cortar(i, k) + cortar(k, j) + 2 * [C[j - 1] - C[j - 1]])
    - cortar (i, j) en caso contrario.

 Se usará una tabla o matriz de doble dimension para almacenar los resultados de los distintos subproblemas y se tendrá como 
 solución la llamada a cortar(1, n).

 En cuanto al coste:
    - En función del espacio: O(N^2) siendo N el número de cortes posibles
    - En función del tiempo: O(N^3).
     
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

int cortar (vector<int> const& C) {
    int n = C.size();
    Matriz<int> matrices(n + 1, n + 1, 0);
    for (int d = 2; d < n; ++d) {   
        for (int i = 1; i <= n - d; ++i) {  
            int j = i + d;
            matrices[i][j] = INT_MAX;
            for (int k = i + 1; k < j; ++k) {
                int temp = matrices[i][k] + matrices[k][j] + 2 * (C[j - 1] - C[i - 1]);
                if (temp < matrices[i][j]) {
                    matrices[i][j] = temp;
                }
            }
        }
    }
    return matrices[1][n];
}

bool resuelveCaso() {

    int L, C;
    cin >> L >> C;
    if (L == 0 && C == 0)
        return false;

    vector<int> puntos(C + 1);
    for (int i = 1; i < puntos.size(); i++)
        cin >> puntos[i];
    puntos.push_back(L);

    cout << cortar(puntos) << endl;
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
