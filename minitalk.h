/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:10:00 by malavaud          #+#    #+#             */
/*   Updated: 2026/02/03 16:30:09 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <limits.h>

/* client.c */
void	send_bit(int server_pid, int bit);
void 	send_message(int server_pid, char *message);
void 	send_char(int server_pid, char c);

/* server.c */
void	server(int signal);

/* utils.c */
void	ft_putnbr(int nb);
int		ft_atoi(const char *str);

/* check.c */
int check_pid(char *str);
int check_pid_max(char *str);

#endif
