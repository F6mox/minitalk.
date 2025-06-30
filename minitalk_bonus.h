/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fal-kaf <fal-kaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:53:50 by fatima            #+#    #+#             */
/*   Updated: 2025/06/30 20:10:11 by fal-kaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "ft_printf/ft_printf.h"

void	send_char(pid_t server_pid, unsigned char c);
void	handle_ack(int sig);
void	handle_signal(int sig, siginfo_t *info, void *context);

#endif
