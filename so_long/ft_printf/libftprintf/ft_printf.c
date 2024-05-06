/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:12:00 by alvaquer          #+#    #+#             */
/*   Updated: 2023/12/21 13:59:08 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check(va_list args, char c)
{
	if (c == 'c')
		return (cnvchar(va_arg(args, int)));
	else if (c == 's')
		return (cnvstring(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (cnvdec(va_arg(args, int)));
	else if (c == 'u')
		return (cnvunsigned(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (cnvhexmin(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (cnvhexmay(va_arg(args, unsigned int)));
	else if (c == 'p')
		return (cnvpunter(va_arg(args, unsigned long long)));
	else if (c == '%')
		return (write(1, "%", 1));
	else
		return (0);
}

static int	valid(char a)
{
	if (a == 'c' || a == 's' || a == 'p' || a == 'd' || a == 'i' || a == 'u'
		|| a == 'x' || a == 'X' || a == '%')
		return (1);
	else
		return (0);
}

int	ft_printf(char const *string, ...)
{
	int		i;
	int		cont;
	va_list	vargs;

	va_start(vargs, string);
	i = 0;
	cont = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	while (string[i] != '\0')
	{
		if (string[i] != '%' && string[i] != '\0')
			cont = cont + write(1, &string[i], 1);
		else if (string[i] == '%' && valid(string[i + 1]) == 1)
		{
			cont += check(vargs, string[i + 1]);
			i++;
		}
		i++;
	}
	va_end(vargs);
	return (cont);
}

/* int	main(void)
{
	char c = 'a';
	char *s = NULL;
	int d = 0;
	unsigned int u = 456;
	void *p = &d;

	printf("Expected:\n");
	printf("Decimal ch: %d\n", printf("%d", d));
	printf("String: %s\n", s);
	printf("Decimal: %d\n", d);
	printf("Unsigned: %u\n", u);
	printf("Pointer: %p\n", p);
	printf("Hexadecimal: %x\n", d);
	printf("Hexadecimalmayus: %X\n", d);
	printf("porcentaje: %%\n");
	printf("\nActual:\n");
	ft_printf("Decimal: %d\n", ft_printf("%d", d));
	ft_printf("Hexadecimalmayus: %X\n", d);
	ft_printf("String: %s\n", s);
	ft_printf("Hexadecimal: %x\n", d);
	ft_printf("Decimal: %d\n", d);
	ft_printf("Unsigned: %u\n", u);
	ft_printf("porcentaje: %%\n", 5);
	ft_printf("Pointer: %p\n", p);

	return (0);
} */