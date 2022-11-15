/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:14:36 by mzarichn          #+#    #+#             */
/*   Updated: 2022/11/12 12:56:37 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_pchar(int c);
int		ft_pstring(char *s);
int		ft_varf(va_list args, const char varf);
int		ft_pnbr(int nbr);
int		ft_phex(unsigned int nbr, const char varf);
void	ft_phex_f(unsigned int nbr, const char varf);
int		ft_phex_len(unsigned int nbr);
int		ft_ppercent(void);
int		ft_punsigned(unsigned int nbr);
int		ft_n_len(unsigned	int nbr);
char	*ft_u_itoa(unsigned int nbr);

#endif