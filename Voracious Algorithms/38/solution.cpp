/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

/*@ <answer>

 Supongamos las personas ordenadas dependiendo de sus pesos de forma que P[0] <= P[1] <= ...

 El algoritmo voraz V toma la el peso más pequeño con el más grande disponible que pueden ocupar 
 un telesilla sin superar el peso máximo indicado. En el caso de que no se pueda dar esto, una sola persona 
 ocupará una sola telesila. Por tanto, el algoritmo voraz es una secuencia de conjuntos de personas que componen
 un telesilla

 Ejemplo:
    P 10 10 10 10

 La solución voraz: {1, 4} {2, 3} siendo estos los índices

 Sea O una solución óptima y sea i la primera posición donde O y V difieren O[i] != V[i]
 Entonces el conjunto de personas que conforman el telesilla en V[i] ha sido asignada más adelante en O.
 Sea k la posición que cumple que V[i] == O[k]

 P:  P[0] <= P[1] ...
 V:  V[0] V[1] ... | V[i]
        =   =  ... |  != 
 O:  O[0] O[1] ... | O[i] ... O[k] == V[k]

 Caso 1: V[i] == O[i] (los pesos conformados por el telesilla en la posición i son los mismos tanto en la voraz como en la óptima)

 Caos 2: V[i] != O[i] (al menos un peso en la solución voraz no coincide con la solución óptima). Si esto sucede, se intercambiaría i y k
 y el número de telesillas empleado para la resolución del caso de prueba no cambia. 
 
 El coste del algoritmo voraz es O(NlogN) siendo N el número de pesos de cada caso de prueba
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Telesilla {
    int peso1, peso2;
};

bool resuelveCaso() {
    
    int P, N;
    cin >> P >> N;
    if (!cin)
        return false;

    vector<int> pesos(N);
    for (int i = 0; i < N; i++)
        cin >> pesos[i];
    sort(pesos.begin(), pesos.end(), less<int>());

    vector<Telesilla> telesillas;
    int menor = 0;
    int mayor = N - 1;
    while (N-- && mayor >= menor) {
        if (pesos[menor] + pesos[mayor] <= P) {
            telesillas.push_back({ pesos[menor], pesos[mayor] });
            menor++;
            mayor--;
        }
        else {
            telesillas.push_back({0, pesos[mayor]});
            mayor--;
        }
    }
    cout << telesillas.size() << "\n";
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
