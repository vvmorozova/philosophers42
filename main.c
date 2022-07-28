/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eward <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:00:23 by eward             #+#    #+#             */
/*   Updated: 2022/07/28 15:00:25 by eward            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argv, char **argc)
{
	t_program	program;

	if (argv != 5 && argv != 6)
		return (ft_print_error("Wrong number of arguments\n"));
	if (!init_program(&program))
		return (ft_print_error("Malloc error\n"));
	if (!put_values(program.input, argv, argc))
		return (ft_print_error("Wrong arguments\n"));
	if (!status_init(&program))
		return (ft_print_error("Malloc error\n"));
	if (!philo_init(&program, 0))
		return (ft_print_error("Malloc error\n"));
	if (!start_algo(&program))
		return (ft_print_error("Malloc error\n"));
	(void)argv;
	(void)argc;
}
