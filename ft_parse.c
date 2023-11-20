/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:00:57 by dgiurgev          #+#    #+#             */
/*   Updated: 2023/11/20 20:27:05 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	int	temp;

	temp = write(1, &c, 1);
	if (temp == -1)
		*len = -1;
	else
		*len += temp;
}

void	ft_putstr(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_putchar(*str++, len);
		if (*len == -1)
			return ;
	}
}

void	ft_putptr(size_t nbr, int base, int *len)
{
	ft_putstr("0x", len);
	if (*len == -1)
		return ;
	ft_putnbr_ptr(nbr, base, 'x', len);
}

void	ft_putnbr(long long int nbr, int base, char x, int *len)
{
	const char	*hex = {"0123456789abcdef"};
	const char	*hex_b = {"0123456789ABCDEF"};

	if (nbr < 0)
	{
		ft_putchar('-', len);
		if (*len == -1)
			return ;
		nbr = -nbr;
	}
	if (nbr >= base)
		ft_putnbr(nbr / base, base, x, len);
	if (x == 'X')
		ft_putchar(hex_b[nbr % base], len);
	else
		ft_putchar(hex[nbr % base], len);
	if (*len == -1)
		return ;
}

void	ft_putnbr_ptr(size_t nbr, int base, char x, int *len)
{
	const char	*hex = {"0123456789abcdef"};
	const char	*hex_b = {"0123456789ABCDEF"};

	if (nbr < 0)
	{
		ft_putchar('-', len);
		if (*len == -1)
			return ;
		nbr = -nbr;
	}
	if (nbr >= base)
		ft_putnbr(nbr / base, base, x, len);
	if (x == 'X')
		ft_putchar(hex_b[nbr % base], len);
	else
		ft_putchar(hex[nbr % base], len);
	if (*len == -1)
		return ;
}

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
}
