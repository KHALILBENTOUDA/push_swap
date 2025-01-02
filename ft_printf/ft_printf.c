/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:02:41 by kben-tou          #+#    #+#             */
/*   Updated: 2024/11/19 09:53:58 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	checktp(const char *format, va_list args, int *char_counter)
{
	int	status;

	status = 0;
	if (*format == '%')
		status = ft_printf_char('%', char_counter);
	if (*format == 'c')
		status = ft_printf_char(va_arg(args, int), char_counter);
	else if (*format == 's')
		status = ft_printf_str(va_arg(args, char *), char_counter);
	else if (*format == 'd' || *format == 'i')
		status = ft_printf_number(va_arg(args, int), char_counter);
	else if (*format == 'u')
		status = ft_printf_unsigned(va_arg(args, unsigned int), char_counter);
	else if (*format == 'p')
		status = ft_printf_pointer(va_arg(args, void *), char_counter);
	else if (*format == 'x')
		status = ft_print_hex(va_arg(args, unsigned int), char_counter, 0);
	else if (*format == 'X')
		status = ft_print_hex(va_arg(args, unsigned int), char_counter, 1);
	return (status);
}

static char	*ft_strrchr(const char *s, int c)
{
	char	conv_char;
	char	*store;

	conv_char = (char)c;
	store = NULL;
	while (*s)
	{
		if (*s == conv_char)
			store = (char *)s;
		s++;
	}
	if (conv_char == '\0')
		return ((char *)s);
	return (store);
}

int	handle_specifier(const char *format, va_list args, int *char_counter)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (*char_counter);
			else if (ft_strrchr("cspdiuxX%", *format))
			{
				if (checktp(format, args, char_counter) == -1)
					return (-1);
			}
			else if ((*format >= 9 && *format <= 13))
			{
				if (ft_printf_char(*format, char_counter) == -1)
					return (-1);
			}
		}
		else if (*format && ft_printf_char(*format, char_counter) == -1)
			return (-1);
		format++;
	}
	return (*char_counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		char_counter;

	char_counter = 0;
	va_start(args, format);
	if (handle_specifier(format, args, &char_counter) == -1)
		return (-1);
	va_end(args);
	return (char_counter);
}
