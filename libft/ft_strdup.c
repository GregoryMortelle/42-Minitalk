/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmortel <grmortel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:45:06 by grmortel          #+#    #+#             */
/*   Updated: 2023/04/11 19:03:28 by grmortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	lenght;
	char	*string;

	i = 0;
	lenght = ft_strlen(s);
	string = malloc(lenght + 1 * sizeof(char));
	if (!string)
		return (0);
	while (i < lenght)
	{
		string[i] = s[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}
