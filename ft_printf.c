/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:22:56 by dgiurgev          #+#    #+#             */
/*   Updated: 2023/11/19 17:47:26 by dgiurgev         ###   ########.fr       */
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
// 	ft_printf("Hello %s\n", "World");
// 	printf("Hello %s\n", "World");
// 	printf("\n");
// 	ft_printf("Hello %d\n", 42);
// 	printf("Hello %d\n", 42);
// 	printf("\n");
// 	ft_printf("Hello %i\n", 42);
// 	printf("Hello %i\n", 42);
// 	printf("\n");
// 	ft_printf("Hello %u\n", 42);
// 	printf("Hello %u\n", 42);
// 	printf("\n");
// 	ft_printf("Hello %x\n", 42);
// 	printf("Hello %x\n", 42);
// 	printf("\n");
// 	ft_printf("Hello %X\n", 42);
// 	printf("Hello %X\n", 42);
// 	printf("\n");
// 	ft_printf("Hello %c\n", 'c');
// 	printf("Hello %c\n", 'c');
// 	printf("\n");
// 	ft_printf("Hello %p\n", &ft_printf);
// 	printf("Hello %p\n", &ft_printf);
// 	printf("\n");
// 	ft_printf("Hello %%\n");
// 	printf("Hello %%\n");
// 	ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
// 	printf(" %p %p ", LONG_MIN, LONG_MAX);
// 	printf("\n");
// 	ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
// 	printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
// 	return (0);
// }
