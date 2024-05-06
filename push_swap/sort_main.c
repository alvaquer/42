/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:04:04 by alvaquer          #+#    #+#             */
/*   Updated: 2024/03/11 10:09:15 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_brain(t_list **lst, int i)
{
	if (i == 2)
		sort_two(lst);
	else if (i == 3)
		sort_three(lst);
	else if (i > 3)
		sort_more(lst);
}

void	sort_two(t_list **lst)
{
	sa(lst, 0);
}

void	sort_three(t_list **lst)
{
	t_list	*t;
	int		a;
	int		b;
	int		c;

	t = *lst;
	a = t->index;
	b = t->next->index;
	c = t->next->next->index;
	if (a > b && a < c)
		sa(lst, 0);
	else if (a > b && a > c)
		ra(lst, 0);
	else if (a < b && b > c)
		rra(lst, 0);
	t = *lst;
	if (t->index > t->next->index)
		sa(lst, 0);
}

void	sort_more(t_list **lst)
{
	t_list	*b;
	int		i;

	move_to_b(lst, &b);
	sort_three(lst);
	update_costs_and_positions(lst, &b);
	i = 0;
	while (b)
	{
		move_cheaper(lst, &b, find_cheaper(&b));
		update_costs_and_positions(lst, &b);
		i++;
	}
	check_order(lst);
}

void	update_costs_and_positions(t_list **a, t_list **b)
{
	fix_position(a, b);
	target_position(a, b);
	cost(a, b);
}
