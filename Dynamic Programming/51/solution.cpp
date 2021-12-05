/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include "EnterosInf.h"
#include "Matriz.h"
using namespace std;

/*@ <answer>
  
 Nos dicen que el valor de las monedas que llevemos debe ser exacto al precio del coche, por lo que si se 
 lleva una moneda que sobrepase al precio actual, esa moneda se descarta automaticamente.
 Si se coge la moneda tenemos que asegurarnos que todavía haya monedas de ese valor, que el numero de monedas
 que se coja de ese tipo no sobrepase el valor actual requerido y que el valor de la moneda actual no sobrepase el precio pedido. 
 Se tendrá la siguiente función recursiva:
    Caso base: f(i, 0) = 0. No se tienen ningun tipo de moneda.
    f(i, j) = minimo numero de monedas con valor del 1 al i que se necesitan para pagar un coche con valor j.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

int monedas(vector<int> const& valoresMoneda, vector<int> const& cantidad, int& precio) {
    int n = valoresMoneda.size();
    Matriz<int> monedas(n + 1, n + 1, INT_MAX - 1);

    cout << "h";
    monedas[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        monedas[i][0] = 0;
        for (int j = 1; j <= precio; j++) { //Precio actual
            if (j >= valoresMoneda[i - 1]) {
                int temp = INT_MAX - 1;
                for (int k = 1; k >= cantidad[i - 1] && j - k * valoresMoneda[i - 1] >= 0 && j - k * valoresMoneda[i - 1] <= precio; k++) {
                    temp = monedas[i - 1][j - k * valoresMoneda[i - 1]] + k;
                    if (temp < monedas[i][j]) {
                        monedas[i][j] = temp;
                    }
                }
            }
        }
    }

    return monedas[n][precio];
}

bool resuelveCaso() {

    int N;
    cin >> N;
    if (!cin)
        return false;

    vector<int> valoresMoneda(N);
    vector<int> cantidad(N);

    for (int i = 0; i < N; i++) 
        cin >> valoresMoneda[i];
    for (int i = 0; i < N; i++)
        cin >> cantidad[i];

    int coche;
    cin >> coche;

    int num = monedas(valoresMoneda, cantidad, coche);
    if (num == INT_MAX - 1) 
        cout << "NO\n"; 
    else 
        cout << "SI" << num << "\n";
    
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
