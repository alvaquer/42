/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:16:26 by alvaquer          #+#    #+#             */
/*   Updated: 2023/12/12 16:03:43 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int a)
{
	while (*str != '\0')
	{
		if (*str == (unsigned char)a)
		{
			return ((char *)str);
		}
		str++;
	}
	if ((unsigned char)a == '\0')
		return ((char *)str);
	return (0);
}

/* La función `ft_strchr` busca la primera
 ocurrencia del carácter `a` en la cadena `str`. */