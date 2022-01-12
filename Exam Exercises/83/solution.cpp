/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <string>

#include "Matriz.h"
#include "EnterosInf.h"
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

EntInf trim_rec(string const& palabra, int i, int j, Matriz<EntInf> & tabla) {

    if (i > j) {
        tabla[i][j] = 0;
    }
    else if (palabra[i] == palabra[j])
        tabla[i][j] = trim_rec(palabra, i + 1, j - 1, tabla);
    else 
        tabla[i][j] = min(trim_rec(palabra, i + 1, j - 1, tabla), trim_rec(palabra, i, j - 1, tabla) + 1);

    return tabla[i][j];
}

bool resuelveCaso() {

    string palabra;
    cin >> palabra;
    if (!cin)
        return false;

    int n = palabra.size();
    Matriz<EntInf> tabla(n, n, Infinito);
    cout << trim_rec(palabra, 0, n - 1, tabla) << endl;

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
