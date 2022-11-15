/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:11:39 by mzarichn          #+#    #+#             */
/*   Updated: 2022/11/12 13:00:41 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_varf(va_list args, const char varf)
{
	int	p_len;

	p_len = 0;
	if (varf == 'c')
		p_len += ft_pchar(va_arg(args, int));
	else if (varf == 's')
		p_len += ft_pstring(va_arg(args, char *));
	else if (varf == 'p')
		p_len += ft_pptr(va_arg(args, unsigned long long));
	else if (varf == 'd' || varf == 'i')
		p_len += ft_pnbr(va_arg(args, int));
	else if (varf == 'u')
		p_len += ft_punsigned(va_arg(args, unsigned int));
	else if (varf == 'x' || varf == 'X')
		p_len += ft_phex(va_arg(args, unsigned int), varf);
	else if (varf == '%')
		p_len += ft_ppercent();
	return (p_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		p_len;

	i = 0;
	p_len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			p_len += ft_varf(args, str[i + 1]);
			i++;
		}
		else
			p_len += ft_pchar(str[i]);
		i++;
	}
	va_end(args);
	return (p_len);
}
