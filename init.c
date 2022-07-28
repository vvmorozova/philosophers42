/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eward <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:25:56 by eward             #+#    #+#             */
/*   Updated: 2022/07/28 20:25:58 by eward            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_program(t_program *program)
{
	memset(program, 0, sizeof(t_program));
	program->input = (t_input *)malloc(sizeof(t_input));
	if (!program->input)
		return (0);
	memset(program->input, 0, sizeof(t_input));
	return (1);
}

int	is_valid(int argc, char *argv[])
{
	if (my_atoi(argv[1]) < 1 || my_atoi(argv[2]) < 0 || my_atoi(argv[3]) < 0
		|| my_atoi(argv[4]) < 0 || (argc == 6 && my_atoi(argv[5]) < 1))
		return (0);
	return (1);
}

int	put_values(t_input *input, int argc, char **argv)
{
	if (!is_valid(argc, argv))
		return (0);
	input->phil_num = my_atoi(argv[1]);
	input->die_time = my_atoi(argv[2]);
	input->eat_time = my_atoi(argv[3]);
	input->sleep_time = my_atoi(argv[4]);
	if (argc == 6)
		input->add_eat = my_atoi(argv[5]);
	else
		input->add_eat = -1;
	input->start = do_newtime(0);
	return (1);
}

int	status_init(t_program *program)
{
	int	i;

	i = 0;
	program->servant = (t_servant *)ft_calloc(sizeof(t_servant), 1);
	if (program->servant != NULL)
	{
		if (pthread_mutex_init(&program->servant->print, NULL))
			return (0);
		program->servant->forks = malloc(sizeof(pthread_mutex_t)
				* program->input->phil_num);
	}
	if (program->servant == NULL || program->servant->forks == NULL)
		return (0);
	while (i < program->input->phil_num)
	{
		if (pthread_mutex_init(&program->servant->forks[i], NULL))
			return (0);
		i++;
	}
	return (1);
}

int	philo_init(t_program *program, int i)
{
	program->philos = (t_philo *)ft_calloc(sizeof(t_philo),
			program->input->phil_num);
	if (program->philos == NULL)
		return (0);
	while (i < program->input->phil_num)
	{
		program->philos[i].index = i + 1;
		program->philos[i].input = program->input;
		program->philos[i].servant = program->servant;
		if (i == program->input->phil_num - 1)
		{
			program->philos[i].left_fork = &program->servant->forks[i];
			program->philos[i].right_fork = &program->servant->forks[0];
		}
		else
		{
			program->philos[i].left_fork = &program->servant->forks[i];
			program->philos[i].right_fork = &program->servant->forks[i + 1];
		}
		i++;
	}
	return (1);
}
