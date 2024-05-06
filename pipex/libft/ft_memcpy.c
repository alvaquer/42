/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:26:44 by alvaquer          #+#    #+#             */
/*   Updated: 2023/12/12 15:58:24 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *origen, size_t num)
{
	size_t	i;
	char	*str;
	char	*str1;

	str = (char *)dest;
	str1 = (char *)origen;
	if (!dest && !origen)
		return (0);
	i = 0;
	while (i < num)
	{
		*str = *str1;
		i++;
		str++;
		str1++;
	}
	return (dest);
}

/* La función `ft_memcpy` copia `num` bytes desde la 
ubicación de memoria apuntada por `origen`
 a la ubicación de memoria apuntada por `dest`. */