/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:17:12 by alvaquer          #+#    #+#             */
/*   Updated: 2024/03/08 14:08:54 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a, t_list **b, int both)
{
	t_list	*temp;
	t_list	*temp1;

	temp = *b;
	if (temp->next != NULL)
	{
		temp1 = temp->next;
		*b = temp1;
	}
	else
		*b = NULL;
	temp->next = *a;
	*a = temp;
	if (!both)
		write(1, "pa\n", 3);
}

void	pb(t_list **b, t_list **a, int both)
{
	t_list	*temp;
	t_list	*temp1;

	temp = *b;
	if (temp->next != NULL)
	{
		temp1 = temp->next;
		*b = temp1;
	}
	else
		*b = NULL;
	temp->next = *a;
	*a = temp;
	if (!both)
		write(1, "pb\n", 3);
}

void	sa(t_list **a, int both)
{
	t_list	*temp;
	t_list	*temp1;

	temp = *a;
	temp1 = temp->next;
	temp->next = temp1->next;
	temp1->next = temp;
	*a = temp1;
	if (!both)
		write(1, "sa\n", 3);
}

void	sb(t_list **b, int both)
{
	t_list	*temp;
	t_list	*temp1;

	temp = *b;
	temp1 = temp->next;
	temp->next = temp1->next;
	temp1->next = temp;
	*b = temp1;
	if (!both)
		write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b, int both)
{
	sa(a, 1);
	sb(b, 1);
	if (!both)
		write(1, "ss\n", 3);
}
