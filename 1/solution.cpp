/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez nieto
 * 
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <cassert>
#include <sstream>
using namespace std;

#include "BinTree.h"

/*@ <answer>
  
 Un árbol AVL por definición es un arbol binario de busqueda equilibrado.
 Para comprobar que el árbol que se nos plantea es AVL se irá viendo si es de busqueda y 
 si se encuentra equilibrado. Por ello:
 - Para saber si es de busqueda se localizand el maximo y el minimo del arbol correspondiente
 y se compara con el nodo raiz. Si alguna de estas variables no cumple con el requisito de 
 ser mayor o menor respectivamente no se tratará de un arbol binario de búsqueda y por tanto,
 no será un árbol AVL
 - Para conocer si el árbol se encuentra equilibrado se utilizará la variable altura de 
 cada respectivo árbol obteniendo su diferencia y comprobando que esta no es mayor que 1.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

BinTree<int> leerArbol() {
   char c;
   cin >> c;
   if (c == '.') 
      return BinTree<int>();
   else {
      BinTree<int> left = leerArbol();
      int elem;
      cin >> elem;
      BinTree<int> right = leerArbol();
      cin >> c;
      BinTree<int> result(left, elem, right);
      return result;
   }
}

void compruebaAVL(BinTree<int> const& arbol, bool& esAVL, int& altura, int minimo, int maximo) {
  if (!arbol.empty()) {
    altura++;
    int alturaActual = altura;

    if (arbol.root() <= minimo) 
      esAVL = false;
    if (arbol.root() >= maximo)
      esAVL = false;
    
    compruebaAVL(arbol.left(), esAVL, altura, minimo, arbol.root());
    int alturaIz = altura;
    altura = alturaActual;

    compruebaAVL(arbol.right(), esAVL, altura, arbol.root(), maximo);
    int alturaDer = altura;

    if (abs(alturaIz - alturaDer) > 1)
      esAVL = false;
    
    altura = max(alturaIz, alturaDer);
  }
}

void resuelveCaso() {
   
   BinTree<int> arbol = leerArbol();
   bool AVL = true;
   int altura = 0, minimo = -1, maximo = numeric_limits<int>::max();
   
   compruebaAVL(arbol, AVL, altura, minimo, maximo);

   if (AVL) cout << "SI" << endl;
   else cout << "NO" << endl;
}

//@ </answer>

int main() {
    
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   std::cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
      resuelveCaso();
   
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
