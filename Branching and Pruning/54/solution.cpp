/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

/*@ <answer>
  
 Se presenta un ejercicio en el que se quiere saber el tiempo minimo en realizar una
 serie de trabajos. Dichos trabajos serán realizadas por N trabajadores de los cuales se conoce
 el tiempo que tardan en realizar cada trabajo.
 El objetivo es seleccionar un subconjunto S de los n trabajos realizados por los funcionarios
 que puedan realizarse en un tiempo minimo.
 Las soluciones son subconjuntos de funcionarios. Cada subconjunto se representa mediante su función característica,
 mediante una tupla (x1, ..., xn) donde xi = 1 indica que el funcionario i realiza la tarea i-ésima, mientras
 que xi = 0 indica que no.
 Test de factibilidad:
 Un subconjunto S de funcionarios es factible si y solo si la secuencia que ordena los funcionarios en S de forma
 no decreciente según el tiempo es admisible.  
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

void print(vector <vector<int>> const& v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

struct Nodo {
    vector<bool> sol;
    int k;
    double tiempo;
    double coste;
    double costeEstimado;
    bool operator<(Nodo const& other) const {
        return other.costeEstimado < costeEstimado;
    }
};

double calculoEstimacion(vector<vector<int>> trabajos, Nodo const& Y) {
    double estimacion = Y.coste;

    return estimacion;
}

void trabajos_rp(vector<vector<int>> const& trabajos, vector<bool>& mejorSolucion, double& mejorTiempo) {
    int N = trabajos.size();
    //Se genera la raiz
    Nodo Y;
    Y.sol = vector<bool>(N, false);
    Y.k = -1;
    Y.tiempo = Y.coste = 0;
    Y.costeEstimado = calculoEstimacion(trabajos, Y);
    priority_queue<Nodo> cola;
    cola.push(Y);
    mejorTiempo = numeric_limits<double>::infinity();
    int j = 0;
    while (!cola.empty() && cola.top().costeEstimado < mejorTiempo) {
        Y = cola.top();
        cola.pop();
        Nodo X(Y);
        X.k++;
        //En caso de que el hijo izquierdo, se realiza el trabajo
        if ()

        else {

        }
    }
}

bool resuelveCaso() {

    int N;
    cin >> N;
    if (N == 0)
        return false;
    
    vector<vector<int>> trabajos(N, vector<int>(N,0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> trabajos[i][j];
    }
    print(trabajos);

    vector<bool> mejorSolucion;
    double mejorTiempo = 0;
    trabajos_rp(trabajos, mejorSolucion, mejorTiempo);
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
