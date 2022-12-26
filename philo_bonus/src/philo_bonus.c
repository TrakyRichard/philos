/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 05:30:22 by rkanmado          #+#    #+#             */
/*   Updated: 2022/12/26 09:14:53 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	main(int arc, char *arg[])
{
	t_data	d;

	check_params(arc);
	parse(&d, arg);
	init_table(&d);
	close_semaphores(&d);
	if (create_processes(&d) == false)
		error();
	monitor(&d);
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
