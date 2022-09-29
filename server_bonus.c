/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:16:26 by dokim2            #+#    #+#             */
/*   Updated: 2022/09/26 22:19:15 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_info g_info;

void print_reset(t_info *g_info)
{
	ft_printf("%c", g_info->letter);
	g_info->count = 0;
	g_info->letter = 0;
}

void handler(int signo, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	g_info.c_pid = info->si_pid;
	if (signo == SIGUSR1)
		g_info.sig_count++;
	if (signo == SIGUSR2)
	{
		g_info.letter += (1 << g_info.count);
		g_info.sig_count++;
	}
	g_info.count++;
	usleep(100);
	kill(g_info.c_pid, SIGUSR1);
	g_info.sig_count++;
	if (g_info.count == 8)
	{
		if (g_info.letter == '\0')
		{
			ft_printf("\nfrom client : %d\n", g_info.c_pid);
			ft_printf("interaction cnt : %d\n", g_info.sig_count);
			g_info.sig_count = 0;
		}
		print_reset(&g_info);
	}
}

int display_pid(void)
{
	char *pid;

	if (getpid() > MAX_PID || getpid() < MIN_PID)
		return (0);
	pid = ft_itoa(getpid());
	if (!pid)
		return (0);
	write(1, "Server PID : ", 13);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	free(pid);
	return (1);
}

int main(void)
{
	struct sigaction sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	g_info.count = 0;
	g_info.letter = 0;
	g_info.sig_count = 0;
	if (!display_pid())
	{
		write(1, "PID malloc error", 16);
		exit(1);
	}
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
}
