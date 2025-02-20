/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:45:16 by alvdelga          #+#    #+#             */
/*   Updated: 2025/02/20 13:06:34 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	long	*numbers;
	int		i;
	t_stack	*a;
	t_stack	*b;

	i = 0;
	a = NULL;
	b = NULL;
	if (argc == 1 || argv[1][0] == '\0')
	{
		write(2, "[!] Error: missing arguments\n", 29);
		return (0);
	}
	numbers = initialize(argc, argv);
	if (!numbers)
		return (0);
	while (numbers[i] != LONG_MAX)
		fill_stack(&a, numbers[i++]);
	free(numbers);
	if (!(check_sort(&a)))
		sort(&a, &b);
	free_stack(&a);
	return (0);
}
// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   push_swap.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/02/01 13:45:16 by alvdelga          #+#    #+#             */
// /*   Updated: 2025/02/19 13:13:49 by alvdelga         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include <unistd.h>    // Para la función write()
// #include <stdlib.h>    // Para malloc() y free()
// #include <stdio.h>     // Para depuración (printf)
// #include "push_swap.h" // Incluye las funciones auxiliares y estructuras

// int	main(int argc, char *argv[])
// {
// 	long	*numbers; // Array donde se almacenarán los números pasados como argumentos
// 	int		i;
// 	t_stack	*a;       // Puntero a la pila A
// 	t_stack	*b;       // Puntero a la pila B

// 	i = 0;
// 	a = NULL;
// 	b = NULL;

// 	// ─────────────────────────────
// 	// 1. Verificación de argumentos
// 	// ─────────────────────────────
// 	if (argc == 1 || argv[1][0] == '\0') // Si no se pasan argumentos válidos
// 	{
// 		write(2, "[!] Error: missing arguments\n", 29);
// 		return (0); // Termina el programa con código 0
// 	}

// 	// ─────────────────────────────
// 	// 2. Procesamiento de la entrada
// 	// ─────────────────────────────
// 	// `initialize` convierte los argumentos en un array de números y valida errores.
// 	numbers = initialize(argc, argv);
// 	if (!numbers) // Si la conversión falló (entrada inválida), termina el programa.
// 		return (0);

// 	// ─────────────────────────────
// 	// 3. Construcción de la pila A
// 	// ─────────────────────────────
// 	// Se recorre `numbers` hasta encontrar `LONG_MAX`, agregando cada valor a la pila A.
// 	while (numbers[i] != LONG_MAX)
// 		fill_stack(&a, numbers[i++]);

// 	free(numbers); // Libera la memoria del array de números, ya que ahora están en la pila.

// 	// ─────────────────────────────
// 	// 4. Verificación del orden
// 	// ─────────────────────────────
// 	// Se verifica si la pila A ya está ordenada; si lo está, no es necesario hacer nada.
// 	if (!(check_sort(&a)))
// 		sort(&a, &b); // Si no está ordenada, se llama a `sort` para ordenarla.

// 	// ─────────────────────────────
// 	// 5. Liberación de memoria
// 	// ─────────────────────────────
// 	free_stack(&a); // Libera la memoria usada por la pila A.

// 	return (0); // Finaliza el programa correctamente.
// }

