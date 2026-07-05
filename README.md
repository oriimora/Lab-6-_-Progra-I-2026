# Laboratorio: Punteros a funciones

**Ejercicio:** Ordenamiento de estructuras
**Estudiante** Oriana Mora López
**Carnet* B75079

## Descripción

El objetivo de este laboratorio era manejar un arreglo de estructuras `Persona` (con descripcion de `nombre`, `edad` y `estatura`) y ordenarlo de tres formas distintas usando la función `qsort`, cada una
con su propia función de comparación pasada como puntero a función.

## Solución

Se definió la estructura `Persona` con los tres campos solicitados. Luego se implementaron tres funciones de comparación: `int (*)(const void *, const void *)`.

- `comparar_por_nombre`: convierte los `void*` a `Persona*` y usa `strcmp` para comparar los nombres alfabéticamente.
- `comparar_por_edad`: convierte los punteros y resta las edades.
- `comparar_por_estatura`: como `estatura` es `double`, no se puede restar y castear a `int` directamente (se pierde precisión con diferencias pequeñas), así que se compara con `if/else` y se retorna `-1`, `0` o `1` manualmente.

En el `main` se creó un arreglo con 5 personas y se llamó a `qsort` tres veces, una por cada requerimiento, imprimiendo el arreglo después de cada ordenamiento para poder comparar los resultados.

## Resultados

**=== Arreglo original ===
  Carlos     | Edad: 25 | Estatura: 172.5 cm
  Ana        | Edad: 31 | Estatura: 160.2 cm
  Beto       | Edad: 19 | Estatura: 180.0 cm
  Diana      | Edad: 45 | Estatura: 165.8 cm
  Elena      | Edad: 22 | Estatura: 158.4 cm

=== Ordenado por nombre (alfabetico) ===
  Ana        | Edad: 31 | Estatura: 160.2 cm
  Beto       | Edad: 19 | Estatura: 180.0 cm
  Carlos     | Edad: 25 | Estatura: 172.5 cm
  Diana      | Edad: 45 | Estatura: 165.8 cm
  Elena      | Edad: 22 | Estatura: 158.4 cm

=== Ordenado por edad (menor a mayor) ===
  Beto       | Edad: 19 | Estatura: 180.0 cm
  Elena      | Edad: 22 | Estatura: 158.4 cm
  Carlos     | Edad: 25 | Estatura: 172.5 cm
  Ana        | Edad: 31 | Estatura: 160.2 cm
  Diana      | Edad: 45 | Estatura: 165.8 cm

=== Ordenado por estatura (menor a mayor) ===
  Elena      | Edad: 22 | Estatura: 158.4 cm
  Ana        | Edad: 31 | Estatura: 160.2 cm
  Diana      | Edad: 45 | Estatura: 165.8 cm
  Carlos     | Edad: 25 | Estatura: 172.5 cm
  Beto       | Edad: 19 | Estatura: 180.0 cm**