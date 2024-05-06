/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnvdec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:24:04 by alvaquer          #+#    #+#             */
/*   Updated: 2023/12/21 13:43:06 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putch(int n)
{
	char	c;

	if (n < 0 && n != -2147483648)
	{
		write(1, "-", 1);
		n = n * -1;
	}
	if (n >= 10)
	{
		putch(n / 10);
		putch(n % 10);
	}
	if (n < 10 && n >= 0)
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

static int	countl(int n)
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

int	cnvdec(int n)
{
	int	l;

	l = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (n == 0)
	{
		l++;
		write(1, "0", 1);
	}
	else
	{
		l = countl(n);
		putch(n);
	}
	return (l);
}
