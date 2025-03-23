#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

#include "exercises.h"

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
   List* L = create_list();

   for (int i = 1; i <= 10; i++) {
      int* element = (int*)malloc(sizeof(int));
      if (element == NULL) {
         break; // Handle memory allocation failure
      }
      *element = i;
      pushBack(L, element); // Add the element to the list
   }

   return L;
}
/*
List* crea_lista() {
   List* L = create_list();
   
   for (int i = 1; i <= 10; i++) {

      if (L->size >= 100) {
         break;
      }
      
      int* element = (int*)malloc(sizeof(int));
      if (element == NULL) {
         break;
      }
      *element = i;

        
      L->data[L->size] = (void*)element;
      L->size++;
   }
   for (int i = 0; i < L->size; i++) {
      int* element = (int*)L->data[i];
      printf("%d ", *element);
   }
   printf("\n");

   return L;
}
*/

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
/*
int sumaLista(List *L) {
   int suma = 0;

   for (int i = 0; i < L->size; i++) {
      int* elemento = (int*)L->data[i];
      suma += *elemento;
   }
   return suma;
}
*/

int sumaLista(List *L) {
   int suma = 0;
   int *dato = (int*)first(L);

   while (dato != NULL) {
      suma += *dato;
      dato = (int*)next(L);
   }

   return suma;
}
/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/
/*
void eliminaElementos(List*L, int elem){

}
*/

void eliminaElementos(List* L, int elem) {
   int *dato = (int*)first(L);

   while (dato != NULL) {
      if (*dato == elem) {
         popCurrent(L); // Remove the current element
      } else {
         dato = (int*)next(L);
      }
   }
}
/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/
/*
void copia_pila(Stack* P1, Stack* P2) {
}
*/
void copia_pila(Stack* P1, Stack* P2) {
   Stack* aux = create_stack();

   // First, reverse P1 into aux
   while (!is_empty(P1)) {
      void* dato = pop(P1);
      push(aux, dato);
   }

   // Then, reverse aux into P2 and restore P1
   while (!is_empty(aux)) {
      void* dato = pop(aux);
      push(P1, dato);
      push(P2, dato);
   }
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/
/*
int parentesisBalanceados(char *cadena) {
   return 0;
}
*/
int parentesisBalanceados(char *cadena) {
   Stack* P = create_stack();

   for (int i = 0; cadena[i] != '\0'; i++) {
      if (cadena[i] == '(' || cadena[i] == '[' || cadena[i] == '{') {
         push(P, &cadena[i]);
      } else if (cadena[i] == ')' || cadena[i] == ']' || cadena[i] == '}') {
         if (is_empty(P)) {
            return 0; // Unbalanced
         }
         char* top_char = (char*)pop(P);
         if ((cadena[i] == ')' && *top_char != '(') ||
             (cadena[i] == ']' && *top_char != '[') ||
             (cadena[i] == '}' && *top_char != '{')) {
            return 0; // Unbalanced
         }
      }
   }

   return is_empty(P); // Balanced if stack is empty
}