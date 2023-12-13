/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:37:39 by dgiurgev          #+#    #+#             */
/*   Updated: 2023/12/13 17:16:01 by dgiurgev         ###   ########.fr       */
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
	ft_putnbr_ptr(nbr, base, len);
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
	if (*len == -1)
		return ;
	if (x == 'X')
		ft_putchar(hex_b[nbr % base], len);
	else
		ft_putchar(hex[nbr % base], len);
}

void	ft_putnbr_ptr(size_t nbr, int base, int *len)
{
	const char	*hex = {"0123456789abcdef"};

	if (nbr >= (size_t)base)
		ft_putnbr_ptr(nbr / base, base, len);
	ft_putchar(hex[nbr % base], len);
}
