/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:21:28 by alvaquer          #+#    #+#             */
/*   Updated: 2023/12/12 16:21:41 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	posinicial(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	op;

	op = 1;
	i = 0;
	j = 0;
	while (s1[i] != '\0' && op == 1)
	{
		op = 0;
		j = 0;
		while (set[j] != '\0')
		{
			if (set[j] == s1[i])
				op = 1;
			j++;
		}
		i++;
	}
	return (i - 1);
}

static int	posfinal(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	op;

	i = ft_strlen(s1) - 1;
	j = 0;
	op = 1;
	while (i > 0 && op == 1)
	{
		op = 0;
		j = 0;
		while (set[j] != '\0')
		{
			if (set[j] == s1[i])
				op = 1;
			j++;
		}
		i--;
	}
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		j;
	int		k;

	if (*set == '\0')
		return (ft_strdup(s1));
	if (*s1 == '\0')
		return (ft_strdup(""));
	i = posinicial(s1, set);
	j = posfinal(s1, set);
	if (i > j)
		return (ft_strdup(""));
	res = (char *)malloc(j - i + 2);
	if (res == NULL)
		return (NULL);
	k = 0;
	while (i <= j)
	{
		res[k] = s1[i];
		i++;
		k++;
	}
	res[k] = '\0';
	return (res);
}

/* La función `ft_strtrim` recorta los
 caracteres especificados en `set` del inicio
  y del final de la cadena `s1`. */