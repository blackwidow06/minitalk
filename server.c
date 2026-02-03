/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:09:57 by malavaud          #+#    #+#             */
/*   Updated: 2026/02/03 16:29:57 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	server(int signal)
{
	int		bit_count;
	int		current;

	current = (current << 1) | (signal == SIGUSR2);
	bit_count++;
	if (bit_count == 8)
	{
		if (current == '\0')
			write(1, "\n", 1);
		else 
			write(1, &current, 1);
		bit_count = 0;
		current = 0;
	}
}

int	main(void)
{
	ft_putnbr(getpid());
	write(1, "\n", 1);

	signal(SIGUSR1, server);
	signal(SIGUSR2, server);

	while (1)
		pause();
}