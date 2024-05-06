/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:39:23 by alvaquer          #+#    #+#             */
/*   Updated: 2024/02/23 15:26:52 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_while_i_pos_j_neg(t_list **a, t_list **b, int *i, int *j)
{
	while (*i > 0 && *j < 0)
	{
		rrb(b, 0);
		ra(a, 0);
		(*i)--;
		(*j)++;
	}
}

void	move_while_i_neg_j_zero(t_list **a, int *i)
{
	while (*i < 0)
	{
		rra(a, 0);
		(*i)++;
	}
}

void	move_while_i_pos_j_zero(t_list **a, int *i)
{
	while (*i > 0)
	{
		ra(a, 0);
		(*i)--;
	}
}

void	move_while_i_zero_j_neg(t_list **b, int *j)
{
	while (*j < 0)
	{
		rrb(b, 0);
		(*j)++;
	}
}

void	move_while_i_zero_j_pos(t_list **b, int *j)
{
	while (*j > 0)
	{
		rb(b, 0);
		(*j)--;
	}
}
