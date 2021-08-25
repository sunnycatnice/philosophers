/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ../../includes/philo.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaderi <rpaderi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:52:17 by dmangola          #+#    #+#             */
/*   Updated: 2021/08/12 19:32:28 by rpaderi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
/*
** Flags for threads
*/

# define FORK_MSG 		0
# define EAT_MSG		1
# define SLEEP_MSG		2
# define THINKING_MSG	3
# define DEAD_MSG 		4
# define MUSTEAT_MSG	5

/*
** Error Codes
*/

# define ERR_0 "Error: wrong number of arguments. Must be 5 or 6.\n"
# define ERR_1 "Error: found a char in arguments\n"
# define ERR_2 "Error: insert a valid number.(s)\n"
# define ERR_3 "Error: Too much Philosopher bruh!\n"
# define ERR_4 "Error: Too few ms for die!\n"
# define ERR_5 "Error: Too few ms for eat!\n" 
# define ERR_6 "Error: Too few ms for sleeping!\n"
# define ERR_7 "Error: Too few Philosopher bruh\n"
# define ERR_8 "Error: Couldn't create mutex\n"

struct	s_data;

typedef struct s_philo
{
	int				pos;
	int				is_eating;
	uint64_t		limit;
	uint64_t		last_eat;
	int				lfork;
	int				rfork;
	int				eat_count;
	struct s_data	*state;
	pthread_mutex_t	eat_m;
	pthread_mutex_t	mtx;
}				t_philo;

typedef struct s_data
{
	int				n_philo;
	uint64_t		todie;
	uint64_t		toeat;
	uint64_t		tosleep;
	int				n_musteat;
	int				n_forchette;
	uint64_t		start;

	t_philo			*philos;
	pthread_mutex_t	*forks_m;
	pthread_mutex_t	can_print;
	pthread_mutex_t	somebody_dead_m;
}				t_data;

/* Lib */

int					ft_isdigit(char c);
int					is_space(char c);
int					is_neg(char c);
int					check_bychar(char const *c);
void				ft_putnbr_fd(uint64_t n, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);

/* Core */
void				ft_print_start_msg(void);
int					ft_parser_checker(int ac, char const **av, t_data *state);
void				ft_printerr(int err);
int					ft_strlen(char const *str);
int					check_string(int ac, char const **av);
long int			ft_atoi(const char *str);
void				ft_putnbr_fd(uint64_t n, int fd);
uint64_t			get_time(void);
int					clear_state(t_data *state);
int					exit_error(char const *str);
int					philo_start(t_data *state, int argc, char const **argv);
void				take_forks(t_philo *philo);
void				clean_forks(t_philo *philo);
void				eat(t_philo *philo);
void				show_msg(t_philo *philo, int type);

#endif
