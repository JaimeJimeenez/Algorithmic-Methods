/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 Se introducen los parametros de entrada y se recoge el número de personas
 para cada instrumento en un vector.
 Se crea una estructura llamada instrumentos la cual recoge el numero de 
 personas que tienen dicho instrumento y la cantidad de partituras que 
 obtienen por ello.
 Se recorre el vector creado anteriormente y se reparte cada partitura.
 Una vez repartidas las partituras se crea una cola de prioridad en la que
 se introducirá el resultado de dividir el numero de personas que tocan cada 
 instrumento con el número de partituras que le ha tocado.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class Instrumento {
public:
   Instrumento(int musicos) : musico(musicos), partitura(1), tamMax(musicos) {

   }

   void repartir() {
      partitura++;
      tamMax = musico / partitura + (musico % partitura != 0);
   }

   int getMax() const {
      return tamMax;
   }

   bool operator<(Instrumento const& other) const {
      return other.tamMax  > this->tamMax;
   }

private:
   int musico;
   int partitura;
   int tamMax;

};

bool resuelveCaso() {
   
   // leer los datos de la entrada
   int p, n; //p numero de partituras y n numero de instrumentos distintos
   cin >> p >> n;

   if (!std::cin)  // fin de la entrada
      return false;

   priority_queue<Instrumento> orquesta;
   int musico;
   for (int i = 0; i < n; i++) {
      cin >> musico;
      orquesta.push(musico);
   }

   p -= n;
   while (p--) {
      Instrumento ins = orquesta.top();
      orquesta.pop();
      ins.repartir();
      orquesta.push(ins);
   }

   cout << orquesta.top().getMax() << "\n";
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
