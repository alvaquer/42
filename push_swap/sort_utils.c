/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:14:26 by alvaquer          #+#    #+#             */
/*   Updated: 2024/02/26 11:11:57 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost(t_list **a, t_list **b)
{
	t_list	*d;

	d = *b;
	while (d != NULL)
	{
		if (d->pos <= (lastpos(b) / 2) + 1)
		{
			d->cost_b = d->pos - 1;
			if (d->target_pos <= (lastpos(a) / 2) + 1)
				d->cost_a = d->target_pos - 1;
			else
				d->cost_a = d->target_pos - (lastpos(a) + 1);
		}
		else if (d->pos > (lastpos(b) / 2))
		{
			d->cost_b = d->pos - (lastpos(b) + 1);
			if (d->target_pos <= (lastpos(a) / 2) + 1)
				d->cost_a = d->target_pos - 1;
			else
				d->cost_a = d->target_pos - (lastpos(a) + 1);
		}
		d->coste_total = total_cost(d->cost_a, d->cost_b);
		d = d->next;
	}
}

int	total_cost(int cost_a, int cost_b)
{
	if (cost_a >= 0 && cost_b >= 0)
	{
		if (cost_a >= cost_b)
			return (cost_a);
		else
			return (cost_b);
	}
	else if (cost_a < 0 && cost_b < 0)
	{
		if (positive(cost_a) >= positive(cost_b))
			return (positive(cost_a));
		else
			return (positive(cost_b));
	}
	else
		return (positive(cost_a) + positive(cost_b));
}

int	find_cheaper(t_list **b)
{
	t_list	*a;
	int		total;
	int		temp;

	a = *b;
	total = -1;
	while (a != NULL)
	{
		if (total == -1)
		{
			total = a->pos;
			temp = a->coste_total;
		}
		else
		{
			if (a->coste_total < temp)
			{
				temp = a->coste_total;
				total = a->pos;
			}
		}
		a = a->next;
	}
	return (total);
}

void	check_order(t_list **a)
{
	t_list	*b;
	int		pos;

	pos = -1;
	b = *a;
	while (b != NULL)
	{
		if (b->index == 0)
			pos = b->pos - 1;
		b = b->next;
	}
	b = *a;
	check_rotate(a, pos);
}

void	check_rotate(t_list **a, int pos)
{
	int		total;
	int		i;

	i = 0;
	total = lastpos(a);
	if (pos <= total / 2 + 1)
	{
		while (i < pos)
		{
			ra(a, 0);
			i++;
		}
	}
	else
	{
		while (i < total - pos)
		{
			rra(a, 0);
			i++;
		}
	}
}
