/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:25:04 by alvaquer          #+#    #+#             */
/*   Updated: 2023/12/12 15:59:24 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int valor, size_t num)
{
	size_t	i;
	char	*ptr1;

	ptr1 = (char *)ptr;
	i = 0;
	while (i < num)
	{
		*ptr1 = (char)valor;
		ptr1++;
		i++;
	}
	return (ptr);
}

/* La función `ft_memset` se utiliza para llenar 
los primeros `num` bytes del bloque de memoria
 apuntado por `ptr` con el valor de `valor`. */