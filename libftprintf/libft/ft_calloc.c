/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:12:34 by alvaquer          #+#    #+#             */
/*   Updated: 2023/12/12 16:15:35 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	cont;

	cont = 0;
	ptr = (char *)malloc(count * size);
	if (ptr == NULL)
		return (ptr);
	else
	{
		while (cont < (count * size))
		{
			ptr[cont] = 0;
			cont++;
		}
		return (ptr);
	}
}

/* La función `ft_calloc` asigna memoria para
 un arreglo de `count` elementos, cada uno de tamaño
  `size` bytes, y luego llena la memoria asignada
   con bytes de valor cero. */