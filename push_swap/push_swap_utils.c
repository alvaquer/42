/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:51:42 by alvaquer          #+#    #+#             */
/*   Updated: 2024/02/19 11:57:21 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = ft_strlen(s1) + ft_strlen(s2) + 1;
	s3 = (char *)malloc(k + 1);
	if (s3 == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	s3[i] = ' ';
	i++;
	while (s2[j] != '\0')
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (s3);
}

size_t	ft_strlen(const char *cadena)
{
	int	i;

	i = 0;
	while (cadena[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = (char *)malloc(ft_strlen(s1) + 1);
	if (s2 == NULL)
		return (NULL);
	s2 = (char *)ft_memcpy(s2, s1, ft_strlen(s1) + 1);
	return (s2);
}

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

long	ft_numero(const char *str)
{
	long		sign;
	long		res;

	sign = 1;
	res = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str != '\0')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}
