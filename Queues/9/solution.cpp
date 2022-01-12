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

 Para saber cual es la bateria máxima que se usa en cada vuelo se necesita ordenar las
 baterias de mayor a menor dado que se cogerán principalmente las que tengan una duración mayor
 y se tendrá que conocer el número de drones que se tienen.

 Coste O(N + M) siendo N el número de baterias de 9,5V y M el número de baterias de 1,5V

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

void vuelo(priority_queue<int> &bateria1, priority_queue<int> &bateria9, int duracion1, int duracion9, int &maxHoras) {

    if (duracion1 > duracion9) {
        bateria1.push(duracion1 - duracion9);
        maxHoras += duracion9;
    }
    else if (duracion1 < duracion9) {
        bateria9.push(duracion9 - duracion1);
        maxHoras += duracion1;
    }
    else 
        maxHoras += duracion1;
}

void horas(priority_queue<int> bateria1, priority_queue<int> bateria9, int N) {
    int max = 0;
    int cont = 0;

    while (!bateria1.empty() && !bateria9.empty()) {
        if (cont == N) { 
            cont = 0;
            cout << max << " ";
            max = 0;
        }
        int duracion1 = bateria1.top();
        bateria1.pop();
        int duracion9 = bateria9.top();
        bateria9.pop();
        vuelo(bateria1, bateria9, duracion1, duracion9, max);
        cont++;
    }

    cout << max << "\n";
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

    priority_queue<int> bateria1;
    while (B--) {
        cin >> duracion;
        bateria1.push(duracion);
    }

    horas(bateria1, bateria9, N);
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
