/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*@ <answer>
 
 Coste O(T * logN) siendo N el número de baterias que se dispongan.
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Bateria {
	int id, duracion, capacidad;
	bool operator<(Bateria const& other) const {
		return duracion > other.duracion || (duracion == other.duracion && id > other.id);
	}
};

void print(priority_queue<Bateria> baterias) {
	while (!baterias.empty()) {
		auto bateria = baterias.top(); baterias.pop();
		cout << bateria.id << " " << bateria.duracion << "\n";
	}
}

bool resuelveCaso() {

	int B;
	cin >> B;
	if (!cin)
		return false;
	
	priority_queue<Bateria> baterias;
	int id = 1;
	int duracion;
	for (int i = 0; i < B; i++) {
		cin >> duracion;
		baterias.push( {id++, duracion, duracion } );
	}

	int R;
	cin >> R;
	priority_queue<Bateria> repuestos;
	while (R--) {
		cin >> duracion;
		repuestos.push( {id++, duracion, duracion });
	}

	int Z, T;
	cin >> Z >> T;
	
	int cont = 0;

	while (cont <= T + 1) {
		if (baterias.top().duracion == cont) {
			priority_queue<Bateria> aux;
			while (!baterias.empty()) {
				auto bateria = baterias.top(); baterias.pop();
				if (bateria.duracion == cont) {
					if (bateria.capacidad - Z > 0) 
						aux.push( {bateria.id, bateria.duracion + Z, bateria.capacidad - Z} );
					else if (!repuestos.empty()) {
					aux.push(repuestos.top());
					repuestos.pop();
					}
				}
				else 
					aux.push(bateria);
			}
			baterias = aux;
		}
		cont++;
	}

	if (baterias.empty())
		cout << "ABANDONEN INMEDIATAMENTE LA BASE\n";
	else {
		if (baterias.size() == B)
			cout << "CORRECTO\n";
		else 
			cout << "FALLO EN EL SISTEMA\n";
		print(baterias);
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
