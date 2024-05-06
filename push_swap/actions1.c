/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:01:57 by alvaquer          #+#    #+#             */
/*   Updated: 2024/03/11 10:06:41 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **lst, int both)
{
	t_list	*nodo;
	t_list	*temp;

	nodo = *lst;
	temp = *lst;
	while (nodo->next != NULL)
		nodo = nodo->next;
	*lst = temp->next;
	nodo->next = temp;
	temp->next = NULL;
	if (!both)
		write(1, "ra\n", 3);
}

void	rb(t_list **lst, int both)
{
	t_list	*nodo;
	t_list	*temp;

	nodo = *lst;
	temp = *lst;
	while (nodo->next != NULL)
		nodo = nodo->next;
	nodo->next = temp;
	*lst = temp->next;
	temp->next = NULL;
	if (!both)
		write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b, int both)
{
	ra(a, 1);
	rb(b, 1);
	if (!both)
		write(1, "rr\n", 3);
}

void	rra(t_list **lst, int both)
{
	t_list	*nodo;
	t_list	*temp;
	t_list	*temp1;

	if (lst != NULL && *lst != NULL && (*lst)->next != NULL)
	{
		nodo = *lst;
		temp = *lst;
		while (nodo->next->next != NULL)
		{
			nodo = nodo->next;
		}
		temp1 = nodo;
		*lst = temp1->next;
		temp1->next->next = temp;
		nodo->next = NULL;
		if (!both)
			write(1, "rra\n", 4);
	}
}

void	rrb(t_list **lst, int both)
{
	t_list	*nodo;
	t_list	*temp;
	t_list	*temp1;

	if (lst != NULL && *lst != NULL && (*lst)->next != NULL)
	{
		nodo = *lst;
		temp = *lst;
		while (nodo->next != NULL && nodo->next->next != NULL)
			nodo = nodo->next;
		temp1 = nodo;
		*lst = temp1->next;
		temp1->next->next = temp;
		nodo->next = NULL;
		if (!both)
			write(1, "rrb\n", 4);
	}
}
