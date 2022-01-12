/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

/*@ <answer>
  
 Se pide conocer la primera caja que quedará libre después del último cliente que se encuentre en la cola 
 del supermercado.
 Para ello, se crea una estructura llamada Cliente que almacene el número de caja que le toca y el tiempo que
 le va a llevar pagar su compra. Esta estructura será almacenada en una cola de prioridad la cual estará ordenada 
 de manera creciente en función del tiempo y en caso de que se tengan tiempos equivalentes, en función de la caja de manera
 creciente (de menor a mayor).

 A medida que se van introduciendo los datos de los clientes que hay por delante de Ismael se va cuestionando en que caja le tocará a cada uno
 según el primero que vaya a terminar en su respectiva caja viendo la cola de prioridad.

 El coste de la operación es: O(C) siendo C el número de clientes que se tiene en la cola inicialmente.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Cliente {
    int caja, tiempo;
    bool operator<(Cliente const& other) const {
        return tiempo > other.tiempo || (tiempo == other.tiempo && caja > other.caja);
    }
};

bool resuelveCaso() {

    int N, C;
    cin >> N >> C;
    if (N == 0 && C == 0)
        return false;

    priority_queue<Cliente> cajas;
    for (int i = 0; i < C; i++) {
        int tiempoCliente;
        cin >> tiempoCliente;
        if (i < N)  
            cajas.push({i + 1, tiempoCliente});
        else {
            Cliente fuera = cajas.top(); cajas.pop();
            cajas.push({fuera.caja, fuera.tiempo + tiempoCliente});
        }
    }

    if (N > C)
        cout << C + 1 << endl;
    else
        cout << cajas.top().caja << endl;
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
