/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaderi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:52:17 by dmangola          #+#    #+#             */
/*   Updated: 2021/07/29 15:45:58 by rpaderi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <time.h>

# define ERR_0 "Error: wrong number of arguments. Must be 5 or 6.\n"
# define ERR_1 "Error: found a char in arguments\n"
# define ERR_2 "Error: insert a valid number.(s)\n"
# define ERR_3 "Error: Too much Philosopher bruh!\n"
# define ERR_4 "Error: Too much low ms for die!\n"
# define ERR_5 "Error: Too much low ms for eat!\n" 
# define ERR_6 "Error: Too much low ms for sleeping!\n"
# define ERR_7 "Error: Too few Philosopher bruh\n"

typedef struct s_philo
{
	int				n_philo;
	int				n_forchette;
	int				todie;
	int				toeat;
	int				tosleep;
	int				n_musteat;
	pthread_mutex_t	*forchetta;
	int				i;
	pthread_t		tid;
	pthread_mutex_t	**lock;
}				t_philo;

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

/*
** Philo functions
*/
int			check_bychar(char *c);
int			check_string(int ac, char **av);
void		ft_printerr(int err);
void		ft_init(t_philo *philo);
void		ft_print_start_msg(void);
void		ft_checker(t_philo *philo);
int			ft_parser_checker(int ac, char **av, t_philo *philo);

#endif
