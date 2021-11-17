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

 Se rellenará una matriz inicializada a 0 con la siguiente función recursiva:
    - Matriz[i][j] = mochila[i][j] - mochila[i - 1][j] si la profundidad del tesoro * 3 > j
    - Matriz[i][j] = max(mochila[i - 1][j], mochila[i - 1][j - (tesoros[i].profundidad * 3)] + tesoros[i].oro) en caso contrario
 Después se recorrerá dicha matriz para saber qué tesoros se cogen y cuantos en total se han recogido
 en función de si Matriz[i][resto] == Matriz[i - 1][resto], siendo resto la cantidad total de segundos que se puede sumergir

 El coste de la solución es:
    - Temporal: O(nT) siendo n el número de tesoros y T el número de segundos de la botella
    - Espacial: O(nT) siendo n el número de tesoros y T el número de segundos de la botella
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Tesoro {
    int profundidad;
    int oro;
};

void recogeTesoros(vector<Tesoro> const& tesoros, int T, int& maxOro, int& cuantos, vector<bool> & posibles) {
    size_t n = tesoros.size() - 1;
    Matriz<int> mochila(n + 1, T + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= T; j++) {
            if (tesoros[i].profundidad * 3 > j) //Profundidad de subir y bajar = 3 * profundidad
                mochila[i][j] = mochila[i - 1][j];
            else
                mochila[i][j] = max(mochila[i - 1][j], mochila[i - 1][j - (tesoros[i].profundidad * 3)] + tesoros[i].oro);
        }
    }

    maxOro = mochila[n][T];

    int resto = T;
    for (size_t i = n; i >= 1; i--) {
        if (mochila[i][resto] == mochila[i - 1][resto])
            posibles[i] = false;
        else {
            posibles[i] = true;
            resto = resto - (tesoros[i].profundidad * 3);
            cuantos++;
        }
    }
}

bool resuelveCaso() {

    int T, N;
    cin >> T >> N;
    if (!cin) 
        return false;
    
    vector<Tesoro> tesoros(N + 1);
    for (int i = 1; i <= N; i++) 
        cin >> tesoros[i].profundidad >> tesoros[i].oro;
    
    int maxOro = 0;
    int cuantos = 0;
    vector<bool> posibles(N + 1);
    recogeTesoros(tesoros, T, maxOro, cuantos, posibles);

    cout << maxOro << "\n";
    cout << cuantos << "\n";

    for (int i = 1; i <= N; i++) {
        if (posibles[i])
            cout << tesoros[i].profundidad << " " << tesoros[i].oro << "\n";
    }
    cout << "---" << "\n";

    return true;
}

//@ </answer>

int main() {

#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   while (resuelveCaso());
   
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
