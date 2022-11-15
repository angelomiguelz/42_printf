/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:58:26 by mzarichn          #+#    #+#             */
/*   Updated: 2022/11/12 13:04:36 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(unsigned long long ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		len++;
		ptr = ptr / 16;
	}
	return (len);
}

void	ft_put_ptr(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_put_ptr(ptr / 16);
		ft_put_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd((ptr + '0'), 1);
		else
			ft_putchar_fd((ptr - 10 + 'a'), 1);
	}
}

int	ft_pptr(unsigned long long ptr)
{
	int	p_len;

	p_len = 0;
	p_len += write(1, "0x", 2);
	if (ptr == 0)
		p_len += write(1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		p_len += ft_ptr_len(ptr);
	}
	return (p_len);
}
