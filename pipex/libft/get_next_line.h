/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:29:44 by alvaquer          #+#    #+#             */
/*   Updated: 2023/12/26 16:33:59 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

char	*ft_strchr(const char *str, int a);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *cadena);
char	*get_next_line(int fd);
char	*ft_strdup(char *s1);

#endif