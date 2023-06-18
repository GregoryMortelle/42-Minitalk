/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmortel <grmortel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:58:01 by grmortel          #+#    #+#             */
/*   Updated: 2023/04/13 17:03:34 by grmortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*string;
	int		lenght;
	char	character;

	string = (char *)s;
	lenght = ft_strlen(string);
	character = (char)c;
	while (lenght >= 0)
	{
		if (string[lenght] == character)
			return (&string[lenght]);
		lenght--;
		if (lenght == -1)
			return (0);
	}
	return (0);
}
