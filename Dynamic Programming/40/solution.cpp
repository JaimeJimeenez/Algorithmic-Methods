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
