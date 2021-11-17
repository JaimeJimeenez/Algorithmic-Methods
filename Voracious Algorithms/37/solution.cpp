/*@ <answer>
 *
 * Nombre y Apellidos:
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

void resuelveCaso() {

    int N, V, voltio;
    cin >> N >> V;
    vector<int> coches;
    for (int i = 0; i < N; i++) {
        cin >> voltio;
        coches.push_back(voltio);
    }
    sort(coches.begin(), coches.end());

    int menor = 0;
    int mayor = N - 1;
    for (int i = 0; i < N; i++) {
        if (coches[iInicio].voltio + coches[iFinal].voltio >= V) 
            pilas.push_back({coches[iInicio].voltio, coches[iFinal].voltio});
            ++menor;
            --mayor;
        else{
            ++menor;
        }
    }
    sort(pilas.begin(), pilas.end(), ComparadorPilas());

    cout << pilas.size() << "\n";
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   std::cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
      resuelveCaso();
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
