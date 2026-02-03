/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:06:42 by malavaud          #+#    #+#             */
/*   Updated: 2026/02/03 15:27:18 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(int server_pid, int bit)
{
	if (bit == 0)
		kill(server_pid, SIGUSR1);
	else
		kill(server_pid, SIGUSR2);
}

void 	send_char(int server_pid, char c)
{
	int		i;
	int		bit;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		send_bit(server_pid, bit);
		i--;
	}
}

void 	send_message(int server_pid, char *message)
{
	int 	i;

	i = 0;
	while (message[i])
	{
		send_char(server_pid, message[i]);
		i++;
	}
	send_char(server_pid, '\0');
}

int		main(int argc, char *argv[])
{
	int		server_pid;
	char	*message;

	if (argc != 3)
		return (1);

	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
		return (0);
	
	message = argv[2];
	send_message(server_pid, message);

	return (0);
}
