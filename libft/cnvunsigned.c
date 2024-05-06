/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnvunsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:33:22 by alvaquer          #+#    #+#             */
/*   Updated: 2023/12/21 13:58:05 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putchu(unsigned int n)
{
	char	c;

	if (n >= 10)
	{
		putchu(n / 10);
		putchu(n % 10);
	}
	if (n < 10 && n >= 0)
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

static int	countl(unsigned int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	cnvunsigned(unsigned int n)
{
	int	l;

	l = 0;
	if (n == 0)
	{
		l++;
		write(1, "0", 1);
	}
	else
	{
		l = countl(n);
		putchu(n);
	}
	return (l);
}
