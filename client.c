/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:10:35 by nhirzel           #+#    #+#             */
/*   Updated: 2021/12/17 19:05:19 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void	char_to_bit(int pid, char c)

{
	static int	j;

	j = 0;
	while (j < 8)
	{
		if ((c >> j) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				return ;
		}
		else
		{
			if (kill(pid, SIGUSR2))
				return ;
		}
		j++;
		usleep(100);
	}
}

void	handler(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		char_to_bit(pid, str[i]);
		i++;
	}
	char_to_bit(pid, '\n');
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	handler((ft_atoi(argv[1])), argv[2]);
	return (0);
}
