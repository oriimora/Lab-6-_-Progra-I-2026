#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_PERSONAS 5

typedef struct {
    char nombre[50];
    int edad;
    double estatura;
} Persona;

int comparar_por_nombre(const void *a, const void *b) {
    const Persona *p1 = (const Persona *)a;
    const Persona *p2 = (const Persona *)b;
    return strcmp(p1->nombre, p2->nombre);
}