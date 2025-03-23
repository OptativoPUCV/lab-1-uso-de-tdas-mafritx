#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

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
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

// Exercise 1: Create a list with numbers 1-10
List* crea_lista() {
    List* L = create_list();
    for(int i = 1; i <= 10; i++) {
        int* num = (int*)malloc(sizeof(int));
        *num = i;
        pushBack(L, num);
    }
    return L;
}

// Exercise 2: Sum all elements in a list
int sumaLista(List* L) {
    int suma = 0;
    int* dato = (int*)first(L);
    while(dato != NULL) {
        suma += *dato;
        dato = (int*)next(L);
    }
    return suma;
}

// Exercise 3: Remove all occurrences of elem from list
void eliminaElementos(List* L, int elem) {
    int* dato = (int*)first(L);
    while(dato != NULL) {
        if(*dato == elem) {
            popCurrent(L);
        }
        dato = (int*)next(L);
    }
}

// Exercise 4: Copy stack to another stack
void copia_pila(Stack* P1, Stack* P2) {
    Stack* temp = create_stack();
    void* dato;

    // Empty P1 into temp
    while((dato = pop(P1)) != NULL) {
        push(temp, dato);
    }

    // Copy from temp back to P1 and P2
    while((dato = pop(temp)) != NULL) {
        push(P1, dato);
        push(P2, dato);
    }
}

// Exercise 5: Check if parentheses are balanced
int parentesisBalanceados(char* cadena) {
    Stack* P = create_stack();

    for(int i = 0; cadena[i] != '\0'; i++) {
        if(cadena[i] == '(' || cadena[i] == '[' || cadena[i] == '{') {
            char* c = malloc(sizeof(char));
            *c = cadena[i];
            push(P, c);
        } else if(cadena[i] == ')' || cadena[i] == ']' || cadena[i] == '}') {
            char* top = (char*)pop(P);
            if(top == NULL) return 0;

            if((cadena[i] == ')' && *top != '(') ||
               (cadena[i] == ']' && *top != '[') ||
               (cadena[i] == '}' && *top != '{')) {
                return 0;
            }
            free(top);
        }
    }

    return pop(P) == NULL; // True if stack is empty
}