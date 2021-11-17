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
 se resuelve el problema y cuál es el coste de la solución (tanto en
 tiempo como en espacio), en función del tamaño del problema.
 Coste O(N) tiempo: siendo N el numero de bombillas
 Coste O(P) espacio: siendo P el numero de costes de cada bombilla 
 Escribe en particular la especificación y definición de la recurrencia
 en la que te has basado para resolver el problema por programación dinámica.
 
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

vector<int> numBombillas(vector<int> const& M, int max, int PMin, int& potenciaF) {
  size_t n = M.size() - 1;
  //Se calcula el vector como una matriz
  vector<int> potencia(max + 1, INT_MAX - 1);
  potencia[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = M[i]; j <= max; j++) {
      potencia[j] = min(potencia[j], potencia[j - M[i]] + 1);
    }
  }
  //print(potencia);
  potenciaF = M[max];

  if (potenciaF != INT_MAX - 1) {
    vector<int> bombillas(n + 1, 0);
    int i = n; int j = max;
    while (j > 0) {
      if (M[i - 1] <= j && potencia[j] == potencia[j - M[i - 1]] + 1) {
        bombillas[i] = potencia[j];
        j = j - potencia[i];
      }
      else {
        i--;
      }
    }
    return bombillas;
  }
  else {
    potenciaF = -1;
    return { };
  }
}

bool resuelveCaso() {
  
  // leemos la entrada
   int N, PMax, PMin;
   cin >> N >> PMax >> PMin;
   if (!cin)
      return false;

   // leemos las características de los tipos de bombillas
   vector<int> potencia(N); // 0-based
   for (int & x : potencia)
      cin >> x;
   vector<int> coste(N); // 0-based
   for (int & x : coste)
      cin >> x;
    

  // resolver el caso
  int potenciaF = 0;
  vector<int> bombillas = numBombillas(potencia, PMax, PMin, potenciaF);
  if (potenciaF != -1) {
    int costeTotal = 0;
    for (int i = 0; i <= N; i++) 
      costeTotal += bombillas[i];
    cout << costeTotal << " " << potenciaF << "\n";
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
