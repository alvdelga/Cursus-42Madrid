# 🖨️ ft_printf

**ft_printf** es un proyecto del campus **42 Madrid** cuyo objetivo es reimplementar la conocida función `printf()` de la libc, permitiendo imprimir múltiples tipos de datos utilizando una cantidad variable de argumentos.

---

## 🎯 Objetivo del proyecto

Crear tu propia versión de `printf()` bajo las siguientes condiciones:

- Sin utilizar la implementación real de `printf()`.
- Con soporte para las conversiones: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`.
- Sin gestión de buffer como hace la versión original.
- Tu función debe llamarse `ft_printf()` y seguir este prototipo:

```c
int ft_printf(const char *format, ...);
```

---

## 📚 Lo que aprenderás

- Manejo de argumentos variádicos con `stdarg.h` (`va_start`, `va_arg`, etc.)
- Modularización del código y diseño limpio
- Conversión y formateo de diferentes tipos de datos
- Lógica de impresión personalizada (incluyendo punteros y hexadecimales)
- Creación de librerías (`ar rc libftprintf.a`)

---

## 📁 Estructura del proyecto

```
Printf/
├── ft_itoa_u.c        # Conversión de unsigned int a string
├── ft_printf.c        # Implementación principal
├── ft_printf.h        # Prototipos y headers
├── Makefile
└── utilities.c        # Funciones auxiliares
```

---

## 🧪 Cómo compilar y usar

```bash
make
./a.out
```

---

## ✅ Conversión soportadas

| Conversión | Descripción                          |
|------------|--------------------------------------|
| `%c`       | Carácter                             |
| `%s`       | Cadena de texto                      |
| `%p`       | Puntero en hexadecimal               |
| `%d` / `%i`| Entero decimal con signo             |
| `%u`       | Entero decimal sin signo             |
| `%x`       | Hexadecimal en minúsculas            |
| `%X`       | Hexadecimal en mayúsculas            |
| `%%`       | Imprime el carácter `%`              |

---

## 📌 Autor

👨‍💻 **alvdelga** - Estudiante de 42 Madrid