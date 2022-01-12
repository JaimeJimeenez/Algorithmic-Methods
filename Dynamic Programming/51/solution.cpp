/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "EnterosInf.h"
#include "Matriz.h"
using namespace std;

/*@ <answer>
  
 Se pide conocer el número mínimo de monedas que se tienen que llevar para conseguir comprar un determinado coche.
 Se utilizará la programación dinámica para conseguir este fin, siendo la función recursiva:
    
    - tabla(i, j) = minimo número de monedas que se necesitan para comprar un coche de precio j si se tienen unas monedas 
    numeradas de 1 a n siendo n el número de monedas.

 Como toda función recursiva se tienen los siguientes casos recursivos:
    - tabla(0, 0) = 0 no se tiene nigún tipo de moneda para pagar un coche de precio 0 (nulo)
    - tabla(i, 0) = 0 no hay ningún coche que pagar
 
 Por conntrapartida se tienen los siguientes casos recursivos:
    - tabla(i, j) = INF si j < monedas[i - 1].valor, es decir el valor de la moneda i-esima es mayor que el coste restante o total del coche
    - tabla(i, j) = min(tabla[i - 1][j - k * monedas[i - 1].valor + k], tabla[i - 1][j]) en caso contrario

 Como se necesitan los valores de la tabla no se puede mejorar el coste en función del espacio. La tabla tendrá una dimensionalidad (N + 1) * (coche + 1)
 siendo N el número de monedas que se disponen. Dicha tabla se recorrerá en diagonal y de izquierda a derecha.

 El coste en función del espacio y del tiempo es O((N + coche)^3) ya que se tendrá que rellenar la tabla.
 La llamada a dicha tabla es tabla(n, coche) ya que se parten de n monedas para conseguir un coche de precio "coche". 
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

const int INF = 1000000000;

struct Moneda {
    int valor, cantidad;
};

class CompararMonedas {
public:
    bool operator()(Moneda const& a, Moneda const& b) const {
        return a.valor > b.valor;
    }
};

int minimasMonedas(vector<Moneda> const& monedas, int coche) {
    int n = monedas.size();
    Matriz<int> tabla(n + 1, coche + 1, INF);
    tabla[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        tabla[i][0] = 0;
        for (int j = 1; j <= coche; j++) {
            tabla[i][j] = tabla[i - 1][j];
            if (j >= monedas[i - 1].valor) { 
                for (int k = 1; k <= monedas[i - 1].cantidad && j - k * monedas[i - 1].valor >= 0 && j - k * monedas[i - 1].valor <= coche; k++) {
                    int temp = tabla[i - 1][j - k * monedas[i - 1].valor] + k; 
                    if (temp < tabla[i][j])
                        tabla[i][j] = temp;
                }
            }
        }
    }

    return tabla[n][coche];
}

bool resuelveCaso() {

    int N;
    cin >> N;
    if (!cin)
        return false;

    vector<Moneda> monedas(N);
    for (int i = 0; i < N; i++)
        cin >> monedas[i].valor;
    
    for (int i = 0; i < N; i++) 
        cin >> monedas[i].cantidad;
    
    sort(monedas.begin(), monedas.end(), CompararMonedas());

    int coche;
    cin >> coche;

    int minimo = minimasMonedas(monedas, coche);
    if (minimo == INF) 
        cout << "NO\n"; 
    else 
        cout << "SI " << minimo << "\n";
    
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
