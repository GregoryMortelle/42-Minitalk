/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmortel <grmortel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:24:34 by grmortel          #+#    #+#             */
/*   Updated: 2023/04/18 19:31:56 by grmortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*string;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	while (s[i + start] && i != len)
		i++;
	string = malloc(sizeof(char) * i + 1);
	if (!string)
		return (NULL);
	i = 0;
	while (s[i + start] && i != len)
	{
		string[i] = s[i + start];
		i++;
	}
	string[i] = '\0';
	return (string);
}
