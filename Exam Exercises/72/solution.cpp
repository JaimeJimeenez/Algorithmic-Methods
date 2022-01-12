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
 
 Se quiere conocer el estado de una base en Marte pasados T tiempo (siendo T un dato introducido por consola). Para ello se utiliza 
 una cola de prioridad para almacenar las baterias que se disponen actualmente y que están actualmente en funcionamiento. El orden de esta
 cola es según el tiempo de duración de dicha batería para poder comprobar su carga en el momento en el que se acabe.

 Coste: O(T*N) siendo T el tiempo que se quiere comprobar el estado de dicha base y N el número de baterias que se dispone en la cola.
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Bateria {
	int id;
	int tiempo;
	int carga;
	Bateria(int id, int tiempo) : id(id), carga(tiempo), tiempo(tiempo) { }
	Bateria(int id, int tiempo, int carga) : id(id), carga(carga), tiempo(tiempo) { }

	bool operator<(Bateria const& other) const {
		return other.tiempo < tiempo || (other.tiempo == tiempo && other.id < id);
	}
};

void print(priority_queue<Bateria> baterias) {
	while (!baterias.empty()) {
		auto bateria = baterias.top(); baterias.pop();
		cout << bateria.id << " " << bateria.tiempo << endl;
	}
}

bool resuelveCaso() {

	int B;
	cin >> B;
	if (!cin)
		return false;

	priority_queue<Bateria> baterias;
	int id = 1;
	int numBaterias = B;
	while (B--) {
		int tiempo;
		cin >> tiempo;
		baterias.push({id++, tiempo});
	}

	queue<Bateria> repuestos;
	int R;
	cin >> R;
	while (R--) {
		int tiempo;
		cin >> tiempo;
		repuestos.push({id++, tiempo});
	}

	int Z, T;
	cin >> Z >> T;
	int tiempoActual = 0;

	if (!baterias.empty()) {
		tiempoActual = baterias.top().tiempo;
		while (tiempoActual <= T && !baterias.empty()) {
			if (baterias.top().carga - Z <= 0) { //Se da por hecho que la primera bateria de la cola se ha acabado
				baterias.pop();
				if (!repuestos.empty()) {
					baterias.push({ repuestos.front().id, repuestos.front().tiempo, repuestos.front().carga });
					repuestos.pop();
				}
			}
			else {
				Bateria bateria = baterias.top();
				baterias.pop();
				baterias.push({bateria.id, bateria.carga - Z + tiempoActual, bateria.carga - Z });
			}
			if (!baterias.empty()) //Si siguen quedando baterias se volverá a comprobar la siguiente bateria con su respectivo tiempo
				tiempoActual = baterias.top().tiempo;
		}
	}

	if (baterias.empty()) 
		cout << "ABANDONEN INMEDIATAMENTE LA BASE\n";
	else {
		if (baterias.size() == numBaterias)
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
