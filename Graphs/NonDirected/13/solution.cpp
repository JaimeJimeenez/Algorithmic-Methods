#include "Grafo.h"
/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

using Mapa = vector<string>;

#ifndef MANCHAS_H_
#define MANCHAS_H_

class Manchas {
public:
    Manchas(Mapa const& m) : row(m.size()), column(m[0].size()), visit(row, vector<bool>(column, false)), num(0), maxim(0){
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (!visit[i][j]&& m[i][j] == '#') {
                    num++;
                    int nuevoTam = dfs(m, i, j);
                    maxim = max(maxim, nuevoTam);
                }
            }
        }
     };

     int numero() const { return num; }

     int maximo() const { return maxim; } 

private:
    int row, column;
    vector<vector<bool>> visit;
    int num;
    int maxim;
    const vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    bool correct(int i, int j) const {
        return 0 <= i && i < row && 0 <= j && j < column;
    }

    int dfs(Mapa const& m, int i, int j) {
        visit[i][j] = true;
        int tam = 1;
        for (auto d : dirs) {
            int ni = i + d.first, nj = j + d.second;
            if (correct(ni, nj) && m[ni][nj] == '#' && !visit[ni][nj])
                tam += dfs(m, ni, nj);
        }

        return tam;
    }
};

#endif
bool resuelveCaso() {
   
   // leer los datos de la entrada
   int n, m;
   cin >> n >> m;

   if (!std::cin)  // fin de la entrada
      return false;
   
   Mapa q(n);
   for (string & linea : q)
    cin >> linea;
   // resolver el caso posiblemente llamando a otras funciones
   
   Manchas manchas(q);
   cout << manchas.numero() << ' ' << manchas.maximo() << "\n";
   // escribir la solución

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
