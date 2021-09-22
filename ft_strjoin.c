/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 04:28:24 by lchristo          #+#    #+#             */
/*   Updated: 2021/08/30 14:02:10 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		y;

	s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	y = 0;
	while (s1[i] != '\0')
	{
		s[y] = s1[i];
		i++;
		y++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		s[y] = s2[i];
		y++;
		i++;
	}
	s[y] = '\0';
	return (s);
}
