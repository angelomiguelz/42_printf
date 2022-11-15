/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_punsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:49:08 by mzarichn          #+#    #+#             */
/*   Updated: 2022/11/12 12:56:28 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_n_len(unsigned	int nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

char	*ft_u_itoa(unsigned int nbr)
{
	char	*n;
	int		len;

	len = ft_n_len(n);
	n = (char *)malloc(sizeof(char) * (len + 1));
	if (!n)
		return (0);
	n[len] = '\0';
	while (nbr != 0)
	{
		n[len - 1] = nbr % 10 + 48;
		nbr = nbr / 10;
		len--;
	}
	return (n);
}

int	ft_punsigned(unsigned int nbr)
{
	int		p_len;
	char	*n;

	p_len = 0;
	if (nbr == 0)
		p_len += write(1, "0", 1);
	else
	{
		n = ft_u_itoa(nbr);
		p_len += ft_pstring(n);
		free(n);
	}
	return (p_len);
}
