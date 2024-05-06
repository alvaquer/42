/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:24:58 by alvaquer          #+#    #+#             */
/*   Updated: 2024/03/11 13:16:32 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**read_all(int nargs, char **vargs)
{
	char	**res;
	char	*args;

	if ((nargs < 2 && vargs[1] == NULL))
		return (NULL);
	else if (vargs[1][0] == '\0')
	{
		write(2, "Error\n", 7);
		return (NULL);
	}
	else
	{
		args = read_args(nargs, vargs);
	}
	res = ft_split(args, ' ');
	free(args);
	return (res);
}

char	*read_args(int nargs, char **vargs)
{
	char	*args;
	char	*temp;
	int		i;

	i = 1;
	args = ft_strdup(vargs[i]);
	i++;
	while (i < nargs)
	{
		temp = ft_strjoin(args, " ");
		free(args);
		args = temp;
		temp = ft_strjoin(args, vargs[i]);
		free(args);
		args = temp;
		i++;
	}
	return (args);
}

void	frees(char **res)
{
	int	i;

	i = 0;
	while (res[i] != NULL)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

void	free_list(t_list **a)
{
	t_list	*c;

	c = *a;
	while (c != NULL)
	{
		c = c->next;
		free(*a);
		*a = c;
	}
}

int	main(int nargs, char **vargs)
{
	char	**res;
	int		i;
	t_list	*nodo;
	t_list	*lst;

	res = read_all(nargs, vargs);
	if (res == NULL)
		return (0);
	lst = create_list(res);
	order_index(lst);
	nodo = lst;
	i = 0;
	while (nodo != NULL)
	{
		nodo = nodo->next;
		i++;
	}
	if (is_sorted(&lst) == 1)
	{
		sort_brain(&lst, i);
	}
	frees(res);
	free_list(&lst);
	return (0);
}
