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

class ComponenteConexa {
public:
    ComponenteConexa(Grafo const& G) : visit(G.V(), false), componente(G.V()), superComponente(G.V()) {

        for (int v = 0; v <= G.V(); v++) {
            if (!visit[v]) {
                int tam  = min(dfs(G, v), superComponente[v]);
            }
        }
    }


private:
    vector<bool> visit; //Vector que indica si un vertice ya ha sido visitado
    vector<int> componente; //Vector que para cada vertice indica a que componente pertenece
    vector<int> superComponente; //Vector que contiene para cada componente el minimo precio de papel

    int dfs(Grafo const& G, int v) {
        int tam = 1;
        visit[v] = true;
        for (int w : G.ady(v)) {
            if (!visit[w])
                tam += dfs(G, w);
        }
    }
};

bool resuelveCaso() {

    int N, C;
    cin >> N >> C;
    if (!cin)
        return false;

    Grafo g(N + 1);
    while (C--) {
        int v, w;
        cin >> v >> w;
        g.ponArista(v, w);
    }
    cout << g << endl;

    //Supermercados
    int S;
    cin >> S;
    while (S--) {

    }

    //Numero de consultas
    int K;
    cin >> K;
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
