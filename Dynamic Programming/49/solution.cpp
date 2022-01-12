/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Matriz.h"
using namespace std;

/*@ <answer>
 Se pide conocer el minimo esfuerzo posible de cortar un tablos de longitud j en N trozos.
 Se utilizará programación dinámica para resolver este ejercicio siguiendo la siguiente función recursiva:
 
 - tablon(i, j) = minimo esfuerzo que se debe realizar con los puntos de cortes de i a N para un tablón de longitud j.
 
 Como se tiene una función recursiva, se tienen los siguientes casos basicos:
 - tablon(i, 0) = 0 sin el tablón es nulo y por tanto tiene una longitud nula
 - tablon(0, j) = Infinito si no se tiene ningún punto de corte para j.
 - tablon(i, j) = 0 si i == j
 Por contrapartida, se tienen los siguientes casos recursivos:
 - tablon(i, j) = tablon(i - 1, j) si i >= j
 - tablon(i, j) = min(tablon(i, k) + tablon(k, j) + 2 * puntos[i]) en caso contrario.
 
 La llamada inicial será f(1, L) siendo L la longitud del tablón inicial.
 Costes en función del:
    - Tiempo: O(n^3): siendo n el número de tablones
    - Espacio: O(n^3): siendo n el número de tablones.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

const int INF = 100000;
int cortaTableros(vector<int> const& C) {
    int n = C.size();
    Matriz<int> matrices(n + 1, n + 1, 0);
    for (int d = 2; d < n; ++d) {   //Las diagonales van de 1 a n - 1
        for (int i = 1; i <= n - d; ++i) {  //Nº total de elems en la diagonal d es n - d
            int j = i + d;  //La columna a la que pertenece el elem i de la diagonal d es i + d
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

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int L, N;
    cin >> L >> N;
    if (L == 0 && N == 0)
        return false;

    vector<int> cortes;
    cortes.push_back(0);
    for (int i = 0; i < N; ++i) {
        int c;
        cin >> c;
        cortes.push_back(c);
    }
    cortes.push_back(L);

    cout << cortaTableros(cortes) << "\n";
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
