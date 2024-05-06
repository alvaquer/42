/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:43:41 by alvaquer          #+#    #+#             */
/*   Updated: 2023/12/12 16:09:51 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*str == (unsigned char)c)
		{
			return ((unsigned char *)str);
		}
		str++;
		i++;
	}
	return (0);
}

/* La función `ft_memchr` busca la primera
 ocurrencia del carácter `c` en los
  primeros `n` bytes de la cadena `s`. */