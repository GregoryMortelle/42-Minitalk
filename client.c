/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmortel <grmortel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:28:42 by grmortel          #+#    #+#             */
/*   Updated: 2023/06/19 01:37:27 by grmortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1 << i)
		{
			if (pid != -1)
				kill(pid, SIGUSR1);
		}
		else
		{
			if (pid != -1)
				kill(pid, SIGUSR2);
		}
		i++;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	if (ac != 3)
	{
		ft_printf("Mhhh retry ?\n");
		return (0);
	}
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
			return (1);
		while (av[2][i])
			ft_send(pid, av[2][i++]);
		ft_send(pid, '\n');
	}
	else
	{
		ft_printf("Mhhh nope\n");
		ft_printf("Try : ./client [PID] [message]\n");
		return (1);
	}
	return (0);
}
