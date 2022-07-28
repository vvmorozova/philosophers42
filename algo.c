/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eward <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:25:07 by eward             #+#    #+#             */
/*   Updated: 2022/07/28 20:25:09 by eward            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, WHITE TAKE_LEFT_FORK, do_newtime(philo->input->start));
	pthread_mutex_lock(philo->right_fork);
	print_action(philo, WHITE TAKE_RIGHT_FORK,
		do_newtime(philo->input->start));
	print_action(philo, YELLOW EAT RESET, do_newtime(philo->input->start));
	philo->last_eat = do_newtime(philo->input->start);
	ft_usleep(philo->input->eat_time);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	think(t_philo *philo)
{
	print_action(philo, GREEN THINK RESET, do_newtime(philo->input->start));
}

void	go_to_sleep(t_philo *philo)
{
	print_action(philo, BLUE SLEEP RESET, do_newtime(philo->input->start));
	ft_usleep(philo->input->sleep_time);
}

void	*live(t_philo *philo)
{
	while (1)
	{
		eat(philo);
		philo->count_eat++;
		if (philo->input->add_eat != -1
			&& philo->count_eat == philo->input->add_eat)
			return (NULL);
		go_to_sleep(philo);
		think(philo);
	}
	return (NULL);
}

int	start_algo(t_program *program)
{
	int			i;
	pthread_t	servant;

	i = 0;
	if (pthread_create(&servant, NULL, (void *)did_all_eat, program) != SUCCESS)
		return (0);
	while (i < program->input->phil_num)
	{
		if (pthread_create(&program->philos[i].thread_id, NULL,
				(void *)live, &(program->philos[i])) != SUCCESS)
			return (0);
		ft_usleep(100);
		i++;
	}
	if (pthread_join(servant, NULL) != SUCCESS)
		return (0);
	return (1);
}
