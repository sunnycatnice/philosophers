/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaderi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:52:17 by dmangola          #+#    #+#             */
/*   Updated: 2021/07/30 20:16:22 by rpaderi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*
** Libraries
*/

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>

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

/*
** Flags for threads
*/

# define EATING 	0
# define SLEEPING	1
# define TAKIN_FORK	2
# define THINKING	3
# define DIED	 	4
# define DONE	 	5

/*
** Structs
*/

typedef struct		s_philo
{
	int				position;
	int				is_eating;
	uint64_t		limit;
	uint64_t		last_eat;
	int				lfork;
	int				rfork;
	int				eat_count;
	struct s_data	*data;
	pthread_mutex_t	mutex;
	pthread_mutex_t	eat_mutex;
}					t_philo;

typedef struct 		s_data
{
	int				n_philo;
	int				n_forchette;
	uint64_t		todie;
	uint64_t		toeat;
	uint64_t		tosleep;
	int				n_musteat;

	pthread_t		tid;
	uint64_t		start;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*dead_mutex;
	int				i;
	t_philo			*philos;
}					t_data;

/*
** phread_utils
*/

int			pthread_mutex_init(pthread_mutex_t *mutex,
				const pthread_mutexattr_t *mattr);
/*
** MiniLibft functions
*/

void		ft_putchar_fd(char c, int fd);
long int	ft_atoi(const char *str);
void		ft_putstr_fd(char const *s, int fd);
char		**ft_split(char const *s, char c);
char		*ft_strcat(char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
void		ft_strdel(char **as);
char		*ft_strdup(const char *s1);
void		*ft_memalloc(size_t size);
int			ft_isdigit(char c);
void		ft_bzero(void *s, size_t n);
size_t		ft_strcpy(char *dst, const char *src);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
uint64_t	get_time(void);
void		sleep_ms(int ms);

/*
** Philo functions
*/

int			check_bychar(char *c);
int			check_string(int ac, char **av);
void		ft_printerr(int err);
void		ft_init(t_data *philo);
void		ft_print_start_msg(void);
void		ft_checker(t_data *philo);
int			ft_parser_checker(int ac, char **av, t_data *philo);
int			ft_philo(t_data *philo, pthread_t tid);
void		ft_threads(t_data *philo);
void		ft_create_mutex(t_data *philo);

void		*ft_infinite_loop(t_data *data);
void		*ft_musteat(t_data *data);
int			ft_start_philo(t_data *data);
#endif
