/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 08:20:23 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/19 23:47:23 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>



// void suma(int num, ...) {
//     va_list args;       // 1️⃣ Declaramos la lista de argumentos
//     va_start(args, num); // 2️⃣ La inicializamos con el último argumento fijo

//     int total = 0;
//     for (int i = 0; i < num; i++) {
//         total += va_arg(args, int); // 3️⃣ Obtenemos cada argumento
//     }

//     va_end(args);       // 4️⃣ Cerramos la lista
//     printf("Suma total: %d\n", total);
// }

// int main() {
//     suma(2, 10, 20, 30);  // Llama a la función con 3 argumentos
//     return 0;
// }


//

#include <stdarg.h>
#include <stdio.h>

void concatenar(char *first, ...) {
    va_list args;
    va_start(args, first);

    char *str = first;  // Inicializamos con el primer argumento
    str = va_arg(args, char *);
    while (str != NULL) {  // 🔹 Seguimos mientras no encontremos NULL
        printf("%s ", str);
        str = va_arg(args, char *);
    // 🔹 Obtenemos la siguiente cadena
    }

    va_end(args);
    printf("\n");  // Nueva línea al final
}

int main() {
    concatenar("Hola", "mundo", "!", "una", "prueba", NULL);
    concatenar("Esto", "es", "una", "prueba", NULL);
    concatenar("Solo", "una", "frase", NULL);
    return 0;
}

//Código simplificado de cómo printf maneja va_list

#include <stdarg.h>
#include <unistd.h>

void my_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int i = 0;
    while (format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            i++;  // Avanzamos para ver el especificador
            if (format[i] == 'd')
            {
                int num = va_arg(args, int);
                char buffer[12];
                int len = sprintf(buffer, "%d", num);  // Convertimos a string
                write(1, buffer, len);
            }
            else if (format[i] == 's')
            {
                char *str = va_arg(args, char *);
                while (*str)
                    write(1, str++, 1);
            }
        }
        else
        {
            write(1, &format[i], 1);
        }
        i++;
    }

    va_end(args);
}

// int main()
// {
//     my_printf("Hola %s, tienes %d años\n", "Juan", -25);
//     return 0;
// }
