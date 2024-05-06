/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:30:58 by alvaquer          #+#    #+#             */
/*   Updated: 2024/03/11 10:07:33 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_list *a)
{
	int	min;

	min = a->index;
	while (a)
	{
		if (min > a->index)
			min = a->index;
		a = a->next;
	}
	return (min);
}

void	move_to_b(t_list **a, t_list **b)
{
	int		old_limit;
	int		half_limit;
	int		limit;

	limit = lastpos(a) / 2;
	half_limit = limit / 2;
	while (lastpos(a) > 3)
	{
		while (get_min(*a) < limit && lastpos(a) > 3)
		{
			if ((*a)->index <= half_limit)
			{
				pb(a, b, 0);
				rb(b, 0);
			}
			else if ((*a)->index <= limit)
				pb(a, b, 0);
			else
				ra(a, 0);
		}
		old_limit = limit;
		limit = (old_limit / 2) + old_limit;
		half_limit = (limit + old_limit) / 2;
	}
}

int	media(t_list *a)
{
	t_list	*c;
	int		sum;

	c = a;
	sum = 0;
	while (c != NULL)
	{
		sum += c->index;
		c = c->next;
	}
	return (sum / lastpos(&a));
}

int	sub_media(t_list **a, int media)
{
	return (media + get_min(*a) / 2);
}

void	fix_position(t_list **a, t_list **b)
{
	t_list	*c;
	t_list	*d;
	int		i;

	c = *a;
	d = *b;
	i = 1;
	while (c != NULL && d != NULL)
	{
		c->pos = i;
		d->pos = i;
		c = c->next;
		d = d->next;
		i++;
	}
	if (c == NULL)
		fix_position_b(&d, i);
	else if (d == NULL)
		fix_position_a(&c, i);
}
