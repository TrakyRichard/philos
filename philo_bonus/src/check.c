/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 05:29:22 by rkanmado          #+#    #+#             */
/*   Updated: 2022/12/26 11:42:29 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	check_params(int arc)
{
	if (arc != 5 && arc != 6)
		error();
	return ;
}

t_b	open_sem(sem_t **sem, char *str, int value)
{
	*sem = sem_open(str, O_CREAT, S_IRWXU, value);
	if (*sem == SEM_FAILED)
		return (false);
	return (true);
}

t_b	open_sem_child(sem_t **sem, char *str, int value)
{
	*sem = sem_open(str, value);
	if (*sem == SEM_FAILED)
		return (false);
	return (true);
}
