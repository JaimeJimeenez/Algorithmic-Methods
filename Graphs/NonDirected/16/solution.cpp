/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

#include "Grafo.h"
using namespace std;

/*@ <answer>
  
 Se pide conocer el supermercado que venda más barato el rollo de papel. Para ello se representa la ciudad mediante un grafo 
 siendo los puntos de interés sus vertices y las calles las aristas. 
 Como no se pide el supermercado más próximo desde un punto de origen se elegirá el recorrido en profundidad. Se almacena en un 
 vector la componente conexa a la que pertenece cada vertice y en otro vector el precio más bajo que existe en dicha componente.
 
 El coste del ejercicio es O(N + M) siendo N el número de vértices y M el número de aristas.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class RecorridoProfundidad {
public:

    RecorridoProfundidad(Grafo const& g, vector<int> const& supermercados) : visit(g.V(), false), componente(g.V()), minim(INT_MAX - 1), supermercados(supermercados) {
        for (int v = 0; v < g.V(); v++) {
            if (!visit[v]) {
                dfs(g, v);
                precioComp.push_back(minim);
                minim = INT_MAX - 1;
            }
        }
    }

    int minimo(int v) const { return precioComp[componente[v]]; }

private:
    vector<bool> visit;
    vector<int> componente;
    vector<int> precioComp;
    vector<int> supermercados;
    int minim;

    void dfs(Grafo const& g, int v) {
       visit[v] = true;
       componente[v] = precioComp.size();
       if (supermercados[v] != -1) 
           minim = min(supermercados[v], minim);
       for (int w : g.ady(v)) {
           if (!visit[w])
            dfs(g, w);
       }
    }
};

bool resuelveCaso() {

    int N, M;
    cin >> N >> M;
    if (!cin)
        return false;

    Grafo g(N + 1);
    while (M--) {
        int v, w;
        cin >> v >> w;
        g.ponArista(v, w);
    }

    int S;
    cin >> S;
    vector<int> supermercados(N + 1, -1);
    while (S--) {
        int i, precio;
        cin >> i >> precio;
        supermercados[i] = precio;
    }

    RecorridoProfundidad recorrido(g, supermercados);
    int K;
    cin >> K;
    while (K--) {
        int s;
        cin >> s;
        if (recorrido.minimo(s) == INT_MAX - 1)
            cout << "MENUDO MARRON\n";
        else
            cout << recorrido.minimo(s) << "\n";
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
