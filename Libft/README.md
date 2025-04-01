
# 📚 Libft - Tu primera librería en C

**Libft** es uno de los primeros y más fundamentales proyectos del campus 42. Consiste en desarrollar desde cero una librería en C que implemente funciones básicas de manipulación de memoria, cadenas, listas, y más. Esta librería será la base para muchos proyectos futuros.

---

## ✨ ¿Qué se aprende?

- Cómo funcionan las funciones estándar de la libc por dentro.
- Creación y manipulación de strings, memoria, listas y caracteres.
- Gestión manual de memoria con `malloc`, `free`, etc.
- Modularidad, Makefiles, compilación y buenas prácticas.
- Uso de punteros, estructuras y programación defensiva en C.

---

## 📁 Estructura del proyecto

```
Libft/
├── ft_*.c               # Implementación de funciones estándar y adicionales
├── ft_*bonus.c          # Funciones de manejo de listas enlazadas
├── libft.h              # Header con todas las declaraciones
├── Makefile             # Para compilar libft.a
└── libft.a              # Archivo de librería generado
```

---

## 🔧 Funciones implementadas

### ✅ Funciones de la libc

- `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- `ft_strlen`, `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`
- `ft_strlcpy`, `ft_strlcat`, `ft_toupper`, `ft_tolower`
- `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_memchr`, `ft_memcmp`
- `ft_strnstr`, `ft_atoi`, `ft_calloc`, `ft_strdup`

### 🔄 Funciones adicionales

- `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`
- `ft_strmapi`, `ft_striteri`
- `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

### 💡 Bonus: manejo de listas

- `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`
- `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

---

## ⚙️ Compilación

Para compilar la librería:

```bash
make        # Compila la parte obligatoria
make bonus  # Añade la parte bonus (listas)
```

Esto generará el archivo `libft.a` que podrás usar en tus futuros proyectos.

---

## 📌 Autor

👨‍💻 alvdelga - Estudiante de 42 Madrid
