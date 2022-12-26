/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:48:28 by rkanmado          #+#    #+#             */
/*   Updated: 2022/12/26 07:42:22 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

time_t	current_time(void)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	return (current.tv_sec * 1000 + current.tv_usec / 1000);
}

time_t	elapsed_ms(void)
{
	static time_t	start;

	if (start == 0)
		start = current_time();
	return (current_time() - start);
}

time_t	elapsed_from_new_turn(t_b is_new_turn)
{
	static time_t	start;

	if (start == 0 && is_new_turn)
			start = current_time();
	return (current_time() - start);
}

int	msleep(unsigned int tms)
{
	return usleep(tms * 1000);
}
