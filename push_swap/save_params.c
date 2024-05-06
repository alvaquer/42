/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:57:09 by alvaquer          #+#    #+#             */
/*   Updated: 2024/03/11 13:13:54 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_nodo(int content, int pos, t_list **lst)
{
	t_list	*new;
	t_list	*move;

	new = NULL;
	new = malloc(sizeof(t_list));
	new->content = content;
	new->next = NULL;
	new->pos = pos;
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		move = *lst;
		while (move->next != NULL)
		{
			move = move->next;
		}
		move->next = new;
	}
}

int	is_a_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' && str[1] == '\0')
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9'))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_valid(int numero, t_list *lst)
{
	t_list	*nodo;

	nodo = lst;
	while (nodo != NULL)
	{
		if (nodo->content == numero)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		nodo = nodo->next;
	}
	return (1);
}

t_list	*create_list(char **res)
{
	int		i;
	long	numero;
	t_list	*lst;

	i = 0;
	lst = NULL;
	while (res[i])
	{
		if (is_a_number(res[i]) != 1)
			return (delete(&lst));
		numero = ft_numero(res[i]);
		if (numero < -2147483648 || numero > 2147483647)
		{
			write(2, "Error\n", 6);
			return (delete(&lst));
		}
		if (is_valid((int)numero, lst) != 1)
			return (delete(&lst));
		new_nodo((int)numero, i, &lst);
		i++;
	}
	return (lst);
}

void	order_index(t_list *lst)
{
	t_list	*nodo;
	t_list	*nodo2;

	nodo2 = lst;
	while (nodo2 != NULL)
	{
		nodo2->index = 0;
		nodo = lst;
		while (nodo != NULL)
		{
			if (nodo->content < nodo2->content)
				nodo2->index++;
			nodo = nodo->next;
		}
		nodo2 = nodo2->next;
	}
}
