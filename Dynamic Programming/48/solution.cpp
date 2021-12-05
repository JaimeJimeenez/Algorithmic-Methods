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
  
Se empieza comparando sus dos ultimos caracteres. Si son iguales e seguro que la subsecuencia más larga
termina en ese caracter
f(i, j) = subsecuencia comun más larga de x[0, i) e Y[0, j)

f(i,j) = 1 + f(i-1, j-1) si X[i - 1] == Y[i - 1]
         max(f(i - 1, j) f(i, j - 1)) ioc

Caso basico: f(0, j) = 0
             f(i, 0) = 0
Llamada inicial f(N, M)
 

 Funcion de dos argumentos = tabla de dos dimensiones

 Para la reconstruccion:
    if (i = N && j = M)
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

void subcadenaMasLarga(string const& palabra1, string const& palabra2) {
    int n = palabra1.size();
    int m = palabra2.size();
    Matriz<int> mat (n + 1, m + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (palabra1[i - 1] == palabra2[j - 1]) 
                mat[i][j] = mat[i - 1][j - 1] + 1;
            else 
                mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
        }
    }

    int tam = mat[n][m];
    string subcadena(tam, ' ');
    int i = n, j = m;

    while (tam > 0) {
        if (palabra1[i - 1] == palabra2[j - 1]) {
            subcadena[--tam] = palabra1[i - 1];
            tam--;
            i--;
            j--;
        }
        else {
            if (mat[i][j - 1] > mat[i - 1][j]) 
                j--;
            else
                i--;
        }
    }

    cout << subcadena << "\n";
}

bool resuelveCaso() {

    string palabra1, palabra2;
    cin >> palabra1 >> palabra2;
    if (!cin) 
        return false;

    subcadenaMasLarga(palabra1, palabra2);
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
