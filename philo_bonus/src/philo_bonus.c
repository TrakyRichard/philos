/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 05:30:22 by rkanmado          #+#    #+#             */
/*   Updated: 2022/12/26 13:50:38 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	main(int arc, char *arg[])
{
	t_data		d;

	check_params(arc);
	parse(&d, arg);
	if (!init_table(&d))
		err_msg("Init failed", "data initialisation failed");
	if (create_processes(&d) == false)
		err_msg("process failed", "process creation failed");
	if (pthread_create(&d.th, NULL, &monitor, (void *) &d) != 0)
		err_msg("Thread failed", "error while creating the thread");
	free_table(&d);
	return (0);
}

// int	main(int arc, char *arg[])
// {
// 	t_data	*d;

// 	d = (t_data *) malloc(sizeof(t_data));
// 	if (d == NULL)
// 		return (1);

// 	check_params(arc);
// 	parse(d, arg);
// 	close_semaphores(d);
// 	init_table(d);
// 	if (create_processes(d) == false)
// 		error();
// 	monitor(d);
// 	free_table(d);
// 	return (0);
// }
