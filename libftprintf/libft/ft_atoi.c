/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:37:33 by alvaquer          #+#    #+#             */
/*   Updated: 2023/12/12 16:14:20 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;

	sign = 0;
	res = 0;
	while (*str != '\0')
	{
		if (sign == 0 && ((*str >= '\t' && *str <= '\r') || *str == ' '))
		{
			sign = 0;
		}
		else if (sign == 0 && *str == '-')
			sign = -1;
		else if ((*str >= '0' && *str <= '9') || (sign == 0 && *str == '+'))
		{
			if (*str >= '0' && *str <= '9')
				res = res * 10 + (*str - '0');
			if (sign == 0)
				sign = 1;
		}
		else
			return (res * sign);
		str++;
	}
	return (res * sign);
}

/* La función `ft_atoi` convierte una cadena de caracteres que representa
 un número entero en su representación numérica. */