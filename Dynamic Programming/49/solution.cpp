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
 Se nos presenta un ejercicio cuya finalidad es saber el minimo esfuerzo posible
 que existe para cortar un tablon de longitud j en N trozos, siendo N un número positivo. Al igual que
 se nos presentan N diferentes puntos de cortes (i) siendo estos menores que el tamaño de la longitud
 de dicho tablón. 
 Cuando se corta un trozo, el esfuerzo es el doble del punto de corte y como resultado se tiene
 el doble de tablones que se tenían anteriormente pero con un inicio y un final k, siendo k el punto de corte.
 Se presentará la función f(i, j) la cual indica el minimo esfuerzo que se debe realizar con los cortes de i a N
 para un tablón de longitud j. 
 Si se llega a dar el caso de que el punto de corte que se nos presenta no se toma, se pasará al punto siguiente.
 Si el punto de corte actual coindice con uno de los extremos del tablón, tampoco se tomará.
 En el caso de querer tomar ese punto de corte se comparará los esfuerzos de hacer ese corte con los posibles posteriores.
 Teniendo entonces la siguiente función recursiva:
 Caso base:
    f(i, j) = 0. En el caso que el numero de cortes concuerde con la longitud que se quiere cortar.
 Casos recursivos:
    f(i, j) = f(i + 1, j) si i >= j
              min(f(i, k) + f(k, j) + 2*puntos[i]) siendo puntos un vector donde se almacenan los posibles cortes
 La llamada inicial será f(1, L) siendo L la longitud del tablón inicial.
 Costes en función del:
    - Tiempo: O(n^3): siendo n el número de tablones
    - Espacio: O(n^3): siendo n el número de tablones.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

const int INF = 10000;

int esfuerzo(vector<int> const& puntos, int& L) {
    int n = puntos.size() - 1;
    Matriz<int> tablon(L + 1, L + 1, 0);

    for (int d = 1; d <= n - 1; d++) { //Recorre diagonales
        for (int i = 1; i <= n - d; i++) { //Recorre elementos de la diagonal
            int j = i + d; //Elemento de la diagonal
            tablon[i][j] = INF;
            for (int k = i; k <= j - 1; k++) {
                int temp = tablon[i][k] + tablon[k + 1][j] + 2 * puntos[i];
                if (temp < tablon[i][j])
                    tablon[i][j] = temp;
            }
        }
    }
    cout << tablon << endl;
    return tablon[1][n];
}

bool resuelveCaso() {

    int L, N;
    cin >> L >> N;
    if (N == 0 && L == 0)
        return false;
    
    vector<int> puntos(N);
    for (int i = 0; i < N; i++) {
       cin >> puntos[i];
    }

    int esfuerzoMin = esfuerzo(puntos, L);
    cout << esfuerzoMin << endl;
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
