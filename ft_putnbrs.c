/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:43:43 by mzarichn          #+#    #+#             */
/*   Updated: 2022/11/17 12:41:33 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(t_ull n, char *base, t_ull baselen, char c)
{
	int	count;

	count = 0;
	if (n >= baselen)
		count += ft_putnbr_base(n / baselen, base, baselen, c);
	return (write(1, &base[n % baselen], 1) + count);
}

int	ft_putnbr(long long nbr)
{
	int			count;

	count = 0;
	if (nbr < 0)
	{	
		nbr = -nbr;
		count += write(1, "-", 1);
	}
	return (count + ft_putnbr_base(nbr, DEC, 10, 'd'));
}
