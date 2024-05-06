/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:26:26 by alvaquer          #+#    #+#             */
/*   Updated: 2023/12/12 16:24:06 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*convert(int n, int i, int op)
{
	char	*res;

	res = (char *)malloc(i + op + 1);
	if (res == NULL)
		return (NULL);
	if (n == 0)
	{
		res[0] = '0';
		res[1] = '\0';
	}
	else
	{
		if (op == 1)
			res[0] = '-';
		if (n != 0)
			res[i + op] = '\0';
		while (i > 0)
		{
			res[(i - 1) + op] = (n % 10) + '0';
			n = n / 10;
			i--;
		}
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		num;
	int		i;
	int		op;

	i = 0;
	op = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = n * -1;
		op = 1;
	}
	num = n;
	while (num > 0)
	{
		num = num / 10;
		i++;
	}
	if (i == 0)
		i = 1;
	res = convert(n, i, op);
	return (res);
}

/* La función `ft_itoa` convierte un 
número entero `n` en una cadena de caracteres. */