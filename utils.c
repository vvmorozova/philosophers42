/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eward <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:26:05 by eward             #+#    #+#             */
/*   Updated: 2022/07/28 20:26:06 by eward            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	do_newtime(time_t start)
{
	struct timeval	tv;
	time_t			mls;

	gettimeofday(&tv, NULL);
	mls = tv.tv_sec * (time_t)1000 + tv.tv_usec / (time_t)1000;
	return (mls - start);
}

int	is_num(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}

int	my_atoi(char *str)
{
	long	num;

	if (!is_num(str))
		return (BAD_RESULT);
	num = 0;
	while (*str)
	{
		num = num * 10 + *str - 48;
		str++;
	}
	if (num >= 0 && num <= MAX_INT)
		return ((int)num);
	return (BAD_RESULT);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*data;
	size_t	n;

	n = count * size;
	data = (void *)malloc(n);
	if (!data)
		return (NULL);
	else
		memset(data, 0, n);
	return (data);
}

void	ft_usleep(time_t time)
{
	time_t	start;
	time_t	end;

	start = do_newtime(0);
	end = do_newtime(0) + time;
	while (start < end)
	{
		usleep(20);
		start = do_newtime(0);
	}
}
