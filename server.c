/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmortel <grmortel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:22:24 by grmortel          #+#    #+#             */
/*   Updated: 2023/06/19 01:35:07 by grmortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_signal(int sign)
{
	static int	i;
	static char	c;

	if (sign == SIGUSR1)
		c |= 1 << i;
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf(ANSI_COLOR_YELLOW "Current PID : %d\n" ANSI_COLOR_YELLOW, pid);
	ft_printf(ANSI_COLOR_GREEN "Can you send a message ?\n" ANSI_COLOR_RESET);
	ft_printf(ANSI_COLOR_GREEN "-----------------------|\n" ANSI_COLOR_RESET);
	while (1)
	{
		signal(SIGUSR1, ft_signal);
		signal(SIGUSR2, ft_signal);
		pause();
	}
	return (0);
}
