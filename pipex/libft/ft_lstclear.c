/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:44:49 by alvaquer          #+#    #+#             */
/*   Updated: 2024/04/01 13:30:28 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	temp = *lst;
	while ((*lst) != NULL)
	{
		temp = temp->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}

/* Su propósito es liberar la memoria de cada elemento de una lista 
enlazada y establecer
el puntero de la lista a `NULL`. */