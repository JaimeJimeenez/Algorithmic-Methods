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
  
 
 Ordenando las peliculas de menor a mayor dependiendo de la duración de las películas 
 no es una solución correcta ya que se puede tener una pelicula que solape dos diferentes.
 Ordenando las peliculas por tiempo de inicio tampoco sería una solución correcta ya que se
 puede tener una pelicula cuya duración sea mayor que la duración de otras peliculas juntas.
 La solución por tanto es ordenar las peliculas de menor a mayor por tiempo de finalización.
 Su demostración se basará en reducción por diferencias:
  Se parte de la estrategia voraz planteada (X) y la solución óptima las cuales tienen en un principio
  las mismas peliculas. Llega un punto en que la estrategia voraz y la solución óptima eligen una pelicula distinta.
  La estrategia voraz elige una película la cual no solapa con las anteriores. Se propoone realizar un cambio que consistirá en 
  sustituir la película planteada en la solución optima por la propuesta en la estrategia voraz.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Pelicula {
    int inicio;
    int fin;
};

class ComparadorPeliculas {
public:
    bool operator()(Pelicula const& a, Pelicula const& b) const {
        return a.fin < b.fin;
    }
};

bool resuelveCaso() {
    
    int N;
    cin >> N;
    if (N == 0)
        return false;
    
    vector <Pelicula> cine(N);
    int h, m, duracion;
    char c;
    for (int i = 0; i < N; i++) {
        cin >> h >> c >> m >> duracion;
        cine[i].inicio = h * 60 + m;
        cine[i].fin = cine[i].inicio + duracion;
    }

    sort(cine.begin(), cine.end(), ComparadorPeliculas());
    int vistas = 1;
    int libre = cine[0].fin + 10;
    for (int i = 1; i < N; i++) {
        if (cine[i].inicio >= libre) {
            vistas++;
            libre = cine[i].fin + 10;
        }
    }
    cout << vistas << "\n";
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
