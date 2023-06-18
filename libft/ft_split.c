/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmortel <grmortel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:26:16 by grmortel          #+#    #+#             */
/*   Updated: 2023/04/18 00:00:04 by grmortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_string_length(const char *str, char c)
{
	size_t	i;
	size_t	length;

	if (!str)
		return (0);
	i = 0;
	length = 1;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			length++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (length);
}

static char	*ft_extract(const char *str, char c)
{
	size_t	len;
	char	*substr;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (0);
	ft_strlcpy(substr, str, len + 1);
	return (substr);
}

static char	**ft_free(char **split, size_t i)
{
	while (i)
	{
		i--;
		free(split[i]);
	}
	free(split);
	return (0);
}

char	**ft_split(const char *str, char c)
{
	char	**split;
	size_t	i;
	size_t	j;

	split = malloc(ft_string_length(str, c) * sizeof(char *));
	if (!str || !split)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
		{
			split[j] = ft_extract(&str[i], c);
			if (!split[j])
				return (ft_free(split, j));
			j++;
		}
		while (str[i] && str[i] != c)
			i++;
	}
	split[j] = 0;
	return (split);
}
