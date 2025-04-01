# 📡 Minitalk

**Minitalk** es un proyecto del campus **42 Madrid** que consiste en crear un sistema de comunicación entre procesos usando exclusivamente señales UNIX (`SIGUSR1` y `SIGUSR2`). Simula una transferencia de datos entre un cliente y un servidor sin utilizar sockets ni pipes.

---

## 🎯 Objetivo del proyecto

- Crear un **servidor** que pueda recibir mensajes desde múltiples clientes.
- Implementar un **cliente** que envíe mensajes al servidor usando solo señales.
- Cada carácter es codificado bit a bit con señales, transmitiendo así toda una string.
- El servidor muestra por pantalla la string recibida.

---

## 📁 Estructura del proyecto

```
Minitalk/
├── client/                   # Código fuente del cliente
├── server/                   # Código fuente del servidor
├── src/                      # Archivos principales
├── bonus_src/                # Implementación con extras
├── ft_printf/                # Implementación personalizada de printf
├── libft/                    # Librería de funciones básicas
├── minitalk.h                # Header principal
├── minitalk_bonus.h
└── Makefile
```
---

### Parte obligatoria:

```bash
make
./server
# Muestra el PID
./client <PID> "Mensaje a enviar"
```

### Parte bonus:

```bash
make bonus
./server_bonus
./client_bonus <PID> "Mensaje con confirmaciones"
```

---

## 🧠 Funciones autorizadas

- `write`, `malloc`, `free`, `exit`
- `signal`, `sigaction`, `kill`, `pause`, `usleep`, `getpid`
- Tu propia versión de `ft_printf`

---

## 💡 Bonus implementados

- El servidor envía confirmaciones de recepción al cliente (`ACK` por señal).
- Soporte para múltiples clientes conectándose consecutivamente.
- Mejora en la gestión de señales simultáneas.

---

## 📚 Lo que aprenderás

- Señales UNIX: uso de `sigaction`, `kill`, `pause`, etc.
- Comunicación asincrónica entre procesos
- Codificación binaria de caracteres y sincronización
- Manejo de procesos y PID
- Control de errores robusto y sin fugas de memoria

---

## 📌 Autor

👨‍💻 **alvdelga** - Estudiante de 42 Madrid