/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:27:28 by alvaquer          #+#    #+#             */
/*   Updated: 2023/12/12 16:18:59 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (i < len && (start + i < ft_strlen(s)))
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* La función `ft_substr` crea una nueva cadena que es una
 subcadena de la cadena `s`. La subcadena comienza
  en el índice `start` y tiene una longitud máxima de `len`. */