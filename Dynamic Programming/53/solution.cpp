/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "Matriz.h"
using namespace std;


/*@ <answer>
 
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución (tanto en
 tiempo como en espacio), en función del tamaño del problema.

 Se plantea el problema de saber el coste minimo con el que se puede acceder
 de un poblado a otro. Para ello se plantea una función f(i, j) siendo esta el
 coste minimo que existe para poder viajar de un poblado i hasta un poblado j.
 
 Como se tienen dos argumentos se rellenará una tabla de dos dimensiones.Dicha tabla
 se recorrerá de manera diagonal. Cada celda indicará
 el coste minimo del viaje de llegar de un poblado i a un poblado j. La tabla se rellenará siguiendo 
 la siguiente función recursiva.

 El caso base será querer viajar al mismo poblado al que estamos, entonces el coste minimo
 será 0. Entonces:
    f(i, j) = 0 si i == j
 Se tendrá entonces la siguiente función recursiva:
    f(i, j) = f(i + 1, j) en el caso de que i + 1 == j.
    f(i, j) = min(viajes(i, k) + alquiler[i][k]) ioc siendo k un poblado no vecino.
 
 
 Escribe en particular la especificación y definición de la recurrencia
 en la que te has basado para resolver el problema por programación dinámica.

 El coste de las solución es:
    - En función del espacio O(n^3) siendo n el número de poblados.
    - En función del tiempo O(n^3) siendo n el número de poblados.
 
 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

const int INF = 10000000;

Matriz<int> matricesViajes(vector<vector<int>> const& alquiler) {
    int n = alquiler.size();
    Matriz<int> viajes(n + 1, n + 1, 0);
    
    for (int d = 1; d <= n - 1; d++) { //Se recorre la diagonal
        for (int i = 0; i <= n - d; i++) { 
            int j = i + d; //Elementos de la diagonal
            viajes[i][j] = INF;
            if (i + 1 == j) 
                viajes[i][j] = alquiler[i][j]; //En el caso de que j sea el poblado vecino de i 
            else {
                for (int k = i; k <= j - 1; k++) {
                    int temp = viajes[i][k] + alquiler[k][j];
                    if (temp < viajes[i][j])
                        viajes[i][j] = temp;
                }
            }
           
        }
    }

    return viajes;
}

bool resuelveCaso() {
  
  // leemos la entrada
  int N;
  cin >> N;
  
  if (!cin)
    return false;
  
  // leemos alquileres
  vector<vector<int>> alquiler(N, vector<int>(N,0));
  for (int i = 0; i < N-1; ++i) {
    for (int j = i+1; j < N; ++j) {
      cin >> alquiler[i][j];
    }
  }
  
  // resolver el caso
  Matriz<int> viajeBarato = matricesViajes(alquiler);
  for (int i = 0; i < N - 1; i++) {
      for (int j = i + 1; j < N; j++) {
          cout << viajeBarato[i][j] << " ";
      }
      cout << "\n";
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
  
  // Resolvemos
  while (resuelveCaso());
  
  // para dejar todo como estaba al principio
#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
  system("PAUSE");
#endif
  return 0;
}
