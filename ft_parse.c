/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:00:57 by dgiurgev          #+#    #+#             */
/*   Updated: 2023/11/17 19:13:09 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>

int	ft_parse(char conversion_specifier, va_list args)
{
	int		ret;
	char	*s;

	if (conversion_specifier == 'c')
		ret = ft_putchar_fd(va_args(args, char), 1);
	else if (conversion_specifier == 's')
		ret = ft_putstr_fd(va_args(args, char *), 1);
	else if (conversion_specifier == 'd')
		ret = ft_putnbr_fd(va_args(args, int), 1);
	else if (conversion_specifier == 'i')
		ret = ft_putnbr_fd(va_args(args, int), 1);
	else if (conversion_specifier == 'u')
		ret = ft_putnbr_fd(va_args(args, unsigned int), 1);
	else if (conversion_specifier == 'p')
		ret = ft_putnbr_fd(va_args(args, unsigned int), 1);
}
