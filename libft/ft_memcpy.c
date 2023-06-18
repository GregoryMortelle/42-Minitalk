/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmortel <grmortel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:27:41 by grmortel          #+#    #+#             */
/*   Updated: 2023/04/18 00:12:11 by grmortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*destination;
	unsigned char	*source;

	if (!dst && !src)
		return (0);
	i = 0;
	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (n > i)
	{
		destination[i] = source[i];
		i++;
	}
	return (destination);
}
