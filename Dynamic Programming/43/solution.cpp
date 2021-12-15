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

#include "EnterosInf.h"

/*@ <answer>
 
 Se pide calcular el minimo coste para conseguir una potencia específica a partir de un 
 número de bombillas con una potencia que las distingue unas de otras
 Se utilizará programación dinámica para resolver el problema atendiendo a la función recursiva:

 -luces(i, j) = minimo coste que se necesita para conseguir la potencia j a partir de los tipos de bombillas
 del 1 al i.

 Como se tiene una función recursiva, se parten de casos básicos los cuales son: 
 - luces (i, 0) = 0 en el caso de que no se necesite niguna potencia, es decir, la potencia que se pide es 0.
 - luces (0, j) = INF en el caso de que se disponga de 0 bombillas para una potencia j.
 Por contrapartida se tienen los siguientes casos recursivos:
 - luces (i, j) = luces(i - 1, j) si la potencia que se nos pide es mayor que la solicitada
 - luces (i, j) = min(luces(i - 1, j), luces (i, j - V_i) + C_i) en caso contrario.
 La solución buscada es la que cumple con la siguiente función recursiva: luces(N, j)

 Se utiliza una matriz con posibilidad de utilizar un vector para mejorar el coste del espacio. La matriz tendrá 
 una dimensión (N + 1) * (PMax) siendo N + 1 filas y PMax columnas. Se rellenará siguiendo la función recursiva explicada 
 anteriormenete: con el fin de obtener el valor de la matriz en la posición [i][j] se tendrá que haber calculado el valor
 de una fila anterior ([i - 1][j]) y el valor de la posición [i][j - V_i].

 Como se ha mencionado, se puede mejorar el coste espacial sustituyendo la matriz por un vector que se rellenará de izquierda 
 a derecha y que irá tomando los valores de cada una de las filas de la matriz.
 
 Así pues se tienen los costes:
 - En función del tiempo: O(N * PMax) siendo N el número de bombillas y PMax la potencia máxima permitida. Este coste se debe a que
 se rellena completamente la tabla y cada valor se calcula en tiempo constante.
 - En función del espacio: O(PMax) en el caso de que se use un vector.

 Se recorrerá el vector de costes para saber que bombillas coinciden con el precio final.
 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso() {
  
  int N, PMax, PMin;
  cin >> N >> PMax >> PMin;
  if (!cin)
    return false;
  
  vector<int> potencia(N);
  for (int & x : potencia)
    cin >> x;

  vector<int> coste(N);
  for (int & x : coste)
    cin >> x;
  
  vector<EntInf> luces(PMax + 1, Infinito);
  luces[0] = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = potencia[i - 1]; j <= PMax; j++)
      luces[j] = min(luces[j], luces[j - potencia[i - 1]] + coste[i - 1]);
  }

  int sol = PMin;
  for (int i = PMin + 1; i <= PMax; i++) {
    if (luces[i] < luces[sol])
      sol = i;
  }

  if (luces[sol] == Infinito)
    cout << "IMPOSIBLE\n";
  else
    cout << luces[sol] << " " << sol << "\n";
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
