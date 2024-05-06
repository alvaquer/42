/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:41:29 by alvaquer          #+#    #+#             */
/*   Updated: 2024/02/12 14:45:14 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*move;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		move = *lst;
		while (move->next != NULL)
		{
			move = move->next;
		}
		move->next = new;
	}
}

// Su propósito es agregar un nuevo elemento al final de una lista enlazada.