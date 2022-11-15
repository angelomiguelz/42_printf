/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:11:53 by mzarichn          #+#    #+#             */
/*   Updated: 2022/11/12 12:43:01 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_phex_len(unsigned int nbr)
{
	int	n_len;

	n_len = 0;
	while (nbr != 0)
	{
		nbr /= 16;
		n_len++;
	}
	return (n_len);
}

void	ft_phex_f(unsigned int nbr, const char varf)
{
	if (nbr >= 16)
	{
		ft_phex_f(nbr / 16, varf);
		ft_phex_f(nbr % 16, varf);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd((nbr + '0'), 1);
		else
		{
			if (varf == 'x')
				ft_putchar_fd((nbr - 10 + 'a'), 1);
			if (varf == 'X')
				ft_putchar_fd((nbr - 10 + 'A'), 1);
		}
	}
}

int	ft_phex(unsigned int nbr, const char varf)
{
	if (nbr == 0)
		return (write(1, "0", 1));
	else
		ft_phex_f(nbr, varf);
	return (ft_phex_len(nbr));
}
