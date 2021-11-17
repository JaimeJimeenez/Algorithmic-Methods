/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

/*@ <answer>


 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Persona {
    int peso;
};

class ComparadorPersonas {
public:
    bool operator()(const Persona& a, const Persona& b) const {
        return a.peso > b.peso;
    }
};

void print(vector<Persona> const& a) {
    for (auto elem : a) {
        cout << elem.peso << " ";
    }
    cout << endl;
}

bool resuelveCaso() {
    
    int telesilla, usuarios;
    cin >> telesilla >> usuarios;
    if (!std::cin)
        return false;

    int peso;
    vector<Persona> personas;
    for (int i = 0; i < usuarios; i++) {
        cin >> peso;
        personas.push_back({peso});
    }    
    sort(personas.begin(), personas.end(), ComparadorPersonas());
    print(personas);

    int viajes = 0;
    int inicio = 1;
    int pesoTotal = personas[0].peso + personas[personas.size() - 1].peso;
    int final = personas.size() - 1;

    while (inicio < final) {

    }

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
