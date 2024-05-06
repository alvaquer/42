/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:31:41 by alvaquer          #+#    #+#             */
/*   Updated: 2023/12/12 16:27:20 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/* La función `ft_striteri` aplica la función `f`
 a cada carácter de la cadena `s`. La función `f`
  toma dos argumentos: el índice del carácter
   y un puntero al carácter mismo. */