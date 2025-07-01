/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fal-kaf <fal-kaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:54:48 by fatima            #+#    #+#             */
/*   Updated: 2025/06/30 23:31:32 by fal-kaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int sig)
{
	static unsigned char	current_char = 0;
	static int				bit_index = 0;

	current_char <<= 1;
	if (sig == SIGUSR2)
		current_char |= 1;
	bit_index++;
	if (bit_index == 8)
	{
		write(1, &current_char, 1);
		bit_index = 0;
		current_char = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf ("Server PID: %d\n", pid);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
