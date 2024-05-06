/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:03:14 by alvaquer          #+#    #+#             */
/*   Updated: 2023/12/12 16:11:03 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str1;

	str = (unsigned char *)s1;
	str1 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (*str != *str1)
			return (*str - *str1);
		i++;
		str++;
		str1++;
	}
	return (0);
}

/* La función ft_memcmp compara los
 primeros n bytes de las áreas de
  memoria apuntadas por s1 y s2. */