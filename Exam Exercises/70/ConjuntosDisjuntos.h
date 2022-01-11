//
//  ConjuntosDisjuntos.h
//
//  ImplementaciÃ³n de estructuras de particiÃ³n o conjuntos disjuntos
//  con uniÃ³n por tamaÃ±o y compresiÃ³n de caminos
//
//  Facultad de InformÃ¡tica
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2020  Alberto Verdejo
//

#ifndef CONJUNTOSDISJUNTOS_H_
#define CONJUNTOSDISJUNTOS_H_

#include <vector>
#include <iostream>

class ConjuntosDisjuntos {
protected:
   int ncjtos;  // nÃºmero de conjuntos disjuntos
   mutable std::vector<int> p;  // enlace al padre
   std::vector<int> tam;  // tamaÃ±o de los Ã¡rboles
public:
   
   // crea una estructura de particiÃ³n con los elementos 0..N-1,
   // cada uno en un conjunto, particiÃ³n unitaria
   ConjuntosDisjuntos(int N) : ncjtos(N), p(N), tam(N,1) {
      for (int i = 0; i < N; ++i)
      p[i] = i;
   }
   
   //  devuelve el representante del conjunto que contiene a a
   int buscar(int a) const {
      if (p.at(a) == a) // es una raÃ­z
         return a;
      else
         return p[a] = buscar(p[a]);
   }
   
   // unir los conjuntos que contengan a a y b
   void unir(int a, int b) {
      int i = buscar(a);
      int j = buscar(b);
      if (i == j) return;
      if (tam[i] > tam[j]) { // i es la raÃ­z del Ã¡rbol mÃ¡s grande
         tam[i] += tam[j]; p[j] = i;
      } else {
         tam[j] += tam[i]; p[i] = j;
      }
      --ncjtos;
   }

   // devuelve si a y b estÃ¡n en el mismo conjunto
   bool unidos(int a, int b) const {
      return buscar(a) == buscar(b);
   }
   
   // devuelve el nÃºmero de elementos en el conjunto de a
   int cardinal(int a) const {
      return tam[buscar(a)];
   }
   
   // devuelve el nÃºmero de conjuntos disjuntos
   int num_cjtos() const { return ncjtos; }

};

#endif