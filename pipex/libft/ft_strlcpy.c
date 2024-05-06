/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:50:38 by alvaquer          #+#    #+#             */
/*   Updated: 2023/12/12 16:00:58 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *origen, size_t num)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (origen[j] != '\0')
		j++;
	if (num == 0)
		return (j);
	while (origen[i] != '\0' && i < num - 1)
	{
		dest[i] = origen[i];
		i++;
	}
	dest[i] = '\0';
	return (j);
}

/* La función `ft_strlcpy` copia hasta `num - 1`
 caracteres de la cadena `origen` a la cadena `dest`,
  asegurándose de que la cadena resultante esté
   terminada por un carácter nulo ('\0'). */