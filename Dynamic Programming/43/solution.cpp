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
#include "Matriz.h"
using namespace std;


/*@ <answer>
 
 luces(i, j) = min coste que se necesita para conseguir una potencia requerida (j) a partir de unas bombillas especificas (i).


 luces (i, j) = luces(i - 1, j) si V_i > j
                min(luces(i - 1, j), luces(i, j - V_i) + C_i) en caso contrario
 

 Se recorrerá el vector de costes para saber que bombillas coinciden con el precio final.
 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

void print(vector<int> const& v ) {
  for (auto elem : v) {
    cout << elem << " ";
  }
  cout << endl;
}

vector<int> numBombillas(vector<int> const& potencia, vector<int> const& coste,int max, int PMin, int& costeMinimo) {
  int n = potencia.size() - 1;
  Matriz<int> costeBombillas(n + 1, max + 1, 0);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= max; j++) {
      if (potencia[i] > j)
        costeBombillas[i][j] = costeBombillas[i - 1][j];
      else 
        costeBombillas[i][j] = min(costeBombillas[i - 1][j], costeBombillas[i][j - potencia[i] + coste[i]]);
    }
  }

  costeMinimo = costeBombillas[n][max];
  cout << costeMinimo;
  //Una vez hallado el coste minimo se conseguirá un vector

  return { };
}

bool resuelveCaso() {
  
   int N, PMax, PMin;
   cin >> N >> PMax >> PMin;
   if (!cin)
      return false;

   vector<int> potencia(N + 1); 
   for (int & x : potencia)
      cin >> x;
   vector<int> coste(N + 1);
   for (int & x : coste)
      cin >> x;
    
  int costeMinimo = 0;
  vector<int> bombillas = numBombillas(potencia, coste, PMax, PMin, costeMinimo);
  if (costeMinimo != 0) {

  }
  else 
    cout << "Imposible\n";
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
