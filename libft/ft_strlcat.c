/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmortel <grmortel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 22:55:21 by grmortel          #+#    #+#             */
/*   Updated: 2023/04/13 23:39:58 by grmortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	source_len;

	i = 0;
	j = 0;
	dest_len = ft_strlen(dst);
	source_len = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (source_len);
	if (dstsize <= dest_len)
		return (dstsize + source_len);
	while (dst[i] && i < dstsize)
		i++;
	while (src[j] && i + 1 < dstsize)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dest_len + source_len);
}
