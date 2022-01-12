/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/*@ <answer>

 Supongamos los tamaños de los esquis y la longitud de las personas de la forma que siendo
 i <= j => P[i] <= P[j] && E[i] <= E[j]

 El algoritmo voraz V toma los esquies más pequeños que quedan y se le asigna con la persona
 cuya estatura sea la menor para que la diferencia entre estas dos medidas sea la menor posible.
 Por tanto, el aspecto de la solución voraz es una secuencia creciente de índices de longitudes (tanto
 de esquíes como de personas) en las que se suma la diferencia que se tiene al comparar estas dos medidas.

 Ejemplo:
    E 10 15 20
    P 12 16 23
 
 La solución voraz: 2 1 3 que corresponden con las diferencias (en valor absoluto) de la altura de las personas 
 con la longitud de los esquis.

 Sea O una solución óptima y sea i la primera posición donde 0 y V difieren:
 Entonces la diferencia de V[i] ha sido asignada más adelante en O. Sea k la posición que cumple que
 V[i] == O[k]
 
 E:     E[0] <= E[1] ...
 V:     V[0] V[1]   ... | V[i]
            =     =     | !=
 O:     O[0] O[1] ...   | O[i] ... O[k] == V[k]

 Caso 1: O[i] == V[i] (la diferencia entre las distintas longitudes es la misma)

 Caso 1.2: Si la diferencia en la solución óptima no coincide con la voraz, se puede intercambiar i y k sin que cambie 
 el resultado final.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso() {

    int N;
    cin >> N;
    if (N == 0)
        return false;
    
    vector<int> personas(N);
    for (auto &x : personas)
        cin >> x;
    sort(personas.begin(), personas.end(), greater<int>());

    vector<int> esquis(N);
    for (auto &x : esquis)
        cin >> x;
    sort(esquis.begin(), esquis.end(), greater<int>());

    int diferencia = 0;
    for (int i = 0; i < N; i++) 
        diferencia += abs(personas.at(i) - esquis.at(i));

    cout << diferencia << "\n";
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
