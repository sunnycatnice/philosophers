/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaderi <rpaderi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 13:31:31 by rpaderi           #+#    #+#             */
/*   Updated: 2021/08/14 16:59:30 by rpaderi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

static void	*notinfinite_loop(void *state_v)
{
	t_data	*state;
	int		i;
	int		total;

	state = (t_data *)state_v;
	total = 0;
	while (total < state->n_musteat)
	{
		i = 0;
		while (i < state->n_philo)
			pthread_mutex_lock(&state->philos[i++].eat_m);
		total++;
	}
	show_msg(&state->philos[0], MUSTEAT_MSG);
	pthread_mutex_unlock(&state->someone_died);
	return ((void *)0);
}

static void	*monitor(void *philo_v)
{
	t_philo		*philo;

	philo = (t_philo *)philo_v;
	while (1)
	{
		pthread_mutex_lock(&philo->mtx);
		if (!philo->is_eating && get_time() >= philo->limit)
		{
			show_msg(philo, DEAD_MSG);
			pthread_mutex_unlock(&philo->mtx);
			pthread_mutex_unlock(&philo->state->someone_died);
			return ((void *)0);
		}
		pthread_mutex_unlock(&philo->mtx);
		usleep(500);
	}
}

static void	*infinite_loop(void *philo_v)
{
	t_philo		*philo;
	pthread_t	tid;

	philo = (t_philo *)philo_v;
	philo->last_eat = get_time();
	philo->limit = philo->last_eat + philo->state->todie;
	if (pthread_create(&tid, NULL, &monitor, philo_v) != 0)
		return ((void *)1);
	pthread_detach(tid);
	while (1)
	{
		take_forks(philo);
		eat(philo);
		clean_forks(philo);
		show_msg(philo, THINKING_MSG);
	}
	return ((void *)0);
}

static int	boot_thr(t_data *state)
{
	int			i;
	pthread_t	tid;
	void		*philo;

	state->start = get_time();
	if (state->n_musteat > 0)
	{
		if (pthread_create(&tid, NULL, &notinfinite_loop, (void *)state) != 0)
			return (1);
		pthread_detach(tid);
	}
	i = 0;
	while (i < state->n_philo)
	{
		philo = (void *)(&state->philos[i]);
		if (pthread_create(&tid, NULL, &infinite_loop, philo) != 0)
			return (1);
		pthread_detach(tid);
		usleep(100);
		i++;
	}
	return (0);
}

int
	main(int argc, char const **argv)
{
	t_data	state;

	ft_print_start_msg();
	if (argc == 5 || argc == 6)
		ft_parser_checker(argc, argv, &state);
	else
		ft_printerr(0);
	if (philo_start(&state, argc, argv))
		return (clear_state(&state) && exit_error("error: fatal\n"));
	if (boot_thr(&state))
		return (clear_state(&state) && exit_error("error: fatal\n"));
	pthread_mutex_lock(&state.someone_died);
	pthread_mutex_unlock(&state.someone_died);
	clear_state(&state);
	return (0);
}
