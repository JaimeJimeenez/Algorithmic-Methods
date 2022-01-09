/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

/*@ <answer>
  
 Supongamos los libros ordenados de la forma que siendo i <= j => L[i] => L[j]

 El algoritmo voraz V toma el libro más caro que queda (después de haber ido recorriendo los libros de 
 manera creciente de dos en dos) y suma el precio de dicho libro al descuento total. A continuación reinicia
 el contador a 0 para informar que el siguiente libro que se vaya a comprar es el primer libro de la oferta 3 X 2.

 Ejemplo:
 L: 40 35 30 25 20 15 10

 La solución voraz: 2, 5 son los índices de los libros a los que se ha aplicado el descuento, teniendo un descuento total de 45.
 Se representa la solución como N-tuplas, donde V_i es que se ha hecho con el libro en dicha posición.
 Si V[i] = L[r] es que ese libro se ha descontado del precio total. En caso contrario, si V[i] = comprada, es que se ha
 tenido que comprar el libro para intentar conseguir la oferta del 3 X 2.

 Sea O una solución óptima y sea i la primera posición donde O y V difieren: O[i] != V[i].
 Entonces el libro escogido por la solución voraz ha sido asignado más adelante en O. Sea k la posición que cumple que
 V[i] != O[k]

 L: L[0] >= L[1] ...
 V: V[0]    V[1] ... | V[i]
     =       =          != 
 O: O[0]    O[1] ... | O[i] ... O[k] == V[k]
 
 Caso 1: V[i] = comprada -> se ha tenido que comprar el libro para intentar alcanzar la oferta del 3 X 2. Por lo que O[i] también es nueva.
 Caso 2: V[i] = L_r 
    Si O no utiliza L_r, el cambio es hacer O[i] = L[r]. O no puede empeorar. En otro caso habrá un O[k] = L[r].
 
 El coste es O(NlogN) siendo N el número de libros que se tienen disponibles para comprar.
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso() {

    int N;
    cin >> N;
    if (!cin)
        return false;

    vector<int> libros(N);
    for (auto &x : libros) 
        cin >> x;
    
    if (libros.size() <= 2) {
        cout << "0\n";
        return true;
    }
    sort(libros.begin(), libros.end(), greater<int>()); //O(NlogN)

    int cont = 0;
    int descuento = 0;
    for (int i = 0; i < libros.size(); i++) {
        if (cont == 2) {
            descuento += libros.at(i);
            cont = 0;
            i++;
        }
        cont++;
    }
    cout << descuento << "\n";
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
