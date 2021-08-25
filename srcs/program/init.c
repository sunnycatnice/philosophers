/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaderi <rpaderi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:52:15 by rpaderi           #+#    #+#             */
/*   Updated: 2021/08/12 19:32:27 by rpaderi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	check_string(int ac, char const **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (check_bychar(av[i]) == 1)
		{
			ft_printerr(1);
			exit (1);
		}
		i++;
	}
	return (0);
}

static int	init_mutexes(t_data *state)
{
	int	i;

	pthread_mutex_init(&state->can_print, NULL);
	pthread_mutex_init(&state->somebody_dead_m, NULL);
	pthread_mutex_lock(&state->somebody_dead_m);
	state->forks_m = (pthread_mutex_t *)malloc(sizeof(*(state->forks_m)) * \
		state->n_philo);
	if (!(state->forks_m))
		return (1);
	i = 0;
	while (i < state->n_philo)
		pthread_mutex_init(&state->forks_m[i++], NULL);
	return (0);
}

static void	init_philos(t_data *state)
{
	int	i;

	i = 0;
	while (i < state->n_philo)
	{
		state->philos[i].is_eating = 0;
		state->philos[i].pos = i;
		state->philos[i].lfork = i;
		state->philos[i].rfork = (i + 1) % state->n_philo;
		state->philos[i].eat_count = 0;
		state->philos[i].state = state;
		pthread_mutex_init(&state->philos[i].mtx, NULL);
		pthread_mutex_init(&state->philos[i].eat_m, NULL);
		pthread_mutex_lock(&state->philos[i].eat_m);
		i++;
	}
}

int	philo_start(t_data *state, int argc, char const **argv)
{
	check_string(argc, argv);
	state->n_philo = ft_atoi(argv[1]);
	state->todie = ft_atoi(argv[2]);
	state->toeat = ft_atoi(argv[3]);
	state->tosleep = ft_atoi(argv[4]);
	if (argc == 6)
		state->n_musteat = ft_atoi(argv[5]);
	else
		state->n_musteat = 0;
	state->forks_m = NULL;
	state->philos = NULL;
	state->philos = (t_philo *)malloc(sizeof(*(state->philos)) * \
		state->n_philo);
	if (!(state->philos))
		return (1);
	init_philos(state);
	return (init_mutexes(state));
}
