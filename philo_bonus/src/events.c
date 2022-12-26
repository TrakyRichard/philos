/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:28:18 by rkanmado          #+#    #+#             */
/*   Updated: 2022/12/26 12:29:13 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	eating_event(t_data *d)
{
	time_t	ms;
	t_philo	*ph;

	ph = &d->ph;
	sem_wait(d->i.eat_sem);
	if (ph->is_rf_taken && ph->is_lf_taken)
	{
		outlog(d, "is eating");
		ph->meal_nbr++;
		if (ph->meal_nbr == d->i.meal_required)
			d->i.satiated_philos++;
		ms = elapsed_ms();
		ph->time_of_starvation = ms + d->i.to_die;
		ph->last_meal_time = ms;
		msleep(d->i.to_eat);
	}
	sem_post(d->i.eat_sem);
	return ;
}

void	sleeping_event(t_data *d)
{
	sem_wait(d->i.sleep_sem);
	outlog(d, "is sleeping");
	msleep(d->i.to_sleep);
	sem_post(d->i.sleep_sem);
	return ;
}

t_b	take_forks(t_data *d)
{
	sem_wait(d->i.forks);
	d->ph.is_lf_taken = true;
	outlog(d, "has taken left fork");
	sem_wait(d->i.forks);
	d->ph.is_rf_taken = true;
	outlog(d, "has taken right fork");
	return (true);
}

t_b	drop_forks(t_data *d)
{
	sem_post(d->i.forks);
	d->ph.is_rf_taken = false;
	outlog(d, "dropped the right fork");
	sem_post(d->i.forks);
	d->ph.is_lf_taken = false;
	outlog(d, "dropped the left fork");
	return (true);
}

void	thinking_event(t_data *d)
{
	outlog(d, "is thinking");
	return ;
}
