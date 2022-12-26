/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 05:29:08 by rkanmado          #+#    #+#             */
/*   Updated: 2022/12/26 11:57:35 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

t_b	kill_processes(t_data *d, int thread_nbr)
{
	int	i;

	i = 0;
	while (i < thread_nbr)
	{
		if (kill(d->pids[i++], 9) != 0)
			return (false);
	}
	return (true);
}

void	free_table(t_data *d)
{
	free(d->pids);
	close_semaphores(d);
	return ;
}
