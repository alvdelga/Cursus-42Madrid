#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int    ft_putstr_fd(char *s, int fd)
{
    int    i;

    i = 0;
    if (s == NULL)
    {
        write(fd, "(null)", 6);
        return (6);
    }
    while (s[i] != '\0')
    {
        write(fd, &s[i], 1);
        i++;
    }
    return (i);
}

static int	hexa_pointer(char *base, unsigned long long n, int c)
{
	unsigned long long b;

	b = 16;
	if (n >= b)
	{
		c = hexa_pointer(base, n / b, c);
		write (1, &base[n % b], 1);
		c++;
	}
	else if (n < b)
	{
		write (1, &base[n], 1);
		c++;
	}
	return (c);
}

int	ft_memdir(void *p)
{
	unsigned long long	pointer;
	int					i;

	if (p == 0)
    return (ft_putstr_fd("(nil)", 1));

	i = 0;
	pointer = (unsigned long long)p;
	write(1, "0x", 2);
	i = hexa_pointer("0123456789abcdef", pointer, i);
	i += 2;
	return (i);
}

int    ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
    return (1);
}

int    ft_putnbr_fd(int n, int fd, int i)
{
    char    c;

    if (n == -2147483648)
    {
        write(fd, "-2147483648", 11);
        return (11);
    }
    if (n < 0)
    {
        write(fd, "-", 1);
        n = -n;
        i++;
    }
    if (n > 9)
    {
        i = ft_putnbr_fd(n / 10, 1, i);
    }
    c = n % 10 + '0';
    write(fd, &c, 1);
    i++;
    return (i);
}

int    ft_cases(va_list arguments, char *format, int i)
{
    int    c;

    c = 0;
    if (format[i] == 's')
        c += ft_putstr_fd(va_arg(arguments, char *), 1);
	
	else if (format[i] == 'p')
		c += ft_memdir(va_arg(arguments, void *));
    else if (format[i] == 'i' || format[i] == 'd')
		c += ft_putnbr_fd((int)va_arg(arguments, int), 1, 0);

    return (c);
}

int    ft_putnbr_base(unsigned int nbr, char *base)
{
    int    i;

    i = 0;
    if (nbr >= 16)
    {
        i += ft_putnbr_base(nbr / 16, base);
        i += ft_putnbr_base(nbr % 16, base);
    }
    else
    {
        ft_putchar_fd(base[nbr], 1);
        i++;
    }
    return (i);
}

int    ft_is_in_set(char c, char const *set)
{
    int    i;

    i = 0;
    while (set[i] != '\0')
    {
        if (set[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int    ft_printf(const char *format, ...)
{
    va_list        arguments;
    int            i;
    int            lenght;

    i = 0;
    lenght = 0;
    va_start(arguments, format);
    if (!format)
        return (0);
    while (format[i])
    {
        if (format[i] == '%' && ft_is_in_set(format[i + 1], "sXdcxpiu%"))
        {
            lenght += ft_cases(arguments, (char *)format, ++i);
        }
        else
        {
            write(1, &format[i], 1);
            lenght++;
        }
        i++;
    }
	//printf("%d\n", lenght);
    va_end(arguments);
    return (lenght);
}
/*int main()
{
    char *array = "Hola";
    int c = ft_printf("%p\n", array);
	int d = ft_printf("%p\n", array);

    printf("Total characters printed: %d\n", c);
    printf("Total characters printed: %d\n", d);
    return 0;
}*/

int    main()
{
    char *array = "hola";
    int i = ft_printf("%p%%%%pp%%%%\n", array);
       int a = printf("%p%%%%pp%%%%\n", array);

	// ft_printf("%d\n", i);
	// ft_printf("%d\n", a);
	// printf("%d\n", i);
	// printf("%d\n", a);


    return 0;
}

