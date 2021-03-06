/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 01:38:40 by lchristo          #+#    #+#             */
/*   Updated: 2021/08/30 14:58:08 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_clean(t_pft *one)
{
	one->pres1 = 0;
	one->truepres1 = 0;
	one->truepres2 = 0;
	one->decal = 0;
	one->display = 0;
	one->p1 = 1;
	one->p2 = 1;
	one->point = 0;
	one->zero = 0;
	one->null = 0;
	one->pres1neg = 0;
	one->pres2 = 0;
	one->pres2neg = 0;
	one->resultneg = 0;
	one->resaff = 0;
	one->flag = 0;
	one->dot = 0;
	one->star = 0;
	one->minus = 0;
}

void	ft_errors(const char *s, t_pft *one)
{
	char	a;
	char	b;

	if (s[one->index] == '0' && s[one->index + 1] == '-')
		one->index += 1;
	if (s[one->index] == '-' && s[one->index + 1] == '.')
		one->index += 1;
	a = s[one->index];
	b = s[one->index + 2];
	while (a == s[one->index + 1] && !ft_checkdisplay(a))
	{
		if (!ft_checkflag(a))
			break ;
		one->index++;
		a = s[one->index];
	}
	while (a == b && s[one->index + 1] == s[one->index + 3])
	{
		if (ft_checkdisplay(a) || ft_checkdisplay(s[one->index + 1]))
			break ;
		one->index += 4;
		a = s[one->index];
		b = s[one->index + 2];
	}
}

void	ft_var(const char *s, va_list *ap, t_pft *one)
{
	ft_errors(s, one);
	if (s[one->index] == 'x')
		ft_puthexa(va_arg(*ap, unsigned int), one);
	if (s[one->index] == 'X')
		ft_puthexa_maj(va_arg(*ap, unsigned int), one);
	if (s[one->index] == 'u')
		ft_putu(va_arg(*ap, unsigned long), one);
	if (ft_alpha(s[one->index]))
		ft_star(s, ap, one);
	if (s[one->index] == '\0')
		one->index--;
	ft_varum(s, ap, one);
}

void	ft_detection(const char *s, va_list *ap, t_pft *one)
{
	one->index = 0;
	while (s[one->index] != '\0')
	{
		ft_clean(one);
		if (s[one->index] == '%')
		{
			one->index++;
			ft_var(s, ap, one);
		}
		else
			ft_putchar_pf(s[one->index], one);
		one->index++;
	}
}

int	ft_printf(const char *s, ...)
{
	va_list		ap;
	t_pft		one;

	va_start(ap, s);
	one.cpt = 0;
	ft_detection(s, &ap, &one);
	va_end(ap);
	return (one.cpt);
}
