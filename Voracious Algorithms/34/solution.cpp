/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;


/*@ <answer>
 
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 Se organizan los puntos de los broncos de mayor a menor y en cambio los puntos
 de los rivales de menor a mayor. Después se recorren los partidos y se sumará al
 resultado final la diferencia de los puntos de los partidos en los que los puntos
 de los broncos sean mayores que los puntos de sus rivales.
 
 Coste: O(NlogN) siendo N el número de partidos que se plantean. 
 
 Escribe también una demostración que justifique que tu solución encuentra
 siempre soluciones óptimas.
 Se representa las soluciones como N-tuplas, donde x_i son los puntos realizados
 por los broncos en el partido i. Si x_i > r_i, (siendo r_i los puntos obtenidos
 por los rivales) se le sumará su diferencia al resultado final.
 Suponiendo los puntos de los partidos de los broncos ordenados de mayor a menor:
    x_1 >= x_2 >= ... >= x_N
 Y suponiendo los puntos de los partidos de los rivales  ordenados de menor a mayor:
    r_1 <= r_2 <= ... <= r_N
 Se comparar la solución X del algoritmo voraz con una solución óptima Y. Suponiendo que
 ambas son iguales hasta la posición i, donde difieren:
    Sol X: x_1, x_2 ....  | x_i     ....
                            != 
    Sol Y: y_1, y_2 ....  | y_i     ....    y_k
 -x_i > r_i => Se realiza la diferencia entre los puntos de los broncos y la de los rivales
  (esto no es una diferencia)
 -x_i - r_i != y_i - r_i
    Si Y no está usando los mismos puntos de los broncos que X. Se puede intercambiar y_i = x_i.
 
 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Broncos {
    int puntos;
};

class ComparadorBroncos{
public:
    bool operator()(Broncos const& a, Broncos const& b) const {
        return a.puntos > b.puntos;
    }
};

struct Rival {
    int puntos;
};

class ComparadorRivales {
public:
    bool operator()(Rival const& a, Rival const& b) const {
        return a.puntos < b.puntos;
    }
};

bool resuelveCaso() {

    int N;
    cin >> N;
    if (N == 0) {
        return false;
    }

    int sumaTotal = 0;
    int puntos;
    vector<Rival> rivales;
    vector<Broncos> broncos;
    while (N--) {
        cin >> puntos;
        rivales.push_back({puntos});
    }
    sort(rivales.begin(), rivales.end(), ComparadorRivales());

    for (int i = 0; i < rivales.size(); i++) {
        cin >> puntos;
        broncos.push_back({puntos});
    }
    sort(broncos.begin(), broncos.end(), ComparadorBroncos());

    for (int i = 0; i < broncos.size(); i++) {
        if (broncos[i].puntos > rivales[i].puntos) {
            sumaTotal += (broncos[i].puntos - rivales[i].puntos);
        }
    }
    cout << sumaTotal << "\n";
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
  
  // Resolvemos
  while (resuelveCaso());
  
  // para dejar todo como estaba al principio
#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
  system("PAUSE");
#endif
  return 0;
}
