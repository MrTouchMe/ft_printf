/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:00:57 by dgiurgev          #+#    #+#             */
/*   Updated: 2023/12/12 18:47:39 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse(char conversion_specifier, va_list args, int *len)
{
	if (conversion_specifier == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (conversion_specifier == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (conversion_specifier == 'd')
		ft_putnbr((long long int)va_arg(args, int), 10, 'x', len);
	else if (conversion_specifier == 'i')
		ft_putnbr((long long int)va_arg(args, int), 10, 'x', len);
	else if (conversion_specifier == 'u')
		ft_putnbr((long long int)va_arg(args, unsigned int), 10, 'x', len);
	else if (conversion_specifier == 'p')
		ft_putptr((long long int)va_arg(args, size_t), 16, len);
	else if (conversion_specifier == 'x')
		ft_putnbr((long long int)va_arg(args, unsigned int), 16, 'x', len);
	else if (conversion_specifier == 'X')
		ft_putnbr((long long int)va_arg(args, unsigned int), 16, 'X', len);
	else
		*len = -1;
}
