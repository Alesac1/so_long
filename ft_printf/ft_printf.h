/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:42:31 by asacchin          #+#    #+#             */
/*   Updated: 2023/02/04 17:45:18 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

int	ft_printint(int n);
int	ft_printhex(unsigned int n, const char ptr);
int	ft_printunsint(unsigned int n);
int	ft_printp(uintptr_t n);
int	ft_printchar(int c);
int	ft_printstr(char *s);
int	ft_formats(va_list args, const char format);
int	ft_printf(char const *ptr, ...);

#endif