/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include "Grafo.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 Se representa la ciudad como un grafo donde los vértices son los puntos más cercanos
 en los que son posibles la existencia de un supermercado y las aristas son las calles que conectan
 dichos puntos. A continuación, se almacena en un vector los puntos en los que se encuentra un supermercado
 junto con su precio. Por último, se realizan las consultas partiendo de un punto en concreto.
 Se creará un patrón de solución que consisitirá en ir recorriendo los diferentes vértices y almacenando en que
 componente conexa pertenencen. Además se almacenará el tamaño de cada componente conexa en un vector definido.
 

 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class MinComponente{
public:
    MinComponente(Grafo const& G, vector<int> const& precios) : visit(G.V(), false), componente(G.V()) {
        for (int v = 0; v < G.V(); v++) {
            if (!visit[v]) {
                int mejor = dfs(G, v, precios);
                mejorPrecio.push_back(mejor);
            }
        }
    }

    int compConexa(int v) {
        return componente[v];
    }

    //Mejor precio de la componente a la que pertenece v
    int menorPrecio(int v) {
        return mejorPrecio[componente[v]];
    }
private:
    vector<int> visit; //visit[v] = vertice visitado
    vector<int> componente; //Número de componente a la que pertence el vertice i
    vector<int> mejorPrecio; //Mejor precio[i] = mejor precio de la componente a la que pertenece i

    int dfs(Grafo const& G, int v, vector<int> precios) {
        visit[v] = true; //Marca como visitado el vertice
        componente[v] = mejorPrecio.size(); //Coloca el vertice en la componente conexa
        int mejor = precios[v];

        for (int w : G.ady(v)) {
            if (!visit[w])
                mejor = min(mejor, dfs(G, w, precios));
        }

        return mejor;
    }
};

bool resuelveCaso() {
   
   int N, C; //Se presenta una ciudad con N vertices y C aristas
   cin >> N >> C;

   if (!std::cin)  // fin de la entrada
      return false;
   
   Grafo G(N);
   int v, w;

   while (C--) {
       cin >> v >> w;

       G.ponArista(v - 1, w - 1);
   }

   int S, punto, precio;
   vector<int> supermercados;
   supermercados.resize(N, 0);

   cin >> S;
   while (S--) {
       cin >> punto >> precio;
       supermercados.at(punto) = precio;
   }

   MinComponente m(G, supermercados);
   int K, nodo;

   cin >> K;
   while (K--) {
       cin >> nodo;
       if (m.menorPrecio(nodo) == 0)
            cout << "MENUDO MARRON\n";
        else
            cout << m.menorPrecio(nodo) << "\n"; 
    }
   
   cout << "---\n";
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
