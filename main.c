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

int comparar_por_edad(const void *a, const void *b) {
    const Persona *p1 = (const Persona *)a;
    const Persona *p2 = (const Persona *)b;
    return p1->edad - p2->edad;
}

int comparar_por_estatura(const void *a, const void *b) {
    const Persona *p1 = (const Persona *)a;
    const Persona *p2 = (const Persona *)b;

    if (p1->estatura < p2->estatura) return -1;
    if (p1->estatura > p2->estatura) return 1;
    return 0;
}

void imprimir_personas(Persona personas[], int n) {
    for (int i = 0; i < n; i++) {
        printf("  %-10s | Edad: %2d | Estatura: %.1f cm\n",
               personas[i].nombre, personas[i].edad, personas[i].estatura);
    }
    printf("\n");
}

int main(void) {
    Persona personas[NUM_PERSONAS] = {
        {"Carlos", 25, 172.5},
        {"Ana",    31, 160.2},
        {"Beto",   19, 180.0},
        {"Diana",  45, 165.8},
        {"Elena",  22, 158.4}
    };

    printf("=== Arreglo original ===\n");
    imprimir_personas(personas, NUM_PERSONAS);

    qsort(personas, NUM_PERSONAS, sizeof(Persona), comparar_por_nombre);
    printf("=== Ordenado por nombre (alfabetico) ===\n");
    imprimir_personas(personas, NUM_PERSONAS);

    qsort(personas, NUM_PERSONAS, sizeof(Persona), comparar_por_edad);
    printf("=== Ordenado por edad (menor a mayor) ===\n");
    imprimir_personas(personas, NUM_PERSONAS);

    qsort(personas, NUM_PERSONAS, sizeof(Persona), comparar_por_estatura);
    printf("=== Ordenado por estatura (menor a mayor) ===\n");
    imprimir_personas(personas, NUM_PERSONAS);

    return 0;
}