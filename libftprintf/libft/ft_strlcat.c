/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:33:38 by alvaquer          #+#    #+#             */
/*   Updated: 2023/12/12 16:02:25 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *origen, size_t num)
{
	size_t	i;
	size_t	j;
	size_t	x;

	i = 0;
	j = 0;
	x = 0;
	while (dest[j] != '\0' && j < num)
		j++;
	while (origen[i] != '\0')
		i++;
	if (j == num)
		return (j + i);
	while (origen[x] != '\0' && j + x + 1 < num)
	{
		dest[j + x] = origen[x];
		x++;
	}
	dest[j + x] = '\0';
	return (j + i);
}

/* La función `ft_strlcat` concatena la cadena `origen`
 a la cadena `dest`, asegurándose de que la cadena
  resultante esté terminada por un carácter nulo ('\0')
   y que no exceda el tamaño `num`. */