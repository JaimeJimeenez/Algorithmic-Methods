/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>

#include "Grafo.h"
using namespace std;

/*@ <answer>
  
 Se quiere conocer el número minimo de guardias que hay que colocar en un determinado sitio.
 Para ello se comprueba la eficencia de poner o no un guardia en un cruce. Si el resultado es favorable
 se suma a la número de guardias necesarios.

 El coste del ejercicio es O(V + A) siendo V el número de vértices (o cruces) y A el número de aristas (o calles).
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class ColocaGuardias {
public:
    ColocaGuardias(Grafo const& g) : visit(g.V(), false), guardia(g.V(), 0) {
        for (int i = 0; i < g.V(); ++i) {
            if (!visit[i]) {
                int aux = coloca(g, i);

                if (aux == -1) {
                    minimo = -1;
                    break;
                }
                else minimo += aux;
            }
        }
    }

    int minimoGuardias() const { return minimo; }

private:
    int minimo = 0;
    vector<bool> visit;
    vector<int> guardia;

    int coloca(Grafo const& g, int v) {
        int nGuardiasCon = poneGuardia(g, v);

        for (int i = 0; i < g.V(); ++i)
            guardia[i] = 0;

        int nGuardiasSin = noPoneGuardia(g, v);

        if (nGuardiasCon > -1 && nGuardiasSin == -1)
            return nGuardiasCon;
        else if (nGuardiasCon == -1 && nGuardiasSin > -1)
            return nGuardiasSin;
        else return min(nGuardiasCon, nGuardiasSin);
    }

    int poneGuardia(Grafo const& g, int v) {
        guardia[v] = 1;
        visit[v] = true;
        int nG = 1;
        for (int w : g.ady(v)) {
            if (guardia[w] == 1)
                return -1;
            else if (guardia[w] == 0) {
                int aux = noPoneGuardia(g, w);
                if (aux == -1) return -1;
                nG += aux;
            }
        }
        return nG;
    }

    int noPoneGuardia(Grafo const& g, int v) {
        guardia[v] = -1;
        visit[v] = true;
        int nG = 0;
        for (int w : g.ady(v)) {
            if (guardia[w] == -1)
                return -1;
            else if (guardia[w] == 0) {
                int aux = poneGuardia(g, w);
                if (aux == -1) return -1;
                nG += aux;
            }
        }
        return nG;
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

    ColocaGuardias coloca(g);
    if (coloca.minimoGuardias() == -1)
        cout << "IMPOSIBLE\n";
    else
        cout << coloca.minimoGuardias() << "\n";
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
