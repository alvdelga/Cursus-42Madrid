#include "../ft_printf/ft_printf.h"


// int	main()
// {
// 	int i = ft_printf("%%%%hola%%%%");
// 	printf("\n");
// 	int a = printf("%%%%hola%%%%");
// 	printf("\n");
// 	printf("%d\n", i);
// 	printf("%d\n", a);
// 	return 0;
// }

// int	main()
// {
// 	char *stream = "hola";
// 	int i = ft_printf(" ");
//     ft_printf("\n");
// 	int a = printf(" ");
//     printf("\n");
//     printf("%d\n", i);
//     printf("%d\n", a);
// 	return 0;
// }
// int	main()
// {
//     void *ptr = (void *)42;
//     int i = ft_printf(" %p ", ptr);
//     int a = printf(" %p ", ptr);

//     ft_printf("%d\n", i);
//     printf("%d\n", a);
//     ft_printf("%d\n", i);
//     printf("%d\n", a);

//     void *add = (void *)42;
//     void *ptr2 = (void *)NULL;
//     ft_printf(" %p %p ", add, ptr2);
//     printf(" %p %p ", add, ptr2);

// 	return 0;
// }

<<<<<<< HEAD
int    main()
{
    char *a = "hola";
    ft_printf("%%%%%%%%%%%%%1%", a, a, a);
    printf("\n");
       printf("%%%%%%%%%%%%%1%", a, a, a);
    return 0;
}
=======
// int    main()
// {
//     char *a = "hola";
//     ft_printf("%%%%%%%%%%%%%%\n", a, a, a);
//        printf("%%%%%%%%%%%%%%\n", a, a, a);
//     return 0;
// }


// int main()
// {
//     char *array = "hola";
//     int i = ft_printf("SSSSSS%sSSSS%", array, array);
//        int a = printf("SSSSSS%sSSSS%", array, array);
// 	ft_printf("%d\n", i);
// 	ft_printf("%d\n", a);
// 	printf("%d\n", i);
// 	printf("%d\n", a);
//     return 0;
// }
>>>>>>> 2fe291993207a4bf16e627e24a51776758baccba


// int main()
// {
//     char *array = "hola";
//     int i = ft_printf("SSSSSS%sSSSS%", array, array);
//        int a = printf("SSSSSS%sSSSS%", array, array);
// 	ft_printf("%d\n", i);
// 	ft_printf("%d\n", a);
// 	printf("%d\n", i);
// 	printf("%d\n", a);
//     return 0;
// }

// int    main()
// {
//     char *array = "hola";
//     int d = 10;
//     int i = ft_printf("%d%%%%s%%%%\n%", d, array);
//        int a = printf("%d%%%%s%%%%\n%", d, array);

// 	ft_printf("%d\n", i);
// 	ft_printf("%d\n", a);
// 	printf("%d\n", i);
// 	printf("%d\n", a);


//     return 0;
// }

// int main()
// {
// 	int a, b;
// a = ft_printf("Hello, %s%!\n", "world");
// b = printf("Hello, %s%!\n", "world");
// printf("a: %d, b: %d\n", a, b);
// ft_printf("Hello, %c!\n", 'w');
// printf("original: %c!\n", 'w');
// ft_printf("Hello, %d!\n", 42);
// printf("original: %d!\n", 42);
// ft_printf("Hello, %i!\n", 42);
// printf("original: %i!\n", 42);
// ft_printf("Hello, %p!\n", NULL);
// printf("original: %p!\n", NULL);
// ft_printf("Hello, %u!\n", 42);
// printf("original: %u!\n", 42);
// ft_printf("Hello, %x!\n", 25);
// printf("original: %x!\n", 25);
// ft_printf("Hello, %X!\n", 25);
// printf("original: %X!\n", 25);
// ft_printf("Hello, %%!\n");
// printf("original: %%!\n");
// return (0);
// }


// int main() {
//     // Caso de gestión de conversiones simples
//     printf("Original: Este es un ejemplo de cadena simple\n");
//     ft_printf("Custommm: Este es un ejemplo de cadena simple\n");
    
//     // Caso de conversión con varios argumentos
//     printf("Original: Entero: %d, Carácter: %c, Cadena: %s\n", 42, 'A', "Hola mundo");
//     ft_printf("Custommm: Entero: %d, Carácter: %c, Cadena: %s\n", 42, 'A', "Hola mundo");
    
//     // Caso de gestión de conversiones con valores especiales
//     printf("Original: Cero: %d, El int más pequeño: %d, Cadena vacía: %s, Puntero NULL: %p\n", 0, INT_MIN, "", NULL);
//     ft_printf("Custommm: Cero: %d, El int más pequeño: %d, Cadena vacía: %s, Puntero NULL: %p\n", 0, INT_MIN, "", NULL);
    
//     // Caso de múltiples conversiones en medio de una oración
//     printf("Original: Esto es un número: %d, seguido de una cadena: %s, y un carácter: %c\n", 123, "Hola", '!');
//     ft_printf("Custommm: Esto es un número: %d, seguido de una cadena: %s, y un carácter: %c\n", 123, "Hola", '!');
    
//     return 0;
// }

int main() {
    // Caso de gestión de conversiones simples
    printf("Original return: %d\n", printf("Este es un ejemplo de cadena simple\n"));
    printf("Custom return: %d\n", ft_printf("Este es un ejemplo de cadena simple\n"));
    
    // Caso de conversión con varios argumentos
    printf("Original return: %d\n", printf("Entero: %d, Carácter: %c, Cadena: %s\n", 42, 'A', "Hola mundo"));
    printf("Custom return: %d\n", ft_printf("Entero: %d, Carácter: %c, Cadena: %s\n", 42, 'A', "Hola mundo"));
    
    // Caso de gestión de conversiones con valores especiales
    printf("Original return: %d\n", printf("Cero: %d, El int más pequeño: %d, Cadena vacía: %s, Puntero NULL: %p\n", 0, INT_MIN, "", NULL));
    printf("Custom return: %d\n", ft_printf("Cero: %d, El int más pequeño: %d, Cadena vacía: %s, Puntero NULL: %p\n", 0, INT_MIN, "", NULL));
    
    // Caso de múltiples conversiones en medio de una oración
    printf("Original return: %d\n", printf("Esto es un número: %d, seguido de una cadena: %s, y un carácter: %c\n", 123, "Hola", '!'));
    printf("Custom return: %d\n", ft_printf("Esto es un número: %d, seguido de una cadena: %s, y un carácter: %c\n", 123, "Hola", '!'));

    // Caso de conversiones idénticas una tras otra
    printf("Original return: %d\n", printf("Múltiples conversiones: %d %d %d\n", 42, 42, 42));
    printf("Custom return: %d\n", ft_printf("Múltiples conversiones: %d %d %d\n", 42, 42, 42));

    // Caso de combinaciones de conversiones más complejas
    printf("Original return: %d\n", printf("Combinaciones complejas: %c %s %p %d %x %X %u\n", 'A', "Hello", (void *)0x12345678, 42, 42, 42, 42));
    printf("Custom return: %d\n", ft_printf("Combinaciones complejas: %c %s %p %d %x %X %u\n", 'A', "Hello", (void *)0x12345678, 42, 42, 42, 42));

    return 0;
}

//////////////

// int main()
// {
//     ft_printf("Esto es una cadena de prueba sin ningún especificador de formato.\n");
//     return 0;
// }


// int main()
// {
//     // Pruebas con printf
//     printf("===== Pruebas con printf =====\n");
//     printf("Número: %d\n", 0);
//     printf("Entero más pequeño: %d\n", INT_MIN);
//     printf("Cadena vacía: %s\n", "");
//     printf("Puntero NULL: %p\n", NULL);

//     // Pruebas con ft_printf
//     printf("===== Pruebas con ft_printf =====\n");
//     ft_printf("Número: %d\n", 0);
//     ft_printf("Entero más pequeño: %d\n", INT_MIN);
//     ft_printf("Cadena vacía: %s\n", "");
//     ft_printf("Puntero NULL: %p\n", NULL);

//     return 0;
// }


// int main()
// {
//     // Pruebas con printf
//     printf("===== Pruebas con printf =====\n");
//     printf("Número: %d\n", 42);
//     printf("Cadena: %s, Número: %d, Carácter: %c\n", "Hola", 123, 'A');
//     printf("Entero más pequeño: %d\n", INT_MIN);
//     printf("Cadena vacía: %s\n", "");
//     printf("Puntero NULL: %p\n", NULL);

//     // Pruebas con ft_printf
//     printf("===== Pruebas con ft_printf =====\n");
//     ft_printf("Número: %d\n", 42);
//     ft_printf("Cadena: %s, Número: %d, Carácter: %c\n", "Hola", 123, 'A');
//     ft_printf("Entero más pequeño: %d\n", INT_MIN);
//     ft_printf("Cadena vacía: %s\n", "");
//     ft_printf("Puntero NULL: %p\n", NULL);

//     return 0;
// }
