/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnvhexmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:27:00 by alvaquer          #+#    #+#             */
/*   Updated: 2023/12/21 13:56:34 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	buscalen(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static void	printhex(unsigned int n)
{
	char	a;

	if (n >= 16)
	{
		printhex(n / 16);
		printhex(n % 16);
	}
	else
	{
		if (n <= 9)
		{
			a = n + '0';
			write(1, &a, 1);
		}
		else
		{
			a = n - 10 + 'a';
			write(1, &a, 1);
		}
	}
}

int	cnvhexmin(unsigned int n)
{
	if (n != 0)
		printhex(n);
	else
		write(1, "0", 1);
	return (buscalen(n));
}
