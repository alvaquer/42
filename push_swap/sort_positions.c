/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_positions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:40:25 by alvaquer          #+#    #+#             */
/*   Updated: 2024/02/26 10:25:32 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_position(t_list **a, t_list **b)
{
	t_list	*c;
	t_list	*d;
	int		min_pos;

	min_pos = -1;
	d = *b;
	while (d != NULL)
	{
		c = *a;
		min_pos = target_pos_min(c, d);
		if (min_pos == -1)
		{
			target_pos_max(a, d);
		}
		d = d->next;
	}
}

void	target_pos_max(t_list **a, t_list *d)
{
	t_list	*c;
	int		max_pos;
	int		max_index;

	c = *a;
	max_pos = -1;
	max_index = -1;
	while (c != NULL)
	{
		if (c->index > d->index)
		{
			if (max_index == -1)
			{
				max_pos = c->pos;
				max_index = c->index;
			}
			else if (c->index < max_index)
			{
				max_pos = c->pos;
				max_index = c->index;
			}
			d->target_pos = max_pos;
		}
		c = c->next;
	}
}

int	target_pos_min(t_list *c, t_list *d)
{
	int		min_pos;
	int		min_index;

	min_pos = -1;
	min_index = -1;
	while (c != NULL)
	{
		if (c->index < d->index)
		{
			if (min_index == -1)
			{
				min_pos = c->pos + 1;
				min_index = c->index;
			}
			else if (c->index > min_index)
			{
				min_pos = c->pos + 1;
				min_index = c->index;
			}
			d->target_pos = min_pos;
		}
		c = c->next;
	}
	return (min_pos);
}

int	lastpos(t_list **a)
{
	t_list	*c;
	int		i;

	i = 0;
	c = *a;
	while (c != NULL)
	{
		c = c->next;
		i++;
	}
	return (i);
}

int	positive(int num)
{
	if (num < 0)
		num = num * -1;
	return (num);
}
