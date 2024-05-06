/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:04:19 by alvaquer          #+#    #+#             */
/*   Updated: 2024/03/11 13:13:26 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_list **a, t_list **b, int both)
{
	rra(a, 1);
	rrb(b, 1);
	if (!both)
		write(1, "rrr\n", 4);
}

void	fix_position_a(t_list **c, int i)
{
	while ((*c) != NULL)
	{
		(*c)->pos = i;
		(*c) = (*c)->next;
		i++;
	}
}

void	fix_position_b(t_list **d, int i)
{
	while ((*d) != NULL)
	{
		(*d)->pos = i;
		(*d) = (*d)->next;
		i++;
	}
}

t_list	*delete(t_list **lst)
{
	free_list(lst);
	return (NULL);
}
