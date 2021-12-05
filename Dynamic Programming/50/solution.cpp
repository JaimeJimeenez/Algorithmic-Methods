/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Matriz.h"
using namespace std;

/*@ <answer>

Maximo tiempo que puedo estar viendo peliculas si puedo estar viendo peliculas de i a n 
y j es la ultima que se ha visto.

 f(i, j) = 

 Si la i comienza despues de que termine j + 10
   ci < ji + 10 la i no se puede ver entonces f(i + 1, j)
   ioc   max(f(i + 1, j),f(i + 1, i) + di) Es decir o no la veo f(i + 1, j) o la veo(f(i + 1, i) + di) siendo di la duracion de i

Caso base. f(n + 1, j) = 0

tiempo(i) = maximo tiempo si podemos ver desde la pelicula i hasta la ultima

tiempo(i) = max(tiempo(i + 1) // no se ve la i)
                  di + tiempo(j) //se ve la i y j es la primera que no solapa con la i o N si no hay ninguna que no solape

                  timepo(N) = 0// no quedan peliculas

Como se tienen dos argumentos se tiene una tabla de 2 dimensiones con 1 a N + 1 en vertical y de 0 a N

 int j = i + 1//Pelicula siguiente
    while (j < N && peliculas[i]-fin + 10 > peliculas[j].ini)
      j++;
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Pelicula {
   int ini;
   int fin;
};

class ComparadorPeliculas {
public:
   bool operator()(Pelicula const& a, Pelicula const& b) const {
      return a.fin < b.fin;
   }
};

int maxDuracion(vector<Pelicula> const& peliculas) {
   int n = peliculas.size();
   Matriz<int> duracion(n, n, 0);

   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
         if ()
         else
            max(duracion[i + 1][j], duracion[i + 1][i] + peliculas[i])
      } 
   }

}

bool resuelveCaso() {

   int N;
   cin >> N;
   if (N == 0)
      return false;
   
   vector<Pelicula> peliculas(N);
   int h, m, duracion;
   char c;
   for (int i = 0; i < N; i++) {
      cin >> h >> c >> m >> duracion;
      peliculas[i].ini = h * 60 + m;
      peliculas[i].fin = peliculas[i].ini + duracion; 
   }
   sort(peliculas.begin(), peliculas.end(), ComparadorPeliculas());

   
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
