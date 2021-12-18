/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;

/*@ <answer>

 Coste algoritmico:
    O(N) siendo n el numero de elementos a sumar.
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Sumador {
    int64_t sumando;
    bool operator<(Sumador const& other) const {
        return sumando > other.sumando;
    }
    int64_t operator+(Sumador const& other) const {
        return sumando + other.sumando;
    }
};

void print(priority_queue<Sumador> cola) {
    while (!cola.empty()) {
        Sumador n = cola.top();
        cola.pop();
        cout << n.sumando << " ";
    }
    cout << endl;
}

bool resuelveCaso() {
    
    int N;
    cin >> N;
    if (N == 0)
        return false;
    
    priority_queue<Sumador> sumas;
    while (N--) {
        int sumador;
        cin >> sumador;
        sumas.push({sumador});
    }

    int64_t esfuerzo = 0;
    
    if (sumas.size() == 1) {
        cout << esfuerzo << "\n";
        return true;
    }

    int64_t resultado = 0;

    while (!sumas.empty()) {
      if (sumas.size() == 1) {
          resultado = sumas.top().sumando;
          sumas.pop();
      }
      else  {
          auto primero = sumas.top();
          sumas.pop();
          auto segundo = sumas.top();
          sumas.pop();
          sumas.push( { primero + segundo });
          esfuerzo += primero + segundo;
      }
    }
    cout << esfuerzo << "\n";
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
