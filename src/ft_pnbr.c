/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pnbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:01:27 by mzarichn          #+#    #+#             */
/*   Updated: 2022/11/12 12:03:59 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pnbr(int nbr)
{
	int		n_len;
	char	*n;

	n_len = 0;
	n = ft_itoa(nbr);
	n_len = ft_pstring(n);
	free(n);
	return (n_len);
}
