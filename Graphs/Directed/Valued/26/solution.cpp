#include <iostream>
#include <fstream>
#include <climits>
#include "DigrafoValorado.h"
#include "IndexPQ.h"
using namespace std;

// Función que resuelve el problema, para ello se utiliza un grafo dirigido valorado y el algoritmo
// de Disjkstra. 
//
// Al calcular el algoritmo se añade al peso de cada arista el tiempo de carga del nodo origen.
// Al terminar se comprueba si existe camino hasta el destino y, si lo hay, se devuelve la 
// distancia hasta ese nodo mas el tiempo de carga del mismo.
//
// La complejidad de la funcion es de O(E log V), siendo E el número de aristas (enlaces web) del grafo
// y V el número de nodos (paginas web), ya que para cada arista se hacen operaciones de O(log V) con la 
// cola de prioridad.


int resolver(DigrafoValorado<int> const& grafo, vector<int> const& tiemposDeCarga) {
	vector<int> distTo(grafo.V(), INT_MAX); // distTo[w] = edgeTo[w].weight() + tiemposDeCarga
	vector<bool> marked(grafo.V()); // true if v on tree		
	IndexPQ<int, std::less<int>> pq(grafo.V()); // eligible crossing edges
	
	// Algoritmos de Dijkstra para ver el camino mímimo desde 1 hasta N.
	distTo[1] = 0.0;
	pq.push(1, 0.0);
	while (!pq.empty())	{
		int v = pq.top().elem;
		pq.pop();
		for (AristaDirigida<int> e : grafo.ady(v)) {
			int v = e.desde(), w = e.hasta();
			if (distTo[w] > distTo[v] + e.valor() + tiemposDeCarga[v]) // Mas el tiempo de carga de v
			{
				distTo[w] = distTo[v] + e.valor() + tiemposDeCarga[v];
				pq.update(w, distTo[w]);
			}
		}
	}	
	
	// Si no se pude llegar, devolvemos -1.
	if (distTo[grafo.V() - 1] == INT_MAX) 
		return -1;
	// Sino devolvemos el tiempo minimo mas el tiempo de carga de la última página.
	return distTo[grafo.V() - 1] + tiemposDeCarga[grafo.V() - 1];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int N, M;

	cin >> N;

	if (N == 0) // fin de la entrada
			return false;
	
	// Leemos los tiempos de carga
	vector<int> tiemposDeCarga(N + 1);
	for (int i = 1; i <= N; i++) {
		std::cin >> tiemposDeCarga[i];
	}

	// Leemos los enlaces
	DigrafoValorado<int> datos(N + 1);
	std::cin >> M;
	for (int i = 0; i < M; i++) {
		int v, w, valor;
		cin >> v >> w >> valor;
		AristaDirigida<int> arista(v, w, valor);
		datos.ponArista(arista);
	}

	// Calculamos la solución.
	int sol = resolver(datos, tiemposDeCarga);

	// Mostramos la solución.
	if (sol == -1) {
		cout << "IMPOSIBLE" << endl;
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