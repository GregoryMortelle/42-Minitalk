/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmortel <grmortel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:53:00 by grmortel          #+#    #+#             */
/*   Updated: 2023/04/18 19:30:07 by grmortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	long long	result;
	long long	tmp;
	int			sign;

	while (ft_whitespace(*nptr) == 1)
		nptr++;
	sign = 1;
	if (*nptr == 43 || *nptr == 45)
	{
		if (*nptr++ == 45)
			sign = -1;
	}
	result = 0;
	while (*nptr && *nptr >= 48 && *nptr <= 57)
	{
		tmp = result;
		result = (result * 10) + (*nptr++ - 48);
		if (result < tmp && sign == 1)
			return (-1);
		if (result < tmp && sign == -1)
			return (0);
	}
	if (sign)
		result *= sign;
	return ((int)(result));
}
