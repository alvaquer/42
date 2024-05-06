/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:48:28 by alvaquer          #+#    #+#             */
/*   Updated: 2024/03/11 12:24:42 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_line(char *line, t_list **a, t_list **b)
{
	t_list	*h;

	h = *b;
	if (ft_strcmp(line, "pb\n"))
		pb(a, b, 1);
	else if (ft_strcmp(line, "sa\n"))
		sa(a, 1);
	else if (ft_strcmp(line, "ra\n"))
		ra(a, 1);
	else if (ft_strcmp(line, "rra\n"))
		rra(a, 1);
	else if (h != NULL)
		b_not_null(line, a, b);
	else
		find_error(*a, *b);
	free(line);
}

void	b_not_null(char *line, t_list **a, t_list **b)
{
	if (ft_strcmp(line, "rb\n"))
		rb(b, 1);
	else if (ft_strcmp(line, "rr\n"))
		rr(a, b, 1);
	else if (ft_strcmp(line, "sb\n"))
		sb(b, 1);
	else if (ft_strcmp(line, "ss\n"))
		ss(a, b, 1);
	else if (ft_strcmp(line, "pa\n"))
		pa(a, b, 1);
	else if (ft_strcmp(line, "rrb\n"))
		rrb(b, 1);
	else if (ft_strcmp(line, "rrr\n"))
		rrr(a, b, 1);
}

bool	ft_strcmp(char *str_1, char *str_2)
{
	while (*str_1 == *str_2
		&& *str_1)
	{
		++str_1;
		++str_2;
	}
	if (*str_1 || *str_2)
		return (false);
	return (true);
}

void	find_error(t_list *a, t_list *b)
{
	free_list(&a);
	free_list(&b);
	write(2, "Error\n", 6);
	exit (1);
}

void	message_final(t_list **a, t_list **b)
{
	t_list	*h;

	h = *b;
	if (is_sorted(a) == 1 || h != NULL)
		write(2, "KO\n", 3);
	else
		write(2, "OK\n", 3);
}
