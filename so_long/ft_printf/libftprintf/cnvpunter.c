/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnvpunter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:17:26 by alvaquer          #+#    #+#             */
/*   Updated: 2023/12/21 12:29:45 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	buscalen(unsigned long long n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static void	printptr(unsigned long long n)
{
	char	a;

	if (n >= 16)
	{
		printptr(n / 16);
		printptr(n % 16);
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

int	cnvpunter(unsigned long long n)
{
	int	i;

	i = 0;
	i += write(1, "0x", 2);
	if (n != 0)
	{
		printptr(n);
		i += buscalen(n);
	}
	else
		i += write(1, "0", 1);
	return (i);
}
