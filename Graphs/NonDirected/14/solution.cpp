/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>

#include "Grafo.h"
using namespace std;

/*@ <answer>
  
 Se pide conocer el tamaño de la componente conexa en el que se encuentra cada vertice.
 Para ello, se realizará un recorrido en profundidad que almacenará en un vector (componente)
 el componente al que pertenece cada vertice. Además se tendrá un vector que contendrá para cada
 componente su respectivo tamaño.

 El tamaño del ejercicio es de O(V + A) siendo V el número de vertices que componen el grafo y A el número de
 aristas.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class ComponenteConexa {
public:
    ComponenteConexa(Grafo const& g) : visit(g.V(), false), componente(g.V()) {
        
        for (int v = 0; v < g.V(); v++) {
            if (!visit[v]) {
                int tam = dfs(g, v);
                tamComp.push_back(tam);
            }
        }
    }

    int getTamV(int v) const { return tamComp[componente[v]]; }

private:
    vector<bool> visit;
    vector<int> tamComp;
    vector<int> componente;

    int dfs(Grafo const& g, int v) {
        visit[v] = true;
        componente[v] = tamComp.size();
        int tam = 1;
        for (int w : g.ady(v)) {
            if (!visit[w]) {
                tam += dfs(g, w);
            }
        }

        return tam;
    }
};

bool resuelveCaso() {

    int N, M;
    cin >> N >> M;
    if (!cin)
        return false;
    
    Grafo g(N + 1);
    while (M--) {
        int C, v, w;
        cin >> C;
        if (C > 0)
            cin >> v;
        for (int i = 1; i < C; i++) {
            cin >> w;
            g.ponArista(v, w);
            v = w;
        }
    } 

    ComponenteConexa componentes(g);
    for (int v = 1; v < g.V(); v++) 
        cout << componentes.getTamV(v) << " ";
    cout << endl;

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
