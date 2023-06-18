/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmortel <grmortel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:26:44 by grmortel          #+#    #+#             */
/*   Updated: 2023/04/11 10:52:24 by grmortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*string;
	char	character;

	i = 0;
	string = (char *)s;
	character = c;
	while (string[i])
	{
		if (string[i] == character)
			return (&string[i]);
		i++;
	}
	if (character == '\0')
		return (&string[i]);
	return (0);
}
