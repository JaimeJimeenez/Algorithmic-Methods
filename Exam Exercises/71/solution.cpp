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
  
 Se quiere saber el número minimo de gorras que se necesiten para una serie de partidos.
 Cada partido se disputará por dos equipos los cuales tienen unos seguidores determinados.
 Cada vez que gane un equipo, los seguidores del equipo perdedor pasarán a ser seguidores del equipo ganador.
 Por ello, se ordenarán los seguidores de cada equipo de menor a mayor en una cola de prioridad.
 Cada vez que se dispute un partido se anotarán las gorras necesarias para dicho partido y se insertará en 
 dicha cola los seguidores totales de cada partido.

 En cuanto al coste:
    - En función del tiempo: O(N) siendo N el número de equipos que se tienen inicialmente.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Equipo {
    int64_t seguidor;
    bool operator<(Equipo const& other) const {
        return seguidor > other.seguidor;
    }
};

int gorras(priority_queue<Equipo> equipos) {
    
    int64_t resultado = 0;

    while (!equipos.empty()) {
        if (equipos.size() == 1)
            return resultado;
        else {
            auto primero = equipos.top();
            equipos.pop();
            auto segundo = equipos.top();
            equipos.pop();
            int64_t partido = primero.seguidor + segundo.seguidor;
            resultado += partido;
            equipos.push({partido});
        }
    }
    
    return resultado;
}

bool resuelveCaso() {

    int N;
    cin >> N;
    if (N == 0)
        return false;
    
    priority_queue<Equipo> equipos;
    while (N--) {
        int64_t seguidor;
        cin >> seguidor;
        equipos.push({seguidor});
    }
    
    cout << gorras(equipos) << "\n";
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
