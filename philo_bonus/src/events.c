/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:28:18 by rkanmado          #+#    #+#             */
/*   Updated: 2022/12/26 07:59:50 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	eating_event(t_data *d, int i)
{
	time_t	ms;
	t_philo	*ph;

	ph = &d->philos[i];
	sem_wait(d->i.eat_sem);
	if (ph->is_rf_taken && ph->is_lf_taken)
	{
		outlog(ph, "is eating");
		ph->meal_nbr++;
		if (ph->meal_nbr == d->philos[i].i->meal_required)
			d->philos[i].i->satiated_philos++;
		ms = elapsed_ms();
		ph->time_of_starvation = ms + d->philos[i].i->to_die;
		ph->last_meal_time = ms;
		msleep(d->philos[i].i->to_eat);
	}
	sem_post(d->i.eat_sem);
	return ;
}

void	sleeping_event(t_data *d, int i)
{
	t_philo	*ph;

	ph = &d->philos[i];
	sem_wait(d->i.sleep_sem);
	outlog(ph, "is sleeping");
	msleep(d->i.to_sleep);
	sem_post(d->i.sleep_sem);
	return ;
}

void	thinking_event(t_data *d, int i)
{
	t_philo	*ph;

	ph = &d->philos[i];
	outlog(ph, "is thinking");
	return ;
}
