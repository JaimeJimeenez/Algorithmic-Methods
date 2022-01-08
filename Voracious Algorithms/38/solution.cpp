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
