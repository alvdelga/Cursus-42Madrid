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

int    ft_cases(va_list args, char *format, int i)
{
    int    c;

    c = 0;
    if (format[i] == 's')
        c += ft_putstr_fd(va_arg(args, char *), 1);
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
    va_list        args;
    int            i;
    int            lenght;

    i = 0;
    lenght = 0;
    va_start(args, format);
    if (!format)
        return (0);
    while (format[i])
    {
        if (format[i] == '%' && ft_is_in_set(format[i + 1], "sXdcxpiu%"))
        {
            lenght += ft_cases(args, (char *)format, ++i);
        }
        else
        {
            write(1, &format[i], 1);
            lenght++;
        }
        i++;
    }
    va_end(args);
    printf("%d", lenght);
    return (lenght);
}

int    main()
{
    char *array = "Hola Mundo";
    ft_printf("%s", array);
    printf("%s", array);
    return 0;
}