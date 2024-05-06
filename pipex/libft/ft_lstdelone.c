/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:22:44 by alvaquer          #+#    #+#             */
/*   Updated: 2024/04/01 13:30:45 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

/* Su propósito es liberar la memoria de un solo elemento
 de una lista enlazada.
y un puntero a una función (`del`) que se utiliza para 
liberar la memoria del contenido del elemento.
llama a la función `del` pasándole el contenido del 
elemento de la lista (`del(lst->content)`). 
Esta función `del` es proporcionada por el usuario y 
se supone que sabe cómo liberar la memoria del contenido. */