/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:31:33 by alvaquer          #+#    #+#             */
/*   Updated: 2023/09/27 19:50:04 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0' && s2[i] != '\0'))
	{
		i++;
	}
	res = s1[i] - s2[i];
	return (res);
}

/* int	main(void)
{
	char primera[] = "hole";
	char segunda[] = "hola";
	printf("%d", ft_strcmp(primera, segunda));
	return (0);
} 
 */