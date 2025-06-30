/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fal-kaf <fal-kaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:53:21 by fatima            #+#    #+#             */
/*   Updated: 2025/06/30 20:10:18 by fal-kaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int				bit_index = 0;
	static unsigned char	current_char = 0;

	(void)context;
	current_char <<= 1;
	if (sig == SIGUSR2)
		current_char |= 1;
	bit_index++;
	if (bit_index == 8)
	{
		if (current_char == '\0')
		{
			ft_printf("\n[Server] End of message ✅\n");
			if (info)
				kill(info->si_pid, SIGUSR1);
		}
		else
			ft_printf("%c", current_char);
		bit_index = 0;
		current_char = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
