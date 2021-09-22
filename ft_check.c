/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 09:44:44 by lchristo          #+#    #+#             */
/*   Updated: 2021/09/20 11:24:10 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_letter(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalpha(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_int(long i)
{
	if (i > 2147483647)
		return (1);
	if (i < -2147483648)
		return (1);
	return (0);
}
