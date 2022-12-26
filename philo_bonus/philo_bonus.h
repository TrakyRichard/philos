/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 05:31:20 by rkanmado          #+#    #+#             */
/*   Updated: 2022/12/25 18:07:44 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <sys/stat.h>
# include <signal.h>
# define MUTEXES 6

# define START_SEM  "start_sem"
# define SLEEP_SEM  "sleep_sem"
# define EAT_SEM    "eat_sem"
# define STARV_SEM  "starv_sem"
# define OUT_SEM    "out_sem"
# define DEATH_SEM  "death_sem"
# define FORKS      "forks"

typedef enum s_bool
{
	false,
	true
}	t_b;

typedef struct s_info
{
	int				philo_nbr;
	int				to_die;
	int				to_eat;
	int				to_sleep;
	int				satiated_philos;
	int				meal_required;
	sem_t			*death_sem;
	sem_t			*forks;
	sem_t			*start_sem;
	sem_t			*sleep_sem;
	sem_t			*eat_sem;
	sem_t			*starv_sem;
	sem_t			*out_sem;
}	t_i;

typedef struct s_data
{
	t_i				i;
	t_philo			ph;
}	t_data;

typedef struct s_philo
{
	int				id;
	pid_t			pid;
	t_b				is_rf_taken;
	t_b				is_lf_taken;
	time_t			time_of_starvation;
	time_t			last_meal_time;
	int				meal_nbr;
}	t_philo;

int			main(int arc, char *arg[]);

/* src/check.c */
void		check_params(int arc);
t_b			open_sem_main(sem_t **sem, char *str, int value);
t_b			open_sem_child(sem_t **sem, char *str, int value);

/* src/io.c */
void		error(void);
void		usage(void);
void		err_msg(char *title, char *message);
void		outlog(t_philo *ph, char *mes);

/* src/init.c */
void		init(t_data *d);
void		init_philos(t_data *d);
t_b			alloc_philos_and_forks(t_data *d);
void		init_table(t_data *d);
t_b			init_main_semaphores(t_data *d);
t_b			init_child_semaphores(t_data *d);


/* src/parse.c */
void		parse(t_data *d, char *arg[]);
void		parse_str(char *str, int *num, int index);
long long	ft_atoi(char *str);
void		escape_useless_char(char *str);
char		*get_parsing_params(int index);

/* src/routine */
void		*thread_routine(void *arg);
t_b			create_processes(t_data *d);
t_b			take_forks(t_data *d, int i);
void		routine(t_data *d, int i);

/* src/free.c */
void		free_table(t_data *d);

/* src/events.c */
void		eating_event(t_data *d, int i);
void		satiation_event(t_data *d, int i);
void		sleeping_event(t_data *d, int i);
void		thinking_event(t_data *d, int i);

/* src/destroy.c */
t_b			drop_forks(t_data *d, int i);
t_b			destroy_sems(t_data *d, int nbr_to_del);
t_b			kill_processes(t_data *d, int thread_nbr);
t_b			unlink_semaphores(void);
void		close_semaphores(t_data *d);

/* src/time.c */
time_t		current_time(void);
time_t		elapsed_ms(void);
int			msleep(unsigned int tms);

/* src/monitor */
void		monitor(t_data *d);
t_b			can_continue(t_philo *ph);

#endif
