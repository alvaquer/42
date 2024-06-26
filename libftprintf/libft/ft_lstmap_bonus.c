/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:28:46 by alvaquer          #+#    #+#             */
/*   Updated: 2023/12/11 18:00:12 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*final;
	void	*new;

	final = NULL;
	if (lst && f)
	{
		while (lst != NULL)
		{
			new = f(lst->content);
			temp = ft_lstnew(new);
			if (!temp)
			{
				del(new);
				ft_lstclear(&final, del);
				return (NULL);
			}
			ft_lstadd_back(&final, temp);
			lst = lst->next;
		}
	}
	else
		return (NULL);
	return (final);
}
