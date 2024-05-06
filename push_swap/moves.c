/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:36:11 by alvaquer          #+#    #+#             */
/*   Updated: 2024/03/08 14:00:02 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_while_both_neg(t_list **a, t_list **b, int *i, int *j)
{
	while (*i < 0 && *j < 0)
	{
		rrr(a, b, 0);
		(*i)++;
		(*j)++;
	}
}

void	move_while_both_pos(t_list **a, t_list **b, int *i, int *j)
{
	while (*i > 0 && *j > 0)
	{
		rr(a, b, 0);
		(*i)--;
		(*j)--;
	}
}

void	move_while_i_neg_j_pos(t_list **a, t_list **b, int *i, int *j)
{
	while (*i < 0 && *j > 0)
	{
		rra(a, 0);
		rb(b, 0);
		(*i)++;
		(*j)--;
	}
}

void	move_cheaper(t_list **a, t_list **b, int pos)
{
	t_list	*d;
	int		i;
	int		j;

	d = *b;
	while (d->pos != pos)
		d = d->next;
	i = d->cost_a;
	j = d->cost_b;
	move_while_both_neg(a, b, &i, &j);
	move_while_both_pos(a, b, &i, &j);
	move_while_i_neg_j_pos(a, b, &i, &j);
	move_while_i_pos_j_neg(a, b, &i, &j);
	move_while_i_neg_j_zero(a, &i);
	move_while_i_pos_j_zero(a, &i);
	move_while_i_zero_j_neg(b, &j);
	move_while_i_zero_j_pos(b, &j);
	pa(a, b, 0);
}

int	is_sorted(t_list **a)
{
	t_list	*c;

	c = *a;
	if (c == NULL)
		return (0);
	while (c->next != NULL)
	{
		if (c->content > c->next->content)
			return (1);
		c = c->next;
	}
	return (0);
}
