/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:22:56 by dgiurgev          #+#    #+#             */
/*   Updated: 2023/11/17 21:46:13 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		write_value;
	int		return_value;

	return_value = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				write_value = ft_putchar_fd('%', 1);
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

int	main(void)
{
	ft_printf("Hello %s\n", "World");
	return (0);
}
