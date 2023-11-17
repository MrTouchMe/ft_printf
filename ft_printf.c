/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:22:56 by dgiurgev          #+#    #+#             */
/*   Updated: 2023/11/17 19:08:23 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		write_value;
	int		return_value;

	va_start(args, format);
	return_value = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				write_value = ft_putchar('%');
			else
				write_value = ft_parse(*format, args);
		}
		else
			write_value = ft_putchar(*format);
		if (write_value == -1)
			return (va_end(args), -1);
		return_value += write_value;
		format++;
	}
	return (va_end(args), return_value);
}
