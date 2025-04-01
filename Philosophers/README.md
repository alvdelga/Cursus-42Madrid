# 🧠 Philosophers


![Philosophers Banner](./cursus-banner.png)

## 📚 Resumen

Este proyecto simula el clásico problema de los filósofos comensales usando hilos (threads) y sincronización mediante **mutex** en C. A través de este ejercicio aprenderás los fundamentos de la programación concurrente, sincronización, y cómo evitar condiciones de carrera y bloqueos.

---

## ⚙️ Compilación

```bash
make
```

También puedes usar las reglas:

- `make all`
- `make clean`
- `make fclean`
- `make re`
- `make test` → ejecuta una serie de simulaciones automáticas para validar el comportamiento
- `make delay` → ejecuta un script opcional de pruebas de latencia

---

## 🧪 Uso

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Ejemplo:

```bash
./philo 5 800 200 200
```

Esto crea una simulación con:

- 5 filósofos
- 800ms antes de morir si no comen
- 200ms comiendo
- 200ms durmiendo

---

## 📦 Estructura del proyecto

```
philo/
├── Makefile
├── philo.h
├── main.c
├── init.c
├── threads.c
├── philo_observer.c
├── actions.c
├── utils.c
```

---

## 🧵 Parte obligatoria

- Cada filósofo es un hilo.
- Cada tenedor es un mutex.
- No se usan variables globales.
- Simulación termina cuando un filósofo muere o todos comen las veces necesarias (si se pasa el argumento opcional).

---

## 🚀 Bonus (philo_bonus)

- Cada filósofo es un proceso.
- Los tenedores están representados por semáforos.
- Mejora de control y gestión de procesos.

---

## 📸 Estado del proyecto

- ✅ Parte obligatoria implementada
- ✅ Logs de acción con timestamps
- ✅ Prevención de condiciones de carrera
- ✅ Simulación estable y sin fugas de memoria
- ✅ Bonus implementado (procesos + semáforos)

---

## 📄 Licencia

MIT © [alvdelga](https://github.com/alvdelga)