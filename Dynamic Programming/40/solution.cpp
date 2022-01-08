/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <limits>
#include <climits>
using namespace std;

/*@ <answer>

 Se pide calcular el número minimo de dardos junto con los sectores que se necesitan acertar
 para conseguir una puntuación determinada.
 Se utilizará programación dinámica para resolver el problema atendiendo a la función recursiva:

 - tiradas(i, j) = minimo número de tiradas para conseguir una puntuación j a partir de unos sectores numerados 
 de la 1 a la i

 Como se tiene una función recursiva, se parten de casos básicos los cuales son:
 - tiradas (i, 0) = 0 en el caso que la puntuación que se quiera sea nula (0)
 - tiradas (0, j) = Infinito en el caso en que no se tenga ningún sector con el que se pueda conseguir una puntuación
 Por contrapartida se tienen los siguientes casos recursivos:
 - tiradas (i, j) = tiradas (i - 1, j) si la puntuación del sector es mayor que j
 - tiradas (i, j) = min(tiradas(i - 1, j), tiradas(i, j - diana[i]) +  1) en caso contrario
 La solución buscada es la que cumple con la siguiente función recursiva: tiradas(1, N)

 Se utiliza una matriz con posibilidad de utilizar un vector para mejorar el espacio utilizado. La matriz tiene una dimensión (N + 1) * (P + 1)
 siendo N el número de sectores que se tienen y P la puntuación requerida. La matriz se rellenará siguiendo las distintas funciones recursivas explicadas
 anteriormente por lo que para conocer el elemento de la matriz localizada en la posición [i][j] se tendrá que haber calculado el valor de una fila anterior
 ([i - 1][j]) y el valor de la posición [i][j - diana[i]].

 Como se ha mencionado, se puede mejorar el coste espacial susituyendo la matriz por un vector que se irá recorriendo de izquierda a derecha y que irá tomando
 los valores de cada una de las filas de la matriz.

 Así pues se tienen los coste:
 - En función del tiempo: O(N * P) siendo N el número de sectores de la diana y P la puntuación pedida. Este valor es debido a que se rellenará completamente la tabla
 y se irá recorriendo de forma constante
 - En función del espacio: O(P) en el caso de que se use un vector.
 
 Se irá recorriendo el vector para saber cuantas tiradas a que sectores hay que lanzar.
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

vector<int> minimoDardos(vector<int> const& diana, int valor, int& numTiradas) {
    size_t n = diana.size() - 1;
    vector<int> tiradas (valor + 1, INT_MAX - 1); //Se presupone que INT_MAX - 1 = INF
    tiradas[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = diana[i]; j <= valor; j++) {
            tiradas[j] = min(tiradas[j], tiradas[j - diana[i]] + 1);
        }
    }
    
    numTiradas = tiradas[valor];
    
    if (numTiradas != INT_MAX - 1) {
        vector<int> cuantas(n + 1, 0);
        int i = n; int j = valor;
        while (j > 0) { //Mientras que no se alcance el valor requerido
            if (diana[i] <= j && tiradas[j] == tiradas[j - diana[i]] + 1){
                cuantas[i]++;
                j = j - diana[i];
            }
            else
                i--;
        }
        return cuantas;
    }
    else {
        numTiradas = -1;
        return { };
    }
}

bool resuelveCaso() {

    int valor, S;
    cin >> valor >> S;
    if (!std::cin)
        return false;

    vector <int> diana(S + 1);
    for (int i = 1; i <= S; i++) {
        cin >> diana[i];
    }
    sort(diana.begin(), diana.end(), less<int>());

    int tiradas = 0;
    vector<int> numTiradas = minimoDardos(diana, valor, tiradas);

    if (tiradas != -1) {
        cout << tiradas << ":";
        for (int i = S; i > 0; i--) { //Se ordena de mayor a menor
            for (int j = numTiradas[i]; j > 0; j--) {
                cout << " " << diana[i];
            }
        }
        cout << "\n";
    }
    else
        cout << "Imposible" << "\n";
    
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
