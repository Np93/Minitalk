/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:14:04 by nhirzel           #+#    #+#             */
/*   Updated: 2021/12/17 19:07:09 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	conv_bit(int signal)

{
	static int	value = 0;
	static int	bit = 0;

	if (signal == SIGUSR1)
		value += 1 << bit;
	bit += 1;
	if (bit == 8)
	{
		ft_putchar_fd(value, 1);
		bit = 0;
		value = 0;
	}
}

int	main(void)
{
	int	pid;

	write(1, "PID: ", 5);
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, conv_bit);
	signal(SIGUSR2, conv_bit);
	while (1)
		sleep(1000);
	return (0);
}
