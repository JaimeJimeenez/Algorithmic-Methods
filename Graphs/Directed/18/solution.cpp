/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include "Digrafo.h"
using namespace std;

/*@ <answer>
  
 Se quiere conocer el orden en el que se tienen que realizar las tareas las cuales tienen un preferencia determinada.
 Para ello se representa las tareas y sus distintas relaciones como un grafo en el que las tareas son los vértices y las relaciones sus respectivas aristas dirigidas.
 Como el una tarea A depende de una tarea B, la misma tarea B no puede depender de la misma tarea A por lo que se considera que si el orden de realizarlas es posible
 el grafo deberá ser aciclíco.

 Se recorre el grafo mediante un recorrido en profunidad y se comprueba mediante un vector (apilado) que no se está considerando de nuevo un vertice. Si ese es el caso 
 se declara que es imposible y en caso contrario se realiza la ordenación topológica de el grafo.

 El coste del ejercicio es: O(V + A) siendo V el número de vértices del grafo y A el número de aristas. 
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class RecorriendoTareas {
private:
   vector<bool> visit;
   vector<bool> apilado;
   vector<int> ant;
   deque<int> camino;
   bool hayCiclo;

   void dfs(Digrafo const& g, int v) {
      visit[v] = true;
      apilado[v] = true;
      for (int w : g.ady(v)) {
          if (hayCiclo)
            return;
          else if (!visit[w]) {
              ant[w] = v;
              dfs(g, w);
          }
          else if (apilado[w])
            hayCiclo = true;
      }
      apilado[v] = false;
      camino.push_front(v);
   }

public:

    RecorriendoTareas(Digrafo const& g) : visit(g.V(), false), apilado(g.V(), false), ant(g.V()), hayCiclo(false) {
        for (int v = 1; v < g.V(); v++)
            if (!visit[v]) 
                dfs(g, v);
                
    }
    
    deque<int> getCamino() const { return camino; }
    
    bool getCiclo() const { return hayCiclo; }
};

bool resuelveCaso() {

   int N, M;
   cin >> N >> M;
   if (!cin)
      return false;

   Digrafo grafo(N + 1);
   while (M--) {
      int v, w;
      cin >> v >> w;
      grafo.ponArista(v, w);
   }

   RecorriendoTareas recorrido(grafo);
   if (recorrido.getCiclo())
      cout << "Imposible";
   else {
       deque<int> tareas = recorrido.getCamino();
       for (int i = 0; i < tareas.size(); i++)
        cout << tareas[i] << " ";
    }
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
