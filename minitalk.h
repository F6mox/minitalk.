/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fal-kaf <fal-kaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:54:02 by fatima            #+#    #+#             */
/*   Updated: 2025/06/30 20:10:15 by fal-kaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "ft_printf/ft_printf.h"

void	send_char(pid_t server_pid, unsigned char c);
void	handle_signal(int sig);

#endif
