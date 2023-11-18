/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:22:56 by dgiurgev          #+#    #+#             */
/*   Updated: 2023/11/18 17:38:44 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				ft_putchar('%', &len);
			else
				ft_parse(*format, args, &len);
		}
		else
			ft_putchar(*format, &len);
		if (len == -1)
			break ;
		format++;
	}
	return (va_end(args), len);
}

// int	main(void)
// {

// 	ft_printf("%p\n", 42);
// 	return (0);
// }
