/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:36:22 by alvaquer          #+#    #+#             */
/*   Updated: 2023/12/12 15:59:36 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *origen, size_t num)
{
	char		*str;
	const char	*str1;

	str = (char *)dest;
	str1 = (const char *)origen;
	if (!dest && !origen)
		return (0);
	if (str1 > str)
	{
		while (num--)
		{
			*str = *str1;
			str++;
			str1++;
		}
	}
	else
	{
		while (num > 0)
		{
			*(str + num - 1) = *(str1 + num - 1);
			num --;
		}
	}
	return (dest);
}

/* La función `ft_memmove` copia `num` bytes desde
 la ubicación de memoria apuntada por `origen`
  a la ubicación de memoria apuntada por `dest`.
   A diferencia de `memcpy`, `memmove` es seguro
    para regiones de memoria superpuestas.

La superposición de punteros se refiere a la situación
 en la que dos o más punteros apuntan a la misma ubicación
  de memoria o a ubicaciones de memoria que se solapan.
   En el contexto de las funciones de copia de memoria
    como `memcpy` y `memmove`, la superposición puede
	 ser problemática.

Si estás copiando de una ubicación de memoria a otra
 y las dos ubicaciones se solapan, el orden en el que
  se copian los bytes puede afectar al resultado final.
   Si copias de izquierda a derecha y las ubicaciones
    se solapan de tal manera que el destino está a la
	 derecha del origen, puedes acabar sobrescribiendo
	  bytes del origen antes de que hayan sido copiados.
	   Este es un problema si estás intentando hacer
	    una copia exacta.

La función `memmove` maneja este problema comprobando
 si el origen está a la derecha del destino. Si es así,
  copia los bytes de derecha a izquierda en lugar de
   izquierda a derecha. De esta manera, incluso si
    las ubicaciones de memoria se solapan, todos
	 los bytes del origen se copian correctamente antes
	  de que puedan ser sobrescritos. */