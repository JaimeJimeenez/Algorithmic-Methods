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
    if (!cin)
        return false;

    vector<int> libros(N);
    for (auto &x : libros) 
        cin >> x;
    
    if (libros.size() <= 2) {
        cout << "0\n";
        return true;
    }
    sort(libros.begin(), libros.end(), greater<int>());

    int cont = 0;
    int descuento = 0;
    for (int i = 0; i < libros.size(); i++) {
        if (cont == 2) {
            descuento += libros.at(i);
            cont = 0;
            i++;
        }
        cont++;
    }
    cout << descuento << "\n";
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
