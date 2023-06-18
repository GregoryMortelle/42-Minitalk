/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmortel <grmortel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:35:15 by grmortel          #+#    #+#             */
/*   Updated: 2023/04/18 18:53:50 by grmortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length_string(int n)
{
	int	length;

	length = 0;
	if (n == 0)
		length = 1;
	while (n)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	int				length;
	unsigned int	tmp;
	char			*string;

	length = length_string(n);
	tmp = n;
	if (n < 0)
	{
		length++;
		tmp = -tmp;
	}
	string = malloc(sizeof(*string) * (length + 1));
	if (!string)
		return (NULL);
	string[length] = '\0';
	while (length)
	{
		string[length - 1] = tmp % 10 + '0';
		tmp = tmp / 10;
		length--;
	}
	if (n < 0)
		string[0] = '-';
	return (string);
}
