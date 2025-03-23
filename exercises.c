#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/
/*
typedef struct List {
   int** ele;
   int cap;
   int size;
} List;
*/
List* create_list() {
   List* L = (List*)malloc(sizeof(List));
   L->ele = (int**)malloc(10 * sizeof(int*));
   L->cap=10;
   L->size=0;
   return L;
}

void agrega_ele(List* L, int* ele) {
   if(L->size == L->cap){
      L->cap *= 2;
      L->ele = (int**)realloc(L->ele, L->cap * sizeof(int*));
   }
   L->ele[L->size]=ele;

   L->size++;
}

List* crea_lista() {
   List* L = create_list();
   for (int i = 1; i <= 10; i++) {
      int* ele = (int*)malloc(sizeof(int));
      *ele = i;
      agrega_ele(L, ele);
   }
   
   return L;
}

void free_lista(List* L) {
   for (int i = 0; i < L->size ; i++){
      free(L->ele[i]);
   }
   free(L->ele);
   free(L);
}


int main() {
   List* L = crea_lista();
   for (int i = 0 ; i <- L->size; i++) {
      printf("%d", *L->ele[i]);
      
   }
   free_lista(L);
   return 0;
}
/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
   return 0;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem){

}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
   return 0;
}

