/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:35:51 by alvaquer          #+#    #+#             */
/*   Updated: 2023/12/12 16:04:50 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int a)
{
	char	*str1;

	str1 = NULL;
	while (*str != '\0')
	{
		if (*str == (unsigned char)a)
		{
			str1 = (char *)str;
		}
		str++;
	}
	if ((unsigned char)a == '\0')
		return ((char *)str);
	return (str1);
}

/* La función `ft_strrchr` busca la última
 ocurrencia del carácter `a` en la cadena `str`. */