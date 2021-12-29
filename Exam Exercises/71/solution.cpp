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
  
 
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Seguidor {
    int64_t s;
    bool operator<(Seguidor const& other) const {
        return this->s < other.s;
    }
    int64_t operator+(Seguidor const& other) const {
        return s + other.s;
    }
};

void print(priority_queue<Seguidor> s) {
    while (!s.empty()) {
        auto seguidor = s.top();
        s.pop();
        cout << seguidor.s << " ";
    }
    cout << endl;
}

bool resuelveCaso() {

    int N;
    cin >> N;
    if (N == 0)
        return false;

    if (N == 1) {
        cout << "0\n";
        return true;
    }

    priority_queue<Seguidor> seguidores;
    while (N--) {
        int S;
        cin >> S;
        seguidores.push({ S });
    }
    //print(seguidores);

    int64_t gorras = 0;
    int64_t resultado = 0;
    while (!seguidores.empty()) {
        if (seguidores.size() == 1) {
            resultado = seguidores.top().s;
            seguidores.pop();
        }
        else {
            auto primero = seguidores.top();
            seguidores.pop();
            auto segundo = seguidores.top();
            seguidores.pop();
            seguidores.push({ primero + segundo });
            gorras += primero + segundo;
            print(seguidores);
        }
    }

    cout << gorras << "\n";
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
