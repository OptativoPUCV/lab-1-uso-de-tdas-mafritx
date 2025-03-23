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


List* crea_lista() {

    List* L = NULL;      // Puntero al inicio de la lista
    List* current = NULL; // Puntero para recorrer la lista

    // Agregar punteros a elementos del 1 al 10
    for (int i = 1; i <= 10; i++) {
        // Reservar memoria para el entero
        int* num = (int*)malloc(sizeof(int));
        if (num == NULL) {
            // Manejo de error en caso de que malloc falle
            // (esto es opcional, dependiendo de los requisitos)
            return NULL;
        }
        *num = i; // Asignar el valor correspondiente

        // Crear un nuevo nodo directamente
        List* temp = (List*)malloc(sizeof(List));
        if (temp == NULL) {
            // Manejo de error en caso de que malloc falle
            free(num); // Liberar la memoria reservada para el entero
            return NULL;
        }
        temp->data = num;
        temp->next = NULL;

        // Agregar el nuevo nodo a la lista
        if (L == NULL) {
            // Si la lista está vacía, el nuevo nodo es el primero
            L = temp;
        } else {
            // Si la lista no está vacía, agregar el nuevo nodo al final
            current->next = temp;
        }
        current = temp; // Mover el puntero al último nodo
    }

   return L;
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

