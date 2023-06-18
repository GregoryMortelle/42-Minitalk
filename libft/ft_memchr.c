/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmortel <grmortel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 10:37:23 by grmortel          #+#    #+#             */
/*   Updated: 2023/04/18 19:18:00 by grmortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*string;
	unsigned char	character;

	i = 0;
	string = (unsigned char *)s;
	character = (unsigned char)c;
	while (i < n)
	{
		if (string[i] == character)
			return (&string[i]);
		i++;
	}
	return (0);
}
