# 🧮 push_swap

**push_swap** es un proyecto del campus 42 Madrid cuyo objetivo es ordenar una lista de números enteros con el menor número posible de operaciones. Para ello, el proyecto utiliza dos pilas (A y B) y un conjunto limitado de instrucciones.

---

## 🎯 Objetivo del proyecto

Recibir una secuencia de números por argumentos y ordenar la pila A utilizando solo las siguientes instrucciones:

- `sa`, `sb`, `ss`: intercambiar los dos primeros elementos
- `pa`, `pb`: mover el primer elemento de una pila a otra
- `ra`, `rb`, `rr`: rotar hacia arriba
- `rra`, `rrb`, `rrr`: rotar hacia abajo

El reto es **ordenar los números con la menor cantidad de instrucciones posible**, lo que implica pensar algoritmos eficientes.

---

## 📚 Qué se aprende en este proyecto

- Manipulación de listas enlazadas en C
- Creación de algoritmos de ordenación adaptados a restricciones
- Asignación y liberación dinámica de memoria
- Gestión de errores, validación de argumentos y edge cases
- Optimización de movimientos con métricas como coste y objetivo
- Análisis de complejidad de algoritmos en tiempo real

---

## 📁 Estructura del proyecto

```
Push_swap/
├── mandatory/
│   ├── push_swap.c           # Función principal
│   ├── push_swap.h           # Definiciones y estructuras
│   ├── *.c                   # Módulos organizados por lógica
├── Makefile
└── README.md
```

---

## 🚀 Ejemplo de uso

```bash
$ ./push_swap 2 3 7 1
pb
rra
ra
pa
rra
```

Cada instrucción representa una operación que el programa realiza sobre las pilas para llegar al estado ordenado.

---

## 🧪 Cómo compilar y probar

```bash
make
./push_swap 3 2 1
```

También puedes usar scripts de test incluidos en el Makefile:

```bash
make test5
make test100
```

Esto genera combinaciones aleatorias y las pasa por `checker_linux` para verificar su validez.

---

## 🧠 Extras implementados

- Cálculo de coste para movimientos
- Elección del nodo más “barato” para mover
- Algoritmo de asignación de objetivos entre pilas
- Optimización conjunta de movimientos (`rotate_two`, `rr`, `rrr`)

---

## 📌 Autor

👨‍💻 **alvdelga** - Estudiante de 42 Madrid