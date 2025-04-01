# 📄 get_next_line

**get_next_line** es un proyecto del campus **42 Madrid** cuyo objetivo es programar una función que devuelva una línea leída desde un file descriptor. Es un ejercicio fundamental para entender el manejo de memoria, archivos y el uso de **variables estáticas** en C.

---

## 🎯 Objetivo del proyecto

Implementar la función:

```c
char *get_next_line(int fd);
```

- Lee y devuelve una línea completa desde el file descriptor `fd`.
- Mantiene el estado entre llamadas mediante una variable estática.
- Devuelve `NULL` cuando se alcanza el final del archivo o hay error.
- Soporta lectura de múltiples líneas y distintos tamaños de buffer.

---

## 📚 Lo que aprenderás

- Cómo funciona `read()` y la lectura de archivos en bajo nivel
- Manejo eficiente de buffers y strings en C
- Uso correcto de memoria dinámica y liberación (`malloc`, `free`)
- Variables estáticas y persistencia entre llamadas
- Implementación segura y eficiente sin `lseek()` ni variables globales

---

## 🧠 Reglas clave del proyecto

- Prohibido usar `lseek()`, variables globales o `libft`
- El programa debe compilar con:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c
```

- Tu implementación debe funcionar correctamente con cualquier valor razonable de `BUFFER_SIZE`, incluyendo `1`, `9999` o incluso `10000000`.

---

## 📁 Estructura del proyecto

```
GNL/
├── get_next_line.c              # Lógica principal
├── get_next_line.h              # Prototipos
├── get_next_line_utils.c        # Funciones auxiliares
├── get_next_line_bonus.c        # Bonus: múltiples fd
├── get_next_line_bonus.h
├── get_next_line_utils_bonus.c
└── files/                       # Archivos de prueba
```

---

## 🧪 Cómo compilar y probar

### Parte obligatoria:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
./gnl
```

### Parte bonus:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus
```

---

## 🧩 Bonus implementados

- Soporte para múltiples file descriptors (usa una única variable estática con lógica adaptable)
- Gestión independiente de la lectura de cada `fd`

---

## 💡 Curiosidades

- Implementar esta función es clave para proyectos posteriores como `pipex`, `minishell`, etc.
- El uso de una **única variable estática** obliga a una estructura de datos bien diseñada.
- Funciona incluso con lectura desde `stdin` o archivos sin saltos de línea finales.


---

## 📌 Autor

👨‍💻 **alvdelga** - Estudiante de 42 Madrid