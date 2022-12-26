/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 05:30:39 by rkanmado          #+#    #+#             */
/*   Updated: 2022/12/26 08:21:31 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	parse(t_data *d, char *arg[])
{
	int	i;

	i = 1;
	init(d);
	while (arg[i] != NULL)
	{
		if (i == 1)
			parse_str(arg[i], &d->i.philo_nbr, i);
		else if (i == 2)
			parse_str(arg[i], &d->i.to_die, i);
		else if (i == 3)
			parse_str(arg[i], &d->i.to_eat, i);
		else if (i == 4)
			parse_str(arg[i], &d->i.to_sleep, i);
		else if (i == 5)
			parse_str(arg[i], &d->i.meal_required, i);
		i++;
	}
	return ;
}

void	parse_str(char *str, int *num, int index)
{
	*num = ft_atoi(str);
	if (*num == -1)
		err_msg(get_parsing_params(index), \
			"must be a positive number");
	else if (*num == -2)
		err_msg(get_parsing_params(index), \
			"must contain only numbers");
	else if (*num == -3)
		err_msg(get_parsing_params(index), \
			"is out of the range of integer");
	return ;
}

char	*get_parsing_params(int index)
{
	if (index == 0)
		return ("Number of philosophers");
	else if (index == 1)
		return ("Time to die");
	else if (index == 2)
		return ("time to eat");
	else if (index == 3)
		return ("time to sleep");
	else if (index == 3)
		return ("Number of time each philosophers must eat");
	else
		return (NULL);
}

void	escape_useless_char(char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	return ;
}

long long	ft_atoi(char *str)
{
	long long	num;

	num = 0;
	escape_useless_char(str);
	if (*str == '-')
		return (-1);
	while (*str)
	{
		if (*str < 48 || *str > 57)
			return (-2);
		num = 10 * num + (*str - '0');
		str++;
	}
	if (num <= INT32_MIN || num >= INT32_MAX)
		return (-3);
	return (num);
}
