/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:00:58 by alvaquer          #+#    #+#             */
/*   Updated: 2023/12/22 12:22:54 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(char const *str, ...);
int	cnvchar(int c);
int	cnvstring(char *str);
int	cnvdec(int a);
int	cnvunsigned(unsigned int a);
int	cnvhexmin(unsigned int a);
int	cnvhexmay(unsigned int a);
int	cnvpunter(unsigned long long str);

#endif