# 🧪 Grademe - 42 Exam Emulator

**Grademe** es una herramienta de código abierto para practicar exámenes de 42 en local, con corrección automática, generación aleatoria de ejercicios y detección de bucles infinitos. Ideal para entrenar antes del examen real.

---

## 🚀 Características

- Compatible con **ExamRank02 a 06** y **PiscineExam**
- Corrección automática sin conexión
- Ejercicios seleccionados aleatoriamente
- Corrección instantánea para usuarios VIP
- Simulación realista del entorno de examen de 42
- Detección de bucles infinitos en algunos niveles
- Interfaz y trazabilidad similares al examen real

![Ejemplo de uso](https://user-images.githubusercontent.com/55356071/188669215-6681228d-e6b5-4229-b177-45d2699e29ae.png)

---

## 🛠 Instalación rápida

```bash
bash -c "$(curl https://grademe.fr)"
```

> Asegúrate de tener `bash`, `make`, y un entorno compatible (Linux/Mac).

---

## 🧑‍💻 Cómo usar

```bash
make          # Lanza el emulador y selecciona nivel
make grade    # Corrige el ejercicio actual
make re       # Reinicia y vuelve a lanzar
make clean    # Borra binarios temporales
make help     # Muestra ayuda
```

---

## 🧙 Trucos y comandos especiales

```text
remove_grade_time  -> Elimina tiempo de espera entre pushes
force_success      -> Marca un ejercicio como aprobado
new_ex             -> Genera nuevo ejercicio del mismo nivel
gradenow (VIP)     -> Corrige instantáneamente sin esperar
```

---

## 🎓 Ideal para estudiantes de 42

Grademe no es oficial de 42, pero te ayudará a:
- Mejorar tus habilidades en C y debugging
- Simular el entorno de examen
- Prepararte psicológicamente para el día del examen

---

## 🙏 Créditos y agradecimientos

Proyecto creado por la comunidad 42. Agradecimientos a [JCluzet](https://github.com/JCluzet), [pandaero](https://github.com/pandaero) y demás contribuidores.

Puedes contribuir leyendo el [CONTRIBUTING.md](CONTRIBUTING.md).

---

## ⚠️ Aviso Legal

Este proyecto **NO** es oficial ni representa a la escuela 42. Es solo un recurso comunitario gratuito para practicar.

---

## 📜 Licencia

Distribuido bajo licencia MIT. Lee el archivo [LICENSE](LICENSE) para más detalles.