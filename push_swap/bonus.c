/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:37:31 by alvaquer          #+#    #+#             */
/*   Updated: 2024/03/08 13:48:27 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**read_all(int nargs, char **vargs)
{
	char	**res;
	char	*args;

	if ((nargs < 2 && vargs[1] == NULL) || vargs[1][0] == '\0')
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
	char	*line;
	t_list	*b;
	t_list	*lst;

	res = read_all(nargs, vargs);
	if (res == NULL)
		return (0);
	lst = create_list(res);
	if (lst == NULL)
		exit (1);
	order_index(lst);
	b = NULL;
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		execute_line(line, &lst, &b);
		line = get_next_line(STDIN_FILENO);
	}
	message_final(&lst, &b);
	frees(res);
	free_list(&lst);
	return (0);
}
