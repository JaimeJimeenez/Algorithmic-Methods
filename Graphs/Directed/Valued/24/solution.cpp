#include <iostream>
#include <fstream>
#include <climits>
#include "DigrafoValorado.h"
#include "IndexPQ.h"
using namespace std;

// Funcion que resuelve el problema, para ello se utiliza el algoritmo de Prim
// para calcular el arbol recubridor mínimo. Si al terminar se han visitado
// todas las islas devolvemos el coste minimo, sino devolvemos -1 para avisar
// que no es posible.
//
// La complejidad de la función es de O(E log V), siendo E el número de aristas
// del grafo y V el número de nodos, ya que para cada arista se hacen operaciones
// de O(log V) con la cola de prioridad (IndexPQ).
int resolver(DigrafoValorado<int> const& grafo) {
	vector<int> distTo(grafo.V(), INT_MAX); // distTo[w] = edgeTo[w].weight()
	vector<bool> marked(grafo.V()); // true if v on tree		
	IndexPQ<int, std::less<int>> pq(grafo.V()); // eligible crossing edges

	// Algoritmo de Prim para calcular el arbol recubridor mínimo.
	distTo[1] = 0;
	pq.push(1, 0); // Initialize pq with 1, weight 0.
	while (!pq.empty()) {
		IndexPQ<int, std::less<int>>::Par v = pq.top();
		pq.pop();
		// Add v to tree; update data structures.
		marked[v.elem] = true;
		for (Arista<int> e : grafo.ady(v.elem))
		{
			int w = e.otro(v.elem);
			if (marked[w]) continue; // v-w is ineligible.
			if (e.valor() < distTo[w])
			{ // Edge e is new best connection from tree to w.
				distTo[w] = e.valor();
				pq.update(w, distTo[w]);
			}
		}
	}

	// Calculamos el coste minimo y comprobamos que se pueden conectar todas las islas.
	int costeMinimo = 0;
	for (int i = 1; i < grafo.V(); i++) {
		if (!marked[i]) {
			return -1; // Devolvemos -1 si no se pueden cubrir todas las islas.
		}
		costeMinimo += distTo[i];
	}

	// Devolvemos el coste minimo de cubrir todas las islas.
	return costeMinimo;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int islas, puentes;

	cin >> islas >> puentes;

	if (!cin) // fin de la entrada
			return false;

	// Leemos los puentes
	GrafoValorado<int> datos(islas + 1);
	for (int i = 0; i < puentes; i++) {
		int v, w, valor;
		cin >> v >> w >> valor;
		Arista<int> arista(v, w, valor);
		datos.ponArista(arista);
	}

	// Calculamos la solución.
	int sol = resolver(datos);

	// Mostramos la solución.
	if (sol == -1) {
		cout << "No hay puentes suficientes" << endl;
	}
	else
		cout << sol << endl;
	
	return true;
}
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