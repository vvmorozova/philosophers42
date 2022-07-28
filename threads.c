/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eward <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:25:22 by eward             #+#    #+#             */
/*   Updated: 2022/07/28 20:25:23 by eward            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, char *text, time_t time)
{
	pthread_mutex_lock(&philo->servant->print);
	printf(text, time, philo->index);
	if (!philo->is_dead)
		pthread_mutex_unlock(&philo->servant->print);
}

int	check_death(t_program *process, int i)
{
	time_t	time_to_live;

	time_to_live = do_newtime(process->input->start)
		- process->philos[i].last_eat;
	if (time_to_live > process->input->die_time
		&& process->philos[i].stop != 1)
	{
		process->philos[i].is_dead = 1;
		print_action(&process->philos[i], PURPLE DIED,
			do_newtime(process->input->start));
		return (FAILURE);
	}
	return (SUCCESS);
}

void	*did_all_eat(t_program *program)
{
	int	i;
	int	everyone_is_full;

	while (1)
	{
		everyone_is_full = 0;
		i = 0;
		while (i < program->input->phil_num)
		{
			if (program->input->add_eat != -1 && \
			program->philos[i].count_eat >= program->input->add_eat)
			{
				everyone_is_full++;
				program->philos[i].stop = 1;
			}
			if (check_death(program, i))
				return (NULL);
			i++;
		}
		if (everyone_is_full == program->input->phil_num)
			return (NULL);
	}
	return (NULL);
}
