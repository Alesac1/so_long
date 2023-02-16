/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:48:30 by asacchin          #+#    #+#             */
/*   Updated: 2023/02/04 17:54:15 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
		i += write(1, &s[i], 1);
	return (i);
}

int	ft_formats(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_printchar(va_arg(args, int));
	else if (format == 's')
		print_length += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
	{
		print_length += ft_printstr("0x");
		print_length += ft_printp(va_arg(args, uintptr_t));
	}
	else if (format == 'd' || format == 'i')
		print_length += ft_printint(va_arg(args, int));
	else if (format == 'u')
		print_length += ft_printunsint(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_printhex(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_length += ft_printchar('%');
	return (print_length);
}

int	ft_printf(char const *ptr, ...)
{
	int		i;
	int		out;
	va_list	v;

	i = 0;
	out = 0;
	va_start(v, ptr);
	while (ptr[i])
	{
		if (ptr[i] == '%')
		{
			out += ft_formats(v, ptr[i + 1]);
			i++;
		}
		else
			out += ft_printchar(ptr[i]);
		i++;
	}
	va_end(v);
	return (out);
}
