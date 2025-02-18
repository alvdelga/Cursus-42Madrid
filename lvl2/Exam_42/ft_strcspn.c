/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 10:02:10 by alvdelga          #+#    #+#             */
/*   Updated: 2024/06/23 10:02:10 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

size_t ft_strcspn(const char *s, const char *reject)
{
    size_t count;

    count = 0;
    while(*s)
    {
        const char *r = reject;
        while(*r)
        {
            if(*s == *r)
            {
                return (count);
            }
            r++;
        }
        count++;
        s++;
    }
    return (count);
}
int main() {
    const char *s1 = "hello, world";
    const char *s2 = "aaaaaawo,iou";

    size_t result = ft_strcspn(s1, s2);
    printf("La longitud del segmento inicial sin vocales es: %zu\n", result);

    return 0;
}