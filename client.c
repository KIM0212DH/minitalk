/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:33:15 by dokim2            #+#    #+#             */
/*   Updated: 2022/09/29 18:04:58 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	check_handler(int signo)
{
	if (signo == SIGUSR1)
		;
	else
		exit(1);
}

int	display(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	ft_printf("Client PID: %d\n", getpid());
	return (ft_atoi(argv[1]));
}

int	main(int argc, char **argv)
{
	unsigned long	idx;
	unsigned char	let;
	int				pid;
	int				i;
	char			*str;

	idx = 0;
	pid = display(argc, argv);
	str = argv[2];
	while (idx < ft_strlen(str) + 1)
	{
		let = str[idx++];
		i = 0;
		while (i < 8)
		{
			usleep(100);
			if ((let & (1 << i++)) != 0)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			signal(SIGUSR1, check_handler);
			pause();
		}
	}
}
