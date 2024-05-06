/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:30:39 by alvaquer          #+#    #+#             */
/*   Updated: 2024/02/08 13:36:20 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd('8', fd);
	}
	if (n < 0 && n != -2147483648)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	if (n < 10 && n >= 0)
	{
		ft_putchar_fd(n + '0', fd);
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

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
