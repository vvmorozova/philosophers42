/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eward <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:00:30 by eward             #+#    #+#             */
/*   Updated: 2022/07/28 15:00:39 by eward            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>

# define SUCCESS 0
# define FAILURE 1
# define BAD_RESULT -1
# define MAX_INT 2147483647
# define MIN_INT -2147483648

# define PURPLE "\033[0;35m" //death
# define RED "\033[0;31m" //error
# define GREEN "\033[0;32m" // think
# define YELLOW "\033[0;33m" // eat
# define BLUE "\033[0;34m" // sleep
# define CYAN "\033[0;36m" // full
# define RESET "\033[1;33m"
# define WHITE "\033[0;37m"

# define DIED "%6lu Philosofer %d  died\n"
# define EAT "%6lu %3d   is eating\n"
# define SLEEP "%6lu %3d   is sleeping\n"
# define THINK "%6lu %3d   is thinking\n"
# define TAKE_RIGHT_FORK "%6lu %3d   has taken a right fork\n"
# define TAKE_LEFT_FORK "%6lu %3d   has taken a left fork\n"

typedef struct s_input
{
	int				phil_num;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				add_eat;
	time_t			start;
}	t_input;

typedef struct s_servant
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}	t_servant;

typedef struct s_philo
{
	int				index;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread_id;
	int				is_dead;
	time_t			last_eat;
	int				count_eat;
	int				stop;
	t_input			*input;
	t_servant		*servant;
}	t_philo;

typedef struct s_program
{
	t_input		*input;
	t_philo		*philos;
	t_servant	*servant;
}	t_program;

time_t	do_newtime(time_t start);
void	*ft_calloc(size_t count, size_t size);
int		init_program(t_program *program);
int		ft_print_error(char *error_text);
int		put_values(t_input *input, int argc, char **argv);
int		my_atoi(char *str);
int		status_init(t_program *program);
int		philo_init(t_program *program, int i);
int		start_algo(t_program *program);
void	*did_all_eat(t_program *program);
void	print_action(t_philo *philo, char *text, time_t time);
void	ft_usleep(time_t time);

#endif
