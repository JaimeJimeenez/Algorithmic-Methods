/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Dron {
    int bateria9;
    int bateria1;
    bool operator<(Dron const& other) const {
        return bateria9 < other.bateria9 && bateria1 < other.bateria1;
    }
};

void print(priority_queue <Dron> v) {
    
    while (!v.empty()) {
        auto elem = v.top();
        v.pop();
        cout << elem.bateria9 << " " << elem.bateria1 << " ";
    }
    cout << endl;
}

void printCola(priority_queue<int> c) {
    while (!c.empty()){
        cout << c.top() << " ";
        c.pop();
    }
    cout << endl;
}

void comprobacionBaterias(int &max, priority_queue<int> &bateria9, priority_queue<int> &bateria1, Dron const& elem) {
    if (elem.bateria9 > elem.bateria1) {
        max += (elem.bateria9 - elem.bateria1);
        bateria9.push(max);
    }
    else if (elem.bateria1 > elem.bateria9) {
        max += (elem.bateria1 - elem.bateria9);
        bateria1.push(max);
    }
    else {
        max += elem.bateria1;
        bateria1.push(0);
        bateria9.push(0);
    }

}

void horas(int N, priority_queue<Dron> &drones, priority_queue<int> &bateria9, priority_queue<int> &bateria1) {
    
    int aux = N - 1;
    int max = 0;
    auto elem = drones.top();
    drones.pop();
    comprobacionBaterias(max, bateria9, bateria1, elem);
    
    while (!bateria9.empty() && !bateria1.empty()) {
        if (aux == 0) {
            cout << max << " ";
            max = 0;
            aux = N;
        }
        elem = drones.top();
        drones.pop();
        comprobacionBaterias(max, bateria9, bateria1, elem);
        aux--;
        drones.push({ bateria9.top(), bateria1.top() });
        bateria9.pop();
        bateria1.pop();   
    }
}

bool resuelveCaso() {

    int N, A, B;
    cin >> N >> A >> B;
    if (!cin)
        return false;

    priority_queue<int> bateria9;
    int duracion;
    while (A--) {
        cin >> duracion;
        bateria9.push(duracion);
    }
    //printCola(bateria9);

    priority_queue<int> bateria1;
    while (B--) {
        cin >> duracion;
        bateria1.push(duracion);
    }
    //printCola(bateria1);

    priority_queue<Dron> drones;
    while (!bateria1.empty() && !bateria9.empty()) {
        drones.push( { bateria9.top(), bateria1.top() });
        bateria9.pop();
        bateria1.pop();
    }
    //print(drones);

    horas(N, drones, bateria9, bateria1);
    cout << endl;
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
