/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanmetol <sanmetol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:53:09 by sanmetol          #+#    #+#             */
/*   Updated: 2023/10/18 19:52:36 by sanmetol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_va_arg(char s, va_list args_l, int *count)
{
	unsigned int	u;
	char			*u_str;

	if (s == 'c')
		ft_putchar(va_arg(args_l, int), count);
	else if (s == 's')
		ft_putstr(va_arg(args_l, char *), count);
	else if (s == 'p')
		ptrhexa(va_arg(args_l, unsigned long int), count);
	else if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(args_l, int), count);
	else if (s == 'u')
	{
		u = va_arg(args_l, unsigned int);
		u_str = ft_itoa_u(u);
		ft_putstr(u_str, count);
		free(u_str);
	}
	else if (s == 'x' || s == 'X')
		ft_puthexa(va_arg(args_l, unsigned int), s, count);
	else if (s == '%')
		ft_putchar('%', count);
}

int	ft_printf(char const *s, ...)
{
	va_list	args_l;
	int		i;
	int		count;

	count = 0;
	va_start(args_l, s);
	i = 0;
	while (s[i])
	{
		if (s[i] != '%')
			ft_putchar(s[i], &count);
		else
		{
			i++;
			ft_va_arg(s[i], args_l, &count);
		}
		if (count == -1)
			return (-1);
		i++;
	}
	va_end(args_l);
	return (count);
}

 int	main(void)
{
	int	i;
	int	j = NULL;
	
	i = printf("%p", "Hola esto es una prueba");
	//j = ft_printf("%p", "");
	printf("\n\nNor: %d\nMio: %d", i, j);
}

/* int	main(void)
{
	int				n = 42;
	unsigned int	u = -100;
	char			c = '0';
	char 			*s = "paola";
	void			*p = &n;
	int				output;
	int				outputZERO;

	outputZERO = ft_printf("\n%c, %s, %p, %d, %i, %u,"
		" %x, %X, %%", c, s, p, n, n, u, n, n);
	ft_printf("%c", '1');
	output     =    printf("\n%c, %s, %p, %d, %i, %u,"
		" %x, %X, %%", c, s, p, n, n, u, n, n);
	printf("\n%d\n%d\n", outputZERO, output);
} */
/* int	main(void)
{
	ft_printf("%c", '0');
	ft_printf(" %c ", '0');
	ft_printf(" %c", '0' - 256);
	ft_printf("%c ", '0' + 256);
	ft_printf(" %c %c %c ", '0', 0, '1');
	ft_printf(" %c %c %c ", ' ', ' ', ' ');
	ft_printf(" %c %c %c ", '1', '2', '3');
	ft_printf(" %c %c %c ", '2', '1', 0);
	ft_printf(" %c %c %c ", 0, '1', '2');

	write(1, "\n", 1);

	printf("%c", '0');
	printf(" %c ", '0');
	printf(" %c", '0' - 256);
	printf("%c ", '0' + 256);
	printf(" %c %c %c ", '0', 0, '1');
	printf(" %c %c %c ", ' ', ' ', ' ');
	printf(" %c %c %c ", '1', '2', '3');
	printf(" %c %c %c ", '2', '1', 0);
	printf(" %c %c %c ", 0, '1', '2');
} */

/* int	main(void)
{
	ft_printf("hola\001\002\007\v\010\f\r\nhola");
	printf("hola\001\002\007\v\010\f\r\nhola");
} */

//gcc ft_printf.c utilities.c && ./a.out
//gcc ft_printf.c utilities.c ft_itoa_u.c && ./a.out
