/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include "Matriz.h"
using namespace std;

/*@ <answer>
  
 
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

const int INF = 1000000000;

int relaciones(Matriz<int> const& red) {
    Matriz<int> P = red;
    int n = red.numfils() - 1;

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <=n; i++) {
            for (int j = 1; j <= n; j++) {
                int temp = P[i][j] + P[j][k];
                if (temp < P[i][j]) {
                    P[i][j] = temp;
                }
            }
        }
    }

    int maxCamino = 0;
    bool conectada = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j && P[i][j] < INF) {
                if (P[i][j] > maxCamino)
                    maxCamino = P[i][j];
            }
            if (j > i && P[i][j] >= INF) 
                conectada = false;
        }
    }

    if (conectada)
        return maxCamino;
    return -1;
}

bool resuelveCaso() {
    int P, R;
    cin >> P >> R;
    if (!cin)
        return false;

    Matriz<int> red(P + 1, P + 1, INF);
    for (int i = 0; i <= P; i++) 
        red[i][i] = 0; //Se rellenan las diagonales a 0  
    
    vector<string> personas(P);
    int u, v;
    for (int i = 1; i <= R; i++) {
        string persona1, persona2;
        cin >> persona1 >> persona2;

        bool nombre1 = false;
        bool nombre2 = false;
        int j = 0;
        while (!nombre1 || !nombre2) {
            if (persona1 == personas[j]) {
                nombre1 = true;
                u = j + 1;
            }
            else if (persona2 == personas[j]) {
                nombre2 = true;
                v = j + 1;
            }
            else if (personas[j] == "") {
                if (!nombre1) {
                    personas[j] = persona1;
                    nombre1 = true;
                    u = j + 1;
                }
                else if (!nombre2) {
                    personas[j] = persona2;
                    nombre2 = true;
                    v = j + 1;
                }
            }
            j++;
        }
        red[u][v] = 1;
        red[v][u] = 1; 
    }

    cout << red;
    int numRelaciones = relaciones(red);
    if (numRelaciones != -1)
        cout << numRelaciones << "\n";
    else
        cout << "DESCONECTADA\n";

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
